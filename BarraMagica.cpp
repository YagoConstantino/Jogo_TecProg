#include "BarraMagica.h"

Entidades::BarraMagica::BarraMagica(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra)
	:Obstaculo(inicialX,inicialY,pgra), _duracaoParalisia(8000.f)
{

	// Gerenciador grafico
	//_pGraf = pgra; não precisa fazer isso aqui,é inicializado lá no Ente, basta chamar a construtura de Obstaculo
	// que a cadeia de construtoras garante a inicialização

	// Imagem do obstaculo
	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/BarreiraEletrica.png")) {
		std::cout << "Falha ao carregar textura!" << std::endl;
	}
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

void Entidades::BarraMagica::obstacular(Entidades::Jogador* pJog) {
	if (pJog == nullptr) {
		std::cerr << "Erro ao acessar ponteiro jogador.\n";
		return;
	}

	pJog->setParalisado(true, _duracaoParalisia);
}



