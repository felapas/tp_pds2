#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#include <iostream>
#include "Jogo.hpp"

class JogoDaVelha : public Jogo {
private:
    int jogadorAtual;

public:
    JogoDaVelha();

    void iniciar() override;
    void lerJogada(int& linha) override;
    void lerJogada(int& linha, int& coluna) override;
    bool validarJogada(int linha, int coluna) override;
    bool validarJogada(int linha) override;
    bool validarVitoria() override;
    int getJogadorAtual();
};

#endif
