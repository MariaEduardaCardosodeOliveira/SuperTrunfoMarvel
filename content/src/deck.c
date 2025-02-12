#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializa o deck
void inicializar_deck(Deck *deck) {
    deck->cartas = NULL; // Inicializa o vetor de cartas como NULL
    deck->tamanho = 0;   // Inicializa o tamanho do deck como 0
}

// Adiciona uma carta ao deck
void adicionar_carta(Deck *deck, Carta carta) {
    // Aumenta o tamanho do deck
    deck->tamanho++;
    // Realoca memória para o novo tamanho
    deck->cartas = (Carta *)realloc(deck->cartas, deck->tamanho * sizeof(Carta));
    if (deck->cartas == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    // Adiciona a nova carta ao final do deck
    deck->cartas[deck->tamanho - 1] = carta;
}

void remover_carta(Deck *deck, int indice) {
    if (indice < 0 || indice >= deck->tamanho) {
        printf("Índice inválido.\n");
        return;
    }
    
    // Move as cartas subsequentes para preencher o espaço da carta removida
    for (int i = indice; i < deck->tamanho - 1; i++) {
        deck->cartas[i] = deck->cartas[i + 1];
    }

    // Reduz o tamanho do deck
    deck->tamanho--;

    // Realoca memória para o novo tamanho, se necessário
    if (deck->tamanho > 0) {
        deck->cartas = (Carta *)realloc(deck->cartas, deck->tamanho * sizeof(Carta));
        if (deck->cartas == NULL) {
            printf("Erro ao realocar memória.\n");
            exit(1); // Em caso de falha, podemos encerrar o programa ou retornar com erro
        }
    } else {
        // Se o deck ficou vazio, libera a memória
        free(deck->cartas);
        deck->cartas = NULL;
    }

    printf("Carta removida com sucesso.\n");
}


// Lista todas as cartas do deck
void listar_cartas(Deck *deck) {
    if (deck->tamanho == 0) {
        printf("O deck está vazio.\n");
        return;
    }
    for (int i = 0; i < deck->tamanho; i++) {
        printf("Carta %d:\n", i + 1);
        printf("  Nome: %s\n", deck->cartas[i].nome);
        printf("  Identidade: %s\n", deck->cartas[i].identidade);
        printf("  Peso: %.2f\n", deck->cartas[i].peso);
        printf("  Altura: %.2f\n", deck->cartas[i].altura);
        printf("  Primeira Aparição: %d\n", deck->cartas[i].primeiraAparicao);
        printf("  Força: %d\n", deck->cartas[i].forca);
        printf("  Inteligência: %d\n", deck->cartas[i].inteligencia);
        printf("  Código: %s\n", deck->cartas[i].codigo);
        printf("  Super Trunfo: %s\n", deck->cartas[i].superTrunfo ? "Sim" : "Não");
        printf("\n");
    }
}

// Pesquisa uma carta pelo nome
Carta* pesquisar_carta_nome(Deck *deck, const char *nome) {
    for (int i = 0; i < deck->tamanho; i++) {
        if (strcmp(deck->cartas[i].nome, nome) == 0) {
            return &deck->cartas[i]; // Retorna um ponteiro para a carta encontrada
        }
    }
    return NULL; // Retorna NULL se a carta não for encontrada
}

// Pesquisa uma carta pelo código
Carta* pesquisar_carta_codigo(Deck *deck, const char *codigo) {
    for (int i = 0; i < deck->tamanho; i++) {
        if (strcmp(deck->cartas[i].codigo, codigo) == 0) {
            return &deck->cartas[i]; // Retorna um ponteiro para a carta encontrada
        }
    }
    return NULL; // Retorna NULL se a carta não for encontrada
}

// Altera uma carta no deck
void alterar_carta(Deck *deck, int indice, Carta novaCarta) {
    if (indice < 0 || indice >= deck->tamanho) {
        printf("Índice inválido.\n");
        return;
    }
    deck->cartas[indice] = novaCarta; // Substitui a carta no índice especificado
}

// Libera a memória alocada para o deck
void liberar_deck(Deck *deck) {
    if (deck->cartas != NULL) {
        free(deck->cartas); // Libera a memória do vetor de cartas
        deck->cartas = NULL;
    }
    deck->tamanho = 0; // Redefine o tamanho do deck como 0
}