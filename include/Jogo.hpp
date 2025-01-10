#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "Tabuleiro.hpp"

class Jogo {
protected:
    const std::string nomeJogo;
    Tabuleiro tabuleiro;

public:
    Jogo(const std::string& nome, int linhas, int colunas)
        : nomeJogo(nome), tabuleiro(linhas, colunas) {}

    virtual void iniciar() = 0;
    virtual void lerJogada(int& linha, int& coluna) = 0;
    virtual bool validarJogada(int linha, int coluna) = 0;
    virtual bool validarVitoria() = 0;

    void exibirTabuleiro() const {
        tabuleiro.exibirTabuleiro();
    }

    virtual ~Jogo() = default;
};

#endif
