#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <iostream>

class Tabuleiro{

    private:
        std::vector<std::vector<char>> matriz;
        int linhas;
        int colunas;
    public:
        Tabuleiro(int linhas, int colunas) 
        : linhas(linhas), colunas(colunas), matriz(linhas, std::vector<char>(colunas, ' ')) {}

        void exibirTabuleiro() const;

        char getPosicao(int linha, int coluna) const;
        void setPosicao(int linha, int coluna, char simbolo);
        
        bool posicaoValida(int linha, int coluna) const;

};

#endif