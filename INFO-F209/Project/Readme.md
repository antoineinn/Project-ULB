# INFOF209-Projet d'année BA2.
Meat war: Rise of the fallen vegan

## A l'attention des Assistants
Afin de lancer notre projet, téléchargez le repo en tant qu'un zip (ou clone) et alors
lancer les exécutables.

## Compilation
Pour compiler notre projet finale([Phase 3](./Phase3/SRC)), il faut compiler séparemment le clien et le serveur.
* Compilation Client:

      Avant tout chose se rendre dans dans le dossier GUI contenu dans le dossier SRC de la Phase 3.
      qmake; make -j4 (-j4 pour compiler plus vite).
      Pour lancer l'exécutable client:
      ./client localhost si serveur lancé sur la même machine
      ./client <nom_du_pc_ou_se_trouve_le_serveur> 
      
* Compilation Serveur:
      
      Avant tout chose se rendre dans le dossier SRC de la Phase 3.
      make
      Pour lancer l'exécutable serveur:
      ./server
      
**Note**: Pour compiler la [Phase 2](./Phase2/SRC), juste faire un make dans le dossier SRC.

Aussi notre projet requiert les librairies/programmes suivants:

+ Qt version >=5
+ make
+ g++/gcc version >=5

## Structure:

Notre répertoire contient un dossier pour chaque phase du projet: 
* [Phase 1](./Phase1/)
* [Phase 2](./Phase2/)
* [Phase 3](./Phase3/) (phase finale)

Chaque phase de projet contient 3 sous-dossiers:
* SRC pour le code source, pour la Phase 3 il contient un sous-dossier GUI contenant le code de l'interface graphique.
* UML pour les fichiers source des différents diagrammes
* [SRD](./Phase3/SRD/SRD.pdf) pour le Software Requirements Document contenant un fichier pdf et le code source en latex ainsi que les différentes images contenue dans le SRD.
  
