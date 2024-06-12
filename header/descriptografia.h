/*
* Esta classe dita quais metodos pertencem a classe de descriptografia
*/

#ifndef DESCRIPTOGRAFIA_H_INCLUDED
#define DESCRIPTOGRAFIA_H_INCLUDED

#include "../header/cd_common.h" //Obtendo as constantes compartilhadas

void UsuarioPreencheMatriz(int matriz[LINHAS][COLUNAS]);
void CalculaMatrizIdentidade(int matriz[LINHAS][LINHAS]);
void CalcularInversa(int inversa[LINHAS][LINHAS]);
void MultiplicarMatrizes(int m[LINHAS][COLUNAS], int inversa[LINHAS][LINHAS]);
void TrocandoNumerosPorLetras(char mChar[LINHAS][COLUNAS], int m[LINHAS][COLUNAS]);

#endif // DESCRIPTOGRAFIA_H_INCLUDED
