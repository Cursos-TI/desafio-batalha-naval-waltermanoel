#include <stdio.h>

int main() {

    // declarando e iniciando a matriz do tabuleiro.
    int tabuleiro [10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
        
    }
    
    // definindo matriz com informaçoes dos navios, como coodernadas e direcao.
    int navios[4][3] = {
        {0, 0, 0},
        {2, 7, 1},
        {5, 7, 20},
        {3, 6, 21}
    };

    // logica de posicionamento dos navios.
    int xTemp = 0, yTemp = 0, movX = 0, movY = 0;

    for (int i = 0; i < 4; i++) {
        xTemp = navios[i][0];
        yTemp = navios[i][1];

        // Definindo a direcao do navio.

        switch (navios[i][2])
        {
        case 0:
            movX = 1;
            movY = 0;
            break;
        
        case 1:
            movX = 0;
            movY = 1;
            break;

        case 20:
            movX = 1;
            movY = 1;
            break;

        case 21:
            movX = 1;
            movY = -1;
            break;
        
        default:
            movX = 0;
            movY = 0;
            break;
        }

        if (movX == 0 && movY == 0) {
            continue;
        }
        
        // Verificar se existe overflow ou sobreposisao.
        int verificado = 0;
        for(int j = 0; j < 3; j++) {
            if (!((tabuleiro[yTemp][xTemp] == 0) && (xTemp >= 0 && xTemp <= 9) && (yTemp >= 0 && yTemp <= 9))) {
                verificado = 0;
                break;

            } else {
                verificado = 1;
                xTemp += movX;
                yTemp += movY;

            }
        }

        if (verificado) {
            // Inserindo no tabuleiro o navio.
            xTemp = navios[i][0];
            yTemp = navios[i][1];

            for (int j = 0; j < 3; j++) {

                tabuleiro[yTemp][xTemp] = 3;
                xTemp += movX;
                yTemp += movY;

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
