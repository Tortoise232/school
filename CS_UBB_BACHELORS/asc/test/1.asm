ASSUME cs:code, ds:data
data SEGMENT
	nr dw 2560 ;merge in binar pana la 126
	sir db '                                       $'
		
data ENDS

code SEGMENT 
start: 
	mov ax,data
	mov ds,ax
	mov ax,nr
	mov bl,10 ;divide by 2, obtain rest.
	mov bp,0
	decomp:
		div bl
		add ah,30h
		mov sir[bp],ah
		mov ah,0
		inc bp
		cmp ax,0
	loopne decomp

	
	mov cx,bp
	printer:
		mov dl,sir[bp-1]
		mov ax,0200h
		int 21h
		dec bp
	loop printer
	
	mov ax,4C00h 
	int 21h 
code ENDS 
END start



