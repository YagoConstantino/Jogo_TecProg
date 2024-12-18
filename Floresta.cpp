#include "Floresta.h"

Fases::Floresta::Floresta(Gerenciadores::Gerenciador_Grafico* pgra, Entidades::Jogador* jog)
    :Fase(pgra,jog)
{
    
    _Lista->insert_back(static_cast<Entidades::Entidade*>(_jog));
    _GC->setJogador1(jog);
}

Fases::Floresta::~Floresta()
{
    //Desaloco o Gerenciador de Colisoes e a ListaEntidades
    if (_GC)
        delete _GC;

    if (_Lista)
        delete _Lista;

    //Seto como nulo os ponteiros para o Gerenciador gráfico e jogador
    _GG = nullptr;
    _jog = nullptr;
}

void Fases::Floresta::criaBarrasMagicas()
{
}

void Fases::Floresta::criaBruxas()
{
}

void Fases::Floresta::executar()
{
    criarInimigos();
    criarObstaculos();


    sf::Event event;
    while (_GG->getOpen())
    {
        while (_GG->getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                _GG->closeWindow();
            }

        }

        _GG->render();
        _GC->executar();
       _Lista->executar();

        _GG->display();
    }

}

void Fases::Floresta::criarInimigos()
{
    criarCavaleiros();
}

void Fases::Floresta::criarObstaculos()
{
    criarPlataformas();
}
