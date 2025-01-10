#ifndef PARTIDA_H
#define PARTIDA_H

#include <iostream>
#include "Jogador.hpp"

class Partida{
    private:
        int _numJogo;
        Joagdor::Jogador jogador1, jogador2;
    public:
        Partida(int numJogo, Jogador::Jogador jogador1, Jogador::);
        
        void executarPartida(Jogo jogo);
        void adicionarVitoria(std::string apelido_vencedor);
        void adicionarDerrota(std::string apelido_perdedor);
};

#endif