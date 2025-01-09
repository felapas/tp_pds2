#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "Tabuleiro.hpp"


class Jogo{
    private:
        const std::string nomeJogo;
        Tabuleiro tabuleiro;
    public:
        Jogo(const std::string nome)
        : nomeJogo(nome) {}
        virtual void lerJogada();
        virtual void validarJogada();
        virtual void validarVitoria();
};


#endif