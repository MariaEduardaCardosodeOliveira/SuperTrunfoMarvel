
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "deck.h"

void leString(char *texto, int tamanho)
{
    setbuf(stdin, NULL); 
    fgets(texto, tamanho, stdin);
    texto[strcspn(tamanho, "\n")] = '\0'; 
}