ASSUME cs: code, ds:data 
data SEGMENT

	s1 db '5','6','7','8'
	l equ $-s1
	s2 db '1','2','3','4'
	s db l dup(?)

data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov al,l
	mov ah,0
	mov cx,ax
	mov bp,0
	mov ax,0
	l1: ; loads s[0] , s[2]
		mov al,s1[bp]
		add al,s2[bp]
		mov s[bp],al
		inc bp
		inc bp
		dec cx
	loop l1
	
	mov al,l
	mov ah,0
	mov cx,ax
	mov bp,1
	mov ax,0
	l2: ; loads s[1] , s[3]
		mov al,s1[bp]
		sub al,s2[bp]
		mov s[bp],al
		inc bp
		inc bp
		dec cx
	loop l2
	mov ax,4C00h 
	int 21h 
code ENDS 
END start