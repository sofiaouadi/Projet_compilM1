; -----------------------------------------------------------
;   Code genere automatiquement par MiniAlgo Compiler
; -----------------------------------------------------------

.MODEL SMALL
.STACK 100h

.DATA
    compteur DW 0
    pair DW 0
    impair DW 0
    L0 DW 0
    T4 DW 0
    L1 DW 0
    T8 DW 0
    T10 DW 0
    L2 DW 0
    T11 DW 0
    L3 DW 0
    T14 DW 0
    _buf DB 6 DUP(?), '$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; [0] (=, 1, , compteur)
    MOV AX, 1
    MOV [compteur], AX

    ; [1] (=, 0, , pair)
    MOV AX, 0
    MOV [pair], AX

    ; [2] (=, 0, , impair)
    MOV AX, 0
    MOV [impair], AX

    ; [3] (label, , , L0)
L0:

    ; [4] (<=, 1, 20, T4)
    MOV AX, 1
    MOV BX, 20
    CMP AX, BX
    MOV AX, 0
    JG _skip4
    MOV AX, 1
_skip4:
    MOV [T4], AX

    ; [5] (ifFalse, T4, , L1)
    MOV AX, [T4]
    CMP AX, 0
    JE L1

    ; [6] (=, 1, , T8)
    MOV AX, 1
    MOV [T8], AX

    ; [7] (=, T8, , pair)
    MOV AX, [T8]
    MOV [pair], AX

    ; [8] (=, 1, , T10)
    MOV AX, 1
    MOV [T10], AX

    ; [9] (=, T10, , impair)
    MOV AX, [T10]
    MOV [impair], AX

    ; [10] (label, , , L2)
L2:

    ; [11] (==, pair, pair, T11)
    MOV AX, [pair]
    MOV BX, [pair]
    CMP AX, BX
    MOV AX, 0
    JNE _skip11
    MOV AX, 1
_skip11:
    MOV [T11], AX

    ; [12] (ifFalse, T11, , L3)
    MOV AX, [T11]
    CMP AX, 0
    JE L3

    ; [13] (=, 44, , pair)
    MOV AX, 44
    MOV [pair], AX

    ; [14] (goto, , , L2)
    JMP L2

    ; [15] (label, , , L3)
L3:

    ; [16] (=, 2, , T14)
    MOV AX, 2
    MOV [T14], AX

    ; [17] (=, T14, , compteur)
    MOV AX, [T14]
    MOV [compteur], AX

    ; [18] (goto, , , L0)
    JMP L0

    ; [19] (label, , , L1)
L1:

    ; --- FIN ---
    MOV AH, 4Ch
    INT 21h
MAIN ENDP
END MAIN
