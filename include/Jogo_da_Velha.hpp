#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#include <iostream>
#include "Jogo.hpp"
#include "Tabuleiro.hpp"

class JogoDaVelha : public Jogo {
private:
    Tabuleiro tabuleiro; 
public:
    JogoDaVelha() : Jogo("JogoDaVelha"), tabuleiro(3, 3) {}

    void lerJogada(int linha, int coluna) override;
    void validarJogada(int linha, int coluna) override;
    void validarVitoria() override;
};

#endif
