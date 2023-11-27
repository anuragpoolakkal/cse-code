.model small
.stack 100h

.data
        text1 db 20h dup(?)
        text2 db 20h dup(?)

        msg1 db 13, 10, "Enter first string: $"
        msg2 db 13, 10, "Enter second string: $"
        equal db 13, 10, "Strings are EQUAL$"
        not_equal db 13, 10, "Strings are NOT EQUAL$"
        dol db "$"
        leng dw ?

        get_len macro msg
                lea si, msg
                mov cx, 0000h
           l1:
                mov ah, [si]
                inc si
                inc cx
                cmp ah, "$"
                jnz l1
                mov leng, cx
        endm

        print macro msg
                lea dx, msg
                mov ah, 09h
                int 21h
        endm

        read macro msg
                lea dx, msg
                mov ah, 3fh
                mov bx, 00h
                int 21h
        endm

.code
        mov ax, @data
        mov ds, ax
        mov es, ax

        print msg1
        read text1

        print msg2
        read text2

        get_len text1
        lea si, text1
        lea di, text2
        mov cx, leng
        rep cmpsb

        jz ok
        print not_equal
        jmp down

        ok: print equal

        down:
                mov ah, 4ch
                int 21h
end