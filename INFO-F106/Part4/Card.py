#Antoine Innocent
from tkinter import *
from setFunctions import *
from PlatformUtils import *

CARDWIDTH=100
CARDHEIGHT=150
selected_card=[]
stock_identifier=[]
class Card():

    def __init__(self,elements,symbols,fillings,colors,positionx,positiony,cardwidth,cardheight,mycanvas,identifier,cardall):
        self.color=colors
        self.element=elements
        self.symbol=symbols
        self.filling=fillings
        self.cardall=cardall
        LEFT,RIGHT=str(PlatformUtils2.getLeftButton()),str(PlatformUtils2.getRightButton())
        self.positionx=positionx 
        self.positiony=positiony
        self.CARDWIDTH=cardwidth
        self.CARDHEIGHT=cardheight
        self.mycanvas=mycanvas
        self.identifier=identifier
        self.mycanvas.create_rectangle(self.positionx, self.positiony,self.CARDWIDTH,self.CARDHEIGHT,outline='black', fill='white',activeoutline='#FF0000',tag="card"+self.identifier)
        self.mycanvas.tag_bind("card"+self.identifier,"<Button-"+LEFT+">",self.mouseClickLeft)
        self.mycanvas.tag_bind("card"+self.identifier,"<Button-"+RIGHT+">",self.mouseClickRight)

       

    def create_card(self):

        self.rectangleadd=0
        self.polyadd=0
        self.rectanglecorr=[30,20,-30,-100]

        for i in range(self.element):
            if self.symbol==1:
                if self.filling=="V": 
                    self.mycanvas.create_rectangle(self.positionx+30,self.positiony+20+self.rectangleadd,self.CARDWIDTH-30,self.CARDHEIGHT-100+self.rectangleadd,outline=self.color)

                elif self.filling=="P":
                    self.mycanvas.create_rectangle(self.positionx+30,self.positiony+20+self.rectangleadd,self.CARDWIDTH-30,self.CARDHEIGHT-100+self.rectangleadd,fill=self.color,outline=self.color)

                elif self.filling=="L":
                    self.mycanvas.create_rectangle(self.positionx+30,self.positiony+20+self.rectangleadd,self.CARDWIDTH-30,self.CARDHEIGHT-100+self.rectangleadd,fill=self.color,stipple="gray12")

            elif self.symbol==2:
                if self.filling=="V":
                    self.mycanvas.create_oval(self.positionx+30,self.positiony+20+self.rectangleadd,self.CARDWIDTH-30,self.CARDHEIGHT-100+self.rectangleadd,outline=self.color)
                elif self.filling=="P":
                     self.mycanvas.create_oval(self.positionx+30,self.positiony+20+self.rectangleadd,self.CARDWIDTH-30,self.CARDHEIGHT-100+self.rectangleadd,fill=self.color,outline=self.color)
                elif self.filling=="L":
                    self.mycanvas.create_oval(self.positionx+30,self.positiony+20+self.rectangleadd,self.CARDWIDTH-30,self.CARDHEIGHT-100+self.rectangleadd,fill=self.color)

            elif self.symbol==3:
                if self.filling=="V":
                    self.mycanvas.create_polygon(self.positionx+45,self.positiony+5+self.polyadd,self.positionx+65,self.positiony+25+self.polyadd,self.positionx+45,self.positiony+45+self.polyadd,self.positionx+25,self.positiony+25+self.polyadd,outline=self.color,fill="white")
                elif self.filling=="P":
                     self.mycanvas.create_polygon(self.positionx+45,self.positiony+5+self.polyadd,self.positionx+65,self.positiony+25+self.polyadd,self.positionx+45,self.positiony+45+self.polyadd,self.positionx+25,self.positiony+25+self.polyadd,fill=self.color,outline=self.color)
                elif self.filling=="L":
                    self.mycanvas.create_polygon(self.positionx+45,self.positiony+5+self.polyadd,self.positionx+65,self.positiony+25+self.polyadd,self.positionx+45,self.positiony+45+self.polyadd,self.positionx+25,self.positiony+25+self.polyadd,fill=self.color,outline=self.color,stipple="gray12")

            self.rectangleadd+=40
            self.polyadd+=45

    def mouseClickLeft(self,mouseevent):
        self.mycanvas.itemconfig("card"+self.identifier,outline="blue")
        self.add_set(mouseevent)



    def mouseClickRight(self,mouseevent):
        self.mycanvas.itemconfig("card"+self.identifier,outline="black")
        self.removecard(mouseevent)


    def removecard(self,mouseevent):
        selected_card.remove(self.cardall)


    def add_set(self,mouseevent):

        if self.cardall not in selected_card:
            selected_card.append(self.cardall)
            stock_identifier.append(self.identifier)

        
        if len(selected_card)==3:
            if askyesno("SET","Voulez vous confirmer le set? "):
                if is_set(selected_card):
                    showinfo("SET","It's a set!")


            else:
                selected_card.clear()
                for identifier in stock_identifier:
                    self.mycanvas.itemconfig("card"+identifier,outline="black")
                stock_identifier.clear()

       








        
