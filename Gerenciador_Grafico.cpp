#include "Gerenciador_Grafico.h"
#include "Ente.h"

Gerenciadores::Gerenciador_Grafico::Gerenciador_Grafico() 
{
    window = new sf::RenderWindow(sf::VideoMode(1200, 800), "Jogo");
    view = sf::View(sf::FloatRect(0, 0, 1200, 800));
}

Gerenciadores::Gerenciador_Grafico::~Gerenciador_Grafico() {}



void Gerenciadores::Gerenciador_Grafico::desenhar(Entidades::Ente* pE)
{
    if (pE)
    {
        window->draw(pE->getBody());
    }
}

void Gerenciadores::Gerenciador_Grafico::render()
{
    window->clear();
}

void Gerenciadores::Gerenciador_Grafico::display() 
{
    window->display();
}

sf::RenderWindow* Gerenciadores::Gerenciador_Grafico::getWindow() 
{
    return window;
}
