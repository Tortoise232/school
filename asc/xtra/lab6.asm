ASSUME cs: code, ds:data 		;(h+yy+d)-(m+m)
data SEGMENT 
	m db 30
	h dw 200
	yy dw 128
	d dw -2
	x dw ?
data ENDS

code SEGMENT 
start: 
	mov ax,data 
	mov ds,ax
	mov ax,h
	add ax,yy
	add al,d
	mov bl,m
	add bl,m
	mov bx,0
	sub ax,bx
	mov x,ax
	mov ax,4C00h 
int 21h 
code ENDS 
END start