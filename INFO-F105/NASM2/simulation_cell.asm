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

SECTION .data

          ; variables du programme


SECTION .text
	
simulation_cell:
			PUSH EBP 			; Prologue de la fonction - Stockage du valeur de EBP dans la pile et copie du ESP dans EBP. 
								; (ESP pourrait être changé par des autre fonctions pendant l'execution de la fonction.) 
			MOV EBP, ESP		; N.B: [EBP+4] correspond à la vielle valeur de EIP donc il ne doit pas être lu.
			
			; A completer - Corps de la fonction
			;
			;
			; La valeur du retour de la fonction doit être stocké dans le registre EAX

end:
			MOV ESP, EBP		; Epilogue de la fonction - Restaurer ESP et EBP aux valeurs anciennes
			POP EBP
			RET						
	
	


