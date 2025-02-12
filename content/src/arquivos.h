#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "deck.h"

void carregar_deck_csv(Deck *deck, const char *caminho_arquivo);

void salvar_deck_csv(Deck *deck, const char *caminho_arquivo);

void salvar_deck_binario(Deck *deck, const char *caminho_arquivo);

void carrega_deck_binario(Deck *deck, const char *caminho_arquivo);

#endif // ARQUIVOS_H