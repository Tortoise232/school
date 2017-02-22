ASSUME cs:code, ds:data
data SEGMENT
	sir db '  $'
	tam db 'AM $'
	tpm db 'PM $'
data ENDS

code SEGMENT

 
start: 
	
	mov ax,data
	mov ds,ax
	mov ax,2c00h
	int 21h
	cmp ch,18h
	jz mn
	cmp ch,0ch ;checks to fit in AM or PM by cmp-ing with 12
	ja pm
	jmp am
	mn:
		sub ch,18h
		lea dx,tam
		jmp don
	pm: ;prints AM and sub 12 from the hours
		sub ch,0ch
		lea dx,tpm
		jmp don ;skips printing PM 
	am: ;prints PM
		lea dx,tam
	don:
	mov ax,0900h
	int 21h
	mov al,ch ;puts in the hour
	mov ah,0h
	mov bp,2
	mov bl,10
	decomp: ;decomposes time to a string, by dividing to 10
		div bl
		add ah,30h
		mov sir[bp-1],ah ;stores the 2 digits from right to left
		mov ah,0
		dec bp
		cmp ax,0
	loopne decomp
	
	mov bp,0
	mov cx,2h 
	printer: ;prints hours
		mov dl,sir[bp]
		mov ax,0200h
		int 21h
		inc bp
	loop printer
	
	mov dl,':'
	int 21h
	mov ax,2c00h
	int 21h ;asking for minutes, yo
	mov al,cl ;puts in the minutes
	mov ah,0h
	decomp2: ;decomposes time to a string, by dividing to 10
		div bl
		add ah,30h
		mov sir[bp-1],ah ;stores the 2 digits from right to left
		mov ah,0
		dec bp
		cmp ax,0
	loopne decomp2
	
	mov bp,0
	mov cx,2h 
	printer2: ;prints minutes?
		mov dl,sir[bp]
		mov ax,0200h
		int 21h
		inc bp
	loop printer2
	
	
	mov ax,4C00h 
	int 21h 
code ENDS 
END start


