
#include "menu.h"
#include "arquivos.h"
#include <stdio.h>
#include <stdlib.h>

void exibir_menu(Deck *deck) {
    int opcao;
    do {
        printf("\n--- Menu Super Trunfo ---\n");
        printf("1. Listar Cartas\n");
        printf("2. Pesquisar Carta por Nome\n");
        printf("3. Pesquisar Carta por Código\n");
        printf("4. Adicionar Carta\n");
        printf("5. Remover Carta\n");
        printf("6. Alterar Carta\n");
        printf("7. Salvar Deck em CSV\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listar_cartas(deck);
                break;
            case 2: {
                char nome[50];
                printf("Digite o nome da carta: ");
                scanf(" %[^\n]", nome);
                Carta *carta = pesquisar_carta_nome(deck, nome);
                if (carta) {
                    printf("Carta encontrada: %s (%s)\n", carta->nome, carta->codigo);
                } else {
                    printf("Carta não encontrada.\n");
                }
                break;
            }
            case 3: {
                char codigo[5];
                printf("Digite o código da carta: ");
                scanf(" %s", codigo);
                Carta *carta = pesquisar_carta_codigo(deck, codigo);
                if (carta) {
                    printf("Carta encontrada: %s (%s)\n", carta->nome, carta->codigo);
                } else {
                    printf("Carta não encontrada.\n");
                }
                break;
            }
            case 4: {
                Carta novaCarta;
                printf("Digite os dados da nova carta:\n");
                printf("Nome: ");
                scanf(" %[^\n]", novaCarta.nome);
                printf("Identidade: ");
                scanf(" %[^\n]", novaCarta.identidade);
                printf("Peso: ");
                scanf("%f", &novaCarta.peso);
                printf("Altura: ");
                scanf("%f", &novaCarta.altura);
                printf("Primeira Aparição: ");
                scanf("%d", &novaCarta.primeiraAparicao);
                printf("Força: ");
                scanf("%d", &novaCarta.forca);
                printf("Inteligência: ");
                scanf("%d", &novaCarta.inteligencia);
                printf("Código: ");
                scanf(" %s", novaCarta.codigo);
                novaCarta.superTrunfo = 0; // Não é Super Trunfo por padrão
                adicionar_carta(deck, novaCarta);
                break;
            }
            case 5: {
                int indice;
                printf("Digite o índice da carta a ser removida: ");
                scanf("%d", &indice);
                if (indice >= 0 && indice < deck->tamanho) {
                    remover_carta(deck, indice);
                } else {
                    printf("Índice inválido.\n");
                }
                break;
            }
            case 6: {
                int indice;
                printf("Digite o índice da carta a ser alterada: ");
                scanf("%d", &indice);
                Carta novaCarta;
                printf("Digite os novos dados da carta:\n");
                printf("Nome: ");
                scanf(" %[^\n]", novaCarta.nome);
                printf("Identidade: ");
                scanf(" %[^\n]", novaCarta.identidade);
                printf("Peso: ");
                scanf("%f", &novaCarta.peso);
                printf("Altura: ");
                scanf("%f", &novaCarta.altura);
                printf("Primeira Aparição: ");
                scanf("%d", &novaCarta.primeiraAparicao);
                printf("Força: ");
                scanf("%d", &novaCarta.forca);
                printf("Inteligência: ");
                scanf("%d", &novaCarta.inteligencia);
                printf("Código: ");
                scanf(" %s", novaCarta.codigo);
                novaCarta.superTrunfo = 0; // Não é Super Trunfo por padrão
                alterar_carta(deck, indice, novaCarta);
                break;
            }
            case 7:
                salvar_deck_csv(deck, "data/deck.csv");
                printf("Deck salvo em CSV.\n");
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 8);
}
