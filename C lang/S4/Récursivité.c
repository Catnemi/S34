#include <stdio.h>

float puissance(float x, int n) {
    // Cas de base
    if (n == 0)
        return 1;

    // Cas général
    if (n > 0)
        return x * puissance(x, n - 1);
    else
        return 1 / puissance(x, -n);
}
void afficher(int* T, int n) {
    // Cas de base
    if (n <= 0)
        return;

    // Cas général
    afficher(T, n - 1);
    printf("%d ", T[n - 1]);
}
void inverser(int* T, int n) {
    int temp;

    // Cas de base
    if (n <= 1)
        return;

    // Échanger premier et dernier
    temp = T[0];
    T[0] = T[n - 1];
    T[n - 1] = temp;

    // Appel récursif sur le sous-tableau
    inverser(T + 1, n - 2);
}
int maximum(int* T, int n) {
    int M;

    // Cas de base
    if (n == 0) {
        printf("Tableau vide !\n");
        return -1; // valeur indicative
    }

    if (n == 1)
        return T[0];

    // Cas général
    M = maximum(T, n - 1);

    if (T[n - 1] > M)
        return T[n - 1];
    else
        return M;
}
int main() {
    int T[] = {3, 8, 2, 7, 5};
    int n = 5;
    int max;

    printf("Tableau avant inversion : ");
    afficher(T, n);

    inverser(T, n);

    printf("\nTableau apres inversion : ");
    afficher(T, n);

    max = maximum(T, n);
    printf("\nMaximum du tableau : %d\n", max);

    // Test puissance
    printf("\nPuissance(2, 3) = %.2f\n", puissance(2, 3));
    printf("Puissance(2, -2) = %.2f\n", puissance(2, -2));

    return 0;
}