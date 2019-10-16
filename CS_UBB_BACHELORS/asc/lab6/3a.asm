ASSUME cs: code, ds:data 
data SEGMENT
	s1 db '12345678'
	l equ $-s1
	s2 db '        '
data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov es,ax
	mov si,offset s1
	mov di,offset s2
	
	mov cx,l
	loop1:
		movsb
		inc si 
		dec cx
	loop loop1
	mov si,offset s1
	inc si
	mov cx,l
	loop2:
		movsb
		inc si
		dec cx
	loop loop2
	
	mov ax,4C00h 
	int 21h 
code ENDS 
END start