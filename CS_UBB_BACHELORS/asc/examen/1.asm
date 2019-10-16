assume cs:code, ds:data

data segment public
	public sir
	public len
	 sir db 1,2,3,0,4,65,105,78,0,10,11,23,0
	 len EQU $-sir
	
data ends

code segment public
extrn parser:proc

start:
	mov ax,data
	mov ds,ax
	call parser
	mov ax,4c00h
	int 21h
code ends
end start