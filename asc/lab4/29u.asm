ASSUME cs: code, ds:data 
data SEGMENT
 a db 8h
 b db 6h
 c db 4h
 d dd 2h
 x dd ?
data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov al,a
	add al,b
	mov ah,0h
	adc ah,0h ; ax = a + b
	mov bl,2
	sub c,bl ; c =  c - 2
	div c
	add al,bl
	mov ah,0h
	adc ah,0h
	sub ax,word ptr d
	sbb dx,word ptr d+1
	mov word ptr d,ax
	mov word ptr d+1,dx
	mov word ptr x,ax
	mov word ptr x+1,dx
	mov ax,4C00h 
	int 21h 
code ENDS 
END start