# INFO-F-101 : Programmation
# Projet 2 : "Save private data"
# Antoine Innocent
# Matricule : 000394700

"""
This program is for encrypting or decrypting certain messages.
"""


import sys

#--------------------Fonctions for Encryption---------------

def Encrypt(message,substitution_key,permutation_key):
    return Permutation_Encrypt(Substitution_Encrypt(Padding_Encrypt(message,permutation_key),substitution_key),permutation_key)
    
    # Order for the fonction calling : Padding_Encrypt/Substitution_Encrypt/Permutation_Encrypt 
    # When calling Encrypt fonction , the encrypted message returns


def Padding_Encrypt(message,permutation_key):
    counter=1
    message=message+"@#"   # Adds "@#" at the end of the message
    while (len(message))%permutation_key!=0: # Until the message lengh is a mutiple of the Permutation key
         message=message+counter*"#"        # Adds a "#" until the condition is met 
    return message

    # Returns the "Padded" message 

def Substitution_Encrypt(message,substitution_key):
    message=list(message)          # Transforms the message to a list
    substitution=substitution_key
    new=[]                         # Create a empty list

    for car in message:
        if 65<=ord(car)<=90:                # In case the character is a capital letter
            if ord(car)+substitution>90:              # In case the new character is not a capital letter
                stock=chr(ord(car)+substitution-26)     # Rectification
            else:                                     
                stock=chr(ord(car)+substitution)
            new.append(stock)                       # Insert the new capital letter in the "new" list 

                
        elif 97<=ord(car)<=122:               # In case the character is a lowercase letter
            if ord(car)+substitution>122:            # In case the new character is not a lowercase
                stock=chr(ord(car)+substitution-26)    # Rectification
            else:
                stock=chr(ord(car)+substitution)
            new.append(stock)                # Insert the new lowercase letter at the end of the "new" list

         
        elif 48<=ord(car)<=57:              # In case the character is a number
            if ord(car)+substitution>57:           # Same method for the capitals and lowercase
               stock=chr(ord(car)+substitution-10)  # Rectification -10 (0,...,9)
           
            else:
                stock=chr(ord(car)+substitution)
            new.append(stock)     
         
        else:                                       # In case the character is not a capital,lowercase or number
            stock=car                               # Keep the same character
            new.append(stock)
            

    message= "".join(new)        # Transform the "new" list into a string
    return message

     # Returns the Subdued message

def Permutation_Encrypt(message,permutation_key):
     message=list(message)          # Transform the string to a list
     counter=0                     
     lst=[]                          # Create empty list
     for i in range(permutation_key):   
          lst.append(message[counter::permutation_key])

          # Create a list with the counter character and a step equal to the permutation key

          counter+=1

     singlelist=sum(lst,[])   # Sums the multiple lists to create a unique list        
     message="".join(singlelist)   # Transforms the resulting list into a string
     return message

       # Returns the Permutated message


#-------------------Fonctions for Decryption------------


def Decrypt(message,substitution_key,permutation_key):
    return Padding_Decrypt(Substitution_Decrypt(Permutation_Decrypt(message,permutation_key),substitution_key))

    # Order of calling: Permutation_Decrypt/Substitution_Decrypt/Padding_Decrypt
    # When calling the Decrypt fonction , the Decrypted message returns
    

def Permutation_Decrypt(message,permutation_key):

    # Same method for the Permutation_Encrypt with some exceptions
    
    message=list(message)
    counter=0
    lst=[]
    for i in range(len(message)//permutation_key):   # This calculation gives use the "number of blocks"
          lst.append(message[counter::(len(message)//permutation_key)]) # Step is the value of the "number of blocks"
          counter+=1

    singlelist=sum(lst,[])        
    message="".join(singlelist)
    return message

      # Returns the "depermutated" message
      
def Substitution_Decrypt(message,Substitution_key):

    # Same method for the Substitution_Encrypt with some exceptions
    
    message=list(message)
    substitution=Substitution_key
    new=[]
    for car in message:
        if 65<=ord(car)<=90:                # For capitals
            if ord(car)-substitution<65:
                stock=chr(ord(car)-substitution+26) # Substract the substitution Key  and rectifies
            else:
                stock=chr(ord(car)-substitution)
            new.append(stock)

                
        elif 97<=ord(car)<=122:               # For lowercases
            if ord(car)-substitution<97:
                stock=chr(ord(car)-substitution+26) # Substract the substitution key
            else:
                stock=chr(ord(car)-substitution)
            new.append(stock)    

         
        elif 48<=ord(car)<=57:              # For numbers
            if ord(car)-substitution<48:
               stock=chr(ord(car)-substitution+10) # Substract the substitution key
           
            else:
                stock=chr(ord(car)-substitution)
            new.append(stock)     
         
        else:        
            stock=car               # If not a capital,lowercase or number still keeps the character 
            new.append(stock)
            
    message= "".join(new)
    return message

   # Returns the "desubdued" message

def Padding_Decrypt(message):

    # Simply removes the "#" and "@" of the message
    
    message=message.strip("#")
    message=message.strip("@")
    return message

    # Returns the "depadded" message

#--------------------------Main Body------------------------


choice=sys.argv[1]                  # Choice of decryption or encryption
substitution_key=int(sys.argv[2])   # Choice of Substitution key
permutation_key=int(sys.argv[3])    # Choice of Permutation key
message="".join(sys.argv[4])        # Choice of Message to encrypt or decrypt

if choice=="e": # In case of encryption
    print("Message: ",message)
    print("Substitution Key: ",substitution_key)
    print("Permutation Key: ",permutation_key)   
    print("Encrypted ",Encrypt(message,substitution_key,permutation_key)) # Calls the Encrypt fonction

elif choice=="d": # In case of decryption

    print("Message: ",message)
    print("Substitution Key: ",substitution_key)
    print("Permutation Key: ",permutation_key)   
    print("Decrypted: ",Decrypt(message,substitution_key,permutation_key)) # Calls the Decrypt fonction
    
