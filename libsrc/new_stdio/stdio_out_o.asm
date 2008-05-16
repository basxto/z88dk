; stdio_out_o
; 05.2008 aralbrec

XLIB stdio_out_o
LIB stdio_numprec, stdio_out_u
XREF DISP_STDIO_OUT_U_COMMON

INCLUDE "stdio.def"

; output %o parameter
;
; enter :    ix  = & attached file / device output function
;             a = precision
;             b = width
;             c = flags [-+ O#P0N]
;            de = integer
;            hl = & parameter list
;           bc' = total num chars output on stream thus far
; exit  :   bc' = total num chars output on stream thus far
;         stack = & parameter list
;         carry set if error on stream, a = (errorno) set appropriately
; uses  : af, bc, de, hl, exx, bc'

.stdio_out_o

   ex (sp),hl
   push hl
   push bc                     ; save width and flags
   
   ld bc,8                     ; num chars in buffer = 0, radix = 8
   ld hl,STDIO_TEMPBUFSZ + 7
   add hl,sp                   ; hl = & last char in temporary buffer
   
   call stdio_numprec          ; write number to buffer including precision digits
   pop de
   
   ;     b = num chars written to buffer
   ;     d = width
   ;     e = flags [-+ O#P0N]
   ;    hl = & next free position in destination buffer

   inc b                       ; no digits written to buffer means precision and integer == 0
   djnz noadj
   ld e,0                      ; in this case clear flags so field remains blank

.noadj

   bit 3,e
   jp z, stdio_out_u + DISP_STDIO_OUT_U_COMMON

.addbaseindicator

   ld (hl),'0'
   dec hl
   inc b

   jp stdio_out_u + DISP_STDIO_OUT_U_COMMON
