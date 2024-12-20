#include "Menu.h"

#define TAMANHO_TITULO 145
#define TAMANHO_BOTOES 50

/*
	IMPORTANTE:
	Botao Jogar é o 1
	Botao Ranking é o 2
	Botao Sair é o 3
*/

Menu::Menu(Gerenciadores::Gerenciador_Grafico* _pGraf) : Entidades::Ente(_pGraf), _botoes(), _textosBotoes(), stateNum(10)
{
	_botoes.clear();
	_textosBotoes.clear();

	carregarFonte();
	criarBackground();
	criarTitulo();
	criarBotoes();

	_funcoesBotoes[1] = [this]() { executarJogar(); };
	_funcoesBotoes[2] = [this]() { executarRanking(); };
	_funcoesBotoes[3] = [this]() { executarSair(); };
}

Menu::~Menu()
{
	_pGraf = nullptr;

	_botoes.clear();
	_textosBotoes.clear();
}

void Menu::carregarFonte()
{
	if (!_fonte.loadFromFile("assets/fontes/EnglishTowne.ttf")) {
		std::cerr << "Erro ao  incluir fonte.\n";
		return;
	}
}

void Menu::criarBotoes()
{
	// --------- >> Botao Jogar

	// Caracteristicas do conteudo
	_textosBotoes.push_back("Jogar");
	_botoes[1].setFont(_fonte);
	_botoes[1].setString("Jogar");
	_botoes[1].setCharacterSize(TAMANHO_BOTOES);
	_botoes[1].setStyle(sf::Text::Style::Regular);
	_botoes[1].setFillColor(sf::Color::White);
	

	// Posicao
	sf::Vector2u tamJanela = _pGraf->getWindow()->getSize();
	sf::FloatRect tamTexto = _botoes[1].getGlobalBounds();

	sf::Vector2f posicao;
	posicao.x = ((float)tamJanela.x / 2.f) - (tamTexto.width / 2.f);
	posicao.y = (float)tamJanela.y / 10.f * 3.f;

	_botoes[1].setPosition(posicao);

	// --------- >> Botao Ranking

	// Caracteristicas do conteudo
	_textosBotoes.push_back("Ranking");
	_botoes[2].setFont(_fonte);
	_botoes[2].setString("Ranking");
	_botoes[2].setCharacterSize(TAMANHO_BOTOES);
	_botoes[2].setStyle(sf::Text::Style::Regular);
	_botoes[2].setFillColor(sf::Color::White);

	// Posicao
	tamJanela = _pGraf->getWindow()->getSize();
	tamTexto = _botoes[2].getGlobalBounds();

	posicao.x = ((float)tamJanela.x / 2.f) - (tamTexto.width / 2.f);
	posicao.y = (float)tamJanela.y / 10.f * 4.f;

	_botoes[2].setPosition(posicao);

	// --------- >> Botao Sair

	// Caracteristicas do conteudo
	_textosBotoes.push_back("Sair");
	_botoes[3].setFont(_fonte);
	_botoes[3].setString("Sair");
	_botoes[3].setCharacterSize(TAMANHO_BOTOES);
	_botoes[3].setStyle(sf::Text::Style::Regular);
	_botoes[3].setFillColor(sf::Color::White);

	// Posicao
	tamJanela = _pGraf->getWindow()->getSize();
	tamTexto = _botoes[3].getGlobalBounds();

	posicao.x = ((float)tamJanela.x / 2.f) - (tamTexto.width / 2.f);
	posicao.y = (float)tamJanela.y / 10.f * 5.f;

	_botoes[3].setPosition(posicao);
}

void Menu::criarTitulo()
{
	// Caracteristicas do conteudo
	_titulo.setFont(_fonte);
	_titulo.setString("JOGO");
	_titulo.setCharacterSize(TAMANHO_TITULO);
	_titulo.setStyle(sf::Text::Style::Regular);
	_titulo.setFillColor(sf::Color::White);

	// Posicao
	sf::Vector2u tamJanela = _pGraf->getWindow()->getSize();
	sf::FloatRect tamTexto = _titulo.getGlobalBounds();
	
	sf::Vector2f posicao;
	posicao.x = ((float)tamJanela.x / 2.f) - (tamTexto.width / 2.f);
	posicao.y = (float)tamJanela.y / 10.f;

	_titulo.setPosition(posicao);
}

void Menu::criarBackground()
{
	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/menu/FundoMedieval.png")) {
		std::cerr<<"Erro ao criar background menu.\n";
		return;
	}
	setTexture(textura);

	// tamanho do background
	sf::Vector2u tamJanela = _pGraf->getWindow()->getSize();
	float escalaX = (float)tamJanela.x / _body.getGlobalBounds().width;
	float escalaY = (float)tamJanela.y / _body.getGlobalBounds().height;

	_body.setScale
	(
		escalaX,
		escalaY
	);
}

void Menu::verificarMouse()
{
	verificarMovimento();

	_houveClique = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void Menu::verificarMovimento()
{
	sf::Vector2i posicaoMouse = _mouse.getPosition();

	// Verifica onde o mouse esta e destaca o botao
	for (int i = 1; i <= 3; i++) {
		if (_botoes[i].getGlobalBounds().contains((float)posicaoMouse.x, (float)posicaoMouse.y)) {
			// Destaca
			destacarTexto(_botoes[i]);

			// Aplica a funcao correspondente
			if (_houveClique) _funcoesBotoes[i]();
		}
		else {
			padronizar(_botoes[i], i);
		}
	}
}

void Menu::destacarTexto(sf::Text& texto)
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

void Menu::reposicionarTexto(sf::Text& texto)
{
	sf::Vector2u tamJanela = _pGraf->getWindow()->getSize();
	sf::FloatRect tamTexto = texto.getGlobalBounds();

	sf::Vector2f posicao;
	posicao.x = ((float)tamJanela.x / 2.f) - (tamTexto.width / 2.f);
	posicao.y = texto.getPosition().y;

	texto.setPosition(posicao);
}

void Menu::padronizar(sf::Text& texto, int id)
{
	texto.setCharacterSize(TAMANHO_BOTOES);
	texto.setString(_textosBotoes[id - 1]);
	texto.setStyle(sf::Text::Style::Regular);

	// Reposiciona no meio da janela
	reposicionarTexto(texto);
}

void Menu::executarJogar()
{
	stateNum = 20;
}

void Menu::executarRanking()
{
	stateNum = 11;
}

void Menu::executarSair()
{
	_pGraf->closeWindow();
}

void Menu::executar()
{
	_pGraf->getWindow()->draw(_body);
	_pGraf->getWindow()->draw(_titulo);
	_pGraf->getWindow()->draw(_botoes[1]);
	_pGraf->getWindow()->draw(_botoes[2]);
	_pGraf->getWindow()->draw(_botoes[3]);

	verificarMouse();
}

const int Menu::getStateNum() const
{
	return stateNum;
}


