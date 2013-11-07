#include <eco/reg24e1.h>
#include <eco/eco_sys.h>
#include <serial/serial.h>
#include <rf/rf.h>
#include <spi/spi.h>
#include <eco/utils.h>
#include <adc/adc.h>

#define interrupt 		__interrupt
#define RECV_LENGTH		16
#define MSG_LENGTH		20
#define RF_CH			(10 << 1)
#define ADDR_LENGTH		3

static char GROUP_ID = 10;
static char ECO_ID = 5;

#define LED_Off()		P0 |= 0x20
#define LED_On()		P0 &= ~(0x20)

//void store_cpu_rate(unsigned long hz);
//void mdelay(unsigned int msec);
void interrupt_rf() interrupt 10;
void read_acc(char offset);
void rf_enter_rx();
void rf_enter_tx();
struct rf_config rf_data = {
{ 0x00 }, /* data2 width(bits) */
{ RECV_LENGTH }, /* data1 width(bits)*/
{ 0x00, 0x00, 0x00, 0x00, 0x00 }, /* addr2 */
{ 0x00, 0x00, 0xE6, 0xE6, 0xE6 }, /* addr1, host addr */
{ 0x61 }, /* 24-bit address, 8-bit CRC */
{ 0x6f, RF_CH } };
struct rf_config *cfg = &rf_data;
char dst_addr[3] = { 0x0F, 0x01, 0x01 };
extern char rf_buf[RF_BUF_LEN];
char rflag;
char msg[MSG_LENGTH];
char start = 0;

void main()
{
	int i;

	char seq = 0;
	char gid = 0;
	char fs = 10;
	int delay = 1000 / fs;
	store_cpu_rate(16);
	/* init led */
	P0_DIR &= ~0x28;
	P0_ALT &= ~0x28;

	/* init. adc */
	adc_init(ADC_CLK_D8, ADC_RES_12, EXTREF);

	/* init rf */
	rf_init();
	rf_configure(cfg);
	rflag = 0;

	for (i = 0; i < MSG_LENGTH; i++){
		msg[i] = i;
	}

	EA = 1;
	EX4 = 1;

	for(i = 0; i < 10; i++)
	{
		blink_led();
		mdelay(200);
	}

	rf_enter_rx();
	while(1) {
		CE = 1;
		if (rflag){
			gid = rf_buf[0];
			if (gid == GROUP_ID){
				fs = rf_buf[1];
				rflag = 0;
				LED_Off();
				if (fs == 0){
					start = 0;
				} else{
					start = 1;
					seq = 0;
					delay = 1000 / fs;
				}
			}
			rflag = 0;
		}

		if (start){
			blink_led();
			msg[0] = (GROUP_ID << 4) | (ECO_ID);
			msg[1] = seq + 1;
			read_acc(0);
			seq = (seq + 1) % fs;
			mdelay(delay);
			msg[10] = (GROUP_ID << 4) | (ECO_ID);
			msg[11] = seq + 1;
			read_acc(10);
			seq = (seq + 1) % fs;

			if (ECO_ID > 0){
				mdelay(ECO_ID * 2);
			}

			rf_enter_tx();
			rf_send(dst_addr, ADDR_LENGTH, msg, MSG_LENGTH);
			rf_enter_rx();
			mdelay(delay - 2 - (ECO_ID * 2));
		} else{
			LED_Off();
			mdelay(1000);
			for (i = 0; i < ECO_ID; i++){
				LED_On();
				mdelay(100);
				LED_Off();
				mdelay(100);
			}
		}
	}
}

void interrupt_rf() interrupt 10
{
	unsigned char i;
	blink_led();
	i=0;
	while (DR1) {
		rf_buf[i++] = spi_write_then_read(0);	/* clock in data */
	}

	rflag = 1;
	start = 0;
	/* clean up rf interrupt */
	CE = 0;
	EXIF &= ~0x40;
}

void read_acc(char offset){
	int tmp, i;
	char h, l, idx;
	char axis[4] = {X_AXIS, Y_AXIS, Z_AXIS, 2}; // 2 for Vref
	for (i = 0; i < 4; i++){
		idx = (i + 1) * 2 + offset;
		tmp = adc_read(axis[i]);
		h = (tmp >> 8);
		l = tmp & 0xFF;
		if (l < 0){
			l *= -1;
		}
		msg[idx] = h;
		msg[idx + 1] = l;
	}
}

void rf_enter_rx(){
	cfg->rf_prog[1] |= 0x01;
	rf_configure(cfg);
	mdelay(1);
}

void rf_enter_tx(){
	cfg->rf_prog[1] &= 0xFE;
	rf_configure(cfg);
	mdelay(1);
}
