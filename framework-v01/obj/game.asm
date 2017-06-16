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
;src/game.c:8: void initCPC(){
;	---------------------------------
; Function initCPC
; ---------------------------------
_initCPC::
;src/game.c:9: cpct_disableFirmware();
	call	_cpct_disableFirmware
;src/game.c:10: cpct_setVideoMode(0);
	ld	l,#0x00
	call	_cpct_setVideoMode
;src/game.c:11: cpct_setBorder(HW_BLACK);
	ld	hl,#0x1410
	push	hl
	call	_cpct_setPALColour
;src/game.c:13: cpct_setVideoMode(0);
	ld	l,#0x00
	call	_cpct_setVideoMode
	ret
;src/game.c:17: void init(){
;	---------------------------------
; Function init
; ---------------------------------
_init::
;src/game.c:18: initCPC();
	jp  _initCPC
;src/game.c:21: void run(){
;	---------------------------------
; Function run
; ---------------------------------
_run::
;src/game.c:23: init();
	call	_init
;src/game.c:26: while(1){
00102$:
;src/game.c:28: processInput();
	call	_processInput
;src/game.c:30: update();
	call	_update
;src/game.c:33: cpct_waitVSYNC();
	call	_cpct_waitVSYNC
;src/game.c:34: draw();
	call	_draw
	jr	00102$
;src/game.c:43: void processInput(){
;	---------------------------------
; Function processInput
; ---------------------------------
_processInput::
;src/game.c:45: cpct_scanKeyboard_f();
	jp  _cpct_scanKeyboard_f
;src/game.c:51: void update(){
;	---------------------------------
; Function update
; ---------------------------------
_update::
;src/game.c:54: }
	ret
;src/game.c:56: void draw(){	
;	---------------------------------
; Function draw
; ---------------------------------
_draw::
;src/game.c:59: }
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
