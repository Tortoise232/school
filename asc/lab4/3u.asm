ASSUME cs: code, ds:data 
data SEGMENT
 a dw 2h
 b db 4h
 c db 8h
 d db 6h
 e dd 0Ah
 x dw ?
data ENDS

code SEGMENT 
start: 
	mov ax,data 
	mov ax,a
	mul 2h
	add word ptr e,ax
	adc word ptr e+1,dx
	mov al,b
	cbw 
	div 2h
	cbw
	add word ptr e,ax
	adc word ptr e+1,0h
	mov al,c
	sub al,d
	cbw 
	mov x,ax
	mov ax,word ptr e
	mov dx,word ptr e+1
	div x
	mov x,ax
	mov ds,ax

	mov ax,4C00h 
	int 21h 
code ENDS 
END start