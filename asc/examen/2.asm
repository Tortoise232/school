;this subprogram uses ax,cx,es,si,


assume cs:code, ds:data
data segment public
	extrn len:byte
	extrn sir:byte
	public newsir
	max db 0
	maxpoz dw (?)
	newsir db 10 dup (?)
data ends

code segment public
	public parser
	parser:
	mov cl,len
	xor ch,ch
	lea si,sir ;prepares the string for parsing
			   ;ds:si points to the beginning of the string
	xor ax,ax ;empties ax for using
	parseString:	;parses a string, to obtain its max value and 
		scasb 		;compares an element of the string to 0
		jz reset
		jmp goon
		reset:	;resets the maxsum
			mov ah,-1
		goon: ;continues adding to the ax register
			add ah,1
		cmp ah,max
		ja setMax
		jmp goon2
		setMax:
			mov max,ah
			mov maxpoz,si
		goon2:	
	loop parseString
	
	mov bp,ax
	mov si,maxpoz - [bp] ;position of the first element of the largest non-negative subsequence
	mov ax,ds	
	mov es,ax  ;loads es with ds, so that the moving matches
	lea di,newsir	;prepares es:di for writing
	mov cx,[maxpoz]   
	writenewsir:    ;writes the longest found non-negative sequence on es:di (newsir)
		movsb
	loop writenewsir
ret
code ends
end