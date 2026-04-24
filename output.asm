; -----------------------------------------------------------
;   Code genere automatiquement par MiniAlgo Compiler
; -----------------------------------------------------------

.MODEL SMALL
.STACK 100h

.DATA
    MAX DW 0
    A DW 0
    B DW 0
    X DW 0
    T3 DW 0
    L0 DW 0
    L1 DW 0
    L2 DW 0
    T4 DW 0
    L3 DW 0
    T6 DW 0
    L4 DW 0
    T7 DW 0
    L5 DW 0
    T8 DW 0
    _buf DB 6 DUP(?), '$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; [0] (=, 10, , MAX)
    MOV AX, 10
    MOV [MAX], AX

    ; [1] (=, 5, , A)
    MOV AX, 5
    MOV [A], AX

    ; [2] (=, 3, , B)
    MOV AX, 3
    MOV [B], AX

    ; [3] (=, 2.500000, , X)
    MOV AX, 2.500000
    MOV [X], AX

    ; [4] (>, 5, 3, T3)
    MOV AX, 5
    MOV BX, 3
    CMP AX, BX
    MOV AX, 0
    JLE _skip4
    MOV AX, 1
_skip4:
    MOV [T3], AX

    ; [5] (ifFalse, T3, , L0)
    MOV AX, [T3]
    CMP AX, 0
    JE L0

    ; [6] (write, 5, , )
    ; --- WRITE 5 ---
    MOV AX, 5
    LEA DI, _buf+5
    MOV BYTE PTR [DI+1], '$'
    CWD
    PUSH AX
    OR AX, AX
    JNS _pos6
    NEG AX
_pos6:
_wloop6:
    MOV BX, 10
    XOR DX, DX
    DIV BX
    ADD DL, '0'
    MOV [DI], DL
    DEC DI
    OR AX, AX
    JNZ _wloop6
    POP AX
    JS _neg6
    INC DI
    JMP _print6
_neg6:
    MOV BYTE PTR [DI], '-'
_print6:
    MOV AH, 09h
    MOV DX, DI
    INT 21h
    MOV AH, 02h
    MOV DL, 0Dh
    INT 21h
    MOV DL, 0Ah
    INT 21h

    ; [7] (goto, , , L1)
    JMP L1

    ; [8] (label, , , L0)
L0:

    ; [9] (write, 3, , )
    ; --- WRITE 3 ---
    MOV AX, 3
    LEA DI, _buf+5
    MOV BYTE PTR [DI+1], '$'
    CWD
    PUSH AX
    OR AX, AX
    JNS _pos9
    NEG AX
_pos9:
_wloop9:
    MOV BX, 10
    XOR DX, DX
    DIV BX
    ADD DL, '0'
    MOV [DI], DL
    DEC DI
    OR AX, AX
    JNZ _wloop9
    POP AX
    JS _neg9
    INC DI
    JMP _print9
_neg9:
    MOV BYTE PTR [DI], '-'
_print9:
    MOV AH, 09h
    MOV DX, DI
    INT 21h
    MOV AH, 02h
    MOV DL, 0Dh
    INT 21h
    MOV DL, 0Ah
    INT 21h

    ; [10] (label, , , L1)
L1:

    ; [11] (label, , , L2)
L2:

    ; [12] (<, 3, 10, T4)
    MOV AX, 3
    MOV BX, 10
    CMP AX, BX
    MOV AX, 0
    JGE _skip12
    MOV AX, 1
_skip12:
    MOV [T4], AX

    ; [13] (ifFalse, T4, , L3)
    MOV AX, [T4]
    CMP AX, 0
    JE L3

    ; [14] (=, 4, , T6)
    MOV AX, 4
    MOV [T6], AX

    ; [15] (=, T6, , B)
    MOV AX, [T6]
    MOV [B], AX

    ; [16] (goto, , , L2)
    JMP L2

    ; [17] (label, , , L3)
L3:

    ; [18] (=, 0, , A)
    MOV AX, 0
    MOV [A], AX

    ; [19] (label, , , L4)
L4:

    ; [20] (<=, 0, 5, T7)
    MOV AX, 0
    MOV BX, 5
    CMP AX, BX
    MOV AX, 0
    JG _skip20
    MOV AX, 1
_skip20:
    MOV [T7], AX

    ; [21] (ifFalse, T7, , L5)
    MOV AX, [T7]
    CMP AX, 0
    JE L5

    ; [22] (write, 0, , )
    ; --- WRITE 0 ---
    MOV AX, 0
    LEA DI, _buf+5
    MOV BYTE PTR [DI+1], '$'
    CWD
    PUSH AX
    OR AX, AX
    JNS _pos22
    NEG AX
_pos22:
_wloop22:
    MOV BX, 10
    XOR DX, DX
    DIV BX
    ADD DL, '0'
    MOV [DI], DL
    DEC DI
    OR AX, AX
    JNZ _wloop22
    POP AX
    JS _neg22
    INC DI
    JMP _print22
_neg22:
    MOV BYTE PTR [DI], '-'
_print22:
    MOV AH, 09h
    MOV DX, DI
    INT 21h
    MOV AH, 02h
    MOV DL, 0Dh
    INT 21h
    MOV DL, 0Ah
    INT 21h

    ; [23] (=, 1, , T8)
    MOV AX, 1
    MOV [T8], AX

    ; [24] (=, T8, , A)
    MOV AX, [T8]
    MOV [A], AX

    ; [25] (goto, , , L4)
    JMP L4

    ; [26] (label, , , L5)
L5:

    ; --- FIN ---
    MOV AH, 4Ch
    INT 21h
MAIN ENDP
END MAIN
