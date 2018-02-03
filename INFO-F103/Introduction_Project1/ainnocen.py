#Antoine Innocent
#BA1 Informatique

class SortedList:
    """
    Classe représentant une liste tiree classique
    permettant de faire en sorte que la méthode d’insertion place
    directement l’élément au bon endroit dans la chaîne de références
    """
    def __init__(self):
        self.head= Node("H",None)

    def insert(self, value):
        """
        Insert un noeud dans la liste tout en gardant cette liste triée
        """

        add=Node(value,None)
        current=self.head
        while current.get_next()is not None:
            if value>=current.get_next().get_value() :

                # Verifie que la valeur du prochain element est plus petite que la valeur ajoutée

                current=current.get_next()

            else:
                add.set_next(current.get_next())
                current.set_next(add)
                break
            # Ajoute l'element a sa place et interrompt la boucle

        if current.get_next() is None:  # Cas ou l'element ajoute est le plus grand de la liste
            current.set_next(add)
            

    def remove(self, value):
        """
        Supprime un noeud dans la liste tout en gardant cette liste triée
        """

        previous= self.head
        current= self.head.get_next()
        found=False
        while current.get_value()<=value and not found:
            # Verifie que l'element recherché est superieur a l'element actuel

            if current.get_value() is value:    # Element trouve
                found=True

            else:
                previous=current # Passe a l'element suivant 
                current=current.get_next()

        if found:
            previous.set_next(current.get_next())   # Suppression de l'element
            
        else:
            return False

    def search(self, value):
        """
        Recherche la valeur donne en argument dans la liste triée
        """

        current= self.head.get_next()
        found=False

        if current!= None:
            while current.get_value()<=value and not found:

            # Verifie que l'element recherché est superieur a l'element actuel

                if current.get_value() is value: # Element trouve
                    found=True

                else:
                    current=current.get_next()  # Passage a l'element suivant

            if found:
                return current
            
    

    def __iter__(self):
        current = self.head.get_next()
        while current is not None:
            yield current.get_value()
            current = current.get_next()


class Node:
    """
    Classe noeud utilisee pour implementer une liste triée.
    
    Attributs:
      - _value: contient une valeur arbitraire mais requiert une relation d'ordre
      - _next: liste Python contenant les references vers d'autres noeuds.

    """

    def __init__(self, value, next):
        """
        Initialise le noeud
        """
        self.value=value
        self.next= next

    def get_next(self):
        return self.next

    def set_next(self, next):
        """
        Modifie la reference vers le prochain element
        """

        self.next=next
        

    def get_value(self):
        return self.value   

    def set_value(self, value):
        """
        Modifie la valeur de l'element
        """
        self.value=value
