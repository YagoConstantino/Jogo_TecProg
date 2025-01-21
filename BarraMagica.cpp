#include "BarraMagica.h"
#include "Constantes.h"
Entidades::BarraMagica::BarraMagica(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra)
	:Obstaculo(inicialX,inicialY,pgra), _duracaoParalisia(Constantes::DURACAO_PARALISIA)
{
	setTipo(Constantes::TIPO_BARRA_MAGICA);
	// Gerenciador grafico
	//_pGraf = pgra; não precisa fazer isso aqui,é inicializado lá no Ente, basta chamar a construtura de Obstaculo
	// que a cadeia de construtoras garante a inicialização

	// Imagem do obstaculo
	sf::Texture* textura = _pGraf->getTextura("BarraMagica");

	/*
	if (!textura->loadFromFile("assets/BarreiraEletrica.png")) {
		std::cout << "Falha ao carregar textura!" << std::endl;
	}

	*/
	setTexture(textura);
	_body.setScale(1.f, 1.f);

	// Posicao
	setPositionX(inicialX);
	setPositionY(inicialY);
	_body.setPosition(Position);

	_segundos = 0;
	_danoso = true;
}

Entidades::BarraMagica::~BarraMagica() {
	_pGraf = nullptr;
	_danoso = false;

	if (_pTexture)
	{
		delete _pTexture;
	}
	_pTexture = nullptr;
}

void Entidades::BarraMagica::executar() {
	desenhar();
}

void Entidades::BarraMagica::obstacular(Entidades::Jogador* pJog) 
{
	if (pJog == nullptr) 
	{
		std::cerr << "Erro ao acessar ponteiro jogador.\n";
		return;
	}

	sf::FloatRect JogBounds = pJog->getBody().getGlobalBounds();
	sf::FloatRect ObsBound = getBody().getGlobalBounds();

	if (JogBounds.top + JogBounds.height <= ObsBound.top + 5.f)
	{
		//Para paralisar e depois pular acho que teriamos que ter um booleano firstTimeOnTop, se for a primeira vez ele paralisa
		//Se for a segunda vez ele pular inves de paralisar
		if (!pJog->getParalisado())
			pJog->pular();
	}
	else
	{
		pJog->setParalisado(true, _duracaoParalisia);
	}
	

	//pJog->setParalisado(true, _duracaoParalisia);
}



