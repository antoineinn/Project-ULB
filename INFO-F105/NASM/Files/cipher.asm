CPU 386
GLOBAL main
EXTERN printMessage
SECTION .bss
SECTION .data

message	:	DB 0x12, 0x01, 0x14, 0x15, 0x01, 0x2d, 0x2c, 0x25, 0x0f, 0x0e, 0x13, 0x41, 0x2e, 0x23, 0x36, 0x2b, 0x12, 0x40, 0x09, 0x0d, 0x62, 0x1b, 0x2d, 0x37, 0x05, 0x0e, 0x14, 0x01, 0x32, 0x2e, 0x27, 0x2f, 0x40, 0x09, 0x13, 0x40, 0x36, 0x2b, 0x2d, 0x2c, 0x05, 0x03, 0x14, 0x4e, 0x21, 0x2d, 0x30, 0x30, 0x47, 0x16, 0x05, 0x40, 0x62, 0x1b, 0x2d, 0x37, 0x05, 0x13, 0x13, 0x06, 0x31, 0x37, 0x21, 0x21, 0x40, 0x04, 0x05, 0x03, 0x37, 0x2e, 0x2e, 0x3b, 0x05, 0x04, 0x40, 0x14, 0x30, 0x3b, 0x32, 0x36, 0x05, 0x13, 0x13, 0x01, 0x2a, 0x27, 0x62, 0x2f, 0x39, 0x0f, 0x15, 0x12, 0x25, 0x27, 0x63, 0x48, 0x01, 0x12, 0x04, 0x40, 0x62, 0x30, 0x27, 0x35, 0x5a, 0x40, 0x23, 0x08, 0x28, 0x2d, 0x29, 0x27, 0x2e, 0x0f, 0x12, 0x12, 0x37, 0x21, 0x29, 0x62, 0x0f, 0x04, 0x05, 0x13, 0x2b, 0x31, 0x62, 0x21, 0x02, 0x09, 0x0e, 0x01, 0x62, 0x2b, 0x2c, 0x62, 0x0e, 0x04, 0x40, 0x17, 0x30, 0x3b, 0x62, 0x23, 0x13, 0x40, 0x01, 0x40, 0x30, 0x2b, 0x36, 0x27, 0x03, 0x0f, 0x04, 0x05, 0x01, 0x69, 0x69, 0x62, 0x01, 0x40, 0x04, 0x0f, 0x62, 0x23, 0x31, 0x62, 0x0e, 0x14, 0x01, 0x14, 0x21, 0x37, 0x2f, 0x27, 0x40, 0x5a, 0x4d, 0x49, 0x2b, 0x2d, 0x2c, 0x6c
blocka:		TIMES  4  DB  0
blockb:		TIMES 4 DB 0
roundkey:	Times 4	Db 0
length	:	DB 184
key:		DD 0xDEADBEEF
SECTION .text

main:
	mov edx,0
	mov esi ,0
	mainloop:
		block:

			mov eax,DWORD[message+esi]	; Takes 32 bits per 32 bits
			mov [blockb],eax

			mov eax,[blockb]
			
			
			add esi,4
			mov eax,DWORD[message+esi]
			mov [blocka],eax

			add esi,4
			mov edi,3  ;counter for round and roundkey 

		round:

			mov eax,[blockb]
			xor eax,0xffffffff
			mov[blockb],eax	;	Modular inverse
			


			roundkeyfinding:

			xor ebx,ebx
			xor eax,eax
			mov bl,byte[key+edi] 
			mov bh,bl
			not bh		
			shl ebx, 16	;	Shift left 
			mov bl,byte[key+edi]
			mov bh,bl
			not bh
			mov [roundkey],ebx
			mov ebx, [roundkey]
	
			



			mov eax,[blockb]
			xor eax,[roundkey]
			xor eax,0xffffffff ;	Modular Inverse
			xchg eax,[blocka]
			mov [blockb],eax

			
			

			
			cmp edi,0	; If the four round have passed
			je endround
			dec edi 
			jmp round

		
		endround:
			mov eax,[blockb]
			xchg eax,[blocka]	; Shift
			mov [blocka],eax

			mov eax,[blocka]

			mov [message+esi-8],eax	; Re-write the message

			mov eax,[blockb]

			mov[message+esi-4],eax
			


			movzx ecx,byte[length]
			cmp esi,ecx
			Je mainend
			jmp mainloop

		mainend:

			xor ecx,ecx
			xor ebx,ebx


			movzx ecx, BYTE[length]	; size of the message
			mov ebx, message		; adr of the beginning of the message
			
			;pass parameters to the function through the stack
			push ecx 				; size
			push ebx 				; message adr 
			
			call printMessage 		; call the fnciton
			
			; restore registers after the function call
			pop ebx
			pop ecx
			
			; return
			MOV EBX, 0	; syscall argument: exit code
			MOV EAX, 1	; system call number: sys_exit
			INT 0x80	; call kernel




