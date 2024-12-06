/*
Para gerenciar um Deck de cartas no estilo Super Trunfo, defina uma estrutura Carta
contendo, no mínimo: nome (texto), uma letra(char), um número(int), um boleano para
saber se é a carta super trunfo (bool) e mais 4 atributos numéricos (int ou float). Deverá
permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) as cartas disponíveis. Essa
relação deve aumentar e diminuir dinamicamente. Cada deck tem no mínimo 32 cartas
com os códigos compostos por letras de A a D e números de 1 a 8 (ou mais caso
necessário).
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    char nome[50];
    char letra[1];
    int numero;
    bool superTrunfo;
    float atributoNumerico1, atributoNumerico2, atributoNumerico3, atributoNumerico4;
}Carta;



//CHAMAR FUNÇÕES CRIADAS NOS OUTROS ARQUIVOS