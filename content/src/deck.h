/*
Para gerenciar um Deck de cartas no estilo Super Trunfo, defina uma estrutura Carta
contendo, no mínimo: nome (texto), uma letra(char), um número(int), um boleano para
saber se é a carta super trunfo (bool) e mais 4 atributos numéricos (int ou float). Deverá
permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) as cartas disponíveis. Essa
relação deve aumentar e diminuir dinamicamente. Cada deck tem no mínimo 32 cartas
com os códigos compostos por letras de A a D e números de 1 a 8 (ou mais caso
necessário).
*/

#ifndef CARTA_H // Nao teria que ser DECK_H?
#define CARTA_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    char nome[50];
    char codigo[10];
    char letra[1];
    int numero;
    bool superTrunfo;
    char identidade[50];
    float peso;
    int primeiraAparicao;
    int forca;
    int inteligencia;
}Carta;

void inserir_cartas(Carta **cartas, int *numCartas);

void listar_cartas(Carta *cartas, int numCartas);

int pesquisar_cartas(Carta *cartas, int numCartas);

void alterar_carta(Carta *cartas, int quantidade_de_cartas);

void excluir_carta(Carta *cartas, int *numCartas);

#endif