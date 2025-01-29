#include "GerenciadorDeJogos.hpp"

// Construtor do sistema de cadastro
GerenciadorDeJogos::GerenciadorDeJogos(Cadastro& cadastro) : cadastro(cadastro), jogador1(nullptr), jogador2(nullptr) {}

// Seleciona os jogadores para a partida
bool GerenciadorDeJogos::selecionarJogadores() {
    std::string apelido1, apelido2;
    std::cout << "Digite o apelido do jogador 1: ";
    std::cin >> apelido1;
    std::cout << "Digite o apelido do jogador 2: ";
    std::cin >> apelido2;

    std::map<std::string, Jogador>& jogadores = cadastro.getJogadores();

    // Verifica se os jogadores existem no cadastro
    if (jogadores.find(apelido1) != jogadores.end() && jogadores.find(apelido2) != jogadores.end()) {
        jogador1 = &jogadores[apelido1];
        jogador2 = &jogadores[apelido2];
        return true;
    } else {
        std::cout << "Um ou ambos os jogadores não foram encontrados no cadastro! Retornando ao Menu:" << std::endl
        << "----------------------------------------------------------" << std::endl << "MENU:" << std::endl
        << "[CJ] - cadastrar um jogador" <<std::endl << "[RJ] - remover um jogador" <<std::endl
        << "[LJ] - listar jogadores" <<std::endl << "[EP] - escolher outro jogo para jogar!" <<std::endl
        << "[FS] - finalizar o programa" << std::endl
        << "----------------------------------------------------------" << std::endl;

        return false;
    }
}

// Executa o jogo escolhido e atualiza estatísticas
void GerenciadorDeJogos::executarJogo(Jogo* jogo, const int& opcao) {
    if (!jogador1 || !jogador2) {
        std::cout << "Jogadores não selecionados! Selecione jogadores antes de iniciar o jogo." << std::endl;
        return;
    }

    if (opcao == 1) 
        jogo = new JogoDaVelha;
    if (opcao == 2) 
        jogo = new Connect4;
    if (opcao == 3) 
        jogo = new Reversi;

    jogo->iniciar();
    while (true) {
        jogo->exibirTabuleiro();
        int linha, coluna;

        if ( (opcao == 1) || (opcao == 3) ) {
            do {
                jogo->lerJogada(linha, coluna);
            } while (!jogo->validarJogada(linha, coluna));
        } else if (opcao == 2) { // Lê jogadas do Connect4, que são uma coluna apenas
            do {
                jogo->lerJogada(coluna);
            } while (!jogo->validarJogada(coluna));
        }

        int resultado = jogo->validarVitoria();
        if (resultado == 1) {
            jogo->exibirTabuleiro();
            // Atualiza estatísticas do vencedor e do perdedor
            if (opcao == 1) {
                std::string vencedorApelido = (jogo->getJogadorAtual() == 2) ? jogador1->getApelido() : jogador2->getApelido();
                atualizarEstatisticas(vencedorApelido, "VELHA");
            } else if (opcao == 2) {
                std::string vencedorApelido = (jogo->getJogadorAtual() == 2) ? jogador1->getApelido() : jogador2->getApelido();
                atualizarEstatisticas(vencedorApelido, "LIG4");
            } else if (opcao == 3) {
                std::string vencedorApelido = (jogo->getJogadorAtual() == 2) ? jogador2->getApelido() : jogador1->getApelido();
                atualizarEstatisticas(vencedorApelido, "REVERSI"); // Pega o apelido do jogador com mais peças
            }
            break;
        } else if (resultado == 2) {
            jogo->exibirTabuleiro();
            std::cout << "Empate!" << std::endl;
            std::cout << "Estatísticas mantidas!\nO que você deseja fazer agora?" << std::endl
            << "----------------------------------------------------------" << std::endl << "MENU:" << std::endl
            << "[CJ] - cadastrar um jogador" <<std::endl << "[RJ] - remover um jogador" <<std::endl
            << "[LJ] - listar jogadores" <<std::endl << "[EP] - escolher outro jogo para jogar!" <<std::endl
            << "[FS] - finalizar o programa" << std::endl
            << "----------------------------------------------------------" << std::endl;
            break;
        }
    }
}

// Atualiza as estatísticas do vencedor e do perdedor
void GerenciadorDeJogos::atualizarEstatisticas(const std::string& vencedorApelido, const std::string& jogo) {
    if (jogador1->getApelido() == vencedorApelido) {
        jogador1->adicionarVitoria(jogo);
        jogador2->adicionarDerrota(jogo);
    } else {
        jogador2->adicionarVitoria(jogo);
        jogador1->adicionarDerrota(jogo);
    }
        
    std::cout << "Estatísticas atualizadas!\nO que você deseja fazer agora?" << std::endl
    << "----------------------------------------------------------" << std::endl << "MENU:" << std::endl
    << "[CJ] - cadastrar um jogador" <<std::endl << "[RJ] - remover um jogador" <<std::endl
    << "[LJ] - listar jogadores" <<std::endl << "[EP] - escolher outro jogo para jogar!" <<std::endl
    << "[TM] - escolher um tema" << std::endl<< "[FS] - finalizar o programa" << std::endl
    << "----------------------------------------------------------" << std::endl;
}