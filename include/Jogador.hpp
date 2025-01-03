#ifndef JOGADOR_H
#define JOGADOR_H


#include <iostream>
#include <string>
#include <map>


class Jogador {
    private:
        std::string _nome;
        std::string _apelido;
        std::map<std::string,int> _vitorias;
        std::map<std::string,int> _derrotas;

    public:
        Jogador(const std::string& _nome, const std::string& _apelido);
        std::string getNome() const;
        std::string getApelido() const;
        void adicionarVitoria(const std::string& jogo);
        void adicionarDerrota(const std::string& jogo);
        void mostrarEstatisticas() const;
};

#endif