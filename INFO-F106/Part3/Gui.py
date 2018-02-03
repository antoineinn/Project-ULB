


import setFunctions as Body
from random import *
from tkinter import *
from Card import *



CARDWIDTH = 100
CARDHEIGHT = 150


class Gui(Frame):
    def __init__(self, master=None):

        Frame.__init__(self, master)
        self.master.title("SET")
        self.mycanvas = None
        self.menu = self.createMenuBar()
        self.field = self.createCardField()
        self.menu = self.createMenuPanel()
        self.pack(fill=BOTH, expand=True)
        self.deck, self.board, self.graveyard = self.initialise_decks()

        self.place_cards()


    def createMenuBar(self):

        menubar = Menu(self)
        menu1 = Menu(menubar, tearoff=0)
        menu1.add_command(label="New Game")
        menu1.add_separator()
        menu1.add_command(label="Quitter", command=quit)
        menubar.add_cascade(label="Fichier", menu=menu1)

        self.master.config(menu=menubar)

    def place_cards(self):

        ax, ax2 = 10, 10
        ay, ay2 = 10, 10

        cardwidth, cardwidth2 = 100, 100
        cardheight, cardheight2 = 150, 150
        self.identifier=0
        for i in range(len(self.board)):
            for cards in self.board[i]:

                self.identifier+=1
                a=Card(cards[0], cards[1], cards[2], cards[3], ax, ay, cardwidth, cardheight, self.mycanvas,str(self.identifier),cards)
                a.create_card()
                ax += 125
                cardwidth += 125
            ax= ax2
            ay= 20 + cardheight
            cardwidth= cardwidth2
            cardheight += 20 + cardheight2

    def createCardField(self):

        frame = Frame(borderwidth=2, relief=GROOVE, bd=15)
        self.mycanvas = Canvas(frame, height=500, width=360, bg="white")

        self.mycanvas.pack(expand=TRUE)
        frame.pack(side=LEFT, padx=30, pady=30, expand=TRUE)

    def createMenuPanel(self):

        frame2 = Frame()

        button = Button(frame2, text="New Game")
        button2 = Button(frame2, text="No Set")

        button.pack(side=TOP, expand=TRUE)
        button2.pack(side=BOTTOM, pady=10, expand=TRUE)

        frame2.pack(padx=10, pady=250, expand=TRUE)

        frame3 = Frame()

        label = Label(frame3, text="Cards in deck: ")
        label.pack(side=LEFT, pady=15, expand=TRUE)
        frame3.pack(side=BOTTOM, padx=50, expand=TRUE)

    def initialise_decks(self):

        colors = {0: "red", 1: "blue", 2: "green"}
        elements = {0: 1, 1: 2, 2: 3}
        symbols = {0: 1, 1: 2, 2: 3}
        fillings = {0: "P", 1: "L", 2: "V"}

        deck, board, graveyard = [], [], []
        temp = []

        for i in elements.values():  # Saves all the possible combinations of elements,symbols,fillings and colors in deck list
            for j in symbols.values():
                for k in fillings.values():
                    for l in colors.values():
                        deck.append([i, j, k, l])

        shuffle(deck)

        for i in range(4):  # Creates an array 4*3 for the board
            for j in range(3):
                temp.append(deck.pop(i))
            board.append(temp)
            temp = []

        return (deck, board, graveyard)







app = Gui()

app.mainloop()
