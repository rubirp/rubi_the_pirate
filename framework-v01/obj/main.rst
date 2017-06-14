                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.5.5 #9498 (CYGWIN)
                              4 ;--------------------------------------------------------
                              5 	.module main
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _main
                             12 	.globl _cpct_getScreenPtr
                             13 	.globl _cpct_drawStringM1
                             14 	.globl _cpct_memset
                             15 ;--------------------------------------------------------
                             16 ; special function registers
                             17 ;--------------------------------------------------------
                             18 ;--------------------------------------------------------
                             19 ; ram data
                             20 ;--------------------------------------------------------
                             21 	.area _DATA
                             22 ;--------------------------------------------------------
                             23 ; ram data
                             24 ;--------------------------------------------------------
                             25 	.area _INITIALIZED
                             26 ;--------------------------------------------------------
                             27 ; absolute external ram data
                             28 ;--------------------------------------------------------
                             29 	.area _DABS (ABS)
                             30 ;--------------------------------------------------------
                             31 ; global & static initialisations
                             32 ;--------------------------------------------------------
                             33 	.area _HOME
                             34 	.area _GSINIT
                             35 	.area _GSFINAL
                             36 	.area _GSINIT
                             37 ;--------------------------------------------------------
                             38 ; Home
                             39 ;--------------------------------------------------------
                             40 	.area _HOME
                             41 	.area _HOME
                             42 ;--------------------------------------------------------
                             43 ; code
                             44 ;--------------------------------------------------------
                             45 	.area _CODE
                             46 ;src/main.c:21: void main(void) {
                             47 ;	---------------------------------
                             48 ; Function main
                             49 ; ---------------------------------
   4000                      50 _main::
                             51 ;src/main.c:25: cpct_memset(CPCT_VMEM_START, 0, 0x4000);
   4000 21 00 40      [10]   52 	ld	hl,#0x4000
   4003 E5            [11]   53 	push	hl
   4004 AF            [ 4]   54 	xor	a, a
   4005 F5            [11]   55 	push	af
   4006 33            [ 6]   56 	inc	sp
   4007 26 C0         [ 7]   57 	ld	h, #0xC0
   4009 E5            [11]   58 	push	hl
   400A CD F0 40      [17]   59 	call	_cpct_memset
                             60 ;src/main.c:28: pvmem = cpct_getScreenPtr(CPCT_VMEM_START, 20, 96);
   400D 21 14 60      [10]   61 	ld	hl,#0x6014
   4010 E5            [11]   62 	push	hl
   4011 21 00 C0      [10]   63 	ld	hl,#0xC000
   4014 E5            [11]   64 	push	hl
   4015 CD FF 40      [17]   65 	call	_cpct_getScreenPtr
   4018 4D            [ 4]   66 	ld	c,l
   4019 44            [ 4]   67 	ld	b,h
                             68 ;src/main.c:29: cpct_drawStringM1("Welcome to CPCtelera!", pvmem, 1, 0);
   401A 21 01 00      [10]   69 	ld	hl,#0x0001
   401D E5            [11]   70 	push	hl
   401E C5            [11]   71 	push	bc
   401F 21 2D 40      [10]   72 	ld	hl,#___str_0
   4022 E5            [11]   73 	push	hl
   4023 CD 43 40      [17]   74 	call	_cpct_drawStringM1
   4026 21 06 00      [10]   75 	ld	hl,#6
   4029 39            [11]   76 	add	hl,sp
   402A F9            [ 6]   77 	ld	sp,hl
                             78 ;src/main.c:32: while (1);
   402B                      79 00102$:
   402B 18 FE         [12]   80 	jr	00102$
   402D                      81 ___str_0:
   402D 57 65 6C 63 6F 6D    82 	.ascii "Welcome to CPCtelera!"
        65 20 74 6F 20 43
        50 43 74 65 6C 65
        72 61 21
   4042 00                   83 	.db 0x00
                             84 	.area _CODE
                             85 	.area _INITIALIZER
                             86 	.area _CABS (ABS)
