#include "Gerenciador_Grafico.h"
#include "Ente.h"

Gerenciadores::Gerenciador_Grafico::Gerenciador_Grafico() 
{
    window = new sf::RenderWindow(sf::VideoMode(900, 600), "Jogo",sf::Style::Fullscreen);
    view = sf::View(sf::FloatRect(0, 0, 900, 600));
    
}

Gerenciadores::Gerenciador_Grafico::~Gerenciador_Grafico() 
{
    delete(window);
}

void Gerenciadores::Gerenciador_Grafico::desenhar(Entidades::Ente* pE)
{
    if (pE)
    {
        window->draw(pE->getBody());
    }
}

void Gerenciadores::Gerenciador_Grafico::desenhar(sf::RectangleShape& shape)
{
    window->draw(shape);
}

void Gerenciadores::Gerenciador_Grafico::render()
{
    window->clear();
}

void Gerenciadores::Gerenciador_Grafico::display() 
{
    window->display();
}

sf::RenderWindow* Gerenciadores::Gerenciador_Grafico::getWindow() const
{
    return window;
}

bool Gerenciadores::Gerenciador_Grafico::getOpen() const
{
    return window->isOpen();
}

void Gerenciadores::Gerenciador_Grafico::closeWindow()
{
    window->close();
}
