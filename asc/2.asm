ASSUME cs: code, ds:data 
data SEGMENT
a dw 1011011010101001b
b dw 1111110010100111b
c dw ?

data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov bx,0
	mov ax,b
	and ax,0000000111100000b
	mov cl,5
	ror ax,cl
	or bx,ax
	mov ax,a
	and ax,0000000000011111b
	mov cl,4
	rol ax,cl
	or bx,ax
	mov ax,a
	and ax,0001111111000000b
	mov cl,3
	rol ax,cl
	or bx,ax
	mov c,bx
	mov ax,4C00h 
	int 21h 
code ENDS 
END start