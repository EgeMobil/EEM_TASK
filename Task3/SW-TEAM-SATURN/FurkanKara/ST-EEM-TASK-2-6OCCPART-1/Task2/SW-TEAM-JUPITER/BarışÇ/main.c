#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int satir, sutun;
    int **matris;
    
    srand(time(NULL));
    

    printf("Matris satir sayisi: ");
    scanf("%d", &satir);
    printf("Matris sutun sayisi: ");
    scanf("%d", &sutun);
    
    matris = (int **)malloc(satir * sizeof(int *));

    for (int i = 0; i < satir; i++) {
        matris[i] = (int *)malloc(sutun * sizeof(int));
    }
    
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            matris[i][j] = rand() % 100 + 1;
        }
    }
    
    printf("\nOluşturulan %dx%d matris:\n", satir, sutun);
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            printf("%4d ", matris[i][j]);
        }
        printf("\n");
    }

}