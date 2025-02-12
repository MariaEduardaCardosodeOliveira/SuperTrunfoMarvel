#include "deck.h"
#include "arquivos.h"
#include "menu.h"
#include <stdio.h>

int main() {
    Deck deck;
    inicializar_deck(&deck);

    // Carregar dados do arquivo CSV ou binário
    carregar_deck_csv(&deck, "data/arquivo.csv");
    // carregarDeckDeBinario(&deck, "data/deck.bin");

    exibir_menu(&deck);

    // Salvar dados ao sair
    salvar_deck_binario(&deck, "data/deck.bin");
    liberar_deck(&deck);

    return 0;
}