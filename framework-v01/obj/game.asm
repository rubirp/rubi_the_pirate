;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.5 #9498 (CYGWIN)
;--------------------------------------------------------
	.module game
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _cpct_setPALColour
	.globl _cpct_waitVSYNC
	.globl _cpct_setVideoMode
	.globl _cpct_scanKeyboard_f
	.globl _cpct_disableFirmware
	.globl _myGame
	.globl _initCPC
	.globl _init
	.globl _run
	.globl _processInput
	.globl _update
	.globl _draw
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_myGame::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/game.c:21: void initCPC(){
;	---------------------------------
; Function initCPC
; ---------------------------------
_initCPC::
;src/game.c:22: cpct_disableFirmware();
	call	_cpct_disableFirmware
;src/game.c:23: cpct_setVideoMode(0);
	ld	l,#0x00
	call	_cpct_setVideoMode
;src/game.c:24: cpct_setBorder(HW_BLACK);
	ld	hl,#0x1410
	push	hl
	call	_cpct_setPALColour
;src/game.c:26: cpct_setVideoMode(0);
	ld	l,#0x00
	call	_cpct_setVideoMode
	ret
;src/game.c:34: void init(){
;	---------------------------------
; Function init
; ---------------------------------
_init::
;src/game.c:35: initCPC();
	jp  _initCPC
;src/game.c:39: void run(){
;	---------------------------------
; Function run
; ---------------------------------
_run::
;src/game.c:41: init();
	call	_init
;src/game.c:45: while(1){
00104$:
;src/game.c:47: processInput();
	call	_processInput
;src/game.c:49: update();
	call	_update
;src/game.c:52: cpct_waitVSYNC();
	call	_cpct_waitVSYNC
;src/game.c:53: draw();
	call	_draw
	jr	00104$
;src/game.c:62: void processInput(){
;	---------------------------------
; Function processInput
; ---------------------------------
_processInput::
;src/game.c:63: cpct_scanKeyboard_f();
	jp  _cpct_scanKeyboard_f
;src/game.c:69: void update(){
;	---------------------------------
; Function update
; ---------------------------------
_update::
;src/game.c:82: }
	ret
;src/game.c:84: void draw(){
;	---------------------------------
; Function draw
; ---------------------------------
_draw::
;src/game.c:98: }
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
