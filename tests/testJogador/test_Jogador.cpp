#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../include/Jogador.hpp"
#include <stdexcept>

TEST_CASE("Teste de Jogador"){
    SUBCASE("Teste de inicialização"){
        Jogador jogador("Hector","AppleMan");
        
        CHECK(jogador.getNome() == "Hector");
        CHECK(jogador.getApelido() == "AppleMan");

    }
    SUBCASE("Teste da configuração das estatísticas"){
        Jogador jogador("Hector","AppleMan");
        
        jogador.setVitorias("REVERSI",8);
        jogador.setDerrotas("LIG4",3);
        jogador.adicionarVitoria("REVERSI");

        std::map<std::string, int> vitorias = jogador.getVitorias();
        std::map<std::string, int> derrotas = jogador.getDerrotas();

        CHECK(vitorias["REVERSI"] == 9);
        CHECK_THROWS_AS((jogador.setVitorias("VELHA",-9)),std::invalid_argument);
        CHECK(vitorias["LIG4"] == 0);
        CHECK(derrotas["LIG4"] == 3);
        
    }
}