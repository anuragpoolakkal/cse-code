DATA SEGMENT
STR1 DB "Enter the first number:$"
STR2 DB 13,10,"Enter the second number :$"
STR3 DB 13,10,"The sum is :$"
PRINT MACRO
        MOV DL,AL
        ADD DL,30H
        MOV AH,02H
        INT 21H
ENDM
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
        MOV AX,DATA
        MOV DS,AX

        LEA DX,STR1
        MOV AH,9
        INT 21H
        CALL READ
        MOV SI,1000
        MOV [SI],AX

        LEA DX,STR2
        MOV AH,9
        INT 21H
        CALL READ
        ADD AX,[SI]
        MOV [SI],AX
PT1:
        LEA DX,STR3
        MOV AH,9
        INT 21H
        MOV CX,0000H
        MOV AX,[SI]
        MOV BX,000AH
PT2:
        MOV DX,000H
        DIV BX
        PUSH dX
        INC CX
        CMP AX,BX
        JGE PT2
        PRINT
PT3:
        POP AX
        PRINT
        LOOP PT3
        MOV AH,4CH
        INT 21H
READ PROC
        MOV AH,1
        INT 21H
        SUB AL,30H
        MOV AH,00H
        MOV BX,000AH
        MUL BX
        MUL BX
        MUL BX
        MOV CX,AX

        MOV AH,1
        INT 21H
        SUB AL,30H
        MOV AH,00H
        MOV BX,000AH
        MUL BX
        MUL BX
        ADD AX,CX
        MOV CX,AX

        MOV AH,1
        INT 21H
        SUB AL,30H
        MOV AH,00H
        MOV BX,000AH
        MUL BX
        ADD AX,CX
        MOV CX,AX

        MOV AH,1
        INT 21H
        SUB AL,30H
        MOV AH,00H
        ADD AX,CX
        MOV CX,AX
        RET
        READ ENDP
        MOV AH,4CH
        INT 21H
        CODE ENDS
        END START
