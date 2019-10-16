ASSUME cs: code, ds:data 
data SEGMENT
s db '1','5','3','8','2','9'
l equ $-s
d1 db l dup(?)
d2 db l dup(?)
data ENDS

code SEGMENT 
start: 
	mov ax,data
	mov ds,ax
	mov al,l
	mov ah,0
	mov cx,ax
	mov bp,0
	mov di,0
	mov bx,0
	mov dx,0
	l1: 
		mov al,s[bp]
		jpe parity
		jpo imparity
		here:
		inc bp
	loop l1
	
	parity:
		mov di,bx
		mov d2[di], al
		inc di
		mov bx,di
		jmp here
	loop parity
	
	imparity:
		mov di,dx
		mov d1[di], al
		inc di
		mov dx,di
		jmp here
	loop imparity
	
	mov ax,4C00h 
	int 21h 
code ENDS 
END start