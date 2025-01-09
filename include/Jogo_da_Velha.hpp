#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#include <iostream>
#include "Jogo.hpp"
#include "Tabuleiro.hpp"

class JogoDaVelha : public Jogo {
private:
    tabuleiro(3, 3);
public:
    JogoDaVelha() : Jogo("JogoDaVelha") {}
    void lerJogada(int linha, int coluna) override;
    void validarJogada() override;
    void validarVitoria() override;
}

#endif