//
// Created by eric-mendes on 04/10/2020.
//

#include <iostream>
using namespace std;
#include "jogo.h"

bool temVencedor(jogo* j) {
    if (((j->tabuleiro[0][0] == j->tabuleiro[0][1]) && (j->tabuleiro[0][1] == j->tabuleiro[0][2])) ||
        ((j->tabuleiro[1][0] == j->tabuleiro[1][1]) && (j->tabuleiro[1][1] == j->tabuleiro[1][2])) ||
        ((j->tabuleiro[2][0] == j->tabuleiro[2][1]) && (j->tabuleiro[2][1] == j->tabuleiro[2][2])))
        return true;

    else if (((j->tabuleiro[0][0] == j->tabuleiro[1][0]) && (j->tabuleiro[1][0] == j->tabuleiro[2][0])) ||
             ((j->tabuleiro[0][1] == j->tabuleiro[1][1]) && (j->tabuleiro[1][1] == j->tabuleiro[2][1])) ||
             ((j->tabuleiro[0][2] == j->tabuleiro[1][2]) && (j->tabuleiro[1][2] == j->tabuleiro[2][2])))
        return true;

    else if (((j->tabuleiro[0][0] == j->tabuleiro[1][1]) && (j->tabuleiro[1][1] == j->tabuleiro[2][2])) ||
             ((j->tabuleiro[0][2] == j->tabuleiro[1][1]) && (j->tabuleiro[1][1] == j->tabuleiro[2][0])))
        return true;

    return false;
}

bool deuVelha(jogo* j) {
    int soma = 0;
    for (int casa : j->casas)
        soma += casa;

    return (soma == 0);
}

void print(jogo* j) {
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            if (i == 0)
                cout << j->tabuleiro[k][i] << " | ";
            else if (i == 2)
                cout << " | " << j->tabuleiro[k][i] << endl;
            else
                cout << j->tabuleiro[k][i];
        }
    }
}

void fazerJogada(jogo* j, int jogada) {
    bool aux = false;
    for (int & casa : j->casas) {
        if (casa == jogada && casa != 0) {
            casa = 0;
            aux = true;
            break;
        }
    }
    if (!aux) {
        cout << "Jogada Inválida!" << endl;
        return;
    } else {
        bool tmp = false;
        for (int i = 0; i < 3 && !tmp; ++i) {
            for (int k = 0; k < 3; ++k) {
                if (j->tabuleiro[i][k]-48 == jogada) {
                    j->tabuleiro[i][k] = j->p1->simbolo;
                    tmp = true;
                    break;
                }
            }
        }
        jogador* jTmp = j->p2;
        j->p2 = j->p1;
        j->p1 = jTmp;
    }
}

void jogar(jogo* j) {
    while (!temVencedor(j) && !deuVelha(j)) {
        int jogada;
        cout << j->p1->nome << ", é sua vez..." << endl;
        print(j);
        cin >> jogada;
        fazerJogada(j, jogada);
    }
    print(j);
    if (!temVencedor(j)) cout << "Deu Velha!" << endl;
    else {
        cout << "Final de jogo. " << j->p2->nome << " é o campeão!" << endl;
    }
}

void novoJogo(jogo* j, jogador* p1, jogador* p2) {
    int aux = 49;
    j->p1 = p1;
    j->p2 = p2;


    for (int i = 0; i < 9; ++i)
        j->casas[i] = i+1;

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < 3; ++i) {
            j->tabuleiro[k][i] = char (aux);
            aux++;
        }
    }
    jogar(j);
}
