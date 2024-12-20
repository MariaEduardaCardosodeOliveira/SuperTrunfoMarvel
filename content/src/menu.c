//DETECTANDO O SISTEMA OPERACIONAL
#ifdef __unix__ //Unix/Linux
#elif defined(_WIN32) || defined(WIN32) //Windows
#define OS_Windows
#endif

// IMPORTANDO BIBLIOTECAS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// INCLUINDO CABEÇALHOS
#include "deck.h"
//#include "arquivos.h"
#include "menu.h"

// CONFIGURAÇÃO SISTEMA OPERACIONAL
#ifdef OS_Windows
#include <conio.h>
#include <windows.h>
#else
#include <unistd.h>
#endif

//------------------INÍCIO DO deck------------------

void realocaDeck(Cartas **deck, int valor)
{
    *deck = (Cartas *)realloc(*deck, valor * sizeof(Cartas));
}
// verifica se o nome existe na deck, se existir retorna o I encontrado, se nao retorna -1
int verificaSeExisteDeck(Cartas *deck, char *nome, int contadorDeck)
{
    // variavel para retorno
    int retorno = 0;
    int existe = 0;
    for (int i = 0; i < contadorDeck; i++)
    {
        if (strcmp(deck[i].nome, nome) == 0)
        {
            existe = 1;
            // isso sai do for imediatamente, pois ja achou o que procura
            // antes salva a variavel i que é a encontrada
            retorno = i;
            i = contadorDeck;
        }
    }
    // retorno valor de i, se for 0 nao encontrou
    if (existe == 0)
    {
        retorno = -1;
    }
    return retorno;
}


// cond é a mao de cada pessoa, se 1, 0-15, se 2, 16-31
void listarDeck(Cartas *deck, int contadorCartas, int cond)
{
    printf("\033[1;34m"); // Cor azul
    printf("%-30s %-5c %-5d %-5i %-5i %-5i %-5i \n", "Nome", "Letra", "Numero", "atributoNumerico1", "atributoNumerico2", "atributoNumerico3", "atributoNumerico4");
    printf("------------------------------------------------------------\n");
    printf("\033[0m"); // Reseta cor
    int i = 0;
    int lim = cond * 16;
    // caso cond == 1 é a primeira opcao, onde o 0 começa na apresentacao do for, caso for diferente ele comeca por outro
    /*if (cond != 1)
    {
        i = cond * 10; //Nao entendi o que ele quis aqui
    }
     caso cond(paginaDesejada) == paginaMax(maximo de paginas)
    //  entao o limite deve ser o tamanho do contador da tabela, e nao até 20*cond
    if (cond == paginaMax)
    {
        lim = contadorTabela;
    }*/
    for (i = i; i < lim; i++)
    {
        printf("%-30s %-5c %-5d %-5d\n", deck[i].nome, deck[i].letra, deck[i].numero, deck[i].atributoNumerico1, deck[i].atributoNumerico2, deck[i].atributoNumerico3, deck[i].atributoNumerico4);
    }
}

/*void apresentaDeck(Cartas *vetor, int tamanho) // É aqui que adiciona uma nova carta, entao vou mexer depois

}*/

#ifdef OS_Windows
// função para beep
void beep()
{
    Beep(850, 200); // beep
}
#else
void beep()
{
    float frequencia = 850;
    float tempo = 200;
    char comando[255];
    sprintf(comando, "play -nq -t alsa synth %f tri %f", tempo / 1000, frequencia);
    system(comando);
} // Beep
#endif

// funcao para mensagem de erro do usuário
void MensagemErro()
{
    beep();
    printf("\e[1;31m");
    printf("Erro, digite novamente.\n"); // mensagem de erro
    printf("\033[0m");
} // MensagemErro

// exibe o  menu principal
void exibeMenuPrincipal()
{
    printf("\033[1;34m"); // Cor azul
    printf("Menu Principal:\n");
    printf("1. Gerenciar cartas\n");
    printf("2. Gerar Deck\n");
    printf("3. Exportar Deck\n");
    printf("4. Sair\n");
    printf("\033[0m"); // Reseta cor
} // exibeMenuPrincipal

void exibeMenuCartas()
{
    printf("\033[1;34m"); // Cor azul
    printf("Gerenciar cartas:\n");
    printf("1. Inserir cartas\n");
    printf("2. Listar cartas\n");
    printf("3. Pesquisar cartas\n");
    printf("4. Alterar carta\n");
    printf("5. Excluir carta\n");
    printf("6. Voltar\n");
    printf("\033[0m"); // Reseta a cor

} // exibeMenuCartas

void chamaMenu(Cartas *vetor, int *contador)
{
    int opcaoSubmenu = 0;
    int opcaoPrincipal = 0;
    while (opcaoPrincipal != 4)
    {
        setbuf(stdin, NULL);
        exibeMenuPrincipal();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcaoPrincipal);
        switch (opcaoPrincipal)
        {
        case 1:

            // repeticao infinita do switch case
            while (opcaoSubmenu != 6)
            {
                exibeMenuCartas();
                printf("Escolha uma opcao: ");
                setbuf(stdin, NULL);
                scanf("%d", &opcaoSubmenu);
                switch (opcaoSubmenu)
                {
                    // opcao 1 submenu
                case 1:
                    // Implementa a insercao de cartas
                    insere_cartas(&vetor, contador);
                    break;

                    // opcao 2 submenu
                case 2:
                    // Listagem das cartas(Lista de carta)
                    listar_cartas(vetor, *contador);
                    break;

                    // opcao 3 submenu
                case 3:
                    // Pesquisa as cartas
                    pesquisar_cartas(vetor, *contador);
                    break;

                    // opcao 4 submenu
                case 4:
                    // Alteraçao nas cartas
                    alterar_carta(vetor, *contador);
                    break;

                    // opcao 5 submenu
                case 5:
                    // Exclui carta
                    excluir_carta(vetor, contador);
                    break;

                    // opcao 6 voltar ao menu
                case 6:
                    // case a opcao seja 6, volta para o menu principal
                    break;

                    // default
                default:
                    // printf("Opcao invalida, tente navamente:\n");
                    MensagemErro();
                    break;
                } // switch case Submenu
            } // while Submenu
            break; // break da opcao 1 do menu principal

        // opcao 2 menu principal
        case 2:
            // Gera tabela
            apresentarDeck(vetor, *contador);
            break;
            // opcao 3 menu principal

        case 3:
            // Exportar dados
            cria_arquivo_csv(vetor, *contador);
            break;

        // opcao 4 do menu principal
        case 4:
            printf("Fim do menu");
            break;

        default:
            // printf("Opcao invalida, tente navamente:\n");
            MensagemErro();
            break;
        } // switch case Menu Principal
    } // while Menu Principal
} // switchcase