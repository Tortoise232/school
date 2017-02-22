ASSUME cs: code, ds:data 
data SEGMENT
s1 db '5','6','7','8'
l1 equ $-s1
s2 db '1','2','3','4'
l2 equ $-s2
s3 db '    '
data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov ax,seg s1
	mov ds,ax
	mov si,offset s1
	mov es,ax ;same segment as s1, i guess
	mov di,offset s3
	mov cx,l1
	loop1: ; effectively just stores the first string
		lodsb
		stosb
	loop loop1
	
	mov si,offset s2
	mov di,offset s3
	mov bx,0
	mov cx,l2
	dec cx
	dec cx
	
	addloop:
		lodsb
		mov ah,s3[bx]
		add al,ah
		stosb
		inc di
		inc si
		inc bx
		inc bx
	loop addloop
	
	mov si,offset s2
	inc si ;makes the offset start from s2+1, the odd position
	mov di,offset s3
	inc di ;makes the offset start from s3+1, the odd position
	mov bx,1
	mov cx,l2
	dec cx
	dec cx
	
	sbbloop:
		lodsb
		mov ah,s3[bx]
		sbb ah,al
		mov al,ah
		stosb
		inc di
		inc si
		inc bx
		inc bx
	loop sbbloop
	
	mov ax,4C00h 
	int 21h 
code ENDS 
END start