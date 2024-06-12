/*
* Esta classe dita quais metodos pertencem a classe de criptografia
*/

#ifndef CRIPTOGRAFIA_H_INCLUDED
#define CRIPTOGRAFIA_H_INCLUDED

#include "../header/cd_common.h" //Obtendo as constantes compartilhadas

void CopiarVetorParaMatriz(int max, char palavra[max], char mChar[LINHAS][COLUNAS]);
void PreencherMatrizComAlfabeto(int linha, int coluna, char tabelaLetra[linha][coluna]);
void PreencherMatrizComNumeros(int linha, int coluna, int tabelaNumero[linha][coluna]);
void preencherMatrizCriptografia(int matriz[LINHAS][LINHAS]);
void Criptografar(int m[LINHAS][COLUNAS], int mc[LINHAS][COLUNAS]);


#endif // CRIPTOGRAFIA_H_INCLUDED
