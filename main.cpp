#include <iostream>
#include "game.h"
using namespace std;

int main() {
    char decision = ' ';
    cout << "Olá! Gostaria de jogar um novo jogo? (S/n)" << endl;
    cin >> decision;
    if (decision == 'n') cout << "Tudo bem, até mais!" << endl;
    else {
        cout << "Muito bem!\n" << endl;
        game g;
        newGame(&g);
        while (!fimDeJogo(&g) && !deuVelha(&g)) {
            int jogada = 0;
            printTabuleiro(&g);
            cout << "Jogador " << g.vez << ", jogue..." << endl;
            cin >> jogada;
            play(&g, jogada);
        }
        printTabuleiro(&g);
        if (!deuVelha(&g)) {
            cout << "Jogador " << (g.vez == 1 ? 2: 1) << " venceu!" << endl;
        } else {
            cout << "Deu velha. Empate!" << endl;
        }
    }
    cout << "\nFim." << endl;
    return 0;
}
