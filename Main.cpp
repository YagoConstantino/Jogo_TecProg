#include <SFML/Graphics.hpp>
#include <iostream>
#include "ListaTemplate.h"
#include "Lista2.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
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
    /*
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

    ListaElementar<Pessoa>* l2 = new ListaElementar<Pessoa>();
    l2->insert_back(p1);
    l2->insert_back(p2);
    l2->insert_back(p3);

    for (i = 0; i < 3; i++)
    {
        (*l2)[i]->getInfo()->imprime();
    }

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!",sf::Style::Fullscreen);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;*/

    // Criar o gerenciador gráfico
    Gerenciadores::Gerenciador_Grafico* gerenciador = new Gerenciadores::Gerenciador_Grafico();

    // Criar o jogador
    Entidades::Jogador* jogador = new Entidades::Jogador(100, 100, 50, 50, gerenciador);
    sf::Texture* textura = new sf::Texture();
   
    float speed = 5.0f;

    // Loop principal do jogo

    sf::RenderWindow* window = gerenciador->getWindow();
    sf::Event event;
    sf::RectangleShape* shape = new sf::RectangleShape();
    shape->setFillColor(sf::Color::Red);
    shape->setPosition(sf::Vector2f(20.0, 20.0));
    shape->setSize(sf::Vector2f(50.0, 50.0));
    while (window->isOpen()) 
    {
        // Processar eventos
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window->close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
            {
                shape->move(0.0f, -speed); // Mover para cima
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
            {
                shape->move(-speed, 0.0f); // Mover para a esquerda
            }
            else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
            {
                shape->move(0.0f, speed); // Mover para baixo
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
            {
                shape->move(speed, 0.0f); // Mover para a direita
            }

        }

        

        // Renderizar a cena
        gerenciador->render();
        gerenciador->desenhar(jogador); // Desenhar o jogador
        gerenciador->getWindow()->draw(*shape);
        gerenciador->display();
    }
}