/*
 * Desenvolvido por:
 *
 * Aluno: Anderson da Silva Nogueira Junior
 * Materia: Algebra Linear
 */

 /*
* Sugestoes para melhorar a seguranca do algoritmo de criptografia:
*
* 1. Aumentar o tamanho das matrizes e utilizar valores de chave mais complexos para dificultar ataques de forca bruta.
* 2. Garantir que as chaves de criptografia sejam geradas e armazenadas de forma segura.
* 3. Implementar um mecanismo de verificacao de integridade para detectar alteracoes nos dados criptografados.
* 4. Revisar e testar o codigo para prevenir vulnerabilidades de implementacao.
*/

/*
* Esta classe dita o que acontecera quando o projeto for iniciado
*/

#include <stdio.h>
#include <stdlib.h>

#include <locale.h> //Usando essa biblioteca de idiomas para Permitir acentuacoes
#include <ctype.h> //Usando essa biblioteca para converter characteres em maiusculos

//Interfaces
#include "../header/criptografia.h"
#include "../header/descriptografia.h"
#include "../header/cd_common.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;

	int m[LINHAS][COLUNAS]; //Matriz onde sera armazenada os numeros da palavra informada
	int mc[LINHAS][COLUNAS]; //Matriz resultante da multiplicacao entre m e c
	int inversa[LINHAS][LINHAS]; //Inversa da matriz c

	char palavra[MAX_PALAVRA]; //String informada
	char mChar[LINHAS][COLUNAS]; //Matriz onde sera armazenado a palavra informada


    do{
        limparTela();
        printf("+-------------------------------------+\n");
        printf("| 1 - CRIPTOGRAFAR UM NUMERO          |\n");
        printf("| 2 - DESCRIPTOGRAFAR UM NUMERO       |\n");
        printf("| 0 - SAIR                            |\n");
        printf("+-------------------------------------+\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        /* Inicializacao de matrizes */
        InicializarMatrizInt(LINHAS, COLUNAS, m); // insere valores 0 em toda a matriz inteira
        InicializarMatrizInt(LINHAS, COLUNAS, mc); // insere valores 0 em toda a matriz inteira
        InicializarMatrizInt(LINHAS, LINHAS, inversa); // insere valores 0 em toda a matriz inteira


        switch(opcao) {
            case 1:
                printf("Op��o 1 selecionada - Criptografar um n�mero\n\n");

                printf("Digite uma palavra de at� 6 caracteres: ");
                fgets(palavra, MAX_PALAVRA, stdin);
                fflush(stdin);

	            CopiarVetorParaMatriz(MAX_PALAVRA, palavra, mChar); //Copiando vetor para matriz M (char)
	            PrintarMatrizChar("\nM (char):", LINHAS, COLUNAS, mChar);

	            TrocandoLetraPorNumeros(m, mChar);
	            PrintarMatrizInt("M (int):", LINHAS, COLUNAS, m);

	            Criptografar(m, mc);
	            PrintarMatrizInt("MC - Matriz Criptografada (Formato Matriz):", LINHAS, COLUNAS, mc);
                PrintarMatrizIntLinha("MC - Matriz Criptografada (Formato String):", LINHAS, COLUNAS, mc);

                system("pause");
                break;

            case 2:
                printf("Op��o 2 selecionada - Descriptografar um n�mero\n\n");

                UsuarioPreencheMatriz(m);
                PrintarMatrizInt("Matriz Criptografada Informada:", LINHAS, COLUNAS, m);
                CalcularInversa(inversa);

                MultiplicarMatrizes(m, inversa);
                TrocandoNumerosPorLetras(mChar, m);

                PrintarMatrizChar("Matriz Resultante (Formato Matriz):", LINHAS, COLUNAS, mChar);
                PrintarMatrizCharLinha("Matriz Resultante (Formato String):", LINHAS, COLUNAS, mChar);

                system("pause");
                break;
            case 0:
                printf("Saindo...\n\n");
                break;

            default:
                printf("Op��o inv�lida. Tente novamente.\n\n");
                system("pause");
                break;
        }

    }while(opcao != 0);


	system("pause"); //Pausando finalizacao do programa
    return 0;
}
