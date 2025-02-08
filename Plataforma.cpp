#include "Plataforma.h"
#include "Constantes.h"
Entidades::Plataforma::Plataforma(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra, float alt)
	:Obstaculo(inicialX,inicialY,pgra),altura(alt)
{
	setTipo(Constantes::TIPO_PLATAFORMA);
	sf::Texture* textura = _pGraf->getTextura("Plat");

	/*
	if (!textura->loadFromFile("assets/TerrenoComFundo.png")) {
		std::cout << "Falha ao carregar textura!" << std::endl;
	}
	*/

	setTexture(textura);
	_body.setScale(1.3f,0.3f);
	desenhar();
}

Entidades::Plataforma::~Plataforma()
{
}

void Entidades::Plataforma::executar()
{
	desenhar();
}

void Entidades::Plataforma::obstacular(Entidades::Jogador* pJog)
{
	/*float novaPosicao = pJog->getPositionX();
	pJog->setPositionX(novaPosicao-10);*/
	executar();
}

void Entidades::Plataforma::SalvarDataBuffer(std::ofstream& arquivo)
{
	try
	{
		arquivo.open("Salvamento.txt", std::ios::app);
		if (!arquivo.is_open())
		{
			throw std::runtime_error("Erro ao abrir o arquivo para escrita.");
		}

		arquivo << buffer.str();

		arquivo.close();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exceção em salvarDados: " << e.what() << std::endl;
	}
}

void Entidades::Plataforma::registraDados()
{
	Entidades::Obstaculo::registraDados();
	buffer << "\n";
}


