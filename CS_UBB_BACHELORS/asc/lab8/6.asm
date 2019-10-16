assume ds:data,cs:code 
data segment
	pass db 'luiza'
	len equ $-pass
	pass2 db len dup(?) ;same length as the initial password
data ends

code segment
start:
	mov ax,data
	mov ds,ax
	rereadpass: ;restarts the reading of a password, in case it fails
		mov cx,len ;cx runs for the length of the right password
		mov ah,1h
		mov bx,0h
		mov si,0h
		read: ;reads each character of a pass and puts it on the stack
			int 21h
			mov pass2[si],al
			inc si
			inc bx
			cmp al,13
			je check ;stores the stacked characters
		loop read
		check:
		mov ax, seg pass
		mov ds, ax
		mov es, ax
		mov es, ax
		mov si,offset pass
		mov di,offset pass2
		cmpsb
		jne rereadpass
		mov ax,4c00h
		int 21h
code ends		
end start