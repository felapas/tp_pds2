#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "Tabuleiro.hpp"

class Jogo {
protected:
    const std::string nomeJogo;
    Tabuleiro tabuleiro;
public:
    // Construtor da classe abstrata Jogo
    Jogo(const std::string& nome, int linhas, int colunas)
        : nomeJogo(nome), tabuleiro(linhas, colunas) {}

    virtual void iniciar() = 0;
    virtual void lerJogada(int& linha, int& coluna) = 0;
    virtual void lerJogada(int& coluna) = 0; // Leitura de jogada para o Connect4

    virtual bool validarJogada(int linha, int coluna) = 0;
    virtual bool validarJogada(int coluna) = 0; // Leitura de jogada para o Connect4
    
    virtual bool validarVitoria() = 0;

    void exibirTabuleiro() const {
        tabuleiro.exibirTabuleiro();
    }
    virtual int getJogadorAtual() = 0;

    virtual ~Jogo() = default;
};

#endif
