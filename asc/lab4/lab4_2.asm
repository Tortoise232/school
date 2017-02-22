ASSUME cs: code, ds:data 
data SEGMENT 
a db 2h
b db 4h
c db 6h
d dd 0ah

data ENDS
code SEGMENT 
start:
	mov ax,data 
	mov ds,ax
	mov ah,00h
	mov al,c
	mul b
	add al,a
	adc ah,00h
	sub ax,0009h
	add word ptr d,ax
	adc word ptr d+1,0
	mov ax,4C00h 
int 21h 
code ENDS 
END start