#include <iostream>


class Jogador {
    private:
        std::string nome;
        std::string apelido;
        int vitorias;
        int derrotas;

    public:
        Jogador(const std::string& nome, const std::string& apelido);

        std::string getNome() const;
        std::string getApelido() const;
        void adicionarVitoria(const std::string& jogo);
        void adicionarDerrota(const std::string& jogo);
        void mostrarEstatisticas() const;
};