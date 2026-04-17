#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char Des[40];
    int QA;
    float PU;
}Produit;
typedef struct Maillon{
    Produit p;
    struct Maillon* suivant;
}Maillon;
typedef Maillon* Liste;
    void initliste(Liste *L){ 
        *L = NULL;
    }
    Maillon* creerMaillon(Produit p){
        Maillon* m = (Maillon*) malloc(sizeof(Maillon));
        m -> p = p;
        m -> suivant = NULL;
    return m;
    }
    void insererDebut(Produit p, Liste *L){
        Maillon* m = creerMaillon(p);
        m -> suivant = *L;
        *L = m;
    }
    void insererfin(Produit p, Liste *L){
        Maillon *m = creerMaillon(p);
        
        if(*L == NULL){
            *L = m;
            return;
        }
        Maillon* temp = *L;
        while(temp -> suivant != NULL){
            temp = temp -> suivant;
        }
        temp -> suivant = m;
    }
    void insererOrdre(Produit p, Liste *L){
        Maillon *m = creerMaillon(p);
        if(*L == NULL || strcmp(p.Des,(*L)->p.Des)<0){
            m->suivant = *L;
            *L = m;
            return;
        }
        Maillon* temp = *L;
             while(temp -> suivant != NULL && strcmp(p.Des,temp->suivant->p.Des) > 0){
                temp = temp -> suivant;
            }
            m -> suivant = temp -> suivant;
            temp -> suivant = m;
        }
    void supprimerDebut(Liste *L){
        if(*L == NULL){
            return;
        }
        Maillon* temp = *L;// copier de l'adresse
        *L = (*L)->suivant;//L pointe Maintenant vers deuxieme maillon, car *L est le 1er maillon
        free(temp);// on se debarasse du premier maillon de la memoire, d'ou temp = *L valeur ancienne de L avant changement
    }
    
    void supprimerFin(Liste *L){
        if(*L == NULL){
            free(*L);
            *L = NULL;
            return;
        }
        Maillon* temp = *L;
        while(temp -> suivant -> suivant != NULL){//  tant qu'il y'a 2 maillons apres temp finit sur l'avant dernier
        temp = temp->suivant;
        } 
        free(temp -> suivant);
        temp -> suivant = NULL;
    }
     
    void supprimerProduit(Liste *L, char Des[30]){
        if(*L == NULL){
            return;
        }
        Maillon* temp = *L;
        Maillon* pred = NULL; //initialisation du pred avec NULL
        while(temp != NULL && strcmp(temp->p.Des,Des)!=0){//  tant que temp pointe vers le bon element temp->p.Des==Des(entree par l'utilisateur) D'ou le char Des.
            pred = temp; //[maillon juste avant] = pred garde l'ancienne valeur de temp, dans chaque iteration. Jusqu'a que la conditiom while est achevee
            temp = temp->suivant;
        } 
        if(temp == NULL){
            return;
        }
        if(pred == NULL){
            *L = temp->suivant;/*en veut supprimer le 1er maillon, d'ou il ny'a pas une ancienne valeur de temp(pred). Donc la tete(*L) va pointe vers le maillon suivant,
             qui peux etre: NULL si il ny'a pas de maillon apres temp d'ou *L=temp->suivant = NULL sinon la tete va pointe vers le maillon suivant*/
        }
        else{
            pred->suivant = temp->suivant;/* pred toute seul est juste un pointeur, si pred = temp->suivant; rien ne change seulement la valeur de pred qui etait NULL.
             Mais avec suivant ca change ou le maillon pointe. Dans notre cas c'est temp->suivant*/
        }
        free(temp);
    }
    void saisirListe(Produit *p){
        scanf("%s %d %f",p->Des,p->QA,p->PU);
    }
    void afficherListe(Produit *p){
   printf("Dest: %s | QA: %d | PU: %f",p->Des,p->QA,p->PU);
   }
   float MontantTotale(Liste *L){
    float Tot = 0;
        Maillon* temp = *L;
        while(temp != NULL){
        Tot = Tot + temp->p.QA * temp->p.PU;
        temp = temp -> suivant;
   }
   return Tot;
    }
    void produitMoinsCher(Liste *L){
        if(*L == NULL){
            return;
        }
        Maillon* min = *L;
        Maillon* temp = *L;
        while(temp != NULL){
         if(temp->p.PU < min->p.PU){
            min = temp;
         }
         temp = temp->suivant;
        }
    afficherListe(min->p);
    } 
   void libererListe(Liste *L){
    Maillon *temp;
    if(*L != NULL){
        temp = *L;
        *L = (*L)->suivant;
        free(temp);
    }
   }
   int main(){
    int N;
    Produit p;
    Liste L;
     printf("Nombre de produits : ");
        scanf("%d", &N);
      for(int i = 0 ; i <= N ; i++){
        saisirListe(&p);
        insererDebut(p,&L);  
        insererfin(p,&L);
        insererOrdre(p,&L);
        }
        MontantTotale(&L);
        produitMoinsCher(&L);
        
   return 1;
    }