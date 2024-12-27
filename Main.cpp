#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "ListaTemplate.h"
#include "Lista.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Plataforma.h"
#include "Gerenciador_Colisoes.h"
#include "Espinho.h"
#include "BarraMagica.h"
#include "Cavaleiro.h"
#include "Mago.h"
#include "Floresta.h"
#include "Jogo.h"


using namespace std;

class Pessoa {
private:
    std::string nome;
    int idade;

public:
    Pessoa(const string& nome, int idade) : nome(nome), idade(idade) {}

    ~Pessoa(){}

   
    string getNome() const { return nome; }
    int getIdade() const { return idade; }

    
    void imprimir() const 
    {
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};

int main()
{
   /* Listas::ListaElementar<Pessoa> lista;

    // Criando objetos Pessoa e adicionando à lista
    lista.insert_back(new Pessoa("Alice", 25));
    lista.insert_back(new Pessoa("Bruno", 30));
    lista.insert_back(new Pessoa("Carla", 20));

    // Usando o iterador para percorrer a lista
    Listas::ListaElementar<Pessoa>::Iterator* it = lista.getIterator();
    while (it->hasPNext()) {
        Pessoa* pessoa = it->Atual();
        pessoa->imprimir();
    }

    delete it; // Libera o iterador

    return 0;*/
    srand(static_cast<unsigned>(time(nullptr)));

    Jogo* principal = new Jogo();
    principal->criarJogador1("Player1");
    principal->criarJogador2("Player4");
    principal->executar();

    return 0;
}