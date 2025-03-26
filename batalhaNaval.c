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

    // definindo matrizes das habilidades
    int habilidades [3][4][5] = {
        {
            {0, 0, 1, 0, 0},
            {0, 1, 1, 1, 0},
            {1, 1, 1, 1, 1},
            {2, 0, 0, 0, 0}
        },
        {
            {0, 0, 1, 0, 0},
            {1, 1, 1, 1, 1},
            {0, 0, 1, 0, 0},
            {2, 1, 0, 0, 0}
        },
        {
            {0, 0, 1, 0, 0},
            {0, 1, 1, 1, 0},
            {0, 0, 1, 0, 0},
            {2, 1, 0, 0, 0}
        }

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

    // Logica de implementacao das habilidades
    int habilidade = 0; // 0 - cone; 1 - cruz; 2 - Octaedro;

    // posicão a parti da origen da habilidade.
    int xHab = 4;
    int yHab = 5;

    // Descobrir a posiçao da origem da habilidade.
    int origenX = habilidades[habilidade][3][0];
    int origenY = habilidades[habilidade][3][1];

    // Loops aninhados para percorrer a matriz habilidade 3 x 5.
    for (int i = yHab; i < yHab + 3; i++) {
        for (int j = xHab; j < xHab + 5; j++) {
            // Verificando se a posiçao no tabuleiro não esta fora de escopo.
            if((j - origenX >= 0 && j - origenX <= 9) && (i - origenY >= 0 && i - origenY <= 9)) {
                // Verificando se o valor da matriz habilidade é igual a 1. 
                if(habilidades[habilidade][i - yHab][j - xHab] == 1) {
                    // posicionado o valor 5 no tabuleiro.
                    tabuleiro[i - origenY][j - origenX] = 5;
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