# Jeu d'échecs

**Auteur** : Bergamini enzo

---

## Conception du programme

### Les classes
* **Piece** : Classe abstraite qui représente une pièce du jeu d'échecs.
Elle posséde plusieur classe fille qui représente les différentes pièces
du jeu d'échecs. Le pion (Pawn), la tour (Rook), 
le cavalier (Knight), le fou (Bishop), la reine (Queen) et le roi (King).
    - **Pawn** : Classe qui représente le pion du jeu d'échecs.
    - **Rook** : Classe qui représente la tour du jeu d'échecs.
    - **Knight** : Classe qui représente le cavalier du jeu d'échecs.
    - **Bishop** : Classe qui représente le fou du jeu d'échecs.
    - **Queen** : Classe qui représente la reine du jeu d'échecs.
    - **King** : Classe qui représente le roi du jeu d'échecs.


* **Echiquier** : Classe qui représente l'échiquier du jeu d'échecs.
Elle posséde un tableau de 8x8 qui représente les cases de l'échiquier. 
Chaque case contient un pointeur vers une pièce ou un pointeur null 
si la case est vide.


* **Square** : Classe qui représente une case de l'échiquier. Et qui permet
une gestion plus facile des cases de l'échiquier. Notamment pour la gestion
des format des coordonnées.

* **Jeu** : Classe qui représente le jeu d'échecs. Elle posséde un échiquier 
et permet le déroulement du jeu.