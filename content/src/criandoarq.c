#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __unix__
#elif defined(_WIN32) || defined(WIN32)
#define OS_Windows
#endif

/*
Para gerenciar um Deck de cartas no estilo Super Trunfo, 
defina uma estrutura Carta contendo, no mínimo:
nome (texto), uma letra(char), um número(int), um boleano
para saber se é a carta super trunfo (bool) e
mais 4 atributos numéricos (int ou float). 
Deverá permitir cadastrar (inserir/listar/pesquisar/alterar/excluir) 
as cartas disponíveis. Essa relação deve aumentar e diminuir dinamicamente. 
Cada deck tem no mínimo 32 cartas com os códigos compostos por letras de A a D 
e números de 1 a 8 (ou mais caso necessário).

Ao sair do programa, todos os dados devem ser salvos em arquivos binários
no HD e recarregados novamente ao iniciar. Caso os arquivos não existam,
eles devem ser criados e uma mensagem de boas vindas deve ser apresentada ao usuário;

*/
    void cria_arq(){
    
    Carta *cartass;
    int tamanho = 32; // Mínimo de 32 cartas

    cartass = (Carta*) malloc(tamanho * sizeof(Carta)); // Alocando dinamicamente para 32 cartas

    FILE *arq = fopen("arquivo.dat", "wb");
    
    if (arq == NULL) { // Checar se conseguiu criar o arquivo
        perror("Erro ao abrir o arquivo!!! \n");
        exit(0);
    }

    printf("Bem-Vindos! Dados da estrutura serao salvos em binario...\n");

    for (int i = 0; i < tamanho; i++) { // Lendo cada vetor de cartas e salvando em binário
        // Aqui você deve preencher cartass[i] com os dados da carta antes de escrever
        fwrite(&cartass[i], sizeof(Carta), 1, arq); 
    }

    printf("Dados da estrutura salvos com sucesso em binario!\n");

    free(cartass);
    fclose(arq); 
    }
//não coloquei o int main pois teria problema na main principal