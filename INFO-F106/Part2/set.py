"""
INNOCENT ANTOINE
PROJET D'ANNEE Partie 2
Informatique BA1
"""


import datetime
from setFunctions import *

###################Variables#############################

elements={0:1,1:2,2:3}
symbols={0:9762,1:9822,2:9806}
fillings={0:"P",1:"L",2:"V"}
colors={0:31,1:32,2:34}




##########################Main###############################



def main(elements,symbols,fillings,colors):

    """
    Main body of program
    """

    start=datetime.datetime.now()       # Stocks current time in start variable
    deck,board,graveyard=init(elements,symbols,fillings,colors)  
    end=False
    os.system("clear")

    while not end:
        print("Board: ")
        nbrcard=display_board(board)
        user=input("1) Afficher le deck \n2) Absence de set \n3) Choisir un set \n4) Quitter le jeu \n", )
 
        if user=="1":
            print("#############################")
            display_deck(deck)
            print("#############################")

        elif user=="2":
            if exists_set(board):       # Verifies if the board contains at least a set
                board,deck,end=case_1(board,deck)
                print("Their is a set on the board, sorry..")              
            else:
                deck,graveyard=case_2(deck,graveyard)
				
        elif user=="3":
            userset=select_set(board)

            if userset!=None:
                if is_set(userset):
                    board,deck,graveyard=case_3(board,deck,graveyard)
                    print("Well done, it's a set! ")
                    print("")

                elif not is_set(userset):
                    case_4()
                    
        
        elif user=="4":
            end=True
            print("You ended the game")
        else:
            print("Please enter correct answer.\n")

        if end==False:                                  # Other condition to end game
            if (len(deck)==0 and not exists_set(board)):

                end=True
                print("No more card in deck and no set in board")

            elif len(graveyard)==81:

                end=True
                nbrcard=0
                print("Congratulation, no more card in game")


    print("Deck: ",len(deck))        
    print("Board: ",nbrcard)
    print()
    print("Gameplay time: ",datetime.datetime.now()-start)  # Calculates total game time
        

                
main(elements,symbols,fillings,colors  )
    
            
        
          
