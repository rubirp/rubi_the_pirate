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
                             16 	.globl _myGame
                             17 	.globl _initCPC
                             18 	.globl _init
                             19 	.globl _run
                             20 	.globl _processInput
                             21 	.globl _update
                             22 	.globl _draw
                             23 ;--------------------------------------------------------
                             24 ; special function registers
                             25 ;--------------------------------------------------------
                             26 ;--------------------------------------------------------
                             27 ; ram data
                             28 ;--------------------------------------------------------
                             29 	.area _DATA
   0118                      30 _myGame::
   0118                      31 	.ds 1
                             32 ;--------------------------------------------------------
                             33 ; ram data
                             34 ;--------------------------------------------------------
                             35 	.area _INITIALIZED
                             36 ;--------------------------------------------------------
                             37 ; absolute external ram data
                             38 ;--------------------------------------------------------
                             39 	.area _DABS (ABS)
                             40 ;--------------------------------------------------------
                             41 ; global & static initialisations
                             42 ;--------------------------------------------------------
                             43 	.area _HOME
                             44 	.area _GSINIT
                             45 	.area _GSFINAL
                             46 	.area _GSINIT
                             47 ;--------------------------------------------------------
                             48 ; Home
                             49 ;--------------------------------------------------------
                             50 	.area _HOME
                             51 	.area _HOME
                             52 ;--------------------------------------------------------
                             53 ; code
                             54 ;--------------------------------------------------------
                             55 	.area _CODE
                             56 ;src/game.c:21: void initCPC(){
                             57 ;	---------------------------------
                             58 ; Function initCPC
                             59 ; ---------------------------------
   0043                      60 _initCPC::
                             61 ;src/game.c:22: cpct_disableFirmware();
   0043 CD 07 01      [17]   62 	call	_cpct_disableFirmware
                             63 ;src/game.c:23: cpct_setVideoMode(0);
   0046 2E 00         [ 7]   64 	ld	l,#0x00
   0048 CD F9 00      [17]   65 	call	_cpct_setVideoMode
                             66 ;src/game.c:24: cpct_setBorder(HW_BLACK);
   004B 21 10 14      [10]   67 	ld	hl,#0x1410
   004E E5            [11]   68 	push	hl
   004F CD DB 00      [17]   69 	call	_cpct_setPALColour
                             70 ;src/game.c:26: cpct_setVideoMode(0);
   0052 2E 00         [ 7]   71 	ld	l,#0x00
   0054 CD F9 00      [17]   72 	call	_cpct_setVideoMode
   0057 C9            [10]   73 	ret
                             74 ;src/game.c:34: void init(){
                             75 ;	---------------------------------
                             76 ; Function init
                             77 ; ---------------------------------
   0058                      78 _init::
                             79 ;src/game.c:35: initCPC();
   0058 C3 43 00      [10]   80 	jp  _initCPC
                             81 ;src/game.c:39: void run(){
                             82 ;	---------------------------------
                             83 ; Function run
                             84 ; ---------------------------------
   005B                      85 _run::
                             86 ;src/game.c:41: init();
   005B CD 58 00      [17]   87 	call	_init
                             88 ;src/game.c:45: while(1){
   005E                      89 00104$:
                             90 ;src/game.c:47: processInput();
   005E CD 6C 00      [17]   91 	call	_processInput
                             92 ;src/game.c:49: update();
   0061 CD 6F 00      [17]   93 	call	_update
                             94 ;src/game.c:52: cpct_waitVSYNC();
   0064 CD F1 00      [17]   95 	call	_cpct_waitVSYNC
                             96 ;src/game.c:53: draw();
   0067 CD 70 00      [17]   97 	call	_draw
   006A 18 F2         [12]   98 	jr	00104$
                             99 ;src/game.c:62: void processInput(){
                            100 ;	---------------------------------
                            101 ; Function processInput
                            102 ; ---------------------------------
   006C                     103 _processInput::
                            104 ;src/game.c:63: cpct_scanKeyboard_f();
   006C C3 71 00      [10]  105 	jp  _cpct_scanKeyboard_f
                            106 ;src/game.c:69: void update(){
                            107 ;	---------------------------------
                            108 ; Function update
                            109 ; ---------------------------------
   006F                     110 _update::
                            111 ;src/game.c:82: }
   006F C9            [10]  112 	ret
                            113 ;src/game.c:84: void draw(){
                            114 ;	---------------------------------
                            115 ; Function draw
                            116 ; ---------------------------------
   0070                     117 _draw::
                            118 ;src/game.c:98: }
   0070 C9            [10]  119 	ret
                            120 	.area _CODE
                            121 	.area _INITIALIZER
                            122 	.area _CABS (ABS)
