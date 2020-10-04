//
// Created by eric-mendes on 03/10/2020.
//

#ifndef UNTITLED2_GAME_H
#define UNTITLED2_GAME_H

typedef struct {
    char tabuleiro[3][3];
    int casas[9];
    int vez;
    bool temVencedor;
} game;

void newGame(game* g);
void printTabuleiro(game* g);
void play(game* g, int jogada);
bool casaJogada(game* g, int jogada);
bool deuVelha(game* g);
bool fimDeJogo(game* g);
#endif //UNTITLED2_GAME_H
