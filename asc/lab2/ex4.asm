ASSUME cs: code, ds:data 
data SEGMENT				; (h+h)-yy-(m+d) 

	m db 30
	h dw 200
	yy dw 128
	d db -2
	x dw ?
data ENDS

code SEGMENT 
start: 
	mov ax,data 
	mov ax,h
	add ax,h
	sub ax,yy
	mov bx,ax
	mov ah,0
	mov al,m
	add al,d
	sub bx,ax
	mov x, ax
	mov ds,ax
	
mov ax,4C00h 
int 21h 
code ENDS 
END start