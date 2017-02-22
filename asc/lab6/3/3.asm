ASSUME cs: code, ds:data 
data SEGMENT
	s db '12345678'
	l equ $-s
	d db l dup(?)
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
	l1:
		mov al,s[bp]
		mov d[di],al
		inc bp
		inc bp
		inc di
		dec cx
	loop l1
	mov bp,1
	mov al,l
	mov ah,0
	mov cx,ax
	l2:
		mov al,s[bp]
		mov d[di],al
		inc bp
		inc bp
		inc di
		dec cx
	loop l2
	mov ax,4C00h 
	int 21h 
code ENDS 
END start