#include <stdio.h>
#include <stdlib.h>
typedef struct Maillon{
    int v;
    struct Maillon* suivant; 
}Maillon;

typedef Maillon* Pile;

  Pile Initpile(){
    return NULL;
  }
  int EstPilevide(Pile p){
    return (p == NULL);
  }
  void sommet(Pile p, int* x){
    if(EstPileVide(p) == 0){
      *x = p -> v; 
    }
  }
  void empiler(Pile* p, int x){
    Maillon* m = (Maillon*) malloc(sizeof(Maillon));
    if(m != NULL){
        m -> v = x;
        m->suivant = *p;
        *p = m;
    } 
}
void depiler(Pile* P){
    Maillon* m;
    if (EstPileVide(*P) == 0){
        m = *P;
        *P = (*P)->suivant;
        free(m);
    }
}
