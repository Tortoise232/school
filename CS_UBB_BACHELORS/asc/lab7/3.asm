ASSUME cs: code, ds:data 
data SEGMENT
	s dd 55550000h,44441111h,33332222h
	l equ $-s
	
data ENDS

code SEGMENT 
start: 
	mov ax,data 	
	mov ds,ax
	mov es,ax
	mov si,offset s
	add si,2
	mov cx,l
	loop1:
		mov dx,cx ; store the counter
		mov di,si
		loop2:
			mov bx,4
			add di,4 ; THIS IS WRONG LOL
			lodsw
			mov bx,[es:di]
			cmp ax,bx ;compares the vaue of the initial ds:si to all the es:di, which are the rest of the values in the dd vector
			jl switch
			jmp noswitch
			switch: ;switch the values from ds:si to es:di
				lodsw
				sbb si,2
				mov bx,[es:di]
				stosb
				sbb di,2
				mov [ds:si],bx
				jmp noswitch
			noswitch: ;don't do nuthin'
				sbb cx,3
		loop loop2
		mov cx,dx
		add si,4 ;inc ds:si to keep checking the values of the string
		sbb cx,3
	loop loop1
	mov ax,4C00h 
	int 21h 
code ENDS 
END start