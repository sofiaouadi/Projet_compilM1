; -----------------------------------------------------------
;   Code genere automatiquement par MiniAlgo Compiler
; -----------------------------------------------------------

.MODEL SMALL
.STACK 100h

.DATA
    PI DW 0
    LIMIT DW 0
    A DW 0
    B DW 0
    X DW 0
    Y DW 0
    T4 DW 0
    L0 DW 0
    MAX DW 0
    L1 DW 0
    L2 DW 0
    T6 DW 0
    L3 DW 0
    T8 DW 0
    i DW 0
    L4 DW 0
    T9 DW 0
    L5 DW 0
    T10 DW 0
    T11 DW 0
    T17 DW 0
    L6 DW 0
    L7 DW 0
    T19 DW 0
    L8 DW 0
    T21 DW 0
    L9 DW 0
    L10 DW 0
    T22 DW 0
    L11 DW 0
    T24 DW 0
    L12 DW 0
    L13 DW 0
    T26 DW 0
    L14 DW 0
    T28 DW 0
    L15 DW 0
    T30 DW 0
    T31 DW 0
    T33 DW 0
    T[T32] DW 0
    _buf DB 6 DUP(?), '$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; [0] (=, 3.140000, , PI)
    MOV AX, 3.140000
    MOV [PI], AX

    ; [1] (=, 50, , LIMIT)
    MOV AX, 50
    MOV [LIMIT], AX

    ; [2] (=, 5, , A)
    MOV AX, 5
    MOV [A], AX

    ; [3] (=, 10, , B)
    MOV AX, 10
    MOV [B], AX

    ; [4] (=, 2.500000, , X)
    MOV AX, 2.500000
    MOV [X], AX

    ; [5] (=, 3.000000, , Y)
    MOV AX, 3.000000
    MOV [Y], AX

    ; [6] (>, 5, 10, T4)
    MOV AX, 5
    MOV BX, 10
    CMP AX, BX
    MOV AX, 0
    JLE _skip6
    MOV AX, 1
_skip6:
    MOV [T4], AX

    ; [7] (ifFalse, T4, , L0)
    MOV AX, [T4]
    CMP AX, 0
    JE L0

    ; [8] (=, 5, , MAX)
    MOV AX, 5
    MOV [MAX], AX

    ; [9] (goto, , , L1)
    JMP L1

    ; [10] (label, , , L0)
L0:

    ; [11] (=, 10, , MAX)
    MOV AX, 10
    MOV [MAX], AX

    ; [12] (label, , , L1)
L1:

    ; [13] (label, , , L2)
L2:

    ; [14] (<, 5, 20, T6)
    MOV AX, 5
    MOV BX, 20
    CMP AX, BX
    MOV AX, 0
    JGE _skip14
    MOV AX, 1
_skip14:
    MOV [T6], AX

    ; [15] (ifFalse, T6, , L3)
    MOV AX, [T6]
    CMP AX, 0
    JE L3

    ; [16] (=, 6, , T8)
    MOV AX, 6
    MOV [T8], AX

    ; [17] (=, T8, , A)
    MOV AX, [T8]
    MOV [A], AX

    ; [18] (goto, , , L2)
    JMP L2

    ; [19] (label, , , L3)
L3:

    ; [20] (=, 0, , i)
    MOV AX, 0
    MOV [i], AX

    ; [21] (label, , , L4)
L4:

    ; [22] (<=, 0, 5, T9)
    MOV AX, 0
    MOV BX, 5
    CMP AX, BX
    MOV AX, 0
    JG _skip22
    MOV AX, 1
_skip22:
    MOV [T9], AX

    ; [23] (ifFalse, T9, , L5)
    MOV AX, [T9]
    CMP AX, 0
    JE L5

    ; [24] (+, A, 0, T10)
    MOV AX, [A]
    MOV BX, 0
    ADD AX, BX
    MOV [T10], AX

    ; [25] (=, T10, , A)
    MOV AX, [T10]
    MOV [A], AX

    ; [26] (=, 1, , T11)
    MOV AX, 1
    MOV [T11], AX

    ; [27] (=, T11, , i)
    MOV AX, [T11]
    MOV [i], AX

    ; [28] (goto, , , L4)
    JMP L4

    ; [29] (label, , , L5)
L5:

    ; [30] (>, A, 0, T17)
    MOV AX, [A]
    MOV BX, 0
    CMP AX, BX
    MOV AX, 0
    JLE _skip30
    MOV AX, 1
_skip30:
    MOV [T17], AX

    ; [31] (ifFalse, T17, , L6)
    MOV AX, [T17]
    CMP AX, 0
    JE L6

    ; [32] (label, , , L7)
L7:

    ; [33] (<, A, 30, T19)
    MOV AX, [A]
    MOV BX, 30
    CMP AX, BX
    MOV AX, 0
    JGE _skip33
    MOV AX, 1
_skip33:
    MOV [T19], AX

    ; [34] (ifFalse, T19, , L8)
    MOV AX, [T19]
    CMP AX, 0
    JE L8

    ; [35] (+, A, 1, T21)
    MOV AX, [A]
    MOV BX, 1
    ADD AX, BX
    MOV [T21], AX

    ; [36] (=, T21, , A)
    MOV AX, [T21]
    MOV [A], AX

    ; [37] (goto, , , L7)
    JMP L7

    ; [38] (label, , , L8)
L8:

    ; [39] (goto, , , L9)
    JMP L9

    ; [40] (label, , , L6)
L6:

    ; [41] (label, , , L9)
L9:

    ; [42] (=, 0, , i)
    MOV AX, 0
    MOV [i], AX

    ; [43] (label, , , L10)
L10:

    ; [44] (<=, 0, 3, T22)
    MOV AX, 0
    MOV BX, 3
    CMP AX, BX
    MOV AX, 0
    JG _skip44
    MOV AX, 1
_skip44:
    MOV [T22], AX

    ; [45] (ifFalse, T22, , L11)
    MOV AX, [T22]
    CMP AX, 0
    JE L11

    ; [46] (<, 0, 2, T24)
    MOV AX, 0
    MOV BX, 2
    CMP AX, BX
    MOV AX, 0
    JGE _skip46
    MOV AX, 1
_skip46:
    MOV [T24], AX

    ; [47] (ifFalse, T24, , L12)
    MOV AX, [T24]
    CMP AX, 0
    JE L12

    ; [48] (label, , , L13)
L13:

    ; [49] (<, A, 50, T26)
    MOV AX, [A]
    MOV BX, 50
    CMP AX, BX
    MOV AX, 0
    JGE _skip49
    MOV AX, 1
_skip49:
    MOV [T26], AX

    ; [50] (ifFalse, T26, , L14)
    MOV AX, [T26]
    CMP AX, 0
    JE L14

    ; [51] (+, A, 1, T28)
    MOV AX, [A]
    MOV BX, 1
    ADD AX, BX
    MOV [T28], AX

    ; [52] (=, T28, , A)
    MOV AX, [T28]
    MOV [A], AX

    ; [53] (goto, , , L13)
    JMP L13

    ; [54] (label, , , L14)
L14:

    ; [55] (goto, , , L15)
    JMP L15

    ; [56] (label, , , L12)
L12:

    ; [57] (+, A, 10, T30)
    MOV AX, [A]
    MOV BX, 10
    ADD AX, BX
    MOV [T30], AX

    ; [58] (=, T30, , A)
    MOV AX, [T30]
    MOV [A], AX

    ; [59] (label, , , L15)
L15:

    ; [60] (=, 1, , T31)
    MOV AX, 1
    MOV [T31], AX

    ; [61] (=, T31, , i)
    MOV AX, [T31]
    MOV [i], AX

    ; [62] (goto, , , L10)
    JMP L10

    ; [63] (label, , , L11)
L11:

    ; [64] (write, A, , )
    ; --- WRITE A ---
    MOV AX, [A]
    LEA DI, _buf+5
    MOV BYTE PTR [DI+1], '$'
    CWD
    PUSH AX
    OR AX, AX
    JNS _pos64
    NEG AX
_pos64:
_wloop64:
    MOV BX, 10
    XOR DX, DX
    DIV BX
    ADD DL, '0'
    MOV [DI], DL
    DEC DI
    OR AX, AX
    JNZ _wloop64
    POP AX
    JS _neg64
    INC DI
    JMP _print64
_neg64:
    MOV BYTE PTR [DI], '-'
_print64:
    MOV AH, 09h
    MOV DX, DI
    INT 21h
    MOV AH, 02h
    MOV DL, 0Dh
    INT 21h
    MOV DL, 0Ah
    INT 21h

    ; [65] (write, 2.500000, , )
    ; --- WRITE 2.500000 ---
    MOV AX, 2.500000
    LEA DI, _buf+5
    MOV BYTE PTR [DI+1], '$'
    CWD
    PUSH AX
    OR AX, AX
    JNS _pos65
    NEG AX
_pos65:
_wloop65:
    MOV BX, 10
    XOR DX, DX
    DIV BX
    ADD DL, '0'
    MOV [DI], DL
    DEC DI
    OR AX, AX
    JNZ _wloop65
    POP AX
    JS _neg65
    INC DI
    JMP _print65
_neg65:
    MOV BYTE PTR [DI], '-'
_print65:
    MOV AH, 09h
    MOV DX, DI
    INT 21h
    MOV AH, 02h
    MOV DL, 0Dh
    INT 21h
    MOV DL, 0Ah
    INT 21h

    ; [66] (=, T[T32], , T33)
    MOV AX, [T[T32]]
    MOV [T33], AX

    ; [67] (write, T33, , )
    ; --- WRITE T33 ---
    MOV AX, [T33]
    LEA DI, _buf+5
    MOV BYTE PTR [DI+1], '$'
    CWD
    PUSH AX
    OR AX, AX
    JNS _pos67
    NEG AX
_pos67:
_wloop67:
    MOV BX, 10
    XOR DX, DX
    DIV BX
    ADD DL, '0'
    MOV [DI], DL
    DEC DI
    OR AX, AX
    JNZ _wloop67
    POP AX
    JS _neg67
    INC DI
    JMP _print67
_neg67:
    MOV BYTE PTR [DI], '-'
_print67:
    MOV AH, 09h
    MOV DX, DI
    INT 21h
    MOV AH, 02h
    MOV DL, 0Dh
    INT 21h
    MOV DL, 0Ah
    INT 21h

    ; --- FIN ---
    MOV AH, 4Ch
    INT 21h
MAIN ENDP
END MAIN
