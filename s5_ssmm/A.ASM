.MODEL SMALL
.STACK 64
.DATA
.CODE

START : MOV AX, @DATA
        MOV DX,AX
        MOV AL,01H
        MOV BL,02H
        ADD AL,BL
        MOV SI,3000H
        MOV [SI],AL
        MOV DX,[SI]
        MOV AH,4CH
        INT 21H
        END START
        .END
