ASSUME cs: code, ds:data 

data SEGMENT 
h dw 10
m db 50
yy dw 200
d db -2
x dw ?
data ENDS

code SEGMENT 
start: 
	mov ax,data 
	mov ds,ax
	mov ax,yy
	add ax,h 
	add ax,h
	mov bx,ax
	add bl, m
	add bl, d
	sub ax,bx
	mov x,bx
	mov ax,4C00h 
int 21h 
code ENDS 
END start