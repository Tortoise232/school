ASSUME cs: code, ds:data 		;(h+yy+d)-(m+m)
data SEGMENT 
	m db 30
	h dw 200
	yy dw 128
	d db -2
	x dw ?
data ENDS

code SEGMENT 
start: 
	mov ax,data 
	mov ds,ax
	mov bx,h
	add bx,yy
	mov al,d
	cbw
	add ax,bx
	mov bh,0
	mov bl,m
	add bl,m
	sub ax,bx            
	mov x,ax
	mov ax,4C00h 
int 21h 
code ENDS 
END start