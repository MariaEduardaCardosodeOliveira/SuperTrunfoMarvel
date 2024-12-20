/*
Para gerenciar um Deck de cartas no estilo Super Trunfo, 
defina uma estrutura Carta contendo, no mínimo: 
nome (texto), 
uma letra(char), 
um número(int), 
um boleano para saber se é a carta super trunfo (bool) 
e mais 4 atributos numéricos (int ou float). 
Deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) as cartas disponíveis. Essa
relação deve aumentar e diminuir dinamicamente. Cada deck tem no mínimo 32 cartas
com os códigos compostos por letras de A a D e números de 1 a 8 (ou mais caso
necessário).
*/

// INCLUINDO CABEÇALHOS
#include "deck.h"
#include "arquivos.h"
#include "funcoes.h"
// IMPORTANDO BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//inserir uma nova carta em um array dinâmico de cartas.
void inserir_cartas(Carta **cartas, int *numCartas){
    *cartas = realloc(*cartas, (*numCartas + 1) * sizeof(Carta));
    if (*cartas == NULL)
    {
        printf("Erro ao relocar memória\n");
        exit(EXIT_FAILURE);
    }

    printf("Digite o nome do personagem da sua nova carta:\n");
    setbuf(stdin, NULL);
    leString((*cartas)[*numCartas].nome, 50);

    printf("Digite uma letra para sua nova carta:\n");
    setbuf(stdin, NULL);
    scanf("%c", &(*cartas)[*numCartas].letra);

    printf("Digite um número para sua nova carta:\n");
    scanf("%d", &(*cartas)[*numCartas].numero);

    // Gerar código combinando letra e número
    snprintf((*cartas)[*numCartas].codigo, 10, "%c%d", (*cartas)[*numCartas].letra, (*cartas)[*numCartas].numero);

    printf("Digite (0) para adicionar SUPERTRUNFO ou (1) para adicionar demais cartas");
    scanf("%d", &(*cartas)[*numCartas].superTrunfo);

    printf("Digite a identidade do seu novo personagem:\n");
    setbuf(stdin, NULL);
    leString((*cartas)[*numCartas].identidade, 50);

    printf("Digite o peso do seu novo personagem:\n");
    scanf("%f", &(*cartas)[*numCartas].peso);

    printf("Digite o ano da primeira aparição do seu novo personagem: ");
    setbuf(stdin, NULL);
    scanf("%d",&(*cartas)[*numCartas].primeiraAparicao);

    printf("Digite o valor da força do seu novo personagem:\n");
    scanf("%f", &(*cartas)[*numCartas].forca);

    printf("Digite o valor da inteligência do seu novo personagem(valor entre 0 a 5):\n");
    scanf("%f", &(*cartas)[*numCartas].inteligencia);

    (*cartas)[*numCartas].contador = *numCartas + 1;
    printf("Carta adicionada com sucesso! Código da carta: %d\n", (*cartas)[*numCartas].codigo);
    (*numCartas)++;

    return;
}

void listar_cartas(Cartas *cartas, int numCartas){    
    if (numCartas == 0) {
        printf("Nenhuma carta cadastrada.\n");
        return;
    }

    printf("\n=== Cartas Cadastradas ===\n");
    printf("+--------+---------------------+-------+------+---------------+-------+--------------+------------+------------+\n");
    printf("| Código | Nome                | Letra | Nº   | Super Trunfo  | Peso  | 1ª Aparição  | Força      | Inteligência |\n");
    printf("+--------+---------------------+-------+------+---------------+-------+--------------+------------+------------+\n");

    for (int i = 0; i < numCartas; i++) {
        printf("| %-6s | %-19s | %-5c | %-4d | %-13s | %-5.1f | %-12d | %-10d | %-12d |\n",
               cartas[i].codigo,
               cartas[i].nome,
               cartas[i].letra,
               cartas[i].numero,
               cartas[i].superTrunfo ? "Sim" : "Não",
               cartas[i].peso,
               cartas[i].primeiraAparicao,
               cartas[i].forca,
               cartas[i].inteligencia);
    }

    printf("+--------+-------------------+-------+--------------+-----------+-------------+------------+\n");
}


void pesquisar_carta(Carta *cartas, int numCartas) {
    int escolha;
    printf("Escolha o atributo para pesquisa:\n");
    printf("1 - Nome\n2 - Letra\n3 - Número\n4 - Força\n5 - Inteligência\n");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: {
            char nomePesquisado[50];
            printf("Digite o nome da carta a ser pesquisada:\n");
            setbuf(stdin, NULL);
            leString(nomePesquisado, 50);
            int encontrado = 0;
            for (int i = 0; i < numCartas; i++) {
                if (strcmp(cartas[i].nome, nomePesquisado) == 0) {
                    printf("Carta encontrada: %s\n", cartas[i].nome);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("Carta não encontrada!\n");
            }
            break;
        }
        case 2: {
            char letraPesquisada;
            printf("Digite a letra da carta a ser pesquisada (A a D):\n");
            scanf(" %c", &letraPesquisada);
            int encontrado = 0;
            for (int i = 0; i < numCartas; i++) {
                if (cartas[i].letra == letraPesquisada) {
                    printf("Carta encontrada: %s\n", cartas[i].nome);
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Nenhuma carta encontrada com essa letra!\n");
            }
            break;
        }
        case 3: {
            int numeroPesquisado;
            printf("Digite o número da carta a ser pesquisada:\n");
            scanf("%d", &numeroPesquisado);
            int encontrado = 0;
            for (int i = 0; i < numCartas; i++) {
                if (cartas[i].numero == numeroPesquisado) {
                    printf("Carta encontrada: %s\n", cartas[i].nome);
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Nenhuma carta encontrada com esse número!\n");
            }
            break;
        }
        case 4: {
            float forcaPesquisado;
            printf("Digite o valor da força para pesquisa:\n");
            scanf("%f", &forcaPesquisado);
            int encontrado = 0;
            for (int i = 0; i < numCartas; i++) {
                if (cartas[i].forca >= forcaPesquisado) {
                    printf("Carta encontrada: %s\n", cartas[i].nome);
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Nenhuma carta com força maior ou igual a %.2f\n", forcaPesquisado);
            }
            break;
        }
        case 5: {
            float inteligenciaPesquisada;
            printf("Digite o valor da inteligência para pesquisa (entre 0 a 5):\n");
            scanf("%f", &inteligenciaPesquisada);
            int encontrado = 0;
            for (int i = 0; i < numCartas; i++) {
                if (cartas[i].inteligencia >= inteligenciaPesquisada) {
                    printf("Carta encontrada: %s\n", cartas[i].nome);
                    encontrado = 1;
                }
            }
            if (!encontrado) {
                printf("Nenhuma carta com inteligência maior ou igual a %.2f\n", inteligenciaPesquisada);
            }
            break;
        }
        default:
            printf("Opção inválida.\n");
            break;
    }
}


void alterar_carta(Carta *cartas, int numCartas) {
    char nomAlterar[50];
    printf("Digite o nome da carta a ser alterada:\n");
    setbuf(stdin, NULL);
    leString(nomAlterar, 50);

    int encontrado = 0;
    for (int i = 0; i < numCartas; i++) {
        if (strcmp(cartas[i].nome, nomAlterar) == 0) {
            encontrado = 1;
            printf("Carta encontrada: %s\n", cartas[i].nome);

            // Alterar atributos
            printf("Digite o novo nome do personagem:\n");
            setbuf(stdin, NULL);
            leString(cartas[i].nome, 50);

            printf("Digite a nova letra da carta:\n");
            scanf(" %c", &cartas[i].letra);

            printf("Digite o novo número da carta:\n");
            scanf("%d", &cartas[i].numero);

            snprintf(cartas[i].codigo, 10, "%c%d", cartas[i].letra, cartas[i].numero);

            printf("Digite (0) para SUPER TRUNFO ou (1) para demais cartas:\n");
            scanf("%d", &cartas[i].superTrunfo);

            printf("Digite a nova identidade do personagem:\n");
            setbuf(stdin, NULL);
            leString(cartas[i].identidade, 50);

            printf("Digite o novo peso do personagem:\n");
            scanf("%f", &cartas[i].peso);

            printf("Digite o novo ano da primeira aparição:\n");
            scanf("%d", &cartas[i].primeiraAparicao);

            printf("Digite o novo valor da força do personagem:\n");
            scanf("%f", &cartas[i].forca);

            printf("Digite o novo valor da inteligência do personagem:\n");
            scanf("%f", &cartas[i].inteligencia);

            printf("Carta alterada com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Carta não encontrada!\n");
    }
}


void excluir_carta(Carta *cartas, int *numCartas) {
    char nomeExcluir[50];
    printf("Digite o nome da carta a ser excluída:\n");
    setbuf(stdin, NULL);
    leString(nomeExcluir, 50);

    int encontrado = 0;
    for (int i = 0; i < *numCartas; i++) {
        if (strcmp(cartas[i].nome, nomeExcluir) == 0) {
            encontrado = 1;
            printf("Carta encontrada: %s\n", cartas[i].nome);

            // Deslocar as cartas para remover a carta excluída
            for (int j = i; j < *numCartas - 1; j++) {
                cartas[j] = cartas[j + 1];
            }

            // Reduzir o tamanho do array de cartas
            (*numCartas)--;
            cartas = realloc(cartas, (*numCartas) * sizeof(Carta));

            printf("Carta excluída com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Carta não encontrada!\n");
    }
}