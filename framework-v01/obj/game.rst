                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.5.5 #9498 (CYGWIN)
                              4 ;--------------------------------------------------------
                              5 	.module game
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _cpct_setPALColour
                             12 	.globl _cpct_waitVSYNC
                             13 	.globl _cpct_setVideoMode
                             14 	.globl _cpct_scanKeyboard_f
                             15 	.globl _cpct_disableFirmware
                             16 	.globl _initCPC
                             17 	.globl _init
                             18 	.globl _run
                             19 	.globl _processInput
                             20 	.globl _update
                             21 	.globl _draw
                             22 ;--------------------------------------------------------
                             23 ; special function registers
                             24 ;--------------------------------------------------------
                             25 ;--------------------------------------------------------
                             26 ; ram data
                             27 ;--------------------------------------------------------
                             28 	.area _DATA
                             29 ;--------------------------------------------------------
                             30 ; ram data
                             31 ;--------------------------------------------------------
                             32 	.area _INITIALIZED
                             33 ;--------------------------------------------------------
                             34 ; absolute external ram data
                             35 ;--------------------------------------------------------
                             36 	.area _DABS (ABS)
                             37 ;--------------------------------------------------------
                             38 ; global & static initialisations
                             39 ;--------------------------------------------------------
                             40 	.area _HOME
                             41 	.area _GSINIT
                             42 	.area _GSFINAL
                             43 	.area _GSINIT
                             44 ;--------------------------------------------------------
                             45 ; Home
                             46 ;--------------------------------------------------------
                             47 	.area _HOME
                             48 	.area _HOME
                             49 ;--------------------------------------------------------
                             50 ; code
                             51 ;--------------------------------------------------------
                             52 	.area _CODE
                             53 ;src/game.c:8: void initCPC(){
                             54 ;	---------------------------------
                             55 ; Function initCPC
                             56 ; ---------------------------------
   0043                      57 _initCPC::
                             58 ;src/game.c:9: cpct_disableFirmware();
   0043 CD 07 01      [17]   59 	call	_cpct_disableFirmware
                             60 ;src/game.c:10: cpct_setVideoMode(0);
   0046 2E 00         [ 7]   61 	ld	l,#0x00
   0048 CD F9 00      [17]   62 	call	_cpct_setVideoMode
                             63 ;src/game.c:11: cpct_setBorder(HW_BLACK);
   004B 21 10 14      [10]   64 	ld	hl,#0x1410
   004E E5            [11]   65 	push	hl
   004F CD DB 00      [17]   66 	call	_cpct_setPALColour
                             67 ;src/game.c:13: cpct_setVideoMode(0);
   0052 2E 00         [ 7]   68 	ld	l,#0x00
   0054 CD F9 00      [17]   69 	call	_cpct_setVideoMode
   0057 C9            [10]   70 	ret
                             71 ;src/game.c:17: void init(){
                             72 ;	---------------------------------
                             73 ; Function init
                             74 ; ---------------------------------
   0058                      75 _init::
                             76 ;src/game.c:18: initCPC();
   0058 C3 43 00      [10]   77 	jp  _initCPC
                             78 ;src/game.c:21: void run(){
                             79 ;	---------------------------------
                             80 ; Function run
                             81 ; ---------------------------------
   005B                      82 _run::
                             83 ;src/game.c:23: init();
   005B CD 58 00      [17]   84 	call	_init
                             85 ;src/game.c:26: while(1){
   005E                      86 00102$:
                             87 ;src/game.c:28: processInput();
   005E CD 6C 00      [17]   88 	call	_processInput
                             89 ;src/game.c:30: update();
   0061 CD 6F 00      [17]   90 	call	_update
                             91 ;src/game.c:33: cpct_waitVSYNC();
   0064 CD F1 00      [17]   92 	call	_cpct_waitVSYNC
                             93 ;src/game.c:34: draw();
   0067 CD 70 00      [17]   94 	call	_draw
   006A 18 F2         [12]   95 	jr	00102$
                             96 ;src/game.c:43: void processInput(){
                             97 ;	---------------------------------
                             98 ; Function processInput
                             99 ; ---------------------------------
   006C                     100 _processInput::
                            101 ;src/game.c:45: cpct_scanKeyboard_f();
   006C C3 71 00      [10]  102 	jp  _cpct_scanKeyboard_f
                            103 ;src/game.c:51: void update(){
                            104 ;	---------------------------------
                            105 ; Function update
                            106 ; ---------------------------------
   006F                     107 _update::
                            108 ;src/game.c:54: }
   006F C9            [10]  109 	ret
                            110 ;src/game.c:56: void draw(){	
                            111 ;	---------------------------------
                            112 ; Function draw
                            113 ; ---------------------------------
   0070                     114 _draw::
                            115 ;src/game.c:59: }
   0070 C9            [10]  116 	ret
                            117 	.area _CODE
                            118 	.area _INITIALIZER
                            119 	.area _CABS (ABS)
