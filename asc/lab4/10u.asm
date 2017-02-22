ASSUME cs: code, ds:data 
data SEGMENT
 a db 2h
 b dw 4h
 c db 6h
 d dd 0Ah
 x dd ?
data ENDS

code SEGMENT 
start: 
	mov ax,data 
	mov ds,ax
	mov al,a
	mov ah,0h
	mul b ; dx:ax = a*b 
	mov bl,c 
	mov bh,0h ; bx = c
	add bl,7
	adc bh,0h ; bx = c+7
	mov word ptr x,bx
	mov word ptr x+1,0h ; x = bx
	sub word ptr x,ax
	sbb word ptr x+1,dx ; x = bx - dx:ax
	mov ax, word ptr x
	mov dx, word ptr x+1 ; dx:ax = x
	mov bl,a
	mov bh,0h ; bx =a
	div bx ;ax = x/bx
	sub word ptr d,ax
	sbb word ptr d+1,0h ;d = d - ax
	mov bx,6h
	sub word ptr d,bx
	sbb word ptr d+1,0h ; d = d - 6
	mov ax,word ptr d
	mov dx,word ptr d+1
	mov word ptr x,ax
	mov word ptr x+1,dx
	mov ax,4C00h 
	int 21h 
code ENDS 
END start