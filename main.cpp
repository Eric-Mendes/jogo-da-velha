#include <iostream>
#include "jogo.h"
#include "jogador.h"

using namespace std;

int main() {
    char decision;
    cout << "Olá! Gostaria de jogar um novo jogo? (S/n)" << endl;
    cin >> decision;
    if (decision == 'n' || decision == 'N') cout << "Tudo bem, até mais!" << endl;
    else {
        jogador p1, p2;
        string nome1, nome2;
        char simb1, simb2;

        cout << "Jogador 1, digite seu nome e um símbolo para representá-lo no jogo (separados por um espaço):\t";
        cin >> nome1 >> simb1;
        cout << "Jogador 2, digite seu nome e um símbolo para representá-lo no jogo (separados por um espaço):\t";
        cin >> nome2 >> simb2;

        novoJogador(&p1, nome1, simb1);
        novoJogador(&p2, nome2, simb2);

        jogo j;
        novoJogo(&j, &p1, &p2);
    }
    cout << "\nFim." << endl;
    return 0;
}
