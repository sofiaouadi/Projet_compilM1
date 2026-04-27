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
    T12 DW 0
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

    ; [10] (=, 2, , T12)
    MOV AX, 2
    MOV [T12], AX

    ; [11] (=, T12, , compteur)
    MOV AX, [T12]
    MOV [compteur], AX

    ; [12] (goto, , , L0)
    JMP L0

    ; [13] (label, , , L1)
L1:

    ; --- FIN ---
    MOV AH, 4Ch
    INT 21h
MAIN ENDP
END MAIN
