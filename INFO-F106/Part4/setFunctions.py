import itertools
import os
import random 

# Global variables
FIELD_ROWS=4
FIELD_COLUMNS=3
PENALTY_CARDS=3
CARDS_TO_DRAW=3
CSI="\x1B["

colors = {0: "red" ,1 : "blue", 2 :"green"}
elements = {0 : 1, 1 : 2, 2 : 3}
symbols = {0 : 1,1 : 2,2 : 3}
fillings = {0 : "P",1 : "L",2 : "V"}

# Functions

def print_logo():
    """ Prints a fancy logo for the application """
    print("███████╗███████╗████████╗")
    print("██╔════╝██╔════╝╚══██╔══╝")
    print("███████╗█████╗     ██║")
    print("╚════██║██╔══╝     ██║")
    print("███████║███████╗   ██║")
    print("╚══════╝╚══════╝   ╚═╝")

def init():
    """ Initialization of the main data structures of the game, returns three lists of cards: deck,board,graveyard.  """
    deck = []
    board = []


    # Initialize deck
    deck = [[x,y,z,k] for x in range(3) for y in range(3) for z in range(3) for k in range(3)]
    random.shuffle(deck)

    # Initialize field and draw cards from deck
    board = [deck[i] for i in range(FIELD_ROWS*FIELD_COLUMNS)]
    deck = deck[len(board):]

    # Initialize graveyard
    graveyard = []
    
    return (deck,board,graveyard)


def print_color(color,text):
    """ Prints colored text, the first parameter is an integer representing the ANSI code of the color and the second is a string representing the text to be colored."""
    print(CSI+str(color)+"m" + text + CSI + "0m",end="\t")

def print_card(card):
    """ Print a card in a human readable format (i.e. colored, with an indication of the filling and with symbols). """
    card_str = fillings[card[2]]
    for i in range(0,card[0]+1):
        card_str += symbols[card[1]]
    print_color(colors[card[3]],card_str)

def print_empty_space():
    """ Print the symbol corresponding to the empty space. """
    for i in range(4):
        print(symbols[3],end="")
    print("\t",end="");

def display_deck(deck):
    """ Print deck, 18 cards per row. """
    counter = 0
    print("####################################################");
    for card in deck:
        print_card(card)
        if(counter % 18 == 0 and counter != 0):
            print("");
        counter = counter + 1 
    print("\n####################################################"); 
    return None

def display_board(board):
    """ Print the board, along with row and column indices, preceded by the logo """
    os.system('cls' if os.name == 'nt' else 'clear')
    print_logo()
    print()

    for i in range(len(board)):
        print_card(board[i])
        # Print row index at the end of every row
        if (((i+1) % FIELD_COLUMNS) == 0):
            print("| "+str(i//FIELD_COLUMNS+1),end="\t")
            print("")
            
    # Padding with empty spaces if the number of cards is less than FIELD_ROWS * FIELD_COLUMNS
    if (len(board) < FIELD_ROWS*FIELD_COLUMNS):
        for i in range(FIELD_ROWS*FIELD_COLUMNS - len(board)):
            print_empty_space()
            # Print row index at the end of every row
            if (((len(board)+i+1) % FIELD_COLUMNS) == 0):
                print("| "+str((len(board)+i+1)//FIELD_COLUMNS),end="\t")
                print("")
        
    # Padding with empty spaces if the number of cards is not a multiple of the number of columns    
    if ((len(board) % FIELD_COLUMNS) != 0):
        for i in range(FIELD_COLUMNS - (len(board)%FIELD_COLUMNS)):
            print_empty_space()

    # Print column indexes below the last line
    print("-------------------------")
    for i in range(FIELD_COLUMNS):
        print(str(i+1)+"\t",end="")
    print("")

    return None

def select_set(board):
    """ Prompt the user for a textual input and convert the user selection into a tuple of three cards. Return the tuple of three cards """
    cards_selected = []
    selection_string = input("Inserer les trois cartes séparés par un espace: ")
    cards_index_selected = select_set_verification(selection_string)

    if cards_index_selected is None:
        return None

    for row_index,col_index in cards_index_selected:
        cards_selected.append(board[(row_index-1)*FIELD_COLUMNS+(col_index-1)])

    # Le résultat restitué par itertools est une liste de tuples
    return tuple(cards_selected)

def select_set_verification(selection_string):
    """ Verification of the input string, checking that the string has the correct length, does not contains duplicates, nor non-numeric characters. Return a list of tuple (row_index,col_index= with one element for every card encoded by the user. """
    cards_index_selected = []

    # Verify that the input string has exactly 8 characters: 3x2 numbers + 2 spaces
    if len(selection_string) != 8:
        print("Mauvais encodage des cartes. Réessayer, svp.")
        return None
    
    selection_list = selection_string.split(" ")
    
    # Verify that splitting the string according to the spaces yields to three elements
    if(len(selection_list) != 3):
        print("Mauvais encodage des cartes. Réessayer, svp.")
        return None

    # Verify the absence of duplicates in the list.
    if(len(selection_list) != len(set(selection_list))):
        print("Presence des cartes dupliqueés. Réessayer, svp.")
        return None

    # Verify that every token after the split of the list is correctly encoded
    for card_str in selection_list:
            row_index,col_index = select_set_card_verification(card_str)
            if(row_index is None or col_index is None):
                return None
            cards_index_selected.append((row_index,col_index))
   
    return cards_index_selected

def select_set_card_verification(card_str):
    """ Verification of a single token of the input string, checking that the string has the correct length, and contains only numeric characters. Return a tuple of integers (row_index,col_index) if the encoding is correct, (None,None) otherwise. """
    # Verify that a token is exactly two characters long, and then try to parse every element as an integer
    if(len(card_str) == 2):
        try:
            row_index=int(card_str[0])
        except ValueError:
            print("Erreur de conversion en entier, index ligne. Réessayer, svp.")
            return (None,None)

        try:
            col_index=int(card_str[1])
        except ValueError:
            print("Erreur de conversion en entier, index colonne. Réessayer, svp.")
            return (None,None)
    else:
        print("Mauvais encodage des cartes. Réessayer, svp.")
        return (None,None)

    if(row_index < 0 or row_index > FIELD_ROWS):
        print("Indice de ligne incorrect. Réessayer,svp")
        return (None,None)
    
    if(col_index <0 or col_index > FIELD_COLUMNS):
        print("Indice de colonne incorrect. Réessayer,svp")
        return (None,None)

    return (row_index,col_index)

def operation_input_verification():
    """ Verification of the input of the operation selection request, loops until the input is correct, then returns a single character corresponding to the operation selected. """
    #correct_input = False
    #while(not correct_input):
    raw_string=input("Quelle operation vous voulez faire? (e:Entrer un set/a: Declarer absence set/q: Quitter le jeu) ")
    if not(len(raw_string) == 1 and (raw_string=="e" or raw_string == "a" or raw_string == "q")):
        print("Command non reconnu, Réessayer, svp.")
       
    return raw_string

def is_set(card_trio):
    """ Verifies that a 3-tuple of cards is actually a set. Pre-condition: card_trio is a 3-tuple of cards. Return True if the 3-tuple of cards is a set, False otherwise. """
    if None in card_trio:
        return False
    
    for i in range(4):
        # The function's execution is stopped as soon as the condition to be a set is not met by one property
        if ((card_trio[0][i] + card_trio[1][i] + card_trio[2][i]) % 3) != 0:
            return False
        
    return True


def is_set_lc(card_trio):
    """ Alternative implementation of is_set, using list comprehension.Verifies that a 3-tuple of cards is actually a set. Pre-condition: card_trio is a 3-tuple of cards. Return True if the 3-tuple of cards is a set, False otherwise. """
    if None in card_trio:
        return False
    
    """ 
    Concise and efficient test:
    [x,x,x,x] Card 1
    [x,x,x,x] Card 2
    [x,x,x,x] Card 3
     ^ ^ ^ ^
    With the proposed encoding for the cards, a property has the same values for all the three cards if and only if the sum modulo 3 of the values corresponding to the three cards is equal to zero (i.e. the sum is either zero or 3n with n=1,2).
    On the other hand, if all the values for a different property differ, their sum is equal to 3 = 0+1+2.
    The following code flattens the list of three cards passed as parameters, and compute the sum of the values corresponding to the same property.
    Finally, it computes the modulo 3 of the sum, and returns True if, for all the properties, the sum modulo 3 is equal to zero.
    False otherwise """
    card_trio_flat = sum(card_trio,[])
    return (sum([sum(card_trio_flat[i::len(card_trio[0])]) % 3 for i in range(len(card_trio[0]))]) == 0)

def existing_sets(card_list):
    """ Returns a list containing all the existing sets (3-tuples of cards) in the list of cards passed as parameter. """
    return [trio for trio in itertools.combinations(card_list,3) if is_set(trio)]

def exists_set_v1(card_list):
    """ Return True if there exist at least one set in card_list, False otherwise. Inefficient version, computes all the existing sets and verify whether this list is empty or not """
    return len(existing_sets(card_list)) > 0

def exists_set_v2(card_list):
    """ Return True if there exist at least one set in card_list, False otherwise. More efficient version, using itertools combination function. """
    # With more than 21 cards in the card_list, the existence of a set has been theoretically proven.
    if len(card_list) >= 21:
        return True

    trios=itertools.combinations(card_list,3)
    for trio in trios:
        if is_set(list(trio)):
            return True                                              
    return False

def exists_set(card_list):
    """ Return True if there exist at least one set in card_list, False otherwise. Most efficient version, with nested loops, stopping as soon as the first set is detected. """
    # With more than 21 cards in the card_list, the existence of a set has been theoretically proven.
    if len(card_list) >= 21:
        return True
    
    for i in range(len(card_list)-2):
        for j in range(i+1,len(card_list)-1):
            for k in range(j+1,len(card_list)):
                if is_set([card_list[i],card_list[j],card_list[k]]):
                    return True
    return False           


def case_I(board,deck,end_game):
    """ Implementation of the case I - Set absence declared/Set absence verified. Return the updated board and deck.  """

    # If the deck is not empty then the game can continue.
    # Draw three card from the deck and add them to the board
    if len(deck) > 0 :
        board.extend(deck[:3])
        deck = deck[3:]
        end_game = False;
    else:
        # Game ends due to the absence of set in the board and the simultaneous absence of cards in the deck
        end_game = True;

    return board,deck,end_game
 
def case_II(deck,graveyard):
    """ Implementation of the case II - Set absence declared/Set absence not verified. Returns the updated deck and graveyard.  """
    # If the player makes a wrong guess, pick 3 cards randomly from the graveyard and put them at the end of the deck.
    # If the graveyard is empty, do nothing.
    if len(graveyard) != 0: 
        for i in range(PENALTY_CARDS):
            card = random.choice(graveyard)
            deck.append(card)
            graveyard.remove(card)
            
    return deck,graveyard

def case_III(board,deck,graveyard,selected_cards):
    """ Implementation of the case III - Set selected/Set verified. Returns the updated board, deck and graveyard. 
    Preconditions: selected_cards is not None, is_set(selected_cards) == True """

    # Move the selected set from the board to the graveyard
    for card in selected_cards:
        graveyard.append(card)
        board.remove(card)
        
    # Drawing three card from the top of deck and adding them to the board
    if(len(deck) > 0):
        board.extend(deck[:CARDS_TO_DRAW])
        deck = deck[CARDS_TO_DRAW:]

    return board,deck,graveyard

def case_IV():
    """ Implementation of the case IV - Set selected/Set not verified. Return None.  """
    print("\nL'ensemble des cartes selectionnés ne forme pas un set. Reessayer, svp.")
    return None

def print_stats(deck,board,graveyard):
    """ Print statistics about the the state of the game. """ 
    print("")
    print("Deck: " +str(len(deck)) + " cartes")
    print("Board: " +str(len(board)) + " cartes")
    print("Graveyard: " +str(len(graveyard)) + " cartes")
    print("")

def print_final_message(deck,board,graveyard,msg,time):
    os.system('cls' if os.name == 'nt' else 'clear')
    print_logo()
    print(msg)
    print_stats(deck,board,graveyard)
    print("Temps du jeu: " +str(time) + " s\n")




