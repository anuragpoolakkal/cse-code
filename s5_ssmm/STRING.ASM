.model small
.stack 100h
.data 
    str1 DB "Input String(max 20 chars): ", 10, 13, "$"
    input DB 30,?,30 dup("$")  
    str2 dw 30 dup("$")
.code
start:
    mov ax, @data
    mov ds, ax

        mov ah,09h
        lea dx, str1
        int 21h

        lea si,input
        mov ah,0ah
        mov dx,si
        int 21h

    ;Reverse String    
        mov cl,input
        add cl,1
        add si, 1
        mov bl,[si]
        add bl, 1
        add si,1
        
	
       	
    loop1:
        inc si
        cmp byte ptr[si],"$"
        jne loop1

        dec si
        lea di,str2
    loop2:
    	
        mov al,byte ptr[si]
        mov byte ptr[di],al
        dec si
        inc di
        dec bx
        cmp bx,0
        je next
        loop loop2

        ;Printing the reverse string    
next: 	    mov ah,09h
            lea dx,str2
            int 21h    

        mov ah, 4ch
        int 21h
end start 

    ;Getting the string input
