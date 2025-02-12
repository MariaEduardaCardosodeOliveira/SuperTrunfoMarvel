
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carta.h"
#include "arquivos.h"

/*
#ifdef __unix__
#elif defined(_WIN32) || defined(WIN32)
#define OS_Windows
#endif
*/

void carregar_deck_csv(Deck *deck, const char *caminho_arquivo) {
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo CSV.\n");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), arquivo); // Pular a primeira linha (cabeçalho)

    while (fgets(linha, sizeof(linha), arquivo)) {
        Carta carta;
        // Verifica se a linha foi lida corretamente
        int campos_lidos = sscanf(linha, "%[^;];%[^;];%f;%f;%d;%d;%d;%s",
                                   carta.nome, carta.identidade, &carta.peso, &carta.altura,
                                   &carta.primeiraAparicao, &carta.forca, &carta.inteligencia,
                                   carta.codigo);

        if (campos_lidos == 8) {  // Se os 8 campos foram lidos corretamente
            // Define a carta Super Trunfo (exemplo: última carta do arquivo)
            carta.superTrunfo = (strcmp(carta.codigo, "H4") == 0);
            adicionar_carta(deck, carta);
        } else {
            // Se não conseguir ler todos os campos, imprima a linha com erro
            printf("Erro ao ler linha (campos lidos: %d): %s\n", campos_lidos, linha);
        }
    }

    fclose(arquivo);
    printf("Tamanho do deck após carregamento: %d\n", deck->tamanho);
}

void salvar_deck_csv(Deck *deck, const char *caminho_arquivo) {
    FILE *arquivo = fopen(caminho_arquivo, "w");
    if (!arquivo) {
        printf("Erro ao salvar o arquivo CSV.\n");
        return;
    }

    fprintf(arquivo, "Nome;Identidade;Peso;Altura;Primeira Aparicao;Forca;Inteligencia;Codigo\n");

    for (int i = 0; i < deck->tamanho; i++) {
        Carta carta = deck->cartas[i];
        fprintf(arquivo, "%s;%s;%.2f;%.2f;%d;%d;%d;%s\n",
                carta.nome, carta.identidade, carta.peso, carta.altura,
                carta.primeiraAparicao, carta.forca, carta.inteligencia, carta.codigo);
    }

    fclose(arquivo);
}

void salvar_deck_binario(Deck *deck, const char *caminho_arquivo) {
    FILE *arquivo = fopen(caminho_arquivo, "wb");
    if (!arquivo) {
        printf("Erro ao salvar o arquivo binário.\n");
        return;
    }

    fwrite(&deck->tamanho, sizeof(int), 1, arquivo);
    fwrite(deck->cartas, sizeof(Carta), deck->tamanho, arquivo);

    fclose(arquivo);
}

void carrega_deck_binario(Deck *deck, const char *caminho_arquivo) {
    FILE *arquivo = fopen(caminho_arquivo, "rb");
    if (!arquivo) {
        printf("Arquivo binário não encontrado. Criando novo deck.\n");
        return;
    }

    fread(&deck->tamanho, sizeof(int), 1, arquivo);
    deck->cartas = (Carta *)malloc(deck->tamanho * sizeof(Carta));
    fread(deck->cartas, sizeof(Carta), deck->tamanho, arquivo);

    fclose(arquivo);
}