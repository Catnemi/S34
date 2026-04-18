#include <stdio.h>
#include <stdlib.h>

/* ============================
   Définition du maillon
   ============================ */
typedef struct Maillon {
    char val;                 // valeur stockée dans la pile
    struct Maillon* suivant;  // pointeur vers le maillon suivant
} Maillon;

/* ============================
   Définition de la pile
   ============================ */
typedef Maillon* Pile; 
// 👉 Une pile est simplement un pointeur vers le sommet

/* ============================
   Initialiser la pile
   ============================ */
void initPile(Pile* p) {
    *p = NULL; // pile vide
}

/* ============================
   Tester si la pile est vide
   ============================ */
int estVidePile(Pile p) {
    return p == NULL; // 1 si vide, 0 sinon
}

/* ============================
   Récupérer le sommet
   ============================ */
int sommet(Pile p, char* val) {

    if (p == NULL) // si pile vide
        return 0;

    *val = p->val; // récupérer la valeur du sommet

    return 1;
}

void empiler(Pile* p, char val) {

    // création d’un m maillon
    Maillon* m = (Maillon*)malloc(sizeof(Maillon));

    m->val = val;        // affecter la valeur

    m->suivant = *p;     // pointer vers l'ancien sommet

    *p = m;              // le m devient le sommet
}
int depiler(Pile* p, char* val) {

    if (*p == NULL) // pile vide
        return 0;

    Maillon* tmp = *p; // sauvegarder le sommet

    *val = tmp->val;   // récupérer la valeur

    *p = tmp->suivant; // déplacer le sommet

    free(tmp);         // libérer mémoire

    return 1;
}

/* ============================
   Afficher la pile
   ============================ */
void afficherPile(Pile p) {

    Maillon* tmp = p; // commencer au sommet

    while (tmp != NULL) {
        printf("%c ", tmp->val); // afficher valeur
        tmp = tmp->suivant;  // aller au suivant
    }

    printf("\n");
}

/* ============================
   Programme principal
   ============================ */
int main() {

    Pile p;
    initPile(&p); // initialiser la pile

    int n;
    char val;

    printf("Nombre d'elements : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        printf("Entrer un caractere : ");
        scanf(" %c", &val); // espace avant %c pour éviter bug

        empiler(&p, val); // ajouter dans la pile
    }

    printf("Pile : ");
    afficherPile(p); // afficher la pile

    return 0;
}
// Partie 2
void binaire(int N) {

    Pile p;
    initPile(&p); // pile vide

    while (N != 0) {

        int reste = N % 2; // reste (0 ou 1)

        empiler(&p, reste + '0'); 
        // 👉 conversion en caractère

        N = N / 2; // division
    }

    afficherPile(p); // affichage dans le bon ordre
}
char convertirEntier(int N) {

    if (N < 10)
        return N + '0'; // 0-9
    else
        return N - 10 + 'A'; // A-F
}
void hexadecimal(int N) {

    Pile p;
    initPile(&p);

    char c;

    while (N != 0) {

        c = convertirEntier(N % 16); // conversion

        empiler(&p, c); // empiler

        N = N / 16; // division
    }

    afficherPile(p);
}
int main() {

    int N;

    printf("Entrer un entier : ");
    scanf("%d", &N);

    printf("Binaire : ");
    binaire(N);

    printf("Hexadecimal : ");
    hexadecimal(N);

    return 0;
}