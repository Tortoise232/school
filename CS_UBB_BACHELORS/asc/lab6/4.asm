ASSUME cs: code, ds:data 
data SEGMENT
	s db 1h,2h,4h,6h,0ah,14h,19h ; d= 1,2,2,4,10,15
	l equ $-s 
	d db l dup(?)
data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov al,l
	dec al
	mov ah,0
	mov cx,ax
	mov bp,0
	mov ah,0
	l1:
		mov al,s[bp+1]
		sub al,s[bp]
		mov d[bp],al
		inc bp
	loop l1
	mov ax,4C00h 
	int 21h 
code ENDS 
END start