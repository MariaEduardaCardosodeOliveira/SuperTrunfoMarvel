/*
◦ Para gerenciar um Cartas de Cartass no estilo Super Trunfo, defina uma estrutura Cartas
contendo, no mínimo: nome (texto), uma letra(char), um número(int), um boleano para
saber se é a Cartas super trunfo (bool) e mais 4 atributos numéricos (int ou float). Deverá
permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) as Cartass disponíveis. Essa
relação deve aumentar e diminuir dinamicamente. Cada Cartas tem no mínimo 32 Cartass
com os códigos compostos por letras de A a D e números de 1 a 8 (ou mais caso
necessário).

◦ Deverá apresentar um menu inicial com as opções disponíveis. Caso necessário,
submenus. A interface deverá ser fácil e intuitiva, seja criativo, utilize cores e beeps :) .
Trate erros do usuário com mensagens e alertas;
*/

#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdbool.h>

// STRUCT DA TABELA
typedef struct{
    char nome[50];
    char letra[1];
    int numero;
    bool superTrunfo;
    float peso;
    int primeiraAparicao;
    int forca;
    int inteligencia;
}Cartas;

// Cartas
void realocarDeck(Cartas *deck, int valor);
int verificaExistenciaDeck(Cartas *deck, char *nome, int contadorCartas);
void listarDeck(Cartas *deck, int contadorCartas, int cond);
void apresentarDeck(Cartas *vetor, int tamanho);

// MENU
void beep();
void MensagemErro();
void exibeMenuPrincipal();
void exibeMenuCartas();
void chamaMenu(Cartas *vetor, int *contador);

#endif

