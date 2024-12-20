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
#include "medalha.h"
#include "funcoes.h"
#include "arquivos.h"
#include "menu.h"

// CONFIGURAÇÃO SISTEMA OPERACIONAL
#ifdef OS_Windows
#include <conio.h>
#include <windows.h>
#else
#include <unistd.h>
#endif

//------------------INÍCIO DA TABELA------------------

void realocaTabela(Table **tabela, int valor)
{
    *tabela = (Table *)realloc(*tabela, valor * sizeof(Table));
}
// verifica se o pais existe na tabela, se existir retorna o I encontrado, se nao retorna -1
int VerificaSeExisteTabela(Table *tabela, char *pais, int contadorTabela)
{
    // variavel para retorno
    int retorno = 0;
    int existe = 0;
    for (int i = 0; i < contadorTabela; i++)
    {
        if (strcmp(tabela[i].pais, pais) == 0)
        {
            existe = 1;
            // isso sai do for imediatamente, pois ja achou o que procura
            // antes salva a variavel i que é a encontrada
            retorno = i;
            i = contadorTabela;
        }
    }
    // retorno valor de i, se for 0 nao encontrou
    if (existe == 0)
    {
        retorno = -1;
    }
    return retorno;
}