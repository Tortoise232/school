ASSUME cs: code, ds:data 
data SEGMENT
a dw 1010101010101010b
b dw 0101010101010101b
c dw ?

data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov bx,0
	
	mov ax,a
	and ax,0111000000000000b
	mov cl,4
	rol ax,cl
	or bx,ax
	
	mov ax,b
	and ax,0000000000011111b
	mov cl,3
	rol ax,cl
	or bx,ax
	
	mov ax,a
	and ax,0000001111111000b
	mov cl,6
	rol ax,cl
	or bx,ax
	
	mov c,bx
	mov ax,4C00h 
	int 21h 
code ENDS 
END start