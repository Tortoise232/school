ASSUME cs: code, ds:data 
data SEGMENT
	a db 01010101b
	b db 10101010b
	c dw ?
data ENDS

code SEGMENT 
start: 
	mov ax,data
	mov ds,ax
	mov ah,b
	mov al,01111000b
	and al,ah ; masking the needed nibble we obtain the proper values for rotating
	mov cl,3
	ror al,cl ;cl is always used with the ro,rc,sh,sa shifting and rotating stuff
	mov bl,0; bytes 4-7 are 0
	mov bl,al ;we will use the bx register for our word cl; bytes 0-3 are bytes 3-6 of B
	mov bh,00000110b ; bytes 8-10 have the value 110
	mov ah,a
	mov al,00011111b
	and al,ah ;masking the needed bits we obtain the proper values
	rol al,cl
	or bh,al ;we move the bits into ch, obtaining the proper bits
	mov c,bx
	
	mov ax,4C00h 
	int 21h 
code ENDS 
END start



