#Antoine Innocent
#BA1 Informatique

class Stack:
    def __init__(self):
        self.items = []
    
    def isEmpty(self):
        return self.items == []
    
    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        return self.items.pop()
    
    def top(self):
        return self.items[len(self.items)-1]
    
    def size(self):
        return len(self.items)



class Planning:

    """
    Classe principale Planning
    """

    def __init__(self,fichier):

        """
        Initie les variables de travaille
        """

        file=open(fichier)
        temp=file.readlines()
        self.time=[]

        i=0
        for line in temp:   #Avance ligne par ligne dans le fichier
            i+=1
            if i==1:
                self.n=int(line)
            elif i==2:
                self.m=int(line)
            elif i==3:
                self.deliveryTime=line.split()
            elif i>3:
                self.time.append(line.split())

        self.totalTime_prec=0
        self.parcours_prec=[]
        self.parcours_prec.append(2*self.n)
        
        self.parcours=[]
        self.actions_prec=[str(2*self.n)+" : "+self.heure(self.totalTime_prec)+",carrefour "]   # Commence au carrefour de depart
        self.actions=[]
        self.chargeornot=[False]*self.n
        self.count=0
        self.m_visite=[0]*self.m
        self.m_visite[(2*self.n)]=1     # Prendre en compte le point de depart
        self.n_visite=[False]*self.n
        self.totalTime=1000000000       # Represente l infini
        self.stock=Stack()
        self.stockkeep=Stack()  # Permet de garder les valeurs supprime du premier stack
        
        self.solve(2*self.n)
        
        self.printRes()
        

    
                        
    
    def voisin(self,i,j):
        """
        Fonction qui verifie si les elements sont voisin
        """
        return int(self.time[i][j])!=-1





    def client(self,elem):
        """
        Fonction qui verifie si l'element est un client
        """
        res=False
        if 0<=elem<self.n:
            res=True
        return res

    

    def chargement(self,elem,prec):

        """
        Fonction qui charge le camion(stock) et s'occupe de toutes les manipulations liee au chargement
        """

        self.stock.push(elem-self.n)         # met la marchandise du client dans le camion(stock)
        self.totalTime_prec+=int(self.time[prec][elem])
        self.totalTime_prec+=5
        self.chargeornot[elem-self.n]=True
        self.m_visite[elem]+=1
        self.parcours_prec.append(elem)
        self.actions_prec.append(str(elem)+" : "+self.heure(self.totalTime_prec-5)+", depot du client "+str(elem-self.n)+" fini chargement a "+self.heure(self.totalTime_prec))


    def annulechargement(self,elem,prec):

        """
        Fonction qui inverse les changements de la fontion chargement
        """

        self.actions_prec.pop()
        self.parcours_prec.pop()
        self.m_visite[elem]-=1
        self.chargeornot[elem-self.n]=False

        self.totalTime_prec-=5
        self.totalTime_prec-=int(self.time[prec][elem])
        if self.stock.isEmpty() is False:
            self.stock.pop()
        


    def dechargement(self,elem,prec):

        """
        Fonction qui decharge le camion(stock) et s'occupe de toutes les manipulations liee a la livraison
        """


        self.totalTime_prec+=int(self.time[prec][elem])
        self.totalTime_prec+=5          
        self.stockkeep.push(self.stock.pop())
        self.n_visite[elem]=True
        self.m_visite[elem]+=1
        self.parcours_prec.append(elem)
        self.actions_prec.append(str(elem)+" : "+self.heure(self.totalTime_prec-5)+",client "+str(elem)+" fini dechargement a "+self.heure(self.totalTime_prec))
       
        
    def annuledechargement(self,elem,prec):

        """
        Fonction qui annule toutes les manipulations de la la fonction llivraison
        """

        self.actions_prec.pop()
        self.parcours_prec.pop()
        self.m_visite[elem]-=1
        self.n_visite[elem]=False
        self.stock.push(self.stockkeep.pop())
        self.totalTime_prec-=5
        self.totalTime_prec-=int(self.time[prec][elem])
        

    def depot(self,elem):

        """
        Fonction qui verifie si l element est un depot
        """

        res=False
        if self.n<=elem<=2*self.n-1:
            res=True
        return res


    def passage(self,elem,prec):
        """
        Fonction qui s'occupe du passage simple du camion
        """
        
        self.totalTime_prec+=int(self.time[prec][elem])
        self.m_visite[elem]+=1
        self.parcours_prec.append(elem)

    def annulepassage(self,elem,prec):
        """
        Fonction qui annule le passage simple du camion
        """
        self.parcours_prec.pop()
        self.m_visite[elem]-=1
        self.totalTime_prec-=int(self.time[prec][elem])


    def carrefour(self,elem):
        """
        Fonction qui verifie si l element est un carrefour
        """
        res=False
        if elem>=2*self.n:
            res=True
        return res




    def heure(self,time):
        """
        Affichage de l'heure en format convenu (a partir de 8h)
        """
        

        minute=str(time%60)
        heure=str(8+(time//60))
        return heure+"h"+minute


    def printRes(self):

        """
        Fonction qui affiche les infos demandées
        """

        for info in self.actions:
            print(info)
        print("Temps Total: ", self.totalTime) 
        print("Nombres d'iterations: ",self.count)
        

    def solve(self,prec):
        """
        Fonction qui resoud le probleme donne en utilisant le principe de backtracking
        """


        self.count+=1
        
        if self.n_visite.count(True)==self.n or self.totalTime_prec >= self.totalTime:  # Si solution trouve et meilleur
            
            if self.totalTime>self.totalTime_prec:
                
                self.totalTime=self.totalTime_prec
                self.parcours=[]
                self.actions=[]

                for i in range(len(self.parcours_prec)):
                    self.parcours.append(self.parcours_prec[i])
                    self.actions.append(self.actions_prec[i])
             
        else:
            
            for lieu in range(self.m):
                if self.voisin(prec,lieu) and self.m_visite[lieu]<2:
                    
                    if self.client(lieu):  # Si c est un client
                    

                        if self.n_visite[lieu]: # Client non livre
                            
                            self.actions_prec.append(str(lieu)+" : "+self.heure(self.totalTime_prec)+",client "+str(lieu))
                            self.passage(lieu,prec)

                          

                            if self.totalTime>=self.totalTime_prec: # Si solution est meilleur(Branch and Bound)
                                self.solve(lieu)


                            self.annulepassage(lieu,prec)
                           
                            self.actions_prec.pop()

                        else:
                            if self.stock.isEmpty() is False:   #Verification des conditions pour livrer
                                if self.stock.top()==lieu:
                                    if self.totalTime_prec<=int(self.deliveryTime[lieu]):
                                        self.dechargement(lieu,prec)
                                
                        
                                        if self.totalTime>=self.totalTime_prec and self.totalTime_prec<=int(self.deliveryTime[lieu]):
                                            self.solve(lieu)

                                        self.annuledechargement(lieu,prec)
                            

                    elif self.depot(lieu):
                      
                        if self.chargeornot[lieu-self.n]==False and self.n_visite[lieu-self.n] is False:        # Si le client est non livre et le depot non charge
                            self.chargement(lieu,prec)
                            if self.totalTime>=self.totalTime_prec and self.totalTime_prec<=int(self.deliveryTime[lieu-self.n]):
                                    self.solve(lieu)

                            self.annulechargement(lieu,prec)


                        

                        self.passage(lieu,prec) # Cas ou on charge pas 
                        self.actions_prec.append(str(lieu)+" : "+self.heure(self.totalTime_prec)+",depot du client "+str(lieu-self.n))

                        if self.totalTime>=self.totalTime_prec and self.totalTime_prec<=int(self.deliveryTime[lieu-self.n]):
                                    self.solve(lieu)
                                    

      
                        self.actions_prec.pop() 
                        self.annulepassage(lieu,prec)

                                    
                    elif self.carrefour(lieu):
                       
                        self.passage(lieu,prec)
                        self.actions_prec.append(str(lieu)+" : "+self.heure(self.totalTime_prec)+",carrefour ")
                    
                        if self.totalTime>=self.totalTime_prec:
                            self.solve(lieu)

                        
                        self.actions_prec.pop()
                        self.annulepassage(lieu,prec)

    

    
        
