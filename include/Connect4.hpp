#ifndef JOGO_CONNECT4_H
#define JOGO_CONNECT4_H

#include <iostream>
#include "Jogo.hpp"

class Connect4 : public Jogo {
private:
    int jogadorAtual;   //Indica o jogador que está jogando
public:
    //Inicialização do jogo
    Connect4();
    void iniciar() override; 
    //Leitura da jogada
    void lerJogada(int& coluna)override;
    void lerJogada(int& coluna, int&linha);
    bool validarJogada(int coluna) override;
    bool validarJogada(int linha, int coluna ) override;
    //Valida condições de vítoria após jogada
    bool validarVitoria() override;
    int getJogadorAtual() override;
};

#endif