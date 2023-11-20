.model small
.data
str1 db "Enter first number: $"
str2 db 13,10,"Enter second number: $"
str3 db 13,10,"The sum is: $"
.code

start: mov ax, @data
        mov ds,ax
        lea dx,str1
        mov ah,9
        int 21h
        mov ah,1
        int 21h
        mov bl,al
        lea dx,str2
        mov ah,9
        int 21h
        mov ah,1
        int 21h
        mov bh,al
        sub bh,48
        sub bl,48
        lea dx,str3
        mov ah,9
        int 21h
        add bh,bl
HERE:   xor ax,ax
        mov al,bh
        xor dx,dx
        mov cl,0AH
        div cl
        mov bh,al
        xor dx,dx
        mov ch,ah
        add ah,48
        mov dl,ah
        xor ax,ax
        mov ah,2
        int 21h

        cmp bh,0
        jne HERE


        add bh,48
        lea dx,str3
        mov ah,9
        int 21h
  
        mov ah,4Ch
        int 21h
 end start
 .end
