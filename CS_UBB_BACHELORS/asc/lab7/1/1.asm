ASSUME cs: code, ds:data 
data SEGMENT
	s1 db 'ddd'
	l1 equ $-s1
	s2 db 'ab'
	l2 equ $-s2
	s3 db '     ' ;kind of retarded.
	l3 equ $-s3
data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov es,ax
	mov bx,0 ;index for first string
	mov dx,0 ;index for second string
	mov cx,l3
	mov di,offset s3
	l:
		mov si,offset s1
		add si,bx
		lodsb
		mov ah,al
		mov si,offset s2
		add si,dx
		lodsb
		cmp dx,l2
		jge sets2
		cmp bx,l1
		jge sets1
		cmp ah,al
		ja sets1
		sets2:
			mov al,ah
			stosb
			inc bx
			jmp stop
		sets1:
			stosb
			inc dx
			jmp stop
	stop:
	loop l
	mov ax,4C00h 
	int 21h 
code ENDS 
END start