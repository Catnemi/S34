#include <stdio.h>

typedef struct{
    int CNE;
    char Nom[30];
    float note;
}Etudiant;

typedef struct Maillon{
    Etudiant e;
    struct Maillon* suivant;
}Maillon;

typedef Maillon* Liste;

  void SaisirEtudiant(Etudiant e){
    scanf("%d %s %f",&e.CNE,e.Nom,&e.note);
  }
    void AfficherEtudiant(Etudiant e){
    printf("CNE:%d | Note:%s | note:%f",e.CNE,e.Nom,e.note);
  }
   void initListe(Liste *L){
     *L = NULL;
  }
  Maillon* creerMaillon(Etudiant e){
    Maillon* m = (Maillon*)malloc(sizeof(Maillon));
    m -> e = e;
    m -> suivant = NULL;
    return m;
  }
  void ajouterDebut(Etudiant e,Liste *L){
    Maillon* m = creerMaillon(e);
     m -> suivant = *L;
    *L = m; 
  }
  void ajouterfin(Etudiant e,Liste *L){
    Maillon* m = creerMaillon(e);
    if(*L == NULL){
        return;
    }
    Maillon* temp = *L ;
    while(temp -> suivant != NULL){
        temp = temp->suivant; // Parcourir la liste
    }
    temp->suivant = m; // poser le maillon a la fin de la liste
 }
 void afficherListeEtudiants(Liste *L){
    Maillon* temp = *L;
    while(temp != NULL){
    printf("La liste des etudiants %s", temp->e.Nom);
    temp = temp->suivant;
    }
 }
 int compterEtudiant(Liste *L){
    Maillon* temp = *L;
    int Count = 0;
    while(temp != NULL){
        if(temp->e.Nom >= 10){
        Count++;
       }
    }
    return Count;
 }
 float moyennePromotion(Liste L){
    Maillon* temp = L;
     
    int n = 0;
    float Somme = 0;
    while(temp != NULL){
     Somme = Somme + temp->e.note;
          n++;
        temp = temp->suivant;
    }
    return Somme/n;
 }
 void supprimerDebut(Liste *L){
    if(*L == NULL){
        return;
    }
    Maillon* temp = *L;
     temp = temp -> suivant;
    free(temp);
    
 }
 void supprimerFin(Liste *L){
    if(*L == NULL){
        return;
    }
    if((*L)->suivant == NULL){
        free(*L);
        *L = NULL;
        return;
    }
    Maillon* temp = *L;
    while(temp->suivant->suivant != NULL){
    temp = temp->suivant;
    } 
    free(temp->suivant);
    temp->suivant = NULL;
 }
 void supprimerEtudiant(Liste *L, int CNE){
     if(*L == NULL){
        return;
    }
    Maillon* temp = *L;
    Maillon* pred = NULL;
    while(temp != NULL && temp->e.CNE == CNE){
        pred = temp;
        temp = temp->suivant;
    }
    if(pred ==  NULL){
        *L = temp->suivant;
    }
    else{
        pred->suivant = temp->suivant;
    }
    free(temp);
 }