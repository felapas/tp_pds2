#ifndef CADASTRO_H
#define CADASTRO_H

#include "Jogador.hpp"
#include <iostream>

class Cadastro{
    private:
        std::map<std::string, Jogador> _jogadores;
        const std::string _arquivo = "./gamedata/logs_jogadores.txt";
    public:

        void cadastrarJogador(const std::string& nome, const std::string& apelido);
        bool removerJogador(const std::string& apelido);
        void listarJogadores();

    
        std::map<std::string, Jogador>& getJogadores();


        //Controle de arquivo
        bool salvarEmArquivo();
        bool carregarDeArquivo();
};

#endif