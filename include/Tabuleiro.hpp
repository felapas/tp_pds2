#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <iostream>

class Tabuleiro{

    private:
        int linhas;
        int colunas;
        std::vector<std::vector<char>> matriz;
    public:
        Tabuleiro(int linhas, int colunas) 
        : linhas(linhas), colunas(colunas), matriz(linhas, std::vector<char>(colunas, ' ')) {}

        void exibirTabuleiro() const;

        int getLinhas() const;
        int getColunas() const; // Para usar na configuracao do tabuleiro do Connect4

        char getPosicao(int linha, int coluna) const;
        void setPosicao(int linha, int coluna, char simbolo);
        
        bool posicaoValida(int linha, int coluna) const;

};

#endif