ASSUME cs: code, 			;(yy+h+h)-(yy+m+d)
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
	mov ax,yy
	add ax,h
	add ax,h
	mov bx,ax
	mov ax,yy
	add ah,m
	add ah,d
	sub bx,ax
	mov x,bx
	mov ds,ax
	mov ax,4C00h 
int 21h 
code ENDS 
END start