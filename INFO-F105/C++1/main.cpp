#include <iostream>
#include "ES.hpp"


using namespace std;

int main()
{
    print_bienvenue();

    int compteurAr(0),compteur0(0),current(0),floor(0),ceil(0) ;
    float moyenneAr(0),moyenne0(0);



    while (current!=-1) {   // Tant que -1 n'est pas rentré par l'utilisateur
        current=ask_note();
        if (current!=-1){   // Pas prendre en compte le -1
            moyenneAr+=current;     // Somme les notes
            compteurAr+=1;

            if (current!=0){       // Ne pas prendre en compte les 0
                moyenne0+=current;
                compteur0+=1;

            }

        }

    }
    moyenneAr=moyenneAr/compteurAr;
    moyenne0=moyenne0/compteur0;

    if (int(moyenneAr)==float(moyenneAr)){  // Si la moyenne est une valeur entiere
        floor=moyenneAr;
        ceil=moyenneAr;}
    else{
        floor=int(moyenneAr);
        ceil=int(moyenneAr+1);


        }









    print_moyenne(moyenneAr);
    print_moyenneSansZero(moyenne0);
    print_plancher(floor);
    print_plafond(ceil);



    return 0;
}
