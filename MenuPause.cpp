#include "MenuPause.h"
#include "Constantes.h"
#include "Fase.h"

Menus::MenuPause::MenuPause(Gerenciadores::Gerenciador_Grafico* _pGraf, sf::Sprite* imgFase) : Entidades::Ente(_pGraf), _imagemFase(imgFase), _houveClique(false), _mudouEstado(false), _voltaFase(false), _segundos(0.f)
{
	_clock.restart();

	carregarFonte();

	criarImagemFase();
	criarImagemPause();
	criarTitulo();
	criarBotoes();
}

Menus::MenuPause::~MenuPause()
{
	_imagemFase = nullptr;

	_segundos = 0.f;
}

const bool Menus::MenuPause::getVoltaFase() const
{
	return _voltaFase;
}

void Menus::MenuPause::carregarFonte()
{
	_fonte = _pGraf->getFont();
}

void Menus::MenuPause::criarImagemFase()
{
	_imagemFase->setColor(sf::Color(128, 128, 128));
}

void Menus::MenuPause::criarImagemPause()
{
	sf::Texture* textura = _pGraf->getTextura("Pause");
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

	float posicaoX = ((float)tamJanela.x / 2.f) - ((float)_body.getGlobalBounds().width / 2.f);

	_body.setPosition(posicaoX, 0.f);
}

void Menus::MenuPause::criarTitulo()
{
	sf::FloatRect tamImagemPause = _body.getGlobalBounds();
	sf::FloatRect tamTexto;

	// Caracteristicas do conteudo
	_titulo.setFont(_fonte);
	_titulo.setString("Pausado");
	_titulo.setCharacterSize(Constantes::TAMANHO_BOTOES + 20);
	_titulo.setStyle(sf::Text::Style::Regular);
	_titulo.setFillColor(sf::Color::Black);

	// Posicao
	tamTexto = _titulo.getGlobalBounds();

	sf::Vector2f posicao;
	posicao.x = ((float)tamImagemPause.width / 2.f) - ((float)tamTexto.width / 2.f);
	posicao.x += _body.getPosition().x;
	posicao.y = (float)tamImagemPause.width / 10.f * 1.5f;
	posicao.y += _body.getPosition().y;

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
	_botaoRetomar.setCharacterSize(Constantes::TAMANHO_BOTOES);
	_botaoRetomar.setStyle(sf::Text::Style::Regular);
	_botaoRetomar.setFillColor(sf::Color::Black);

	// Posicao
	tamTexto = _botaoRetomar.getGlobalBounds();

	posicao.x = ((float)tamImagemPause.width / 2.f) - ((float)tamTexto.width / 2.f);
	posicao.x += _body.getPosition().x;
	posicao.y = (float)tamImagemPause.height / 10.f * 5.f;
	posicao.y += _body.getPosition().y;

	_botaoRetomar.setPosition(posicao);

	// ------ >> Cria o botao de Salvar e sair

	// Caracteristicas do conteudo
	_botaoSalvarSair.setFont(_fonte);
	_botaoSalvarSair.setString("Salvar e sair");
	_botaoSalvarSair.setCharacterSize(Constantes::TAMANHO_BOTOES);
	_botaoSalvarSair.setStyle(sf::Text::Style::Regular);
	_botaoSalvarSair.setFillColor(sf::Color::Black);


	// Posicao
	tamTexto = _botaoSalvarSair.getGlobalBounds();

	posicao.x = ((float)tamImagemPause.width / 2.f) - ((float)tamTexto.width / 2.f);
	posicao.x += _body.getPosition().x;
	posicao.y = (float)tamImagemPause.height / 10.f * 6.5f;
	posicao.y += _body.getPosition().y;

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

	// Verifica onde o mouse esta e destaca ou padroniza o botao

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
		texto.setCharacterSize(Constantes::TAMANHO_BOTOES + 5);
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
	posicao.x += _body.getPosition().x;
	posicao.y = texto.getPosition().y;
	posicao.y += _body.getPosition().y;

	texto.setPosition(posicao);
}

void Menus::MenuPause::padronizar(sf::Text& texto)
{
	std::string nomeAtual = texto.getString();
	std::string nomePadronizado;

	if (nomeAtual[0] != '>') return;

	nomePadronizado = nomeAtual.substr(2, nomeAtual.size() - 4);

	texto.setCharacterSize(Constantes::TAMANHO_BOTOES);
	texto.setString(nomePadronizado);
	texto.setStyle(sf::Text::Style::Regular);

	reposicionarTexto(texto);
}

void Menus::MenuPause::atualizarClock()
{
	if (_segundos > 3.f) {
		_segundos = 3.f;
	}
	else {
		_segundos += _clock.restart().asSeconds();
	}
}

void Menus::MenuPause::executarRetomar()
{
	_voltaFase = true;
	_mudouEstado = true;
}

void Menus::MenuPause::executarSalvarSair()
{
	_Fase->SalvarEntidades();
	_voltaFase = false;
	_mudouEstado = true;
}

void Menus::MenuPause::desenharMenu()
{
	_pGraf->getWindow()->draw(*_imagemFase);
	_pGraf->getWindow()->draw(_body);
	_pGraf->getWindow()->draw(_titulo);
	_pGraf->getWindow()->draw(_botaoRetomar);
	_pGraf->getWindow()->draw(_botaoSalvarSair);
}

void Menus::MenuPause::executar()
{
	while (!_mudouEstado) {
		sf::Event event;
		while (_pGraf->getWindow()->pollEvent(event)) {

			// Volta a fase
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && _segundos > 0.25f) 
			{
				executarRetomar();
			}
			
		}

		_pGraf->clear();

		desenharMenu();

		verificarMouse();

		atualizarClock();

		_pGraf->display();
	}
}

void Menus::MenuPause::setFase(Fases::Fase* fas)
{
	_Fase = fas;
}
