ASSUME cs: code, ds:data 
data SEGMENT 
data ENDS
code SEGMENT 
start: 
mov ax,data 
mov ds,ax
mov ax,3
mov bx,8
add ax,bx
mov ax,4C00h 
int 21h 
code ENDS 
END start
