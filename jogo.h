//
// Created by eric-mendes on 04/10/2020.
//

#ifndef UNTITLED2_JOGO_H
#define UNTITLED2_JOGO_H

#include "jogador.h"

typedef struct {
    char tabuleiro[3][3];
    int casas[9];
    jogador* p1;
    jogador* p2;
} jogo;

void novoJogo(jogo* j, jogador* p1, jogador* p2);

#endif //UNTITLED2_JOGO_H
