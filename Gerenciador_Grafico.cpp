#include "Gerenciador_Grafico.h"
#include "Ente.h"

//Inicio o atributo statico como nullptr
Gerenciadores::Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::instancia = nullptr;

Gerenciadores::Gerenciador_Grafico::Gerenciador_Grafico() 
{
    window = new sf::RenderWindow(sf::VideoMode(900, 600), "Jogo", sf::Style::Fullscreen);
    view = sf::View(sf::FloatRect(0, 0, 900, 600));
    
}

//Metodo do Singleton, se ja existir um gerenciador statico ele retorna o mesmo para manter 1, se nao ele instancia um novo
Gerenciadores::Gerenciador_Grafico* Gerenciadores::Gerenciador_Grafico::getInstancia() 
{
    if (instancia == nullptr) {
        instancia = new Gerenciador_Grafico();
    }
    return instancia;
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

void Gerenciadores::Gerenciador_Grafico::desenhar(sf::Text* texto)
{
    if(texto)
    window->draw(*texto);
}

void Gerenciadores::Gerenciador_Grafico::desenhar(sf::Sprite* sprt)
{
    if (sprt)
    {
        window->draw(*sprt);
    }
}

/*void Gerenciadores::Gerenciador_Grafico::desenhar(sf::RectangleShape& shape)
{
    window->draw(shape);
}*/

void Gerenciadores::Gerenciador_Grafico::clear()
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
