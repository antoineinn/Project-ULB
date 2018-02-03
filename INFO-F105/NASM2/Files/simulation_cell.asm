;; FUNCTION PROTOTYPE:
;; unsigned char simulation_cell_asm(unsigned char left_neighbour, unsigned char cell, unsigned_char right_neighbour, unsigned char rule[], unsigned char rule_size);

;; DESCRIPTION:
;; La fonction calcule l'etat suivant d'une cellule d'un automate cellulaire elementaire, etant donnes les valeurs des voisins et la regle de ;; mise à jour. 
;; La valeur du retour est stocke dans le registre EAX.
	
;; PARAMETRES:
;; 	- [EBP+8] - Valeur du voisin de gauche - 8 bit
;; 	- [EBP+12] - Valeur de la cellule - 8 bit
;; 	- [EBP+16] - Valeur du voisin de droit - 8 bit
;; 	- [EBP+20] - Adresse du vecteur rule - 32 bit
;; 	- [EBP+24] - Taille du vecteur rule - 8 bit 	

	
CPU 386
GLOBAL simulation_cell
EXTERN printHex
SECTION .data

     ; variables du programme



SECTION .text
	
simulation_cell:
			PUSH EBP 			; Prologue de la fonction - Stockage du valeur de EBP dans la pile et copie du ESP dans EBP. 
								; (ESP pourrait être changé par des autre fonctions pendant l'execution de la fonction.) 
			MOV EBP, ESP		; N.B: [EBP+4] correspond à la vielle valeur de EIP donc il ne doit pas être lu.
			
			movzx ebx,byte[ebp+8]
			movzx ecx,byte[ebp+12]
			movzx edx,byte[ebp+16]
			cmp ecx,1
			je cellis1	
			cmp edx,1
			je gaucheis1

		
			cellis1:	;Cree des masques afin de bien encoder les parametres
				or bl,00000010b
				cmp edx,1
				je gaucheis1


			gaucheis1:
				or bl,00000100b

			

			mov esi,dword[ebp+20]	; Adresse du vecteur rule
			

			xor edx,edx	; Nettoie le registre edx
			
			inc ebx


			movzx edx,byte[ebp+24]
			sub edx,ebx	; Recherche l'indice du resultat dans le vecteur


			movzx eax,byte[esi+edx]


			



			;MOV EBX, 0	; syscall argument: exit code
			;MOV EAX, 1	; system call number: sys_exit
			;INT 0x80	; call kernel



			

			





			;movzx ebx, [vector+dword[eax]]]	
					;
									;
									; La valeur du retour de la fonction doit être stocké dans le registre EAX

end:
			MOV ESP, EBP		; Epilogue de la fonction - Restaurer ESP et EBP aux valeurs anciennes
			POP EBP
			RET						
	
	


