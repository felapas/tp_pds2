#include "Tabuleiro.hpp"

void Tabuleiro::exibirTabuleiro() const {
    for (int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            std::cout << matriz[i][j];
            if(j<colunas-1) std::cout << " | ";
        }
        std::cout << std::endl;
        if(i < linhas - 1 ){
            for(int k = 0; k < colunas; k++){
                std::cout << "--";
                if(k < colunas - 1) std::cout << "+";
            }
            std::cout << std::endl;
        }
    }
}

char Tabuleiro::getPosicao(int linha, int coluna) const {
    return matriz[linha][coluna];
}

bool Tabuleiro::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}
