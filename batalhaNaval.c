#include <stdio.h>

int main() {

    // declarando e iniciando a matrz do tabuleiro.
    int tabuleiro [10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
        
    }
    
    // definido variaveis de coodernadas
    int xnavio1 = 7;
    int ynavio1 = 2;

    int xnavio2 = 7;
    int ynavio2 = 7;

    // logica de sobreposicao e overflow.
    if(xnavio1 <= 7 && xnavio1 >= 0) {
        if(ynavio1 <= 9 && ynavio1 >= 0) {
            int x = xnavio1, y = ynavio1;

            for (int i = 0; i < 3; i++) {
                tabuleiro[y][x] = 3;
                x++;
            }
        }
    }

    if(ynavio2 <= 7 && ynavio2 >= 0) {
        if(xnavio2 <= 9 && xnavio2 >= 0) {
            if((xnavio1 > xnavio2 || (xnavio1 + 2) < xnavio2) || (ynavio2 > ynavio1 || ynavio2 + 2 < ynavio1)) {
                int x = xnavio2, y = ynavio2;

                for (int i = 0; i < 3; i++) {
                    tabuleiro[y][x] = 3;
                    y++;
                }

            } 
        }

    }

    // Exibindo tabuleiro processado.
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
        
    }
    

    return 0;
}
