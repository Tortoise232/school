ASSUME cs: code, ds:data 
data SEGMENT
	s1 db 1h,2h,4h,6h,0ah,14h,19h
	l equ $-s1
	s2 db l dup(?)
data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov es,ax
	mov si,offset s1
	mov di,offset s2
	mov cx,l
	dec cx ;so that it goes to l-1 and not l
	
	loop1:
		lodsb
		mov ah,al
		lodsb 
		sbb al,ah
		stosb
		dec si
	loop loop1
	
	
	mov ax,4C00h 
	int 21h 
code ENDS 
END start