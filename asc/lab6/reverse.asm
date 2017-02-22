ASSUME cs: code, ds:data 
data SEGMENT
s db '2222'
ls equ $-s
ns db ls dup(?)
x db ?
data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov bp,0
	mov cx,ls
	inc cx
	l:
	mov al,s[bp]
	mov bx,bp
	inc bx
	mov ah,s[bp]
	mov al,s[bx]
	add al,ah
	mov ns[bp],al
	inc bp
	loop l
	mov ax,4C00h 
	int 21h 
code ENDS 
END start