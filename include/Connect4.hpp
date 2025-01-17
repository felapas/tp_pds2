#ifndef JOGO_CONNECT4_H
#define JOGO_CONNECT4_H

#include <iostream>
#include "Jogo.hpp"

class Connect4 : public Jogo {
private:
    int jogadorAtual;

public:
    Connect4();

    void iniciar() override;
    void lerJogada(int& coluna)override;
    bool validarJogada(const int coluna) override;
    bool validarVitoria() override;
};

#endif