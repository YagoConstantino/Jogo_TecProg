#include <SFML/Graphics.hpp>
#include <iostream>
#include "ListaTemplate.h"
#include "Lista2.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Plataforma.h"
#include "Gerenciador_Colisoes.h"


using namespace std;
class Pessoa
{
private:
    string nome;
public:
    Pessoa(const string& name = " ") :nome(name) {};
    ~Pessoa() {};
    void imprime()const{ cout << "Nome :" << nome << endl; }
};

int main()
{
    Pessoa* p1 = new Pessoa("Yago");
    Pessoa* p2 = new Pessoa("Joao");
    Pessoa* p3 = new Pessoa("Ana");
    Lista<Pessoa>* l1 = new Lista<Pessoa>();
    l1->insert_back(p1);
    l1->insert_back(p2);
    l1->insert_back(p3);
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        (*l1)[i]->getInfo()->imprime();
    }

    Listas::ListaElementar<Pessoa>* l2 = new Listas::ListaElementar<Pessoa>();
    l2->insert_back(p1);
    l2->insert_back(p2);
    l2->insert_back(p3);

    for (i = 0; i < 3; i++)
    {
        (*l2)[i]->getInfo()->imprime();
    }

    
    Gerenciadores::Gerenciador_Grafico* gg = new Gerenciadores::Gerenciador_Grafico();
    sf::Event event;
    Listas::ListaEntidades Lista;
    
    Entidades::Jogador* jog = new Entidades::Jogador(10.f, 10.f, gg,"Player");
    Entidades::Projetil pro(1, 1.5f, gg);

    
    Entidades::Plataforma plat(5, 680, gg, 10);
    Entidades::Plataforma plat2(5+plat.getBody().getGlobalBounds().width, 680, gg, 10);
    Entidades::Plataforma plat3(plat2.getPositionX()+plat.getBody().getGlobalBounds().width, 680, gg, 10);
    Entidades::Plataforma plat4(plat3.getPositionX() + plat.getBody().getGlobalBounds().width, 680, gg, 10);
   // plat.setPositionX(plat.getPositionX() - (plat.getBody().getGlobalBounds().width) / 2);

    Lista.insert_back(static_cast<Entidades::Entidade*>(jog));
    Lista.insert_back(static_cast<Entidades::Entidade*>(&pro));
    Lista.insert_back(static_cast<Entidades::Entidade*>(&plat));
    Lista.insert_back(static_cast<Entidades::Entidade*>(&plat2));
    Lista.insert_back(static_cast<Entidades::Entidade*>(&plat3));
    Lista.insert_back(static_cast<Entidades::Entidade*>(&plat4));
    Lista.percorrer();

    Gerenciadores::Gerenciador_Colisoes* gc = new Gerenciadores::Gerenciador_Colisoes(0.5f);
    gc->incluirObstaculo(&plat);
    gc->incluirObstaculo(&plat2);
    gc->incluirObstaculo(&plat3);
    gc->incluirObstaculo(&plat4);
    gc->setJogador1(jog);

    while (gg->getWindow()->isOpen()) 
    {
        while (gg->getWindow()->pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
            {
                gg->getWindow()->close();
            }
            
        }
        gg->render();
        Lista.executar();
        gc->executar();
        gg->display();
    }

}