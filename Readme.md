# Projeto de Criptografia e Descriptografia

## Descrição

Este projeto implementa um sistema de criptografia e descriptografia baseado em álgebra linear, utilizando a inversão de matrizes para garantir a segurança dos dados. Oferecendo uma abordagem prática e eficiente para a proteção de informações sensíveis, o sistema foi desenvolvido por Anderson Júnior como parte da Atividade Prática Supervisionada (APS) de Álgebra Linear do curso de Ciência da Computação do Centro Universitário Carioca (Unicarioca), sob a orientação do Professor Manuel Martins Filho.
<br>
<br>

## Objetivo
O objetivo deste projeto é desenvolver um sistema de criptografia e descriptografia que utilize princípios de álgebra linear, especificamente a inversão de matrizes, para assegurar a segurança e a confidencialidade de dados sensíveis. Além disso, o projeto visa proporcionar uma ferramenta prática e eficiente para a proteção de informações, destacando a aplicação de conceitos teóricos de álgebra linear em problemas reais de segurança da informação.
<br>
<br>
## Vídeo Demonstrativo (Youtube)

[![Assista ao vídeo](https://img.youtube.com/vi/e4qlTyym3oE/hqdefault.jpg)](https://www.youtube.com/watch?v=e4qlTyym3oE)<br>
### APS - Criptografia e Descriptografia usando inversão de matrizes

<br>
<br>

## ESTRUTURA DO PROJETO

APS_AL_Criptografia/
<pre>
├── bin/Debug            // Local onde fica o executável
│   └── projeto.exe      // Executável em si
├── header/              // Pasta dos arquivos de cabeçalho
│   ├── cd_common.h      // Métodos comuns para criptografia e descriptografia
│   ├── criptografia.h   // Arquivo de cabeçalho que declara os métodos de criptografia
│   └── descriptografia.h // Arquivo de cabeçalho que declara os métodos de descriptografia
├── src/                 // Src ou sources, Pasta do código-fonte
│   ├── cd_common.c      // Implementação dos métodos comuns de criptografia e descriptografia
│   ├── criptografia.c   // Implementação dos métodos de criptografia
│   ├── descriptografia.c // Implementação dos métodos de descriptografia
│   └── main.c           // Classe principal que dita como funcionará o executável
└── README.md            // Explicações importantes sobre o que é e como funciona o programa
</pre>

<br>

## IDE Utilizada

CODE BLOCKS<br>
VERSÃO: 20.03<br>
LINGUAGEM: C
<br>
<br>

## Sources e Headers
Os arquivos em src são os arquivos de código-fonte em C, enquanto os arquivos em header são os arquivos de cabeçalho que contêm declarações de funções, macros, constantes e tipos de dados utilizados em múltiplos arquivos de código-fonte.
<br>
<br>


## Interfaces (Headers .h)
Os arquivos de headers em C (com extensão .h) são usados para declarar funções, macros, constantes e tipos de dados que serão utilizados em múltiplos arquivos de código-fonte. Eles atuam como uma interface para o código que está implementado em arquivos .c. Em essência, eles permitem que diferentes partes de um programa C compartilhem informações de maneira organizada.
<br>
<br>

## Sources (.c)

#### common.c
Este arquivo descreve o comportamento dos métodos presentes nos módulos de criptografia e descriptografia. 
Como ambos possuem métodos sem alterações, achei mais prático criar essa classe que armazena apneas métodos presentes em ambas as classes. 
Isso permite reutilização de código e evita redundâncias.
<br>
<br>

#### criptografia.c
Enquanto o header criptografia.h dita quais métodos pertencem ao header de criptografia, 
criptografia.c descreve como os métodos de criptografia se comportam, como são escritos e o que acontece dentro deles.
<br>
<br>

#### descriptografia.c
Semelhante à criptografia.c, descriptografia.c define o comportamento dos métodos de descriptografia de acordo com o header descriptografia.h.

#### main.c
Este arquivo descreve o comportamento do programa quando é aberto.

