#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../include/Cadastro.hpp"
#include <fstream>
#include <sstream>

TEST_CASE("Teste do Sistema de Cadastro") {
    // Cria uma instância do sistema de cadastro
    Cadastro sistema;

    // Define um arquivo temporário para o teste
    const std::string arquivoTeste = "teste_logs_jogadores.txt";
    sistema.setArquivo(arquivoTeste); // Configura o arquivo temporário

    // Garante que o arquivo temporário esteja vazio antes do teste
    std::ofstream limparArquivo(arquivoTeste);
    limparArquivo.close();

    SUBCASE("Persistência em arquivo") {
        // Cadastra um jogador
        sistema.cadastrarJogador("Jhonantan", "jhon");
        CHECK(sistema.getJogadores().size() == 1); // Verifica se o jogador foi cadastrado

        // Salva os dados no arquivo
        CHECK(sistema.salvarEmArquivo()); // Verifica se o salvamento foi bem-sucedido

        // Cria uma nova instância do sistema para testar o carregamento
        Cadastro sistema2;
        sistema2.setArquivo(arquivoTeste); // Configura o mesmo arquivo temporário
        CHECK(sistema2.carregarDeArquivo()); // Verifica se o carregamento foi bem-sucedido

        // Verifica se o jogador foi carregado corretamente
        CHECK(sistema2.getJogadores().size() == 1);
        const Jogador& jogadorCarregado = sistema2.getJogadores().at("jhon");
        CHECK(jogadorCarregado.getNome() == "Jhonantan");
        CHECK(jogadorCarregado.getApelido() == "jhon");
    }

    // Remove o arquivo temporário após o teste
    std::remove(arquivoTeste.c_str());
}

