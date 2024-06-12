#ifndef CD_COMMON_H_INCLUDED
#define CD_COMMON_H_INCLUDED

/* Constantes */
#define MAX_PALAVRA 7 //tamanho maximo da nossa palavra vai ser 6, pois o ultimo e um espaço reservado
#define LINHAS 3
#define COLUNAS 2

extern const char tabelaLetra[7][4]; // Tabela de letras
extern const int tabelaNumero[7][4]; // Tabela de números

void limparTela();
void PrintarMatrizInt(char nomeMatriz[12], int linha, int coluna, int matriz[linha][coluna]);
void PrintarMatrizIntLinha(char nomeMatriz[12], int linha, int coluna, int matriz[linha][coluna]);
void PrintarMatrizChar(char nomeMatriz[12], int linha, int coluna, char matriz[linha][coluna]);
void InicializarMatrizInt(int linha, int coluna, int matriz[linha][coluna]);
void TrocandoLetraPorNumeros(int m[LINHAS][COLUNAS], char mChar[LINHAS][COLUNAS]);

#endif // CD_COMMON_H_INCLUDED
