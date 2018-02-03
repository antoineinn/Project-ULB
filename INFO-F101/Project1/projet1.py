# INFO-F-101 : Programmation
# Projet 1   : "Le bonneteau"
# Antoine Innocent
# Groupe 2


"""
Simulator of the game "Three Card Monte".
"""


from random import choice #Import "choice" from "random" module



print("Welcolme to this game of 'Three Card Monte'! And may the ods\
 be in your favor...") 
print()
print ("If not told otherwise, answer all the current questions with either an interger or a float.")
print()


stop=0 # Stop the game 
money_initial = float(input("How much money do you have? ", )) 
money=money_initial 


if money_initial<=0: #In case the player inserts an invalid balance.
  print()
  print("You are not that poor !")
  print()
  money_initial = float(input("How much money do you have? ", ))
  money=money_initial


while money>0 and stop!=-1: #stop , in order to end the loop.
  cup_winner = choice("LMR")

  #Chooses randomly the winning cup (L,M or R) 

  print()
  print("You have ",money,"$")
  print()
  bet=float(input("How much money are you willing to bet? (-1) to leave: ", ))
  

  if bet>money or bet<0 and bet!=-1 : #In case the bet is negative (can be 0 to test) or higher than the balance of the player. 
    print()
    print("Your bet is not valid ! Do not bet more than you have, or negative.")
    print()
    bet=float(input("How much money are you willing to bet? (-1) to leave: ", ))

    #ask a second time to bet

  if bet==-1: #Ends the loop in case of a -1
    stop=-1
    print()
    print("Well that was fun !")

    if money_initial>money: #Shows the balance of the player and the money lost or won.
      print()  
      print("You have a total of :",money, "$. Sadly, you lost\
 ",money_initial-money,"$...")

      #Calculates the difference between the initial amount and the current amount 

    else:
      print()    
      print("You have a total of :",money, "$.\
 You won",money-money_initial,"$ !")

     #Difference between the current amount and the initial amount

  else:                       
    print()
    cup_player=input("Which cup do you choose? (L for left, M for middle, \
R or right): ", )
          
    if cup_player!="L" and cup_player!="M" and cup_player!="R": #if the player doesn't insert the correct string
      print()
      print("Please choose L, M or R (in capital).")
      print() 
      cup_player=input("Which cup do you choose? (L for left, M for middle, \
R or right): ", )
      
    if cup_player==cup_winner: #If the chip is under the chosen cup
      money+=2*bet

      #Adds two times the bet amount to the player's balance

      print()
      print("Win ! Well done.")

    else:
      print()
      print("Nope ! Better luck next time.")
      money-=bet

      #Current money minus the bet amount
    
  if money==0: #If the player's balance is 0, the game ends.
    print()
    print("You have no more money.")
    print("Game over")
  print()
  print("* * * *") #separates every game.
 
print()


