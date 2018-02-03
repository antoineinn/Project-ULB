"""
INNOCENT ANTOINE
PROJET D'ANNEE Partie 1
Informatique BA1
Matricule:000394700
"""
#!/usr/bin/env python
# -*- coding: utf-8 -*-


from random import shuffle



###################Variables#############################

elements={0:1,1:2,2:3}
symbols={0:9762,1:9822,2:9806}
fillings={0:"P",1:"L",2:"V"}
colors={0:31,1:32,2:34}




###################Functions#############################


def init():

    """
    Initilisation of variables deck,board and graveyard
    Return those variables in tuple
    """

    deck,board,graveyard=[],[],[]
    temp=[]
    for i in elements.values():     # Saves all the possible combinations of elements,symbols,fillings and colors in deck list
        for j in symbols.values():
            for k in fillings.values():
                for l in colors.values():
                    deck.append([i,j,k,l])

    shuffle(deck)
    
    for i in range(4):      # Creates an array 4*3 for the board
        for j in range(3):
            temp.append(deck.pop(i)) 
        board.append(temp)
        temp=[]
        
          
    return (deck,board,graveyard)



def print_card(card):

    """
    Takes for argument the card in list format
    return the card in string variable as display format
    """
    
    CSI="\x1B["
    string=CSI+str(card[3])+"m"+str(card[2])+card[0]*chr(card[1])+CSI+"0m"	# To color the string
    
    if card[0]==1:	# Ads certain number of spaces after string depending on the number of symbols to align the card display
        string+="    "
    elif card[0]==2:
        string+="   "
    elif card[0]==3:
        string+="  "
        
    return string

def display_deck(deck):

    """
    Takes the deck list for argument
    Uses print_card to display the deck
    """

    count=0             # Uses count variable to limit the number of prints in one line (max 18)
    for card in deck:           
        print(print_card(card),end="")
        count+=1
        if count==18:
            print("")
            count=0
    print("")
    
        
    
def display_board(board):

    """
    Takes the board list for argument
    Uses print_card to display the board
    """
    
    for i in range(len(board)):     # Finds in the board array the cards in order to push them in the print_card function 
        for card in board[i]:
          print(print_card(card),end="")  
        print("")
 
    
    
def select_set(board):

    """
    Takes the board list for argument
    Let the user choose 3 cards
    Returns res list containing the 3 cards
    """

    user=str(input("Choose a set: ")).split()  # Splits the string to seperate entry in list
    print("")
    save=[]
    res=None

    if len(user)==3 and user.count(user[0])==1 and user.count(user[1])==1:  # Verify if the user entered 3 cards and all different

        try:                                                                # Verifies If card is in the board
            for i in range(len(user)):    
                save.append(board[int(user[i])//10-1][int(user[i])%10-1])  #  Saves the chosen card by using the right indices 
        
        except:
            print("Not in the board")
            print("")
        else:
            print('{:>0}  {:>0}  {:>0}'.format(print_card(save[0]),print_card(save[1]),print_card(save[2])))  
	
	# Prints and align the chosen cards in display format 

            user2=str(input("Are you sure?('c' to confirm) "))  
            if user2=="c":
                res=save    # Stocks the list with the chosen cards in res
            else:
                print("Incorrect Value")
                print("")

    else:   # If any other encoding problem

        print("Incorrect value ")
        print(" ")
        
    return res

def is_set(cards):

    """
    Takes the cards list from select_set
    Returns True if cards are a ser
    """
    
    res=False
    verifylist=[False]*4    # Creates a list of Flase bool to verify the attributs
    count=0

    if len(cards)==3:   
        for i,j,k in zip(cards[0],cards[1],cards[2]):       # Compares each attribut in parallel to save 
            if (i==j and j==k) or (i!=j and j!=k and i!=k):
                verifylist[count]=True                      # If the current attribut is all different or all identical, changes the verify list
            count+=1

    if all(verifylist):                                     # If the verify list is all True , the chosen cards form a set
        res=True
        
    return res


##########################Main###############################



def main(elements,symbols,fillings,colors):

    """
    Main body of program
    Creates the menu of the program
    1) Afficher le deck
    2) Mélanger le deck 
    3) Choisir un set  
    4) Quitter le jeu 

    """
    
    deck,board,graveyard=init()
    end=False

    while not end:	# Uses the end variable as a flag to "break" the loop
        print("Board: ")
        display_board(board)
        user=input("1) Afficher le deck \n2) Mélanger le deck \n3) Choisir un set \n4) Quitter le jeu \n", ) 
        if user=="1":
            print("#############################")
            display_deck(deck)
            print("#############################")
        elif user=="2":
            shuffle(deck)
        elif user=="3":
            userset=select_set(board)
            if userset!=None:
                if is_set(userset):	# If chosen cards form a set
                    print("Well done, it's a set! ")
                    print("")
                elif not is_set(userset):
                    print("Sorry, not a set...")
                    print("")
        elif user=="4":
            end=True
        else:		# If any other incorrect input
            print("Please enter correct answer.\n")
        
            
            
        
        
    
    
main(elements,symbols,fillings,colors  )
    
            
        
          
