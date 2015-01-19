;
;	ZX IF1 & Microdrive functions
;
;	int i1_from_mdv()
;
;	returns TRUE if the current program 
;	has been loaded from the microdrive
;
;	$Id: if1_from_mdv.asm,v 1.2 2015-01-19 01:33:10 pauloscustodio Exp $
;

	PUBLIC	if1_from_mdv
	
if1_from_mdv:
		ld	de,($5c53) 	; PROG :location of BASIC program 
		ld	hl,($5c4b)	; VARS :location of variables
		sbc	hl,de		; program length
		
		ld	de,(23787)
		sbc	hl,de
		ld	hl,1
		ret	z
		dec	hl
		ret