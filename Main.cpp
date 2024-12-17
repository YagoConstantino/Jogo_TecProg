#include <SFML/Graphics.hpp>
#include <iostream>
#include "ListaTemplate.h"
#include "Lista.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include "Plataforma.h"
#include "Gerenciador_Colisoes.h"
#include "Obst_Dificil.h"
#include "Obst_Medio.h"
#include "InimigoFacil.h"


using namespace std;

int main()
{
   
    Gerenciadores::Gerenciador_Grafico* gg = new Gerenciadores::Gerenciador_Grafico();
    sf::Event event;
    Listas::ListaEntidades Lista;
    
    Entidades::Jogador* jog = new Entidades::Jogador(10.f, 10.f, gg,"Player");
    Entidades::Projetil *pro = new Entidades::Projetil(1, 1.5f, gg);

    
    Entidades::Plataforma *plat = new Entidades::Plataforma (5, 680, gg, 10);
    Entidades::Plataforma *plat2 = new Entidades::Plataforma(5+plat->getBody().getGlobalBounds().width, 680, gg, 10);
    Entidades::Plataforma *plat4 = new Entidades::Plataforma(plat->getPositionX() + plat->getBody().getGlobalBounds().width, 480, gg, 10);
    Entidades::Plataforma *plat5 = new Entidades::Plataforma(plat->getPositionX() + plat->getBody().getGlobalBounds().width * 1.2f, 280, gg, 10);
    
    Entidades::Obst_Dificil *obs = new Entidades::Obst_Dificil(1,plat2->getPositionX() + plat->getBody().getGlobalBounds().width, 680, gg);
    Entidades::Obst_Medio *obsMe = new Entidades::Obst_Medio(plat->getPositionX() + plat->getBody().getGlobalBounds().width * 1.4f, 400, gg);
    Entidades::Plataforma *plat3 = new Entidades::Plataforma(obs->getPositionX() + obs->getBody().getGlobalBounds().width, 680, gg, 10);
   
    Entidades::InimigoFacil *inimigo = new Entidades::InimigoFacil (500, 630, gg, jog,5);


    Lista.insert_back(static_cast<Entidades::Entidade*>(jog));
    Lista.insert_back(static_cast<Entidades::Entidade*>(pro));
    Lista.insert_back(static_cast<Entidades::Entidade*>(plat));
    Lista.insert_back(static_cast<Entidades::Entidade*>(plat2));
    Lista.insert_back(static_cast<Entidades::Entidade*>(plat3));

    Lista.insert_back(static_cast<Entidades::Entidade*>(plat4));
    Lista.insert_back(static_cast<Entidades::Entidade*>(plat5));

    Lista.insert_back(static_cast<Entidades::Entidade*>(obs));
    Lista.insert_back(static_cast<Entidades::Entidade*>(obsMe));
    Lista.insert_back(static_cast<Entidades::Entidade*>(inimigo));
    Lista.percorrer();

    Gerenciadores::Gerenciador_Colisoes* gc = new Gerenciadores::Gerenciador_Colisoes(0.005f);
    //Poderiamos converter explicitamente para obstaculo
    gc->incluirObstaculo(plat);
    gc->incluirObstaculo(plat2);
    gc->incluirObstaculo(plat3);

    gc->incluirObstaculo(plat4);
    gc->incluirObstaculo(plat5);
    gc->incluirObstaculo(obs);
    gc->incluirObstaculo(obsMe);
    gc->setJogador1(jog);
    gc->incluirInimigo(inimigo);
    cout << jog->getNome() << endl;

    while (gg->getOpen() )
    {
        while (gg->getWindow()->pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
            {
                gg->closeWindow();
            }
            
        }

        gg->render();
        gc->executar();
        Lista.executar();
        
        
        gg->display();

        //cout << jog->getVidas();
        
    }

}