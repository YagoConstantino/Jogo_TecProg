#include "Jogo.h"
#include "Floresta.h"
#include <iostream>
#include <vector>
#include <utility>


Fases::Floresta::Floresta(Gerenciadores::Gerenciador_Grafico* pgra, Entidades::Jogador* jog1, Entidades::Jogador* jog2)

    :Fase(pgra,jog1,jog2),maxBruxas(5),maxBarraMagicas(4)

{

    //_Lista->insert_back(static_cast<Entidades::Entidade*>(_jog));
    //_GC->setJogador1(jog);
   
}

Fases::Floresta::~Floresta()
{
    //Seto como nulo os ponteiros para o Gerenciador gráfico e jogador
    _GG = nullptr;
    _jog1 = nullptr;
    _jog2 = nullptr;
}

void Fases::Floresta::criaBarrasMagicas()
{
    // Determinar o número de barras mágicas a serem criadas: entre 1 e 3

    int n = rand() % 4 + 1;

    // Posições centrais das plataformas 2, 4 e 6 (caso a plataforma 6 exista)
    std::vector<std::pair<float, float>> posBarras =
    {

        {468+234 , 630.f},                               // Meio da plataforma 2
        {234,450.f},                                    // Meio da plataforma 4
        {_GG->getWindow()->getSize().x - 200, 450.f},  // Meio da plataforma 3 
        {936.f, 450}
    };

    for (int i = 0; i < n; i++)
    {
        float x = posBarras[i].first;
        float y = posBarras[i].second;


        Entidades::BarraMagica* bar = new Entidades::BarraMagica(x, y, _GG);
        _GC->incluirObstaculo(static_cast<Entidades::Obstaculo*>(bar));
        _Lista->insert_back(static_cast<Entidades::Entidade*>(bar));
    }
}


void Fases::Floresta::criaBruxas()
{

    int n = rand() % 5 + 1;
    int i;
    
    std::vector<std::pair<float, float>> posicaoBruxa =
    {
        {_GG->getWindow()->getSize().x -200, 430.f},
        {_GG->getWindow()->getSize().x - 200, 700.f},
        {450.f,400.f},
        {0.f, 700.f},									
        {468.f, 700.f},

    };

    for (i = 0; i < n; i++)
    {
        float x = posicaoBruxa[i].first;
        float y = posicaoBruxa[i].second;

        Entidades::Bruxa* bru = new Entidades::Bruxa(x, y, _GG, _jog1,_jog2);
        _GC->incluirInimigo(static_cast<Entidades::Inimigo*>(bru));
        _Lista->insert_back(static_cast<Entidades::Entidade*>(bru));
    }
}

void Fases::Floresta::executar()
{

    while (!_mudouEstado) {
        sf::Event event;
        while (_GG->getWindow()->pollEvent(event)) {
            // Volta para o menu
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                Jogo::mudarStateNum(10);
                _mudouEstado = true;
            }
        }

        _GG->clear();
        _GC->executar();

        if (_jog1) 
        {
            _jog1->executar();
           
        }
        if (_jog2)
        {
            _jog2->executar();
           
        }

        _Lista->executar();
        

        //std::cout << _jog1->getPontos() << std::endl;
        _GG->display();
    }
}

void Fases::Floresta::criarInimigos()
{
    criaBruxas();
    criarCavaleiros();
}

void Fases::Floresta::criarObstaculos()
{
    criarPlataformas();
    criaBarrasMagicas();

}
