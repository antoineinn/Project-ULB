from random import shuffle
import os

###################Functions#############################


def init(elements,symbols,fillings,colors):

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
    Uses os module to determine user's operating system
    Returns number of printed cards
    """
    compteur=0
  
    for i in range(len(board)):     # Finds in the board array the cards in order to push them in the print_card function 
        for card in board[i]:
          print(print_card(card),end="")
          compteur+=1
        print("")

    if compteur<12:                 # Case for if their is less than 12 cards left, fill with "X"

        if compteur==0:

            for i in range(4):
                 print('{:>0}  {:>0}  {:>0}'.format(chr(10060)))
                 print()

        if compteur==3:
            for i in range(3):
                 print('{:>0}  {:>0}  {:>0}'.format(chr(10060)))
                 print()
        elif compteur==6:
            for i in range(2):
                 print('{:>0}  {:>0}  {:>0}'.format(chr(10060)))
                 print()
        if compteur==9:
            for i in range(1):
                 print('{:>0}  {:>0}  {:>0}'.format(chr(10060)))
                 print()

    return compteur
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
            print('{:>0}  {:>0}  {:>0}'.format(print_card(save[0]),print_card(save[1]),print_card(save[2])))  # Prints and align the chosen cards in display format 
            user2=str(input("Are you sure?('c' to confirm) "))  
            if user2=="c":
                res=save    # Stocks the list with the chosen cards in res
            else:
                print("Set not confirmed please try again")
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
    verifylist=[False]*4    # Creates a list of False bool to verify the attributs
    count=0

    if len(cards)==3:   
        for i,j,k in zip(cards[0],cards[1],cards[2]):       # Compares each attribut in parallel to save 
            if (i==j and j==k) or (i!=j and j!=k and i!=k):
                verifylist[count]=True                      # If the current attribut is all different or all identical, changes the verify list
            count+=1

    if all(verifylist):                                     # If the verify list is all True
        res=True
        
    return res

def case_1(board,deck):
    """
    Takes for argument the board and deck
    Returns the board deck and end variable
    Case 1: user selects no set on board, if wrong 3 first card of deck put into board
    """
    
    if len(deck)==0:    # If the deck is empty the game ends
        end=True
    else:
        temp=[]
        for i in range(3):
            temp.append(deck.pop(i))
        board.append(temp)
        end=False   
    return(board,deck,end)
        

def case_2(deck,graveyard):

    """
    Takes for argument the deck and graveyard list
    Returns both list
    Case2: Penalty , take 3 random cars in graveyard adds them to bottom of deck
    """
    
    if len(graveyard)!=0:
        for i in range(3):
            deck.append(random.choice(graveyard))

    return (deck,graveyard)

def case_3(board,deck,graveyard,userset):

    """
    Takes for argument the board ,deck ,graveyard list and userset selection
    Returns the 3 lists
    Case3: Chosen set is correct, set is put in graveyard list
    """
    
    graveyard.append(userset)
    temp=[]
    if len(deck)!=0:    # If their is still cards in deck
        for i in range(3):
            temp.append(deck.pop(i))
        board.append(temp)    

    return (board,deck,graveyard)       

def case_4():

    """
    No arguments , return None
    Case4: Chosen cards doesn't form a set
    """
    
    print("Les cartes choisit ne forme pas un set")

    return None

def exists_set(board):

    """
    Takes for argument board list
    Returns Booleen
    Verifies if their is a set in a list of cards
    """
    
    temp=[]
    res=False
    stop=False
    for card in board:  # Adds all cards to a single dimension list
        for value in card:
            temp.append(value)

        
    for i in range(len(temp)-2):    # Tries every set possibilities for one card , stops when set is found
        if not res:                 # Breaks the loop when a set is found
            for j in range(i+1,len(temp)):
                for k in range(i+2,len(temp)):
                    if is_set([temp[i],temp[j],temp[k]]):   # Verifies if current cards form a set
                        res=True
                        

    return res
            
    
