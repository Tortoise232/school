ASSUME cs: code, ds:data 
data SEGMENT 
db m 100
dw h 150
db yy 256
dw d -3
dd r 0 
data ENDS

code SEGMENT 
start: 
mov ax,data 
mov ds,ax
mov ax,m
sub m,d
mov d,m
add d,h
add d,h
mov r,d
add r,yy
mov ax,r
mov ax,4C00h 
int 21h 
code ENDS 
END start