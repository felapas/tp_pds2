#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../include/Connect4.hpp"
#include <sstream>
#include <iostream>
#include <functional>

// Função auxiliar para redirecionar stdout
class OutputRedirector {
    std::streambuf* oldCout;
    std::stringstream buffer;

public:
    OutputRedirector() : oldCout(std::cout.rdbuf(buffer.rdbuf())) {}
    ~OutputRedirector() { std::cout.rdbuf(oldCout); }
    std::string getOutput() { return buffer.str(); }
};

// Função auxiliar para simular inputs
class InputRedirector {
    std::streambuf* oldCin;
public:
    InputRedirector(const std::string& input) {
        auto* newCin = new std::stringstream(input);
        oldCin = std::cin.rdbuf(newCin->rdbuf());
    }
    ~InputRedirector() {
        std::cin.rdbuf(oldCin);
    }
};

TEST_CASE("Teste do Connect4") {
    SUBCASE("Teste de Inicialização") {
        OutputRedirector out;
        InputRedirector in("1\n");  // Simula escolha de tamanho válido
        
        Connect4 jogo;
        jogo.iniciar();
        
        CHECK(jogo.getJogadorAtual() == 1);
        CHECK(out.getOutput().find("Opção inválida") == std::string::npos);
    }

    SUBCASE("Teste de Jogadas Válidas") {
        Connect4 jogo;
        OutputRedirector out;
        InputRedirector in("1\n");  // Configura tamanho do tabuleiro
        jogo.iniciar();

        CHECK(jogo.validarJogada(0) == true);  // Coluna 1 (0 após decremento)
        CHECK(jogo.getJogadorAtual() == 2);
    }

    SUBCASE("Teste de Vitória Horizontal") {
        Connect4 jogo;
        OutputRedirector out;
        InputRedirector in("1\n");
        jogo.iniciar();

        // Jogador 1: colunas 0,1,2,3
        for(int col : {0,1,2,3}) {
            CHECK(jogo.validarJogada(col));
            jogo.validarJogada(6); // Jogador 2 em coluna diferente
        }
        
        CHECK(jogo.validarVitoria() == true);
        CHECK(out.getOutput().find("Jogador 1 venceu!") != std::string::npos);
    }
}