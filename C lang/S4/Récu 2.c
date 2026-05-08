#include <stdio.h>

    float puissance(int x, int n){
        if(n == 0){
            return 1;
        }
        return  x * puissance(x, n - 1);
    }

    int Max(int* T, int N){
        if(N == 0){
            printf("Tab vide");
            return -1;
        }
        if(N == 1){
            return T[0];
        }
        int max = Max(T, N - 1);
        if(T[N - 1] > max){
            return T[N - 1];
        }
        else{
            return max;
        }
    }
    int Inverser(int* T, int N){
        if(N == 0){
            printf("Tab vide");  
        }
        if(N == 1){
            return T[0];
        }
    int temp;
        temp = T[0];
        T[0] = T[N - 1];
        T[N - 1] = temp;
        Inverser(T + 1, N - 2);
    }
    void Afficher(int* T, int N){
        if(N == 0){
            return;
        }
        Afficher(T, N - 1);
        printf("Le tab: %d",T[N - 1]);
    }

int main(){
    int T[] = {2 , 3 , 4 , 5 , 6};
    int N = 5;

    printf("Le tab avant affichage:");
    Afficher(T , N);

    Inverser(T , N);
    
    printf("\nLe tab apres affichage:");
    Afficher(T , N);

    printf("\nLe max du tableau: %d\n", Max(T , N));
    
    printf("La puissance est:%.2f\n", puissance(2,3));
    printf("Puissance(2, -2) = %.2f\n", puissance(2, -2));
    return 0;
}