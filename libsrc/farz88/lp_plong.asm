; Internal routine to write long at far pointer
; 31/3/00 GWL

; Entry: E'H'L'=far pointer
;        DEHL=long

;
; $Id: lp_plong.asm,v 1.3 2015-01-19 01:32:43 pauloscustodio Exp $
;

        PUBLIC    lp_plong

        EXTERN     farseg1,incfar


.lp_plong
        ld      a,($04d1)
	ex	af,af'
        push    hl
        pop     ix
        push    de
        pop     iy
        exx
        ld      b,h
        ld      c,l
        call    farseg1
        ld      a,ixl
        ld      (hl),a
        call    incfar
        ld      a,ixh
        ld      (hl),a
        call    incfar
        ld      a,iyl
        ld      (hl),a
        call    incfar
        ld      a,iyh
        ld      (hl),a
        ex	af,af'
        ld      ($04d1),a
        out     ($d1),a
        ret

