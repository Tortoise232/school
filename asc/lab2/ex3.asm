ASSUME cs: code, ds:data 
data SEGMENT 
	m db 30
	h dw 200
	yy dw 128
	d dw -2
data ENDS

code SEGMENT 
start: 
	mov ax,data 
	mov ds,ax
	mov ax,h
	add ax,h
	add ax,d
	mov bl,m
	mov bx,yy
	sub ax,bx
	mov ax,4C00h 
int 21h 
code ENDS 
END start