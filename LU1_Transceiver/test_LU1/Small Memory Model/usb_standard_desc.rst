                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.9.0 #5416 (Mar 22 2009) (MINGW32)
                              4 ; This file was generated Tue Oct 26 13:21:01 2010
                              5 ;--------------------------------------------------------
                              6 	.module usb_standard_desc
                              7 	.optsdcc -mmcs51 --model-large
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _g_usb_string_desc
                             13 	.globl _g_usb_string_desc_2
                             14 	.globl _g_usb_string_desc_1
                             15 	.globl _g_usb_conf_desc
                             16 	.globl _g_usb_dev_desc
                             17 ;--------------------------------------------------------
                             18 ; special function registers
                             19 ;--------------------------------------------------------
                             20 	.area RSEG    (DATA)
                             21 ;--------------------------------------------------------
                             22 ; special function bits
                             23 ;--------------------------------------------------------
                             24 	.area RSEG    (DATA)
                             25 ;--------------------------------------------------------
                             26 ; overlayable register banks
                             27 ;--------------------------------------------------------
                             28 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                      29 	.ds 8
                             30 ;--------------------------------------------------------
                             31 ; internal ram data
                             32 ;--------------------------------------------------------
                             33 	.area DSEG    (DATA)
                             34 ;--------------------------------------------------------
                             35 ; overlayable items in internal ram 
                             36 ;--------------------------------------------------------
                             37 	.area OSEG    (OVR,DATA)
                             38 ;--------------------------------------------------------
                             39 ; indirectly addressable internal ram data
                             40 ;--------------------------------------------------------
                             41 	.area ISEG    (DATA)
                             42 ;--------------------------------------------------------
                             43 ; absolute internal ram data
                             44 ;--------------------------------------------------------
                             45 	.area IABS    (ABS,DATA)
                             46 	.area IABS    (ABS,DATA)
                             47 ;--------------------------------------------------------
                             48 ; bit data
                             49 ;--------------------------------------------------------
                             50 	.area BSEG    (BIT)
                             51 ;--------------------------------------------------------
                             52 ; paged external ram data
                             53 ;--------------------------------------------------------
                             54 	.area PSEG    (PAG,XDATA)
                             55 ;--------------------------------------------------------
                             56 ; external ram data
                             57 ;--------------------------------------------------------
                             58 	.area XSEG    (XDATA)
                             59 ;--------------------------------------------------------
                             60 ; absolute external ram data
                             61 ;--------------------------------------------------------
                             62 	.area XABS    (ABS,XDATA)
                             63 ;--------------------------------------------------------
                             64 ; external initialized ram data
                             65 ;--------------------------------------------------------
                             66 	.area XISEG   (XDATA)
                             67 	.area HOME    (CODE)
                             68 	.area GSINIT0 (CODE)
                             69 	.area GSINIT1 (CODE)
                             70 	.area GSINIT2 (CODE)
                             71 	.area GSINIT3 (CODE)
                             72 	.area GSINIT4 (CODE)
                             73 	.area GSINIT5 (CODE)
                             74 	.area GSINIT  (CODE)
                             75 	.area GSFINAL (CODE)
                             76 	.area CSEG    (CODE)
                             77 ;--------------------------------------------------------
                             78 ; global & static initialisations
                             79 ;--------------------------------------------------------
                             80 	.area HOME    (CODE)
                             81 	.area GSINIT  (CODE)
                             82 	.area GSFINAL (CODE)
                             83 	.area GSINIT  (CODE)
                             84 ;--------------------------------------------------------
                             85 ; Home
                             86 ;--------------------------------------------------------
                             87 	.area HOME    (CODE)
                             88 	.area HOME    (CODE)
                             89 ;--------------------------------------------------------
                             90 ; code
                             91 ;--------------------------------------------------------
                             92 	.area CSEG    (CODE)
                             93 	.area CSEG    (CODE)
                             94 	.area CONST   (CODE)
   3BA4                      95 _g_usb_dev_desc:
   3BA4 12                   96 	.db #0x12
   3BA5 01                   97 	.db #0x01
   3BA6 00 02                98 	.byte #0x00,#0x02
   3BA8 00                   99 	.db #0x00
   3BA9 00                  100 	.db #0x00
   3BAA 00                  101 	.db #0x00
   3BAB 20                  102 	.db #0x20
   3BAC 15 19               103 	.byte #0x15,#0x19
   3BAE 77 56               104 	.byte #0x77,#0x56
   3BB0 00 01               105 	.byte #0x00,#0x01
   3BB2 01                  106 	.db #0x01
   3BB3 02                  107 	.db #0x02
   3BB4 00                  108 	.db #0x00
   3BB5 01                  109 	.db #0x01
   3BB6                     110 _g_usb_conf_desc:
   3BB6 09                  111 	.db #0x09
   3BB7 02                  112 	.db #0x02
   3BB8 20 00               113 	.byte #0x20,#0x00
   3BBA 01                  114 	.db #0x01
   3BBB 01                  115 	.db #0x01
   3BBC 00                  116 	.db #0x00
   3BBD A0                  117 	.db #0xA0
   3BBE 32                  118 	.db #0x32
   3BBF 09                  119 	.db #0x09
   3BC0 04                  120 	.db #0x04
   3BC1 00                  121 	.db #0x00
   3BC2 00                  122 	.db #0x00
   3BC3 02                  123 	.db #0x02
   3BC4 FF                  124 	.db #0xFF
   3BC5 01                  125 	.db #0x01
   3BC6 00                  126 	.db #0x00
   3BC7 00                  127 	.db #0x00
   3BC8 07                  128 	.db #0x07
   3BC9 05                  129 	.db #0x05
   3BCA 81                  130 	.db #0x81
   3BCB 02                  131 	.db #0x02
   3BCC 40 00               132 	.byte #0x40,#0x00
   3BCE 00                  133 	.db #0x00
   3BCF 07                  134 	.db #0x07
   3BD0 05                  135 	.db #0x05
   3BD1 01                  136 	.db #0x01
   3BD2 02                  137 	.db #0x02
   3BD3 40 00               138 	.byte #0x40,#0x00
   3BD5 00                  139 	.db #0x00
   3BD6                     140 _g_usb_string_desc_1:
   3BD6 2A                  141 	.db #0x2A
   3BD7 03                  142 	.db #0x03
   3BD8 4E                  143 	.db #0x4E
   3BD9 00                  144 	.db #0x00
   3BDA 6F                  145 	.db #0x6F
   3BDB 00                  146 	.db #0x00
   3BDC 72                  147 	.db #0x72
   3BDD 00                  148 	.db #0x00
   3BDE 64                  149 	.db #0x64
   3BDF 00                  150 	.db #0x00
   3BE0 69                  151 	.db #0x69
   3BE1 00                  152 	.db #0x00
   3BE2 63                  153 	.db #0x63
   3BE3 00                  154 	.db #0x00
   3BE4 20                  155 	.db #0x20
   3BE5 00                  156 	.db #0x00
   3BE6 53                  157 	.db #0x53
   3BE7 00                  158 	.db #0x00
   3BE8 65                  159 	.db #0x65
   3BE9 00                  160 	.db #0x00
   3BEA 6D                  161 	.db #0x6D
   3BEB 00                  162 	.db #0x00
   3BEC 69                  163 	.db #0x69
   3BED 00                  164 	.db #0x00
   3BEE 63                  165 	.db #0x63
   3BEF 00                  166 	.db #0x00
   3BF0 6F                  167 	.db #0x6F
   3BF1 00                  168 	.db #0x00
   3BF2 6E                  169 	.db #0x6E
   3BF3 00                  170 	.db #0x00
   3BF4 64                  171 	.db #0x64
   3BF5 00                  172 	.db #0x00
   3BF6 75                  173 	.db #0x75
   3BF7 00                  174 	.db #0x00
   3BF8 63                  175 	.db #0x63
   3BF9 00                  176 	.db #0x00
   3BFA 74                  177 	.db #0x74
   3BFB 00                  178 	.db #0x00
   3BFC 6F                  179 	.db #0x6F
   3BFD 00                  180 	.db #0x00
   3BFE 72                  181 	.db #0x72
   3BFF 00                  182 	.db #0x00
   3C00                     183 _g_usb_string_desc_2:
   3C00 1A                  184 	.db #0x1A
   3C01 03                  185 	.db #0x03
   3C02 45                  186 	.db #0x45
   3C03 00                  187 	.db #0x00
   3C04 63                  188 	.db #0x63
   3C05 00                  189 	.db #0x00
   3C06 6F                  190 	.db #0x6F
   3C07 00                  191 	.db #0x00
   3C08 20                  192 	.db #0x20
   3C09 00                  193 	.db #0x00
   3C0A 55                  194 	.db #0x55
   3C0B 00                  195 	.db #0x00
   3C0C 70                  196 	.db #0x70
   3C0D 00                  197 	.db #0x00
   3C0E 6C                  198 	.db #0x6C
   3C0F 00                  199 	.db #0x00
   3C10 6F                  200 	.db #0x6F
   3C11 00                  201 	.db #0x00
   3C12 61                  202 	.db #0x61
   3C13 00                  203 	.db #0x00
   3C14 64                  204 	.db #0x64
   3C15 00                  205 	.db #0x00
   3C16 65                  206 	.db #0x65
   3C17 00                  207 	.db #0x00
   3C18 72                  208 	.db #0x72
   3C19 00                  209 	.db #0x00
   3C1A                     210 _g_usb_string_desc:
   3C1A D6 3B 80            211 	.byte _g_usb_string_desc_1,(_g_usb_string_desc_1 >> 8),#0x80
   3C1D 00 3C 80            212 	.byte _g_usb_string_desc_2,(_g_usb_string_desc_2 >> 8),#0x80
                            213 	.area XINIT   (CODE)
                            214 	.area CABS    (ABS,CODE)
