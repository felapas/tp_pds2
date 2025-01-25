#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Connect4.hpp"

TEST_CASE("Teste do Connect4") {
    Connect4 jogo;

    SUBCASE("Teste de Inicialização") {
        jogo.iniciar();
        
        CHECK(jogo.getJogadorAtual() == 1); // Jogador 1 começa
    }

    SUBCASE("Teste de Validação de Jogadas") {
        // Jogada válida
        CHECK(jogo.validarJogada(0) == true); // Coluna 0 é válida
        CHECK(jogo.getJogadorAtual() == 2); // Jogador alternou para 2

        // Jogada inválida (coluna cheia)
        for (int i = 0; i < 6; ++i) {
            jogo.validarJogada(0); // Preenche a coluna 0
        }
        CHECK(jogo.validarJogada(0) == false); // Coluna 0 está cheia

        // Jogada inválida (fora do tabuleiro)
        CHECK(jogo.validarJogada(7) == false); // Coluna 7 é inválida
    }

    SUBCASE("Teste de Vitória") {
        // Simula uma vitória do jogador 1
        jogo.validarJogada(0); // Jogador 1 marca (5, 0)
        jogo.validarJogada(1); // Jogador 2 marca (5, 1)
        jogo.validarJogada(0); // Jogador 1 marca (4, 0)
        jogo.validarJogada(1); // Jogador 2 marca (4, 1)
        jogo.validarJogada(0); // Jogador 1 marca (3, 0)
        jogo.validarJogada(1); // Jogador 2 marca (3, 1)
        jogo.validarJogada(0); // Jogador 1 marca (2, 0)

        CHECK(jogo.validarVitoria() == true); // Jogador 1 venceu
    }

    SUBCASE("Teste de Empate") {
        // Simula um empate
        for (int col = 0; col < 7; ++col) {
            for (int row = 0; row < 6; ++row) {
                jogo.validarJogada(col); // Preenche todo o tabuleiro
            }
        }

        CHECK(jogo.validarVitoria() == true); // Empate
    }
}