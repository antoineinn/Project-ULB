# INFO-F-101 : Programmation
# Projet 4 : Introduction a la sténographie
# Antoine Innocent
# Matricule : 000394700
# Message cache : This cake is a lie!

"""

This program is for encoding pgm images into others pgm image,
it can also decode hidden images

"""

import sys
def info_image(nom_image):

    """

    This function verifies the files expansion and returns
    a tuple composed of the name of the PGM file, the width, hight and
    the maximal value of the pixels of the file.

    """

    res="Error"
    file=open(nom_image)    
    if (nom_image.endswith(".pgm") or file.readline=="P2\n"):  # Verifies that the file is a pgm 
        stock=file.readlines(11)       # 11 to take in count the whole header
        elem=stock[1].strip("\n").split() # Splits the stock element to seperate the widht and hight
        res=((stock[0].strip("\n"),int(elem[0]),int(elem[1]),\
              int(stock[2].strip("\n"))))    

        # Creates the result tuple and changes the type of the widht and hight to integers
        # Removes all the "\n" caracters
        
    return res



def charger_image(nom_image):

    """

    Receives the name of the image for arguments
    Returns a height by lenght array of the pixels in the body of the image

    """
    
    file=open(nom_image)   
    array=[]
    stock=[]

    for i in range(3):  # Passes the first 3 lines of the file (header)
        file.readline()       

    for line in file:   # Splits every line into every single pixels and adds them to the stock list
        stock.append(line.split())
        
    for j in range (len(stock)): # Creates the lenght by width array 
        array.append([stock[j]])
        

    for i in range(len(array)):  # Change the type of every element to integers
        for j in range(len(array[i])):  
            for k in range(len(array[i][j])):
                        array[i][j][k]=int(array[i][j][k])
               
    return array



def encodage(source,code,res):

    """

    Receives the image source, the image to encode and the resulting image for argument
    This function as for only goal to encode the "encoding image" in the source image.

    """

    createfile=open(res,"w+") # Creates the file res 
    info=info_image(source)     # Stock the tuple of the heading of the source image
    source=charger_image(source)# Stock the array of the source image       
    code=charger_image(code)     
    reslist=[]

    for i in range(len(source)):
        for j in range(len(source[i])):
            for k in range(len(source[i][j])):

                    if code[i][j][k]==0:        # In case the element in the code array is 0
                        while source[i][j][k]%2!=0:    # the according element in source array 
                                    source[i][j][k]+=1

                    else:                           # The element in the code array is not 0
                        while source[i][j][k]%2==0: # The element in the source array is pair
                                source[i][j][k]+=1


                    if source[i][j][k]>info[1]:        # The case when the pixel limit is surpassed
                                source[i][j][k]-=2     


                    reslist.append(str(source[i][j][k])) # Adds the element in the reslist and transform into strings
                    reslist.append(" ") # Adds a space between every element
            reslist.append("\n") # Jump a line after a full line
                               
    reslist="".join(reslist) # Joins the reslist
    createfile=open(res,"w+") # Creates the file res 
    createfile.write(""+str(info[0])+"\n"+str(info[1])+" "+\
            str(info[2])+"\n"+str(info[3])+"\n"+reslist)   # Writes the header and the reslist

def decodage(crypt,claire):

    """

    This function takes for argument a file with an encoded image and the result image,
    the purpose is to write the encoded image in a separe file

    """

    info=info_image(crypt)      # Stock the crypt header
    crypt=charger_image(crypt)  # Stock the crypt array
    listclaire=[]
    for i in range(len(crypt)):
        for j in range(len(crypt[i])):
            for k in range(len(crypt[i][j])):

                if crypt[i][j][k]%2==0:  # In case the element in the crypt array is pair
                    crypt[i][j][k]=0    # Change element to 0
                
                else:                   # If element is impair
                    crypt[i][j][k]=1    # Change the element to 1
                    
                listclaire.append(str(crypt[i][j][k]))   # Adds the changed element to listclaire and transform into str
                listclaire.append(" ")      # Space between every element
                
            listclaire.append("\n")         # Full line jump a line
                       


    listclaire="".join(listclaire)  # Joins the listclare
    createfile=open(claire,"w+")

    createfile.write(""+str(info[0])+"\n"+str(info[1])+" "+\
             str(info[2])+"\n"+"1"+"\n"+listclaire)     # Write the header and the listclaire



def main():

    """

    Main function

    """

    choice=sys.argv[1]
    
    if choice=="codage":

        image1,image2,image3=sys.argv[2],sys.argv[3],sys.argv[4]

        a,b=info_image(image1),info_image(image2)  # Calls all the headers of the files

        if a and b =="Error":     # If a info_image returned an Error
            raise IOError("File error")
    
        encodage(image1,image2,image3)  # Calls the Encoding function

        print("File source : ",str(image1))
        print("File code : ",str(image2))
        print("Destination File : ",str(image3))
        print("Coding: done !")

    elif choice=="decodage":


        image1,image2=sys.argv[2],sys.argv[3]
        
        a=info_image(image1)       # Calls the info_image function for chosen files

        if (a or b or c) =="Error":
            raise IOError("File error")

        decodage(image1,image2)     # Calls the Decoding Function

        print("File with the message : ",str(image1))
        print("File with decoded message : ",str(image2))
        print("Decoding: done !")

    else:                                           
        raise TypeError("codage ou decodage")
        
            
main()                           


            
    
    
    



    
