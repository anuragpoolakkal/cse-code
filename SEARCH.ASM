.model small
.data
        str1 db 'The sorted array is $'
        sch dw 34
        arr dw 1,2,35,4,5
        count dw 5
        str2 db 13,10, 'Element found $'
        str3 db 13,10,'Element not found $'
.code

start: mov ax, @data
        mov ds, ax
  
        mov si, offset arr
        mov bx, sch
        mov ax,  count

   loop1:mov cx,[si]
         add si, 2
         add dl, 1
        cmp cx,bx
        je note
        sub ax,1
        jnz loop1

        lea dx, str3
        mov ah, 9
        int 21h

        jmp skip

   note:lea dx, str2
        mov ah, 9
        int 21h
  skip:
        mov ah, 4ch
        int 21h

end start
.end

        
