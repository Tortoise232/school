ASSUME cs: code, ds:data 
data SEGMENT
	s1 db '1234' 		;1st string
	ls1 equ $-s1 		;length of 1st string
	s2 db '567' 		;2nd string
	ls2 equ $-s2		;length of 2nd string
	ls equ $-s1		;3rd string, hope it twerks hard
	s db ls dup(?)		; length of 3rd string
	ss1 db ls1 dup(?)	; variable for 1st string (length)
	ss2 db ls2 dup(?)	;variable for 2nd string (length)	
data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov bp,0
	mov al,ss1
	mov ah,0
	mov cx,ax
	l1:
		mov al,s1[bp]
		mov s[bp],al
		inc bp
	loop l1
	mov al,ss2
	mov ah,0
	mov cx,ax
	l2:
		mov al,s2[bp]
		mov s[bp],al
		inc bp
	loop l2

	mov ax,4C00h 
	int 21h 
code ENDS 
END start