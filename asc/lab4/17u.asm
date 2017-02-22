ASSUME cs: code, ds:data 
data SEGMENT
 a db 2h
 b dd 4h
 c db 6h
 x dw ?
data ENDS

code SEGMENT 
start: 
	mov ax,data 
	mov ds,ax
	mov al,a
	mul a 
	add word ptr b,ax
	adc word ptr b+1,0h
	mov al,c
	mov ah,0h
	div a
	add al,a
	mov ah,0h
	mov bx,ax
	mov ax,word ptr b
	mov dx,word ptr b+1
	div bx
	mov x,ax
	mov ax,4C00h 
	int 21h 
code ENDS 
END start