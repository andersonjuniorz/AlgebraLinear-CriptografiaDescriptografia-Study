/*
* Esta classe dita o que acontece em cada metodo de criptografia
*/

#include <stdio.h>
#include <stdlib.h>

#include "../header/cd_common.h"

/* Definindo as tabelas constantes */
const char tabelaLetra[7][4] = {
    {'A', 'H', 'O', 'V'},
    {'B', 'I', 'P', 'W'},
    {'C', 'J', 'Q', 'X'},
    {'D', 'K', 'R', 'Y'},
    {'E', 'L', 'S', 'Z'},
    {'F', 'M', 'T', '*'},
    {'G', 'N', 'U', ' '}
};


const int tabelaNumero[7][4] = {
    {1, 8, 15, 22},
    {2, 9, 16, 23},
    {3, 10, 17, 24},
    {4, 11, 18, 25},
    {5, 12, 19, 26},
    {6, 13, 20, 0},
    {7, 14, 21, 999}
};

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* printar matrizes inteiras em formato de matriz */
void PrintarMatrizInt(char nomeMatriz[12], int linha, int coluna, int matriz[linha][coluna]){
	int i; //Linha
	int j; //Coluna

    printf("%s = \n", nomeMatriz);

    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf(" |  %d  | ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("          [%d]x[%d]\n\n", linha, coluna);
}

/* printar matrizes inteiras em linha */
void PrintarMatrizIntLinha(char nomeMatriz[12], int linha, int coluna, int matriz[linha][coluna]){
    int i; //Linha
    int j; //Coluna

    printf("%s = \n", nomeMatriz);

    for(j = 0; j < coluna; j++){
        for(i = 0; i < linha; i++){
            printf(" %d ", matriz[i][j]);
        }
    }
    printf("\n\n");
}

/* printar matrizes inteiras em linha */
void PrintarMatrizCharLinha(char nomeMatriz[12], int linha, int coluna, char matriz[linha][coluna]){
    int i; //Linha
    int j; //Coluna

    printf("%s = \n", nomeMatriz);

    for(j = 0; j < coluna; j++){
        for(i = 0; i < linha; i++){
            printf(" %c ", matriz[i][j]);
        }
    }
    printf("\n\n");
}

/* printar matrizes inteiras do tipo char em formato de matriz */
void PrintarMatrizChar(char nomeMatriz[12], int linha, int coluna, char matriz[linha][coluna]){
	int i; //Linha
	int j; //Coluna

	printf("%s = \n", nomeMatriz);

	for(i = 0; i < linha ; i++){
		for(j = 0; j < coluna ; j++){
			printf(" |  %c  | ", matriz[i][j]);
		}
		printf("\n");
	}

	printf("          [%d]x[%d]\n\n",linha,coluna);
}

/* Inicializador de matrizes do tipo inteiro */
void InicializarMatrizInt(int linha, int coluna, int matriz[linha][coluna]){
	int i,j;

	for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            matriz[i][j] = 0;
        }
    }
}

/*
* Essa procedimento compara a tabela de letras com a matriz M do tipo char,
* caso ache a mesma letra nas 2 matrizes, ira pegar o numero que representa aquela letra
* e inserir na matriz M do tipo int
*/
void TrocandoLetraPorNumeros(int m[LINHAS][COLUNAS], char mChar[LINHAS][COLUNAS]) {
    int i, i2; // Linhas
    int j, j2; // Colunas

    // Acessando campos da tabela base - tabela de letras
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 7; i++) {
            // Acessando campos da nossa de palavras - m char
            for (j2 = 0; j2 < COLUNAS; j2++) {
                for (i2 = 0; i2 < LINHAS; i2++) {
                    // Caso ache a letra representativa, salve na tabela m do tipo int
                    // Alterando caracteres para maiusculos - evitando bugs
                    if (toupper(mChar[i2][j2]) == tabelaLetra[i][j]) {
                        m[i2][j2] = tabelaNumero[i][j];
                    }
                }
            }
        }
    }

    PrintarMatrizChar("Matriz Alfabeto:", 7, 4, tabelaLetra);
    PrintarMatrizInt("Matriz Alfabeto (N�meros):", 7, 4, tabelaNumero);
}
