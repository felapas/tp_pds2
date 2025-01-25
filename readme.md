# 🎮 Trabalho Prático PDS2 - Sistema de Jogos

[![C++ Version](https://img.shields.io/badge/C%2B%2B-11-blue.svg)](https://en.cppreference.com/w/cpp/11)  
[![License](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)  
[![Documentation](https://img.shields.io/badge/Docs-Doxygen-blueviolet)](https://seusite.com/docs)

Sistema completo para gerenciamento de jogadores e execução de jogos clássicos, desenvolvido em C++11 com documentação Doxygen.

<p align="center">
  <img src="https://imgur.com/BGipuFX" alt="Menu Do Jogo">
</p>

## 📋 Tabela de Conteúdos

- [✨ Funcionalidades](#-funcionalidades)
- [🏗️ Arquitetura do Sistema](#%EF%B8%8F-arquitetura-do-sistema)
- [🛠️ Instalação e Uso](#%EF%B8%8F-instalação-e-uso)
- [📚 Documentação](#-documentação)
- [🎯 Dificuldades e Soluções](#-dificuldades-e-soluções)
- [📄 Licença](#-licença)

## ✨ Funcionalidades

### 🧑💻 Sistema de Jogadores

- Cadastro/remoção de jogadores com apelido único.
- Listagem detalhada com estatísticas por jogo.
- Persistência em arquivo texto.

### 🎲 Jogos Implementados

| Jogo          | Tabuleiro | Modo de Vitória                         | Características Especiais    |
| ------------- | --------- | --------------------------------------- | ---------------------------- |
| Jogo da Velha | 3x3       | Linha/Coluna/Diagonal                   | Detecção de empate           |
| Connect4      | Variável  | 4 em linha vertical/horizontal/diagonal | Sistema de colunas           |
| Reversi       | 8x8       | Contagem de peças                       | Mecânica de captura de peças |

### 📊 Estatísticas

- Histórico individual por jogador.
- Vitórias/derrotas por tipo de jogo.

## 🏗️ Arquitetura do Sistema

```plaintext
📦 TP_PDS2
├── 📂 include
│   ├── Cadastro.hpp           # Gerenciamento de jogadores (cabeçalho)
│   ├── Tabuleiro.hpp          # Interface base de tabuleiro (cabeçalho)
│   ├── Jogo.hpp               # Interface base para jogos (cabeçalho)
│   ├── GerenciadorDeJogos.hpp # Controlador principal (cabeçalho)
│   ├── Jogo_Da_Velha.hpp      # Implementação do Jogo Da Velha (cabeçalho)
│   ├── Reversi.hpp            # Implementação do Reversi (cabeçalho)
│   └── Connect4.hpp           # Implementação do Connect 4 (cabeçalho)
├── 📂 src
│   ├── Cadastro.cpp           # Gerenciamento de jogadores (implementação)
│   ├── Tabuleiro.cpp          # Interface base de tabuleiro (implementação)
│   ├── Jogo.cpp               # Interface base para jogos (implementação)
│   ├── GerenciadorDeJogos.cpp # Controlador principal (implementação)
│   ├── Jogo_Da_Velha.cpp      # Implementação do Jogo Da Velha (implementação)
│   ├── Reversi.cpp            # Implementação do Reversi (implementação)
│   ├── Connect4.cpp           # Implementação do Connect 4 (implementação)
│   └── main.cpp               # Executor do programa
├── 📂 gamedata
│   └── logs_jogadores.txt     # Banco de dados de jogadores
├── 📂 bin
│   └── main.exe               # Executável
├── Makefile                   # Instruções de compilação
```

## 🛠️ Instalação e Uso

### Requisitos

- Compilador C++11 (g++ ou Clang).
- Doxygen (para documentação).
- Make (opcional, facilita compilação).

### Compilação

```bash
git clone https://github.com/mateusacq/tp_pds2
make all
```

### Execução

```bash
./bin/main
```

### Gerar Documentação

```bash
doxygen Doxyfile
# Acesse docs/html/index.html
```

## 📚 Documentação

[🔗 Acesse a Documentação Completa](https://aindanaotemkkkk.com/docs)

## 🎯 Dificuldades e Soluções

| Desafio                        | Solução Implementada          | Tecnologia Utilizada |
| ------------------------------ | ----------------------------- | -------------------- |
| Persistência de dados          | Serialização em arquivo texto | Streams C++          |
| Validação de jogadas complexas | Padrão Strategy               | Polimorfismo         |
| Interface genérica para jogos  | Classe base abstrata          | Herança em C++       |

## 📄 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

---

**Desenvolvido por Felipe Damasceno, Caio Onofre, Mateus Antinossi e Emmanuel Figueiredo**
