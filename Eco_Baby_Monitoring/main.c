#include <eco/reg24e1.h>
#include <eco/eco_sys.h>
#include <serial/serial.h>
#include <rf/rf.h>
#include <spi/spi.h>
#include <eco/utils.h>
#include <adc/adc.h>
#include <timer/timer.h>

#define interrupt 		__interrupt
#define RECV_LENGTH		16
#define MSG_LENGTH		20
#define RF_CH			(10 << 1)
#define ADDR_LENGTH		3

// 0x63C0
#define TIMER0_10MS_HIGH	0x63
#define TIMER0_10MS_LOW		0xC0
// 0xF8360
#define TIMER1_500US_HIGH	0xF8
#define TIMER1_500US_LOW	0x30


//void store_cpu_rate(unsigned long hz);
//void mdelay(unsigned int msec);
void interrupt_rf() interrupt 10;
void interrupt_timer0() interrupt 1;
void read_acc(char offset);
void rf_enter_rx();
void rf_enter_tx();
void restart_timer0();
void restart_timer1();
typedef void (*callback_t)(void);
callback_t timer1_callback;
void LED_Off();
void LED_On();

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
unsigned int timer0_cnt = 0;
unsigned int timer1_cnt = 0;
unsigned int trigger = 200;
unsigned int delay = 0;
unsigned char task_cnt = 0;
char seq = 0;
char fs = 10;


static char GROUP_ID = 10;
static unsigned char ECO_ID = 5;

void main()
{
	int i;

	char gid = 0;
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
	EX4 = 1;

	/* init timer 0 and timer 1 */
	/* timer 0 for periodical task */
	TMOD = (TMOD & 0xF0) | 0x01; // enable Timer0, 16-bit counter mode
	CKCON |= 0x08; // T0M = 1, Timer0 uses CPU_CLK/4(4MHz)
	PT0 = 1; // Timer0 interrupt has high priority
	ET0 = 1; // enable timer0 interrupt
	/* timer 1 for delay */
	TMOD = (TMOD & 0x0F) | 0x10; // enable Timer1, 16-bit counter mode
	CKCON |= 0x10; // T1M = 1, Timer1 uses CPU_CLK/4(4MHz)
	ET1 = 1;


	for(i = 0; i < 10; i++)
	{
		blink_led();
		mdelay(200);
	}

	// enable global interrupt
	EA = 1;
	restart_timer0();

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
					trigger = 200;
				} else{
					start = 1;
					seq = 0;
					trigger = 100 / fs;
					if (ECO_ID == 1){
						delay = 3;
					} else{
						delay = (trigger * 4) * (ECO_ID - 1) + 1;
					}

				}
				restart_timer0();
			}
			rflag = 0;
		}
	}
}

void LED_Off(){
	P0 |= 0x20;
}

void LED_On(){
	P0 &= ~(0x20);
}


void restart_timer0(){
	TR0 = 0;
	timer0_cnt = 0;
	TH0 = TIMER0_10MS_HIGH;
	TL0 = TIMER0_10MS_LOW;
	TR0 = 1;
}

void restart_timer1(){
	TR1 = 0;
	timer1_cnt = 0;
	TH1 = TIMER1_500US_HIGH;
	TL1 = TIMER1_500US_LOW;
	TR1 = 1;
}

void send_reading(){
	blink_led();
	rf_enter_tx();
	rf_send(dst_addr, ADDR_LENGTH, msg, MSG_LENGTH);
	rf_enter_rx();
}

void task(){
	if (task_cnt){
		// second sample
		msg[10] = (GROUP_ID << 4) | (ECO_ID);
		msg[11] = seq + 1;
		read_acc(10);
		seq = (seq + 1) % fs;
		// send out
		timer1_callback = send_reading;
		restart_timer1();

		task_cnt = 0;
	} else{
		// first sample
		msg[0] = (GROUP_ID << 4) | (ECO_ID);
		msg[1] = seq + 1;
		read_acc(0);
		seq = (seq + 1) % fs;

		task_cnt = 1;
	}
}

void blink_ID()
{
	unsigned char i;
	for (i = 0; i < ECO_ID; i++){
		LED_On();
		mdelay(100);
		LED_Off();
		mdelay(100);
	}
}

void interrupt_timer0() interrupt 1
{
	TH0 = TIMER0_10MS_HIGH;
	TL0 = TIMER0_10MS_LOW;

	timer0_cnt++;
	if (timer0_cnt == trigger){
		if (start){
			task();
		}else{
			blink_ID();
		}
		timer0_cnt = 0;
	}
}

void interrupt_timer1() interrupt 3
{
	TH1 = TIMER1_500US_HIGH;
	TL1 = TIMER1_500US_LOW;

	timer1_cnt++;
	if (timer1_cnt == delay){
		timer1_callback();
		timer1_cnt = 0;
		TR1 = 0;
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
//	mdelay(1);
}

void rf_enter_tx(){
	cfg->rf_prog[1] &= 0xFE;
	rf_configure(cfg);
//	mdelay(1);
}
