#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../include/Jogo_Da_Velha.hpp"

TEST_CASE("Teste do Jogo da Velha") {
    JogoDaVelha jogo;

    SUBCASE("Teste de Inicialização") {
        jogo.iniciar();
        CHECK(jogo.getJogadorAtual() == 1); // Jogador 1 começa
    }

    SUBCASE("Teste de Validação de Jogadas") {
        // Jogada válida
        CHECK(jogo.validarJogada(0, 0) == true); // Posição (0, 0) é válida
        CHECK(jogo.getJogadorAtual() == 2); // Jogador alternou para 2

        // Jogada inválida (posição já ocupada)
        CHECK(jogo.validarJogada(0, 0) == false); // Posição (0, 0) já está ocupada

        // Jogada inválida (fora do tabuleiro)
        CHECK(jogo.validarJogada(3, 3) == false); // Posição (3, 3) é inválida
    }

    SUBCASE("Teste de Vitória") {
        // Simula uma vitória do jogador 1
        jogo.validarJogada(0, 0); // Jogador 1 marca (0, 0)
        jogo.validarJogada(1, 0); // Jogador 2 marca (1, 0)
        jogo.validarJogada(0, 1); // Jogador 1 marca (0, 1)
        jogo.validarJogada(1, 1); // Jogador 2 marca (1, 1)
        jogo.validarJogada(0, 2); // Jogador 1 marca (0, 2)

        CHECK(jogo.validarVitoria() == true); // Jogador 1 venceu
    }

    SUBCASE("Teste de Empate") {
        // Simula um empate
        jogo.validarJogada(0, 0); // Jogador 1 marca (0, 0)
        jogo.validarJogada(0, 1); // Jogador 2 marca (0, 1)
        jogo.validarJogada(0, 2); // Jogador 1 marca (0, 2)
        jogo.validarJogada(1, 1); // Jogador 2 marca (1, 1)
        jogo.validarJogada(1, 0); // Jogador 1 marca (1, 0)
        jogo.validarJogada(1, 2); // Jogador 2 marca (1, 2)
        jogo.validarJogada(2, 0); // Jogador 1 marca (2, 0)
        jogo.validarJogada(2, 1); // Jogador 2 marca (2, 1)
        jogo.validarJogada(2, 2); // Jogador 1 marca (2, 2)

        CHECK(jogo.validarVitoria() == true); // Empate
    }
}