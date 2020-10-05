//
// Created by eric-mendes on 04/10/2020.
//

#ifndef UNTITLED2_JOGADOR_H
#define UNTITLED2_JOGADOR_H

#include <string>
using namespace std;

typedef struct {
    string nome;
    char simbolo;
} jogador;

void novoJogador(jogador* p, string nome, char simbolo);

#endif //UNTITLED2_JOGADOR_H
