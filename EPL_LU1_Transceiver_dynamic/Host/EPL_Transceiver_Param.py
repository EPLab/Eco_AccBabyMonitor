# EPL_LU1_Transceiver 
# MCU: nRF24LU1

OP_transceiver = "01"

# Register Definition
RX_PIPE0 = "00"
RX_PIPE1 = "01"
RX_PIPE2 = "02"
RX_PIPE3 = "03"
RX_PIPE4 = "04"
RX_PIPE5 = "05"

# customized pload or not
USRS_PLOAD = "00"
AUTO_PLOAD = "01"

ON 	= "01"
OFF = "00"

# Action Map
EPL_OUTPUT_POWER	= "01"
EPL_CHANNEL			= "02"
EPL_DATARATE		= "03"
EPL_ADDR_WIDTH 		= "04"
EPL_CRC_MODE 		= "05"
EPL_ARD 			= "06"
EPL_ARC				= "07"

EPL_RX_ADDR_P0		= "10"	# nRF24L01 receive address data pipe0 
EPL_RX_ADDR_P1		= "11"  # nRF24L01 receive address data pipe1 
EPL_RX_ADDR_P2		= "12"  # nRF24L01 receive address data pipe2 
EPL_RX_ADDR_P3		= "13"  # nRF24L01 receive address data pipe3 
EPL_RX_ADDR_P4		= "14"  # nRF24L01 receive address data pipe4 
EPL_RX_ADDR_P5		= "15"  # nRF24L01 receive address data pipe5 
EPL_TX_ADDR			= "16"  # nRF24L01 transmit address 

EPL_RX_PW_P0		= "20"  # nRF24L01 \# of bytes in rx payload for pipe0 
EPL_RX_PW_P1		= "21"  # nRF24L01 \# of bytes in rx payload for pipe1 
EPL_RX_PW_P2		= "22"  # nRF24L01 \# of bytes in rx payload for pipe2 
EPL_RX_PW_P3		= "23"  # nRF24L01 \# of bytes in rx payload for pipe3 
EPL_RX_PW_P4		= "24"  # nRF24L01 \# of bytes in rx payload for pipe4 
EPL_RX_PW_P5		= "25"  # nRF24L01 \# of bytes in rx payload for pipe5 

EPL_AUTOACK_P0		= "30"	# nRF24L01 autoack for pipe0 
EPL_AUTOACK_P1		= "31"	# nRF24L01 autoack for pipe1 
EPL_AUTOACK_P2		= "32"	# nRF24L01 autoack for pipe2 
EPL_AUTOACK_P3		= "33"	# nRF24L01 autoack for pipe3 
EPL_AUTOACK_P4		= "34"	# nRF24L01 autoack for pipe4 
EPL_AUTOACK_P5		= "35"	# nRF24L01 autoack for pipe5 

EPL_DATA_LENGTH_P0	= "40"	# nRF24L01 data_length for pipe0 
EPL_DATA_LENGTH_P1	= "41"	# nRF24L01 data_length for pipe1 
EPL_DATA_LENGTH_P2	= "42"	# nRF24L01 data_length for pipe2 
EPL_DATA_LENGTH_P3	= "43"	# nRF24L01 data_length for pipe3 
EPL_DATA_LENGTH_P4	= "44"	# nRF24L01 data_length for pipe4 
EPL_DATA_LENGTH_P5	= "45"	# nRF24L01 data_length for pipe5 

#EPL_DYNPD_LENGTH_P0	= "60"	# nRF24L01 dynamic payload length for pipe0 
#EPL_DYNPD_LENGTH_P1	= "61"	# nRF24L01 dynamic payload length for pipe1 
#EPL_DYNPD_LENGTH_P2	= "62"	# nRF24L01 dynamic payload length for pipe2 
#EPL_DYNPD_LENGTH_P3	= "63"	# nRF24L01 dynamic payload length for pipe3 
#EPL_DYNPD_LENGTH_P4	= "64"	# nRF24L01 dynamic payload length for pipe4 
#EPL_DYNPD_LENGTH_P5	= "65"	# nRF24L01 dynamic payload length for pipe5 

#EPL_GET_PIPE_STATUS	= 0x50
EPL_OPEN_PIPE		= "51"
EPL_CLOSE_PIPE		= "52"


EPL_RUN 			= "F1"
EPL_SHOW_CONFIG		= "F2"
EPL_SENDER_MODE		= "F3"
EPL_DUMPER_MODE 	= "F4"
EPL_EXIT_DUMPER 	= "F5"
EPL_RUN_SENDER 		= "F6"
EPL_RUN_DUMPER 		= "F7"
EPL_NEW_COUNTER		= "F8"
EPL_USER_PLOAD		= "F9"
EPL_DYNAMIC_PD		= "FA"
#EPL_QUIT 			= 0xFF

