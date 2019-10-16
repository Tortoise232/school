assume ds:data,cs:code 
data segment
digits db '0123456789'
lendig equ $-digits ;length of the digits
buffer db 100 dup (?)
data ends 

code segment
start:
	mov ax,data
	mov ds,ax
	mov bp,0
	read:
		mov ah,08h ;keyboard input, no echo
		int 21h
		mov cx,9
		cmpd:
			mov si,cx
			cmp digits[si],al
			je digit
		loop cmpd
		mov ah,'$'
		cmp ah,al
		je done
		mov buffer[bp],al
		inc bp
	loop read
	digit:
	mov ah,02h
	mov dl,al
	int 21h
	jmp read
	done:
	mov buffer[bp],'$'
	mov dx,offset buffer
	mov ah,09h
	int 21h
	mov ax,4C00h 
	int 21h
code ends 
end start

