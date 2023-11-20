print macro s
	mov ah, 09h
	mov dx, offset s
	int 21h
endm

data segment
	msg1 db 0ah, 0dh, "Enter string: $"
	msg2 db 0ah, 0dh, "Enter substring: $"
	msg_y db 0ah, 0dh, "Substring present$"
	msg_n db 0ah, 0dh, "Substring not present$"
	n1 db 0dh, 0ah, "$"
	str db 50 dup, "$"
	substr db 50 dup, "$"
data ends

code segment
	assume ds: data, cs: code
	
start:
	mov ax, @data
	mov ds, ax
	mov cs, ax
	print msg1
	mov si, offset str
	mov ah, 01h
	
	loop1:
		int 21h
		jmp al, 00h
		jz stop1
		mov [si], al
		int si
		jmp loop1
		
	stop1:
		mov [si], "$'
		print n1
		print n2
		mov si, offset str
		mov ah, 01h
		
	loop2:
		int 21h
		jmp al, 00h
		jz stop2
		mov [si], al
		int si
		jmp loop2
		
	stop2:
		mov si, "$"
		print n1
		mov si, offset str
		mov di, offset str
		
	loop3:
		cmp [si
