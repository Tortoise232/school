
assume cs:code, ds:data
data segment
	
data ENDS

code segment
start:
	mov ax,data
	mov ds,ax
	xor cx,cx
	a:
		inc cx
		xor cx,0
	loop a
	mov ax,4c00h
	int 21h
code ends
end start
