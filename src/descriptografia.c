#include <stdio.h>
#include <stdlib.h>

#include <locale.h> //Usando essa biblioteca de idiomas para Permitir acentuacoes
#include <ctype.h> //Usando essa biblioteca para converter characteres em maiusculos

#include "../header/descriptografia.h"
#include "../header/cd_common.h"
#include "../header/criptografia.h" //Reutilizando procedimento preencherMatrizCritografada


void UsuarioPreencheMatriz(int matriz[LINHAS][COLUNAS]){
    int contador = 1;
    int i, j;

    for(j= 0; j<COLUNAS; j++){
       for(i= 0; i<LINHAS; i++){
          printf("Digite o %dº numero: ", contador);
          scanf("%d", &matriz[i][j]);
          fflush(stdin);
          contador++;
       }
    }
    printf("\n\n");
}

void CalculaMatrizIdentidade(int id[LINHAS][LINHAS]){
    int i, j;

	//construindo a identidade
	for(i=0; i < LINHAS; i++){
		for(j=0; j < LINHAS; j++){
			if(i == j)
				id[i][j] = 1;
			else
				id[i][j] = 0;
		}
	}
}

void CalcularInversa(int inversa[LINHAS][LINHAS]) {
	int i, j, k = 0;

	int c[LINHAS][LINHAS]; //Matriz de criptografia
	int pivo = 0, p = 0, m = 0;

    preencherMatrizCriptografia(c);
    PrintarMatrizInt("Matriz Criptografia: ", LINHAS, LINHAS, c);
    CalculaMatrizIdentidade(inversa);

	//calculando a inversa
	for(j=0; j < LINHAS; j++){

		pivo = c[j][j];

		//p = pivo/pivo;
		for(k=0; k < LINHAS; k++){
			c[j][k] = c[j][k] / pivo;
			inversa[j][k] = inversa[j][k] / pivo;
		}

		for(i=0; i < LINHAS; i++){
			if(i != j){
				m = c[i][j];

				for(k=0; k < LINHAS; k++){
					c[i][k] = c[i][k] - (m * c[j][k]);
					inversa[i][k] = inversa[i][k] - (m * inversa[j][k]);
				}
			}
		}
	}

	//imprimindo a inversa
    PrintarMatrizInt("Matriz Criptografia (Inversa): ", LINHAS, LINHAS, inversa);
}

void MultiplicarMatrizes(int m[LINHAS][COLUNAS], int inversa[LINHAS][LINHAS]){
    int i, j, k;
    int M_temp[LINHAS][COLUNAS];

    InicializarMatrizInt(LINHAS, COLUNAS, M_temp);

    // Multiplica��o de matrizes
    for(i = 0; i < LINHAS; i++){ // Percorre as linhas da matriz inversa
        for(j = 0; j < COLUNAS; j++){ // Percorre as colunas da matriz m
            for(k = 0; k < LINHAS; k++){ // Percorre as colunas da matriz inversa/linhas da matriz m
                M_temp[i][j] += inversa[i][k] * m[k][j];
            }
        }
    }

        // Passa os valores da matriz temporaria para a matriz m
    for(i = 0; i < LINHAS; i++){ // Percorre as linhas da matriz inversa
        for(j = 0; j < COLUNAS; j++){ // Percorre as colunas da matriz m
            m[i][j] = M_temp[i][j] ;
        }
    }
}

void TrocandoNumerosPorLetras(char mChar[LINHAS][COLUNAS], int m[LINHAS][COLUNAS]){
    int i, i2; //Linhas
    int j, j2; //Colunas

    //Acessando campos da tabela base - tabela de numeros
    for(j = 0; j < 4; j++){
        for(i = 0; i < 7; i++){
            //Acessando campos da nossa de palavras - m
            for(j2 = 0; j2 < COLUNAS; j2++){
                for(i2 = 0; i2 < LINHAS; i2++){
                    //Caso ache o numero representativo, salve na matriz mChar
                    //Alterando characteres para maiusculos - evitando bugs
                    if(m[i2][j2] == tabelaNumero[i][j]){
                        mChar[i2][j2] = tabelaLetra[i][j]; // Atribui a letra correspondente
                    }
                }
            }
        }
    }
    PrintarMatrizChar("Matriz Alfabeto: ",7,4, tabelaLetra);
    PrintarMatrizInt("Matriz Alfabeto (Numeros): ",7,4, tabelaNumero);
}
