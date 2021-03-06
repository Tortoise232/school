assume ds:data,cs:code 
data segment 
	maxfilename db 12
	lfile db ?
	filename db 12	dup (?)
	buffer db 100 dup (?)
data ends 
code segment 
start: 
	mov ax,data 
	mov ds,ax
	
	;we read the filename (max 12)
	mov ah, 0ah
	mov dx, offset maxFileName
	int 21h
	
	; we transform the filename into an ASCIIZ string (put zero at the end)
	mov al, lfile
	xor ah, ah
	mov si, ax
	mov filename[si], 0
	
	; open the file using function 3dh of the interrupt 21h
	mov ah, 3dh
	mov al, 1 	; open the file for writing
	mov dx, offset fileName
	int 21h
	mov bx,ax ;used later for typing
	
	; read text into buffer string (input from keyboard)
	mov buffer,100
	mov ah,0ah
	mov dx,offset buffer
	int 21h
	;type into file
	mov dx,offset buffer + 2
	mov cl,buffer + 1
	mov ch,0h
	mov ah,40h
	int 21h
	
	mov ax,4C00h 
	int 21h 
code ends
end start

