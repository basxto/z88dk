; void *adt_ListSearch(struct adt_List *list, void *match, void *item1)
; CALLER linkage for function pointers

PUBLIC adt_ListSearch

EXTERN adt_ListSearch_callee
EXTERN ASMDISP_ADT_LISTSEARCH_CALLEE

.adt_ListSearch

   pop bc
   pop de
   pop iy
   pop hl
   push hl
   push hl
   push de
   push bc
   
   jp adt_ListSearch_callee + ASMDISP_ADT_LISTSEARCH_CALLEE
