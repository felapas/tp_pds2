#include "Tabuleiro.hpp"

// Exibe o tabuleiro na tela
void Tabuleiro::exibirTabuleiro() const {
    std::cout << "PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";

    for (int i = 0; i < linhas; i++) {
        // Linha superior das células
        std::cout << "\t";
        for (int j = 0; j < colunas; j++) {
            std::cout << "     ";
            if (j < colunas - 1) std::cout << "|";
        }
        std::cout << "\n\t";

        // Linha com os valores das células
        for (int j = 0; j < colunas; j++) {
            std::cout << "  " << matriz[i][j] << "  ";
            if (j < colunas - 1) std::cout << "|";
        }
        std::cout << "\n";

        // Linha divisória entre as células (exceto na última linha)
        if (i < linhas - 1) {
            std::cout << "\t";
            for (int j = 0; j < colunas; j++) {
                std::cout << "_____";
                if (j < colunas - 1) std::cout << "|";
            }
            std::cout << "\n";
        }
    }

    // Linha inferior do tabuleiro
    std::cout << "\t";
    for (int j = 0; j < colunas; j++) {
        std::cout << "     ";
        if (j < colunas - 1) std::cout << "|";
    }
    std::cout << "\n";
}

int Tabuleiro::getLinhas() const {
    return linhas;
}

int Tabuleiro::getColunas() const {
    return colunas;
}

char Tabuleiro::getPosicao(int linha, int coluna) const {
    return matriz[linha][coluna];
}

void Tabuleiro::setPosicao(int linha, int coluna, char simbolo) {
    matriz[linha][coluna] = simbolo; 
}

// Verifica se a posição está dentro do tabuleiro definido
bool Tabuleiro::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}
