#ifndef DECK_H 
#define DECK_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "carta.h"

typedef struct{
    Carta *cartas;
    int tamanho;
}Deck;

void inicializar_deck(Deck *deck);

void adicionar_carta(Deck *deck, Carta carta);

void remover_carta(Deck *deck, int indice);

void listar_cartas(Deck *deck);

Carta* pesquisar_carta_nome(Deck *deck, const char *nome);

Carta* pesquisar_carta_codigo(Deck *deck, const char *codigo);

void alterar_carta(Deck *deck, int indice, Carta novaCarta);

void liberar_deck(Deck *deck);

#endif