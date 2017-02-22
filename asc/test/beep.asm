ASSUME cs:code, ds:data
data SEGMENT
	
data ENDS

code SEGMENT 
start: 
	mov ax,data
	mov ds,ax
	mov cx,0ffffh
	testme:
	mov ax,0h
	int 16h
	mov dl,al
	mov ax,0200h
	int 21h
	loop testme
	mov ax,4C00h 
	int 21h 
code ENDS 
END start



