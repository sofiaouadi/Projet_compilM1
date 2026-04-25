; -----------------------------------------------------------
;   Code genere automatiquement par MiniAlgo Compiler
; -----------------------------------------------------------

.MODEL SMALL
.STACK 100h

.DATA
    PI DW 0
    A DW 0
    T1 DW 0
    B DW 0
    L0 DW 0
    MAX DW 0
    L1 DW 0
    _buf DB 6 DUP(?), '$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; [0] (=, 3.140000, , PI)
    MOV AX, 3.140000
    MOV [PI], AX

    ; [1] (=, 3276988, , A)
    MOV AX, 3276988
    MOV [A], AX

    ; [2] (>, 3276988, B, T1)
    MOV AX, 3276988
    MOV BX, [B]
    CMP AX, BX
    MOV AX, 0
    JLE _skip2
    MOV AX, 1
_skip2:
    MOV [T1], AX

    ; [3] (ifFalse, T1, , L0)
    MOV AX, [T1]
    CMP AX, 0
    JE L0

    ; [4] (=, 3276988, , MAX)
    MOV AX, 3276988
    MOV [MAX], AX

    ; [5] (goto, , , L1)
    JMP L1

    ; [6] (label, , , L0)
L0:

    ; [7] (=, B, , MAX)
    MOV AX, [B]
    MOV [MAX], AX

    ; [8] (label, , , L1)
L1:

    ; --- FIN ---
    MOV AH, 4Ch
    INT 21h
MAIN ENDP
END MAIN
