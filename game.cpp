//
// Created by eric-mendes on 03/10/2020.
//

#include <iostream>
#include "game.h"
using namespace std;

#define PLAYER1 1
#define PLAYER2 2

void newGame(game* g) {
    char k = '1';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            g->tabuleiro[i][j] = k;
            k = (char)(((int) k) + 1);
        }
    }
    g->vez = PLAYER1;
    g->temVencedor = false;
    for (int l = 0; l < 9; ++l) {
        g->casas[l] = l+1;
    }
}

bool casaJogada(game* g, int jogada) {
    if (g->casas[jogada-1] == 0)
        return false;
    g->casas[jogada-1] = 0;
    return true;
}

bool deuVelha(game* g) {
    bool velha = true;
    for (int i = 0; i < 9; ++i) {
        if (g->casas[i] != 0)
            velha = false;
    }
    return velha;
}

void printTabuleiro(game* g) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j == 0) {
                cout << g->tabuleiro[i][j] << " | ";
            } else if (j == 2) {
                cout << " | " << g->tabuleiro[i][j] << endl;
            } else {
                cout << g->tabuleiro[i][j];
            }
        }
    }
}

void play(game* g, int jogada) {
    if (casaJogada(g, jogada)) {
        bool casa = false;
        if (jogada <= 3) {
            for (int i = 0; i < 3 && !casa; ++i) {
                if ((int) g->tabuleiro[0][i]-48 == jogada) {
                    g->tabuleiro[0][i] = g->vez == PLAYER1 ? 'X': 'O';
                    casa = true;
                }
            }
        } else if (jogada <= 6) {
            for (int i = 0; i < 3 && !casa; ++i) {
                if ((int) g->tabuleiro[1][i]-48 == jogada) {
                    g->tabuleiro[1][i] = g->vez == PLAYER1 ? 'X': 'O';
                    casa = true;
                }
            }
        } else {
            for (int i = 0; i < 3 && !casa; ++i) {
                if ((int) (g->tabuleiro[2][i])-48 == jogada) {
                    g->tabuleiro[2][i] = g->vez == PLAYER1 ? 'X': 'O';
                    casa = true;
                }
            }
        }
        if (g->vez == PLAYER1) g->vez = PLAYER2;
        else if (g->vez == PLAYER2) g->vez = PLAYER1;
    } else {
        cout << "Jogada inválida!" << endl;
    }
}

bool fimDeJogo(game* g) {
    if (((g->tabuleiro[0][0] == g->tabuleiro[0][1]) && (g->tabuleiro[0][1] == g->tabuleiro[0][2])) ||
    ((g->tabuleiro[1][0] == g->tabuleiro[1][1]) && (g->tabuleiro[1][1] == g->tabuleiro[1][2])) ||
    ((g->tabuleiro[2][0] == g->tabuleiro[2][1]) && (g->tabuleiro[2][1] == g->tabuleiro[2][2])))
        return true;

    else if (((g->tabuleiro[0][0] == g->tabuleiro[1][0]) && (g->tabuleiro[1][0] == g->tabuleiro[2][0])) ||
        ((g->tabuleiro[0][1] == g->tabuleiro[1][1]) && (g->tabuleiro[1][1] == g->tabuleiro[2][1])) ||
        ((g->tabuleiro[0][2] == g->tabuleiro[1][2]) && (g->tabuleiro[1][2] == g->tabuleiro[2][2])))
        return true;

    else if (((g->tabuleiro[0][0] == g->tabuleiro[1][1]) && (g->tabuleiro[1][1] == g->tabuleiro[2][2])) ||
        ((g->tabuleiro[0][2] == g->tabuleiro[1][1]) && (g->tabuleiro[1][1] == g->tabuleiro[2][0])))
        return true;

    return false;
}
