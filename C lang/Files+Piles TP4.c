#include <stdio.h>
#include <stdlib.h>
/* =========================
   STRUCTURE DE BASE : MAILLON
   ========================= */
typedef struct Maillon {
    int val;                    // valeur stockée
    struct Maillon* suivant;   // pointeur vers le prochain élément
} Maillon;
/* =========================
   DEFINITIONS SIMPLIFIEES
   ========================= */
typedef Maillon* Pile;   // une pile = pointeur vers le sommet
typedef struct {
    Maillon* tete;   // début de la file
    Maillon* queue;  // fin de la file
} File;
/* =========================
   PILE
   ========================= */

// initialiser la pile (vide)
void initPile(Pile* p) {
    *p = NULL;  // aucune valeur => pile vide
}
// tester si pile vide
int estVidePile(Pile p) {
    return p == NULL;  // si pointeur NULL => vide
}
// empiler (ajouter en haut)
void empiler(Pile* p, int x) {
    Maillon* m = (Maillon*)malloc(sizeof(Maillon)); // créer un nouveau maillon
    m->val = x;        // mettre la valeur
    m->suivant = *p;   // le nouveau pointe vers l'ancien sommet
    *p = m;            // le sommet devient ce nouveau maillon
}
// dépiler (retirer du haut)
int depiler(Pile* p) {
    if (*p == NULL) {
        printf("Pile vide\n");
        return -1;
    }
    Maillon* tmp = *p;       // garder le sommet
    int val = tmp->val;     // récupérer la valeur
    *p = tmp->suivant;      // avancer le sommet
    free(tmp);              // libérer mémoire
    return val;             // retourner valeur
}
/* =========================
   FILE
   ========================= */
// initialiser file
void initFile(File* f) {
    f->tete = NULL;
    f->queue = NULL;
}
// tester si vide
int estVideFile(File* f) {
    return f->tete == NULL;
}
// enfiler (ajouter à la fin)
void enfiler(File* f, int x) {
    Maillon* m = (Maillon*)malloc(sizeof(Maillon));
    m->val = x;
    m->suivant = NULL; // dernier élément => pas de suivant
    if (f->tete == NULL) {
        // si file vide, tete et queue pointent vers le même
        f->tete = f->queue = m;
    } else {
        f->queue->suivant = m; // l'ancien dernier pointe vers le nouveau
        f->queue = m;          // mettre à jour la queue
    }
}
// défiler (retirer du début)
int defiler(File* f) {
    if (f->tete == NULL) {
        printf("File vide\n");
        return -1;
    }
    Maillon* tmp = f->tete;  // garder la tête
    int val = tmp->val;
    f->tete = tmp->suivant;  // avancer la tête
    if (f->tete == NULL) {
        // si plus d'éléments => queue aussi NULL
        f->queue = NULL;
    }
    free(tmp);
    return val;
}
/* =========================
   EXERCICE 3
   PILE -> FILE
   ========================= */
File construireFilePile(Pile* p) {
    File f;
    initFile(&f);
    // on dépile tout et on enfile
    while (*p != NULL) {
        enfiler(&f, depiler(p));
    }
    return f; // pile détruite
}
/* =========================
   EXERCICE 4
   FILE -> PILE
   ========================= */
Pile construirePileFile(File* f) {
    Pile p;
    initPile(&p);
    // on défile tout et on empile
    while (f->tete != NULL) {
        empiler(&p, defiler(f));
    }
    return p; // file détruite
}
/* =========================
   EXERCICE 5
   INVERSER FILE
   ========================= */
void inverserFile(File* f) {
    Pile p;
    initPile(&p);
    // étape 1 : file -> pile
    while (f->tete != NULL) {
        empiler(&p, defiler(f));
    }
    // étape 2 : pile -> file
    while (p != NULL) {
        enfiler(f, depiler(&p));
    }
}
/* =========================
   EXERCICE 6
   SEPARER FILE
   ========================= */
void separerFile(File* f, File* FP, File* FN) {
    initFile(FP); // file des positifs
    initFile(FN); // file des négatifs
    while (f->tete != NULL) {
        int x = defiler(f);
        if (x >= 0)
            enfiler(FP, x); // positif
        else
            enfiler(FN, x); // négatif
    }
}
/* =========================
   FONCTIONS D'AFFICHAGE
   ========================= */

// afficher pile (du sommet vers bas)
void afficherPile(Pile p) {
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->suivant;
    }
    printf("\n");
}
// afficher file
void afficherFile(File* f) {
    Maillon* tmp = f->tete;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->suivant;
    }
    printf("\n");
}
/* =========================
   MAIN TEST
   ========================= */
int main() {
    Pile p;
    initPile(&p);
    // remplir pile
    empiler(&p, 3);
    empiler(&p, 7);
    empiler(&p, 13);
    empiler(&p, 39);
    printf("Pile initiale : ");
    afficherPile(p);
    // pile -> file
    File f = construireFilePile(&p);
    printf("File obtenue : ");
    afficherFile(&f);
    // inverser file
    inverserFile(&f);
    printf("File inversée : ");
    afficherFile(&f);
    // séparer
    File FP, FN;
    separerFile(&f, &FP, &FN);
    printf("Positifs : ");
    afficherFile(&FP);
    printf("Negatifs : ");
    afficherFile(&FN);
    return 0;
}