assume ds:data,cs:code 
data segment 
	maxfilename db 12
	lfile db ?
	filename db 12	dup (?)
	buffer db 100 dup (?)
	key db 'hello'
data ends 
code segment 
start: 
	mov ax,data 
	mov ds,ax
	
	;we read the filename (max 12)
	mov ah, 0ah
	mov dx, offset maxfileName
	int 21h
	
	; we transform the filename into an ASCIIZ string (put zero at the end)
	mov al, lfile
	xor ah, ah
	mov si, ax
	mov filename[si], 0
	
	; open the file using function 3dh of the interrupt 21h
	mov ah, 3dh
	mov al, 0 	; open the file for reading
	mov dx, offset filename
	int 21h
	push ax
	; read from file into buffer
		mov bx,1 ; 1 into bx if the filereading is still going on lololol
	read:
		mov ax, 3f00h
		pop bx
		mov dx, offset buffer		
		mov cx, 100
		int 21h
		cmp si,100 ;verifica daca e ultima citire din fisier sau daca mai sunt
		je go ; daca mai sunt citiri continua
		jne stop ; daca nu mai sunt citiri (lungime buffer < 100) schimba bx la 0, adica validarea va opri citirea dupa procesarea bufferului actual
		stop:
			mov bx,0
		go:
			
			mov bp,0
			mov cx,100
			
		check:
			mov ax,seg key
			mov es,ax
			mov ax,seg buffer
			mov ds,ax
			mov di,offset key
			mov si,offset buffer
			mov si,offset buffer[bp]
			cmpsb
			je fin1
			inc bp
		loop check
		cmp bx,0
		je fin2
	loop read
	jmp fin2
	fin1:
		mov dl,1h
		mov ah,02h
		int 21h
	fin2:
	mov ax,4C00h 
	int 21h 
code ends
end start