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
        std::map<std::string,int> getVitorias() const;
        std::map<std::string,int> getDerrotas() const;
        
        // Para carregar numero de vitorias de arquivo
        // e defini-lo para o jogador no respectivo jogo
        void setVitorias(std::string jogo, int numVitorias);
        void setDerrotas(std::string jogo, int numDerrotas);

        void adicionarVitoria(const std::string& jogo);
        void adicionarDerrota(const std::string& jogo);
        void mostrarEstatisticas() const;
};

#endif