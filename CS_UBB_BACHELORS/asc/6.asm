ASSUME cs: code, ds:data 
data SEGMENT
a dw 01010101b
b dw ?
data ENDS

code SEGMENT 
start: 
	mov ax,data
	mov ds,ax
	mov dx,0
	mov bl,0; we will use bl for the integer number
	mov ax,a; we load the fucking values omgscrub 
	mov cl,1 ; always rotating by 1 bit	
	mov dl,cl
	mov cx,3 ; so we do it three times duh
	mov dh,cl
	lop:
		mov cl,dl
		rcr ax,cl ;ax rotates right, adds bit to carry
		adc bl,al ;bl receives the bit
		rol bl,cl ;bl rotates left, clears space for next bit
		mov cl,dh
		mov ch,0
	loop lop
	mov ax,a
	mov cl,bl
	ror ax,cl
	mov b,ax ;k done.
	mov ax,4C00h 
	int 21h 
code ENDS 
END start



