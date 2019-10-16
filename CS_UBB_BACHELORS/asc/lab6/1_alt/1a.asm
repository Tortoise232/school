ASSUME cs: code, ds:data 
data SEGMENT
	s1 db '1234' 		;1st string
	ls1 equ $-s1 		;length of 1st string
	s2 db '567' 		;2nd string
	ls2 equ $-s2		;length of 2nd string
	ls3 equ $-s1			;3rd string, hope it tworks hard
	s3 db ls3 dup(?)
data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov cx,ls1
	mov si,offset s1
	mov ax,seg s1
	mov ds,ax
	mov di,offset s3
	mov ax,seg s3
	mov es,ax
	cld
	again: ; loads the first string into the destination string
		lodsb
		stosb
	loop again
	
	mov ax,seg s2
	mov ds,ax ;ds becomes the address of the segment of s2
	mov si,offset s2
	add si,ls2;di becomes the offset of the segment of s2 + it's length
	dec si
	mov cx,ls2
	
	again2:
		std
		lodsb
		cld
		stosb
	loop again2
	
	mov ax,4C00h 
	int 21h 
code ENDS 
END start