
; float log2(float x)

SECTION code_fp_math48

PUBLIC cm48_sdcciy_log2

EXTERN cm48_sdcciy_log2_fastcall

cm48_sdcciy_log2:

   pop af
   pop hl
   pop de
   
   push de
   push hl
   push af
   
   jp cm48_sdcciy_log2_fastcall
