CPU 386
GLOBAL main
EXTERN printMessage ; this is the name of a function defined in a cpp code

SECTION .data

message	:	DB 0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x21
length	:	DB 6

SECTION .text

main:
	
	movzx ecx, BYTE[length]	; size of the message
	mov ebx, message		; adr of the beginning of the message
	
	;pass parameters to the function through the stack
	push ecx 				; size
	push ebx 				; message adr 
	
	call printMessage 		; call the fnciton
	
	; restore registers after the function call
	pop ebx
	pop eax
	
	; return
	MOV EBX, 0	; syscall argument: exit code
	MOV EAX, 1	; system call number: sys_exit
	INT 0x80	; call kernel
	
	
	


