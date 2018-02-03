# Antoine Innocent
# Projet 2 : Algorithmique

class Queue:
	"""
	Simple Queue class
	"""

	def __init__(self):
		self.items = []
	
	def head(self):
		return self.items[len(self.items)-1]
	
	def isEmpty(self):
		return self.items == []
	
	def insert(self, item):
		self.items.insert(0,item)
	
	def remove(self):
		return self.items.pop()
	
	def size(self):
		return len(self.items)
	


class Gare():
	def __init__(self,ville,voisin=None,distance=None):
		"""
		Gare object, Illustate a train station
		"""

		self.ville=ville
		
		self.voisin=voisin
		self.distance=distance

	def getvoisin(self):
		return self.voisin
	
	def getdistanceexact(self,other):
		
		"""
		Returns the distance from certain city to another
		"""
		
		res=None
		if type(self.getdistance()) is tuple:	# If their is more than one city in the tuple
			index=self.getvoisin().index(other.getville())
			
			res=int(self.getdistance()[index])
		else:
			res=self.getdistance()	# Only one city
		
		return res
	
	def getdistance(self):
		return self.distance
	def getville(self):
		return self.ville

	def setvoisin(self,voisin):
		self.voisin=voisin

	def setdistance(self,distance):
		self.distance=distance

	
class ReseauFerroviaire():
	def __init__(self,item,father=None) :	
		"""
		Represents the tree with a gare element for base
		"""

		self.ville=item
		self.child=None
		self.brother=None
		self.father=father
		self.niveaulist=[]
		
	
	def getrootval(self):
		return self.ville


	def setrootval(self,newitem):		
		self.ville=newitem
	

	def getchild(self):
		return self.child

	def setchild(self,newitem):

		self.child=ReseauFerroviaire(newitem,self) # Passes himself as father of new element
		return self.child
	

	def getfather(self):
		return self.father

	def getbrother(self):
		return self.brother

	def setbrother(self,newitem):	
		self.brother=ReseauFerroviaire(newitem,self.father) # Passes his father as father of new element
		return self.brother
	
	def getglobalroot(self):
		
		"""
		Finds the global root of the tree
		"""

		res=self
		if res!=None:
			while res.father!=None:	
				res=res.father
		return res

	
	def trouverParcours(self,destinations):
		"""
		Finds path from destinations to root of tree
		"""

		res=[]

		for i in range(len(destinations)):
			temp=[]
			if destinations[i]==self.getrootval().getville():	# Case where the destination is the root
				temp.append([destinations[i]])

			else:	
				
				ville=self.find(destinations[i])	# Find the destination element 
		
				
				if ville!=None:	# If element exists
					while ville.father!=None:
						temp.append(ville.getrootval().getville())	#Finds path to root
						ville=ville.father
					temp.append(ville.getrootval().getville())

				temp.reverse()	# Reverse the list to print in root order
			
			if len(destinations)==1:	# If only one destination
				
				res=temp

			else:
				res.append(temp)
		return res


	def GareAccessibles(self,ville):
		
		"""
		Find all accessible cities from a certain one
		"""

		res=self.niveau()
		if ville in res:
			res.remove(ville)
		return res


	def common_elements(self,list1, list2):
		"""
		Find common elements in two list
		"""
		return [element for element in list1 if element in list2]

		#Could use set() but the order is not saved
	
	def add_distance(self,list1):
		"""
		Sommes the distance of given cities in list
		"""

		add=0
		for j in range(len(list1)-1):
					
			add+=list1[j].getdistanceexact(list1[j+1])
		return add
	
	
	def trouverDistance(self,depart,destinations):
		"""
		Find distance between any given cities
		depart expects string , destinations expect list of string
		"""

		res=[]
		
		for i in range(len(destinations)):
			temp=[]
			counter=0
			add=0
			desttobase=self.trouverparcourselem([destinations[i]]) #Root to destination
			currtobase=self.trouverparcourselem([depart])	#Root to current

			try:
				similarelement=self.common_elements(desttobase,currtobase)	# Finds common element
			
				commonelement=similarelement[-1]	# Take the last similar element
				
			
			except:
				res=None	# No common element
				print("No common element")
			else:

			
				if depart==self.getrootval().getville() or destinations[i]==self.getrootval().getville(): #Case 1 and 2
					if depart==self.getrootval().getville(): #Case 1 : The starting city is the root of tree
					
						
						temp=desttobase
						res.append(self.add_distance(temp))

					elif destinations[i]==self.getrootval().getville() :	# Case2 the destination is the root
					
						temp=currtobase #A voir comme en haut
						res.append(self.add_distance(temp))


				elif commonelement.getville()==self.getrootval().getville():	#Case3 the common element is the root
					
						add=self.add_distance(currtobase)

						currtobase.reverse()
						temp=currtobase
						temp.extend(desttobase[1:])	#	Deletes the 2nd root to only have one
						
						add+=self.add_distance(desttobase[0:])	
						res.append(add)

				elif commonelement.getville()==destinations[i] or commonelement.getville()==depart: # Case 4 and 5
					
					if commonelement.getville()==destinations[i]: # Case4 the common city is the destination
					
						currtobase.reverse()
						temp=currtobase[0:currtobase.index(commonelement)+1]
						temp.reverse() # To get the distance from top to bottom of tree
						res.append(self.add_distance(temp))
					
					else:	# Case 5 the common city is the current city 
					
						desttobase.reverse()
						temp=desttobase[0:desttobase.index(commonelement)+1]
						temp.reverse() 
						res.append(self.add_distance(temp))

				else:	#Case 6 any other case
					
					currtobase.reverse()
					temp=currtobase[0:currtobase.index(commonelement)]# From current city to common city
					temp.reverse() 
					add=self.add_distance(temp)
					temp.extend(desttobase[desttobase.index(commonelement):]) # From common city to destination
					add+=self.add_distance(desttobase[desttobase.index(commonelement):])
					res.append(add)


	
		return res 
	

	def find(self,ville):
		"""
		Find city element by name
		"""

		f=Queue()
		f.insert(self.getglobalroot())
		while not f.isEmpty():
			n=f.remove()
			while n!=None:
				if n.getrootval().getville()== ville:
					return n
				else:	
					f.insert(n.getchild())
					n=n.getbrother()


	def trouverparcourselem(self,destinations):
		"""
		Find path to destination but gives the cities object and not the names
		"""

		res=[]


		for i in range(len(destinations)):
			

			temp=[]
			
			if destinations[i]==self.getrootval().getville():
				temp.append(self.getrootval())
				
			else:		
				
				ville=self.find(destinations[i])
		
				
				if ville!=None:
					while ville.father!=None:
						temp.append(ville.getrootval())
						ville=ville.father
					temp.append(ville.getrootval())

				temp.reverse()
			
			
			if len(destinations)==1:	
				
				res=temp
				
				
			else:
				res.append(temp)
		return res

	
	def niveau(self):
		"""
		Iterate in three by levels
		"""

		f=Queue()
		f.insert(self)
		while not f.isEmpty():
			n=f.remove()
			while n!=None:
				self.niveaulist.append(n.getrootval().getville())
				f.insert(n.getchild())
				n=n.getbrother()
		return self.niveaulist

	def __str__(self):
		return self.ville.getville()





def trouverParcoursMin(reseau,villeA,villeB):
	"""
	Finds the path between two cities in different or in same tree
	"""

	reseau1=reseau[0].niveau()
	reseau2=reseau[1].niveau()
	res=None
	
	if villeA in reseau1:
		if villeB in reseau2:	# Case1 :city in different tree
			common=list(set(reseau1)&set(reseau2))	#Find common city
			
			if len(common)!=0:
				distance1=reseau[0].trouverDistance(common[0],[villeA]) 	#Find distance between common and 1st city
				
				distance2=reseau[1].trouverDistance(common[0],[villeB])	#Find distance between common et 2nd city
			
				res=distance1[0]+distance2[0]
		
		if villeB in reseau1:	# Case2 : Same tree(n1)
			res=reseau[0].trouverDistance(villeA,[villeB])[0]

	elif villeA in reseau2:
		if villeB in reseau1:	#Case 3 : Different tree
			common=list(set(reseau1)&set(reseau2))
			if len(common)!=0:
				distance1=reseau[0].trouverDistance([common[0],villeB])
				distance2=reseau[1].trouverDistance([common[0],villeA])
				res=distance1[0]+distance2[0]
		if villeB in reseau2:	#Case4 : Same tree(n2)
			res=reseau[1].trouverDistance(villeA,[villeB])[0]
	return res 




bruxelles=ReseauFerroviaire(Gare("Bruxelles",("Liege","Lille"),(96,120)))
liege=bruxelles.setchild(Gare("Liege",("Spa","Namur"),(39,65)))
lille=liege.setbrother(Gare("Lille",("London","Paris"),(292,223)))

#Leftside
spa=liege.setchild(Gare("Spa"))
namur=spa.setbrother(Gare("Namur",("Charleroi","Arlon"),(50,128)))
charleroi=namur.setchild(Gare("Charleroi",("Mons"),(50)))
arlon=charleroi.setbrother(Gare("Arlon"))
mons=charleroi.setchild(Gare("Mons"))

#Rightside
london=lille.setchild(Gare("London"))
paris=london.setbrother(Gare("Paris",("Orleans","Lyon","Borges"),(129,465,245)))
orleans=paris.setchild(Gare("Orleans"))
borges=orleans.setbrother(Gare("Borges"))
lyon=borges.setbrother(Gare("Lyon",("Geneve","Milan"),(150,442)))
geneve=lyon.setchild(Gare("Geneve"))
milan=geneve.setbrother(Gare("Milan"))

#Reseau2
rome=ReseauFerroviaire(Gare("Rome",("Florence","Naples"),(278,225)))
florence=rome.setchild(Gare("Florence",("Pisa","Bologna"),(82,104)))
naples=florence.setbrother(Gare("Naples",("Bari","Messina"),(257,493)))

#Leftside
pisa=florence.setchild(Gare("Pisa"))
bologna=pisa.setbrother(Gare("Bologna",("Venice","Milan"),(145,222)))
venice=bologna.setchild(Gare("Venice",("Vicenza"),(75)))
milan=venice.setbrother(Gare("Milan"))
vicenza=venice.setchild(Gare("Vicenza"))


#Rightside
bari=naples.setchild(Gare("Bari"))
messina=bari.setbrother(Gare("Messina",("Catania","Palermo","Trapani"),(98,224,33)))
catania=messina.setchild(Gare("Catania"))
palermo=catania.setbrother(Gare("Palermo"))
trapani=palermo.setbrother(Gare("Trapani"))



