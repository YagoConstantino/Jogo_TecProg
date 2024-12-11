#include "Obst_Medio.h"

Entidades::Obst_Medio::Obst_Medio(float inicialX, float inicialY, Gerenciadores::Gerenciador_Grafico* pgra) 
	:Obstaculo(inicialX,inicialY,pgra)
{
	// Jogador
	_pJog = nullptr;

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

	// Imagem da tela paralisada
	textura2 = new sf::Texture();

	if (!textura2->loadFromFile("assets/TelaParalisada.png")) 
	{
		std::cout << "Falha ao carregar textura!" << std::endl;
	}

	telaParalisada.setTexture(*textura2);
	telaParalisada.setScale
	(
		5.0f,
		3.5f
	);

	// Posicao
	telaParalisada.setPosition(0.f, 0.f);

	_segundos = 0;
	_danoso = true;
}

Entidades::Obst_Medio::~Obst_Medio() {
	_pGraf = nullptr;
	_danoso = false;

	if (_pTexture)
	{
		delete _pTexture;
	}
	_pTexture = nullptr;

	if (textura2) 
	{
		delete textura2;
	}
	textura2 = nullptr;

	_pJog = nullptr;
}

void Entidades::Obst_Medio::executar() 
{
	desenhar();

	// tempo
	if(!_danoso) {
		_segundos += _clock.getElapsedTime().asSeconds();

		if (_segundos > 8000.f) {
			_pJog->setMover(true);

			_danoso = true;
			_segundos = 0.f;
			_clock.restart();
		}

		_pGraf->getWindow()->draw(telaParalisada);

	}
}

void Entidades::Obst_Medio::obstacular(Entidades::Jogador* pJog) {
	if (pJog == nullptr) {
		std::cerr << "Erro ao acessar ponteiro jogador.\n";
		return;
	}

	_pJog = pJog;

	if (_danoso) {
		pJog->setMover(false);

		_danoso = false;

		_clock.restart();
	}
}

void Entidades::Obst_Medio::salvar() {

}

void Entidades::Obst_Medio::render() {

}