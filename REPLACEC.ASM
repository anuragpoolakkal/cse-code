read macro x
	mov dx, offset x
	mov ah, 09h
	int 21h
endm

display macro x
	mov dx, offset x
	mov ah, 09h
	int 21h
endm

.model small
.stack

.data
	msg1 db 0ah, 0dh, "Enter the string: $"
	msg2 db 0ah, 0dh, "Enter the character to be replaced: $"
	msg3 db 0ah, 0dh, "Enter the character to be replaced with: $"
	msg4 db 0ah, 0dh, "New string is: $"
	str1 db 100 dup("$")
	
.code
	start:
		mov ax, @data
		mov ds, ax
		
		display msg1
		read str1
		display msg2
		mov ah, 02h
		int 21h
		mov bl, al
		display msg3
		mov ah, 01h
		int 21h
		
		mov cl, al
		mov si, 00h
		
	l0:
		cmp str1[si], "$"
		je l3
		
	l1:
		cmp str1[si], "$"
		je l2
		inc si
		jmp l0
		
	l2:
		mov str1[si], cl
		inc si
		jmp l0
	
	l3:
		display msg1
		display str1
	
	mov ax, 4ch
	int 21h
	
end start
