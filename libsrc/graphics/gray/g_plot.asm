;
;       TI Gray Library Functions
;
;       Written by Stefano Bodrato - Mar 2001
;
;
;	$Id: g_plot.asm,v 1.4 2015-01-19 01:32:49 pauloscustodio Exp $
;

;Usage: g_plot(int x, int y, int GrayLevel)


                PUBLIC    g_plot

                EXTERN     plotpixel
		EXTERN     respixel
		EXTERN	graypage

.g_plot
		ld	ix,0
		add	ix,sp
		ld	a,(ix+2)	;GrayLevel
		ld	l,(ix+4)	;y
		ld	h,(ix+6)	;x
		
		push	af
		xor	a
		call	graypage
		pop	af
		rra
		jr	nc,set1
		push	af
		push	hl
		call	respixel
		pop	hl
		pop	af
		jr	page2
.set1
		push	af
		push	hl
		call	plotpixel
		pop	hl
		pop	af

.page2
		push	af
		ld	a,1
		call	graypage
		pop	af
		rra
		jp	nc,plotpixel
		jp	respixel
