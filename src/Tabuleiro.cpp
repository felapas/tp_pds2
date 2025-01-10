#include "Tabuleiro.hpp"
void Tabuleiro::exibirTabuleiro() const {
    std::cout << "PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";

    for (int i = 0; i < linhas; i++) {
        std::cout << "\t     |     |     \n\t";

        for (int j = 0; j < colunas; j++) {
            std::cout << "  " << matriz[i][j] << "  ";
            if (j < colunas - 1) std::cout << "|";
        }

        std::cout << "\n";

        if (i < linhas - 1) {
            std::cout << "\t_____|_____|_____\n";
        } else {
            std::cout << "\t     |     |     \n";
        }
    }
}

char Tabuleiro::getPosicao(int linha, int coluna) const {
    return matriz[linha][coluna];
}

void Tabuleiro::setPosicao(int linha, int coluna, char simbolo) {
    matriz[linha][coluna] = simbolo; 
}

bool Tabuleiro::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}
