#ifndef CARTA_H
#define CARTA_H

#include <stdbool.h>

typedef struct {
    char nome[50];
    char identidade[50];
    float peso;
    float altura;
    int primeiraAparicao;
    int forca;
    int inteligencia;
    char codigo[5]; // Código no formato "A1", "B2", etc.
    bool superTrunfo; // Indica se é a carta Super Trunfo
} Carta;

#endif // CARTA_H