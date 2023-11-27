.model small
.data
    str1 db 'Sorted array is : $'
    arr dw 2,6,9,3,1,0
    count dw 6
    i dw 0
    j dw 1
    min dw 0
    m_ind dw -1



.code

start:
        mov ax, @data
        mov ds, ax
        lea dx,str1
        mov ah, 9
        int 21h

        lea si, arr
        mov cx, count
	
        mov bx, 0
        mov ax,0

 loop1 :
 	mov dx, i
 	mov ax, [si + dx*2]
 	inc dx
 	mov i, dx

loop2 :
	mov dx, j
	mov bx,[si + dx*2]
	inc dx
	mov j, dx
	
	cmp bx,ax
	jl minn

minn : mov min, bx
	mov m_index, 
	
	
	
	cmp dx, cx
	jg loop2
	mov dx, i
	inc dx
	mov j, dx
	
	
	
	
	


        mov ah, 4ch
        int 21h
end start
.end