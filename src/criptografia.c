/*
* Esta classe dita o que acontece em cada metodo de criptografia
*/

#include <stdio.h>
#include <stdlib.h>

#include "../header/criptografia.h"
#include "../header/cd_common.h"


/* Copiar vetor para matriz */
void CopiarVetorParaMatriz(int max, char palavra[max], char mChar[LINHAS][COLUNAS]){
	int i; //Linhas
	int j; //Colunas
	int tam = 0; //Tamanho da palavra informada


	for(j=0; j<COLUNAS; j++){ // Copiando String palavra para a matriz mChar
		for(i=0; i<LINHAS; i++){

			if(tam < max - 1){
				mChar[i][j] = palavra[tam++];

			}else{
				mChar[i][j] = ' ';
			}
		}
	}
}

/* Preenche a matriz de criptografia*/
void preencherMatrizCriptografia(int matriz[LINHAS][LINHAS]){
	int i, j;
	//Criando matriz com os valores
    int valores[LINHAS][LINHAS] = {
        {1, 0, 1},
        {1, 1, 1},
        {0, 2, -1}
    };

    //passando valores para a matriz
    for (i = 0; i < LINHAS; i++) {
        for ( j = 0; j < LINHAS; j++) {
            matriz[i][j] = valores[i][j];
        }
    }
}


void Criptografar(int m[LINHAS][COLUNAS], int mc[LINHAS][COLUNAS]){
    int i; //Contador de linhas
    int j, j2; //Contadores de colunas

	int c[LINHAS][LINHAS]; //matriz de criptografia

	preencherMatrizCriptografia(c); //Preenchendo matriz de criptografia

    // Multiplicacao das matrizes
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {

            for (j2 = 0; j2 < LINHAS; j2++) {
                mc[i][j] += c[i][j2] * m[j2][j];
            }
        }
    }
}
