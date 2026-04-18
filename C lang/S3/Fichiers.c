#include <stdio.h>

void SaisirTexte(char *nomfichier){
    FILE *f = fopen(nomfichier,"w");
    if (f == NULL){
        printf ("Invalable");
        return;
    }
   char str[20];
   const char Fin;
    while(fputs(str,f)!=Fin){
        scanf("%s",str);
      }  
       fputs(str,f);
    fclose(f);
     }
void afficherTexte(char *nomfichier){
     FILE *f = fopen(nomfichier,"r");
    if (f == NULL){
        printf ("Invalable");
        return;
    }
        char str[20];
     while(fgets(str,20,f)){
        printf("%s",str);
      }
        fclose(f);
}
void CopierEnMajuscules(char *source, char *Destination){
      FILE *f_Destination = fopen(Destination,"r");
      FILE *f_source = fopen(source,"w");
    if (f_Destination == NULL || f_source){
        printf ("Invalable");
        return;
    }
     char str[20];
    while(fgets(str,20,f_source)=EOF){
         fputs(str,f_Destination);
    }  

    fclose(f_Destination);
    fclose(f_source);
}
void analyserTexte(char *nomFichier, char *chaine){
     FILE *f = fopen(nomFichier,"r");
    if (f == NULL){
        printf ("Invalable");
        return;
    }
    int ligne = 0;
    int occ = 0;
    int x;
    while((x=fgetc(f)) != EOF){
        if(x == "\n");
        ligne ++;
        if(x == chaine){
        occ++;
       }
       printf("La nbr lignes est: %d \n",occ,x);
        printf("La nbr d'occ de x est: %d \n",occ,x);
    }
}
int main(){
    char Tab[50];
    afficherTexte("nomfichier.txt");
    CopierEnMajuscules("source.txt","Destination.txt");
    analyserTexte("nomfichier.txt","chaine.txt");
return 0;
}
typedef struct{
    int code;
    char Dest[50];
    float poids;
}Colis;

    void saisirColis(Colis c){
        printf("le code est: %d | La destination est: %s | Le poids est: %f",c.code,c.Dest,c.poids);
    }
    void afficherColis(Colis *c){
        scanf("%d %s %f",&c->code,c->Dest,&c->poids);
    }
    void creerFichierColis(const char *nomFichier){
        File *f = fopen(nomfichier,"wb");
        if(f == NULL){
            printf("Invalable");
            return;
        }
        Colis c;
        fputs(c,f);
        fclose(f);
    }
    void afficherColis(const char *nomFichier){
        File *f = fopen(nomfichier,"rb");
        if(f == NULL){
            printf("Invalable");
            return;
        }
        Colis c;
        fgets(c,f);
        fclose(f);
    }
    int rechercherColis(const char *nomfichier, int coderecherche){
          File *f = fopen(nomfichier,"wb");
        if(f == NULL){
            printf("Invalable");
            return;
        }
        Colis c;
        printf("saisir code de recherche:");
        scanf("%d",&c.coderecherche);
        for(i = 0 ; i < codeRecherc ; i ++){
            if(c.code==c.coderecherche);
                return 1;
        }
            else{
                return 0;
            }
        fclose(f);
    }
    void modifierColis(const char *nomfichier, Colis *nouvelColis, int coderecherche){
            File *f = fopen(nomfichier,"wb");
        if(f == NULL){
            printf("Invalable");
            return;
        }
        Colis c;
        printf("saisir code de recherche:");
        scanf("%d",&c.coderecherche);
       for(i = 0 ; i < 3 ; i++){ 
            if(c.codeRecherche == c.code){
            fputs(nouvelColis,f);
            
            }
        }
        fclose(f);
    }