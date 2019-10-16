ASSUME cs: code, ds:data 
data SEGMENT 
a db 2h
b db 4h
c db 6h
d dd 0ah
x dd ?

data ENDS
code SEGMENT 
start:
	mov ax,data 
	mov ds,ax
	mov ah,00h
	mov al,c
	imul b
	add al,a
	cbw
	sub ax,0009h
	cwd
	add word ptr d+1,dx
	adc word ptr d,ax
	mov ax,4C00h 
int 21h 
code ENDS 
END start