;
;	Sharp OZ family functions
;
;	ported from the OZ-7xx SDK by by Alexander R. Pruss
;	by Stefano Bodrato - Oct. 2003
;
;
;	int ozgetch();
;	picks a char from keyboard buffer
;
;
; ------
; $Id: ozgetch.asm,v 1.2 2015-01-19 01:33:01 pauloscustodio Exp $
;


	PUBLIC	ozgetch2	; renamed (will be redefined if used)

	EXTERN	KeyBufGetPos
	EXTERN	EnableKeyboard

ozgetch2:
    ld	    hl,KeyBufGetPos
    ld      de,EnableKeyboard
    jr	    WaitForKey
WaitForKey0:
    dec     hl
    halt
WaitForKey:
    ld     a,(de)
    and    0ffh-7
    ld      (de),a
    ld	    a,(hl)   ;; KeyBufGetPos
    inc     hl
    cp	    (hl)     ;; KeyBufPutPos
    jr      z,WaitForKey0
    inc     a
    cp	    0ch
    jr	    c,dontzero
    xor     a
dontzero:
    ld	    c,a
    sla     c
    ld	    b,0
    inc     hl	     ;; KeyboardBuffer
    add     hl,bc
    ld	    c,(hl)
    inc     hl
    ld	    h,(hl)
    ld	    l,c
    ld	    (KeyBufGetPos),a
    ret

