#include "MenuPause.h"

#define TAMANHO_BOTOES 50

Menus::MenuPause::MenuPause(Gerenciadores::Gerenciador_Grafico* _pGraf, sf::Sprite* imgFase) : Entidades::Ente(_pGraf), _imagemFase(imgFase), _houveClique(false), _mudouEstado(false)
{
	carregarFonte();

	criarImagemFase();
	criarImagemPause();
	criarTitulo();
	criarBotoes();
}

Menus::MenuPause::~MenuPause()
{
	_imagemFase = nullptr;
}

void Menus::MenuPause::carregarFonte()
{
	if (!_fonte.loadFromFile("assets/fontes/EnglishTowne.ttf")) {
		std::cerr << "Erro ao incluir fonte.\n";
		return;
	}
}

void Menus::MenuPause::criarImagemFase()
{
	_imagemFase->setColor(sf::Color(128, 128, 128));
}

void Menus::MenuPause::criarImagemPause()
{
	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/menu/menuPause.jpg")) {
		std::cerr << "Erro ao criar background menu de pause.\n";
		return;
	}
	setTexture(textura);

	// tamanho do background
	sf::Vector2u tamJanela = _pGraf->getWindow()->getSize();
	float escalaX = ((float)tamJanela.x / 2.f) / _body.getGlobalBounds().width;
	float escalaY = (float)tamJanela.y / _body.getGlobalBounds().height;

	_body.setScale
	(
		escalaX,
		escalaY
	);
}

void Menus::MenuPause::criarTitulo()
{
	sf::FloatRect tamImagemPause = _body.getGlobalBounds();
	sf::FloatRect tamTexto;

	// Caracteristicas do conteudo
	_titulo.setFont(_fonte);
	_titulo.setString("Pausado");
	_titulo.setCharacterSize(TAMANHO_BOTOES + 10);
	_titulo.setStyle(sf::Text::Style::Regular);
	_titulo.setFillColor(sf::Color::White);

	// Posicao
	tamTexto = _titulo.getGlobalBounds();

	sf::Vector2f posicao;
	posicao.x = ((float)tamImagemPause.height / 2.f) - ((float)tamTexto.width / 2.f);
	posicao.y = (float)tamImagemPause.width / 10.f;

	_titulo.setPosition(posicao);
}

void Menus::MenuPause::criarBotoes()
{
	sf::FloatRect tamImagemPause = _body.getGlobalBounds();
	sf::FloatRect tamTexto;
	sf::Vector2f posicao;

	// ------ >> Cria o botao de retomar

	// Caracteristicas do conteudo
	_botaoRetomar.setFont(_fonte);
	_botaoRetomar.setString("Retomar");
	_botaoRetomar.setCharacterSize(TAMANHO_BOTOES - 10);
	_botaoRetomar.setStyle(sf::Text::Style::Regular);
	_botaoRetomar.setFillColor(sf::Color::White);


	// Posicao
	tamTexto = _botaoRetomar.getGlobalBounds();

	posicao.x = ((float)tamImagemPause.width / 2.f) - ((float)tamTexto.width / 2.f);
	posicao.y = (float)tamImagemPause.height / 10.f * 5.f;

	_botaoRetomar.setPosition(posicao);

	// ------ >> Cria o botao de Salvar e sair

	// Caracteristicas do conteudo
	_botaoSalvarSair.setFont(_fonte);
	_botaoSalvarSair.setString("Salvar e sair");
	_botaoSalvarSair.setCharacterSize(TAMANHO_BOTOES - 10);
	_botaoSalvarSair.setStyle(sf::Text::Style::Regular);
	_botaoSalvarSair.setFillColor(sf::Color::White);


	// Posicao
	tamTexto = _botaoRetomar.getGlobalBounds();

	posicao.x = ((float)tamImagemPause.width / 2.f) - ((float)tamTexto.width / 2.f);
	posicao.y = (float)tamImagemPause.height / 10.f * 6.5f;

	_botaoSalvarSair.setPosition(posicao);
}

void Menus::MenuPause::verificarMouse()
{
	_houveClique = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	verificarMovimento();
}

void Menus::MenuPause::verificarMovimento()
{
	sf::Vector2i posicaoMouse = _mouse.getPosition();

	// Verifica onde o mouse esta e destaca o botao
	if (_botaoRetomar.getGlobalBounds().contains((float)posicaoMouse.x, (float)posicaoMouse.y)) {
		destacarTexto(_botaoRetomar);

		if (_houveClique)
			executarRetomar();
	}
	else {
		padronizar(_botaoRetomar);
	}

	if (_botaoSalvarSair.getGlobalBounds().contains((float)posicaoMouse.x, (float)posicaoMouse.y)) {
		destacarTexto(_botaoSalvarSair);

		if (_houveClique)
			executarSalvarSair();
	}
	else {
		padronizar(_botaoSalvarSair);
	}
}

void Menus::MenuPause::destacarTexto(sf::Text& texto)
{
	char c = *(texto.getString().begin());
	if (c != '>') {
		std::string frase = "> " + texto.getString() + " <";
		texto.setCharacterSize(TAMANHO_BOTOES + 10);
		texto.setString(frase);
		texto.setStyle(sf::Text::Style::Underlined);

		// Reposiciona no meio da janela
		reposicionarTexto(texto);
	}
}

void Menus::MenuPause::reposicionarTexto(sf::Text& texto)
{
	sf::FloatRect tamImagemPause = _body.getGlobalBounds();
	sf::FloatRect tamTexto = texto.getGlobalBounds();

	sf::Vector2f posicao;
	posicao.x = ((float)tamImagemPause.width / 2.f) - ((float)tamTexto.width / 2.f);
	posicao.y = texto.getPosition().y;

	texto.setPosition(posicao);
}

void Menus::MenuPause::padronizar(sf::Text& texto)
{
}

void Menus::MenuPause::executarRetomar()
{
}

void Menus::MenuPause::executarSalvarSair()
{
}

void Menus::MenuPause::desenharMenu()
{
}

void Menus::MenuPause::executar()
{
}
