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
	mov ax,0 
	mov cl,1 ; always rotating by 1 bit	
	mov cx,3 ; so we do it three times duh
	lop:
		rcr ax,cl
		adc dx,ax
		rol dx,cl
	loop lop
	mov ax,a
	mov cl,bl
	ror ax,cl
	mov b,ax ;k done.
	mov ax,4C00h 
	int 21h 
code ENDS 
END start



