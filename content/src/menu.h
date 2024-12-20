/*
◦ Para gerenciar um Deck de cartas no estilo Super Trunfo, defina uma estrutura Carta
contendo, no mínimo: nome (texto), uma letra(char), um número(int), um boleano para
saber se é a carta super trunfo (bool) e mais 4 atributos numéricos (int ou float). Deverá
permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) as cartas disponíveis. Essa
relação deve aumentar e diminuir dinamicamente. Cada deck tem no mínimo 32 cartas
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
    /*
    char nome[50];
    char letra[1];
    int numero;
    bool superTrunfo;
    */
}Table;

// TABELA
void realocarTabela(Table *tabela, int valor);
int VerificaExistenciaTabela(Table *tabela, char *pais, int contadorTabela);
void listarTabela(Table *tabela, int contadorTabela, int cond, int paginaMax);
void apresentarTabela(Carta *vetor, int tamanho);

// MENU
void beep();
void MensagemErro();
void exibeMenuPrincipal();
void exibeMenuMedalhas();
void chamaMenu(Carta *vetor, int *contador);

#endif
