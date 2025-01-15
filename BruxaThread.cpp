#include "BruxaThread.h"

Entidades::BruxaThread::BruxaThread(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra,
	Entidades::Jogador* pJog1, Entidades::Jogador* pJog2, int vidas)
	:Bruxa(inicialX, inicialY, pgra, pJog1, pJog2, vidas), ThreadCPP(),_rodar(false)
{
	setEhThread(true);
	sf::Texture* textura = new sf::Texture();


	if (!textura->loadFromFile("assets/MortovivoTH.png"))
	{
		std::cout << "Falha ao carregar textura!" << std::endl;
	}




	setTexture(textura);
	_body.setScale(1.f, 1.f);
}

Entidades::BruxaThread::~BruxaThread()
{
}

void Entidades::BruxaThread::setRodar(bool rod)
{
	_rodar = rod;
}

void Entidades::BruxaThread::run()
{
	while (getVivo())
	{

		if (_rodar)
		{

			lockMutex();

			double distanciaJog1 = -1;
			double distanciaJog2 = -1;

			if (_pJog1) distanciaJog1 = getDistanciaJogador1();
			if (_pJog2) distanciaJog2 = getDistanciaJogador2();

			if ((distanciaJog1 > 0 && distanciaJog1 <= 700) || (distanciaJog2 > 0 && distanciaJog2 <= 700))
			{
				atacar = true;
			}
			else
			{
				atacar = false;
			}

			if (atacar)
			{
				mover();
			}
			else
			{
				Position.y += _speed.y;
				_body.setPosition(Position);
			}

			if (_num_vidas <= 0)
			{
				setVivo(false);
			}
			unlockMutex();
			setRodar(false);
			//yield();
		}
	}
}

void Entidades::BruxaThread::executar()
{
	desenhar();
}
