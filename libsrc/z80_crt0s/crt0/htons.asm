;
;       Small C+ TCP Implementation
;
;       htons() Convert host to network format and back again!
;
;       djm 24/4/99


                PUBLIC    htons

.htons
        ld      a,l
        ld      l,h
        ld      h,a
        ret

