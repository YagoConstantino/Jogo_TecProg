#include "MenuFases.h"
#include "Jogo.h"

#define TAMANHO_BOTOES 50

MenuFases::MenuFases(Gerenciadores::Gerenciador_Grafico* _pGraf) : Entidades::Ente(_pGraf), _mudouEstado(false), _faseFloresta(false), _faseCastelo(false), _umJog(false), _doisJog(false), _confirmaFase(false), _estaDigitandoCaixa1(false), _estaDigitandoCaixa2(false), _confirmaNomes(false), _primeiraVezCaixa1(true), _primeiraVezCaixa2(true), _retangulos(), _textos(), sizeRetangulos(0), sizeTextos(0)
{
	carregarFonte();
	criaBackground();
	criaMedadeEsquerda();
	criaMedadeDireita();

	carregarObjetos();
}

MenuFases::~MenuFases()
{
	_pGraf = nullptr;

	// Esvaziar o vetor de retangulos
	_retangulos.clear();

	// Esvaziar o vetor de textos
	_textos.clear();
}

void MenuFases::carregarFonte()
{
	if (!_fonte.loadFromFile("assets/fontes/EnglishTowne.ttf")) {
		std::cerr << "Erro ao incluir fonte.\n";
		return;
	}
}

void MenuFases::criaBackground()
{
	sf::Texture* textura = new sf::Texture();

	if (!textura->loadFromFile("assets/menu/pergaminho.jpg")) {
		std::cerr << "Erro ao criar background menu.\n";
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

void MenuFases::criaMedadeEsquerda()
{
	sf::Vector2u tamJanela = _pGraf->getWindow()->getSize();

	// ------ >> Cria imagem da fase floresta, 1
	sf::Texture* textura1 = new sf::Texture();
	if (!textura1->loadFromFile("assets/menu/floresta.png")) {
		std::cerr << "Erro ao criar background menu fases.\n";
		return;
	}
	_imagemFaseFloresta.setSize(sf::Vector2f(textura1->getSize()));
	_imagemFaseFloresta.setTexture(textura1);
	_imagemFaseFloresta.setScale(3.f, 3.f);

	_imagemFaseFloresta.setPosition
	(
		(float)tamJanela.x / 12.f,
		(float)tamJanela.y / 3.5f
	);

	// ------ >> Cria imagem da fase 2
	
	sf::Texture* textura2 = new sf::Texture();
	if (!textura2->loadFromFile("assets/menu/temporario.png")) {
		std::cerr << "Erro ao criar background menu fases.\n";
		return;
	}
	_imagemFaseCastelo.setSize(sf::Vector2f(textura2->getSize()));
	_imagemFaseCastelo.setTexture(textura2);
	_imagemFaseCastelo.setScale(3.f, 3.f);

	_imagemFaseCastelo.setPosition
	(
		_imagemFaseCastelo.getPosition().x + _imagemFaseCastelo.getGlobalBounds().width + (float)tamJanela.x / 10.f,
		(float)tamJanela.y / 3.5f
	);

	// ------ >> Cria texto Fases

	_textoFases.setFont(_fonte);
	_textoFases.setString("Selecione a fase:");
	_textoFases.setCharacterSize(TAMANHO_BOTOES + 10);
	_textoFases.setStyle(sf::Text::Style::Regular);
	_textoFases.setFillColor(sf::Color::Black);

	float meioXImagemFase1 = _imagemFaseFloresta.getPosition().x + (float)_imagemFaseFloresta.getGlobalBounds().width / 2.f;
	float meioXImagemFase2 = _imagemFaseCastelo.getPosition().x + (float)_imagemFaseCastelo.getGlobalBounds().width / 2.f;
	float meioXTextoFases = (meioXImagemFase1 + meioXImagemFase2) / 2.f;
	meioXTextoFases -= (float)_textoFases.getGlobalBounds().width / 2.f;

	_textoFases.setPosition
	(
		meioXTextoFases,
		(float)tamJanela.y / 7.5f
	);

	// ------ >> Cria o nome da fase Floresta

	_nomeFaseFloresta.setFont(_fonte);
	_nomeFaseFloresta.setString("A floresta");
	_nomeFaseFloresta.setCharacterSize(TAMANHO_BOTOES);
	_nomeFaseFloresta.setStyle(sf::Text::Style::Regular);
	_nomeFaseFloresta.setFillColor(sf::Color::Black);

	float meioXNomeFase1 = meioXImagemFase1 - (float)_nomeFaseFloresta.getGlobalBounds().width / 2.f;

	_nomeFaseFloresta.setPosition
	(
		meioXNomeFase1,
		_imagemFaseFloresta.getPosition().y - (float)_nomeFaseFloresta.getGlobalBounds().height * 1.85f
	);

	// ------ >> Cria o nome da fase 2

	_nomeFaseCastelo.setFont(_fonte);
	_nomeFaseCastelo.setString("O castelo");
	_nomeFaseCastelo.setCharacterSize(TAMANHO_BOTOES);
	_nomeFaseCastelo.setStyle(sf::Text::Style::Regular);
	_nomeFaseCastelo.setFillColor(sf::Color::Black);

	float meioXNomeFase2 = meioXImagemFase2 - (float)_nomeFaseCastelo.getGlobalBounds().width / 2.f;

	_nomeFaseCastelo.setPosition
	(
		meioXNomeFase2,
		_imagemFaseCastelo.getPosition().y - (float)_nomeFaseCastelo.getGlobalBounds().height * 1.85f
	);

	// ------ >> Cria botao para confirmar a seleção da fase

	_botaoConfirmaFase.setFont(_fonte);
	_botaoConfirmaFase.setString("Confirmar fase");
	_botaoConfirmaFase.setCharacterSize(TAMANHO_BOTOES);
	_botaoConfirmaFase.setStyle(sf::Text::Style::Regular);
	_botaoConfirmaFase.setFillColor(sf::Color::Black);

	sf::Vector2f posicaoFase1 = _imagemFaseFloresta.getPosition();
	sf::Vector2f posicaoFase2 = _imagemFaseCastelo.getPosition();
	sf::Vector2f posicaoBotao;
	posicaoBotao.x = (posicaoFase1.x + posicaoFase2.x) / 2.f;
	posicaoBotao.y = (posicaoFase1.y + _imagemFaseFloresta.getGlobalBounds().height) + (float)tamJanela.y / 10.f;

	_botaoConfirmaFase.setPosition(posicaoBotao);
}

void MenuFases::criaMedadeDireita()
{
	sf::Vector2u tamJanela = _pGraf->getWindow()->getSize();
	sf::Color cor(192, 192, 192);

	// ------ >> Cria o botao do dois jogador
	
	sf::Color cor2(0, 0, 0);

	_botaoDoisJog.setFont(_fonte);
	_botaoDoisJog.setString("Dois jogadores");
	_botaoDoisJog.setCharacterSize(TAMANHO_BOTOES);
	_botaoDoisJog.setStyle(sf::Text::Style::Regular);
	_botaoDoisJog.setFillColor(cor2);

	_botaoDoisJog.setPosition
	(
		((float)tamJanela.x - (float)tamJanela.x / 12.f) - (float)_botaoDoisJog.getGlobalBounds().width,
		_nomeFaseCastelo.getPosition().y
	);

	// ------ >> Cria o botao do um jogador

	_botaoUmJog.setFont(_fonte);
	_botaoUmJog.setString("Um jogador");
	_botaoUmJog.setCharacterSize(TAMANHO_BOTOES);
	_botaoUmJog.setStyle(sf::Text::Style::Regular);
	_botaoUmJog.setFillColor(cor2);

	_botaoUmJog.setPosition
	(
		_botaoDoisJog.getPosition().x - ((float)tamJanela.x / 10.f) - _botaoUmJog.getGlobalBounds().width,
		_nomeFaseCastelo.getPosition().y
	);

	// ------ >> Cria o titulo dos botoes

	_textoJogadores.setFont(_fonte);
	_textoJogadores.setString("Número de jogadores:");
	_textoJogadores.setCharacterSize(TAMANHO_BOTOES + 10);
	_textoJogadores.setStyle(sf::Text::Style::Regular);
	_textoJogadores.setFillColor(sf::Color::Black);

	float meioXBotaoUmJog = _botaoUmJog.getPosition().x + (float)_botaoUmJog.getGlobalBounds().width / 2.f;
	float meioXBotaoDoisJog = _botaoDoisJog.getPosition().x + (float)_botaoDoisJog.getGlobalBounds().width / 2.f;
	float meioXTextoJogadores = (meioXBotaoUmJog + meioXBotaoDoisJog) / 2.f;
	meioXTextoJogadores -= (float)_textoJogadores.getGlobalBounds().width / 2.f;

	_textoJogadores.setPosition
	(
		meioXTextoJogadores,
		_textoFases.getPosition().y
	);

	// ------ >> Cria as caixas de texto

	sf::FloatRect tamBotaoDoisJog = _botaoDoisJog.getGlobalBounds();
	sf::Vector2f tamCaixaTexto2;
	tamCaixaTexto2.x = (float)tamBotaoDoisJog.width;
	tamCaixaTexto2.y = (float)tamBotaoDoisJog.height;

	_caixaTexto2.setSize(tamCaixaTexto2);
	_caixaTexto2.setFillColor(cor);
	_caixaTexto2.setPosition
	(
		_botaoDoisJog.getPosition().x,
		_botaoDoisJog.getPosition().y + tamBotaoDoisJog.height * 2.f
	);

	_nomeJog2.setFont(_fonte);
	_nomeJog2.setString("Nome jogador 2:");
	_nomeJog2.setCharacterSize(TAMANHO_BOTOES - 10);
	_nomeJog2.setStyle(sf::Text::Style::Regular);
	_nomeJog2.setFillColor(sf::Color::Black);

	_nomeJog2.setPosition(_caixaTexto2.getPosition().x + 5.f, _caixaTexto2.getPosition().y - 8.f);

	_caixaTexto1.setSize(_caixaTexto2.getSize());
	_caixaTexto1.setFillColor(cor);
	_caixaTexto1.setPosition
	(
		_botaoUmJog.getPosition().x + (_botaoUmJog.getGlobalBounds().width / 2.f) - (_caixaTexto1.getGlobalBounds().width / 2.f),
		_caixaTexto2.getPosition().y
	);

	_nomeJog1.setFont(_fonte);
	_nomeJog1.setString("Nome jogador 1:");
	_nomeJog1.setCharacterSize(TAMANHO_BOTOES - 10);
	_nomeJog1.setStyle(sf::Text::Style::Regular);
	_nomeJog1.setFillColor(sf::Color::Black);

	_nomeJog1.setPosition(_caixaTexto1.getPosition().x + 5.f, _caixaTexto1.getPosition().y - 8.f);

	// ------ >> Cria o botao de confirma nomes

	_botaoConfirmaNomes.setFont(_fonte);
	_botaoConfirmaNomes.setString("Confirmar nome(s)");
	_botaoConfirmaNomes.setCharacterSize(TAMANHO_BOTOES);
	_botaoConfirmaNomes.setStyle(sf::Text::Style::Regular);
	_botaoConfirmaNomes.setFillColor(sf::Color::Black);

	float meioXCaixaTexto1 = _caixaTexto1.getPosition().x + ((float)_caixaTexto1.getGlobalBounds().width / 2.f);
	float meioXCaixaTexto2 = _caixaTexto2.getPosition().x + ((float)_caixaTexto2.getGlobalBounds().width / 2.f);
	float meioXCaixas = (meioXCaixaTexto1 + meioXCaixaTexto2) / 2.f;

	_botaoConfirmaNomes.setPosition
	(
		meioXCaixas - _botaoConfirmaNomes.getGlobalBounds().width / 2.f,
		_botaoConfirmaFase.getPosition().y
	);
}

// Preenche o vetor de objetos interagiveis com os seus respectivos metodos
void MenuFases::carregarObjetos()
{
	_retangulos.clear();
	_textos.clear();

	_retangulos.emplace_back
	(
		&_imagemFaseFloresta,
		[this]() { executarFaseFloresta(); }
	);

	_retangulos.emplace_back
	(
		&_imagemFaseCastelo,
		[this]() { executarFaseCastelo(); }
	);

	_textos.emplace_back
	(
		&_botaoConfirmaFase,
		[this]() { executarConfirmaFase(); }
	);

	_textos.emplace_back
	(
		&_botaoUmJog,
		[this]() { executarUmJog(); }
	);

	_textos.emplace_back
	(
		&_botaoDoisJog,
		[this]() { executarDoisJog(); }
	);

	_retangulos.emplace_back
	(
		&_caixaTexto1,
		[this]() { executarCaixaTexto1(); }
	);

	_retangulos.emplace_back
	(
		&_caixaTexto2,
		[this]() { executarCaixaTexto2(); }
	);

	_textos.emplace_back
	(
		&_botaoConfirmaNomes,
		[this]() { executarConfirmaNomes(); }
	);

	sizeRetangulos = static_cast<int>(_retangulos.size());
	sizeTextos = static_cast<int>(_textos.size());
}

void MenuFases::verificarCliques()
{
	// verifica se houve clique esquerdo do mouse
	if (!mouse.isButtonPressed(sf::Mouse::Left)) return;

	// Procuro onde aconteceu
	
	sf::Vector2f posicaoMouse;
	posicaoMouse.x = (float)mouse.getPosition().x;
	posicaoMouse.y = (float)mouse.getPosition().y;

	// Nos retangulos
	for (int i = 0; i < _retangulos.size(); i++) {
		if (_retangulos[i].first != nullptr && _retangulos[i].first->getGlobalBounds().contains(posicaoMouse)) {
			_retangulos[i].second();
		}
	}
	
	// Nos botoes
	for (int i = 0; i < _textos.size(); i++) {
		if (_textos[i].first != nullptr && _textos[i].first->getGlobalBounds().contains(posicaoMouse)) {
			_textos[i].second();
		}
	}
}

void MenuFases::verificarConfirma()
{
	// Verifico se os dois confirmas foram clicados
	if (_confirmaFase && _confirmaNomes) {
		// Mudo o estado e levo para a fase escolhida
		if (_faseFloresta) {
			_mudouEstado = true;
			Jogo::mudarStateNum(20);
		}
		else if (_faseCastelo) {
			_mudouEstado = true;
			Jogo::mudarStateNum(21);
		}

		// Salvo o(s) nome(s) do(s) jogadore(s)
		if (_doisJog) {

		}
		else if (_umJog) {

		}
	}
}

void MenuFases::destacar(sf::Text* texto)
{
	// Deixa o texto sublinhado
	texto->setStyle(sf::Text::Style::Underlined);

	// Reposiciona o texto
	//reposicionar(texto);
}

void MenuFases::destacar(sf::RectangleShape* retangulo)
{
	// Deixa o retangulo com borda
	retangulo->setOutlineThickness(2.5f);
	retangulo->setOutlineColor(sf::Color::Black);
}

void MenuFases::padronizar(sf::Text* texto)
{
	// Deixa o texto nao sublinhado
	texto->setStyle(sf::Text::Style::Regular);
}

void MenuFases::padronizar(sf::RectangleShape* retangulo)
{
	// Deixa o retangulo sem borda
	retangulo->setOutlineThickness(0.f);
}

void MenuFases::desenhar()
{
	_pGraf->getWindow()->draw(_body);

	for (int i = 0; i < sizeRetangulos; i++) {
		_pGraf->getWindow()->draw(*(_retangulos[i].first));
	}
	for (int i = 0; i < sizeTextos; i++) {
		_pGraf->getWindow()->draw(*(_textos[i].first));
	}

	_pGraf->getWindow()->draw(_textoFases);
	_pGraf->getWindow()->draw(_nomeFaseFloresta);
	_pGraf->getWindow()->draw(_nomeFaseCastelo);
	_pGraf->getWindow()->draw(_textoJogadores);
	_pGraf->getWindow()->draw(_nomeJog1);
	_pGraf->getWindow()->draw(_nomeJog2);
	
}

void MenuFases::executar()
{
	while (!_mudouEstado) {
		sf::Event event;
		while (_pGraf->getWindow()->pollEvent(event)) {
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				Jogo::mudarStateNum(10);
				_mudouEstado = true;
			}
		}

		_pGraf->clear();

		desenhar();
		verificarCliques();
		verificarConfirma();

		_pGraf->display();
	}
}

void MenuFases::executarFaseFloresta()
{
	if (!_faseFloresta && !_confirmaFase) {
		// Destaco a imagem clicada
		_faseFloresta = true;
		destacar(&_imagemFaseFloresta);

		// Padronizo a outra imagem
		_faseCastelo = false;
		padronizar(&_imagemFaseCastelo);
	}
}

void MenuFases::executarFaseCastelo()
{
	if (!_faseCastelo && !_confirmaFase) {
		// Destaco a imagem clicada
		_faseCastelo = true;
		destacar(&_imagemFaseCastelo);

		// Padronizo a outra imagem
		_faseFloresta = false;
		padronizar(&_imagemFaseFloresta);
	}
}

void MenuFases::executarConfirmaFase()
{
	if (_faseFloresta || _faseCastelo) {
		if (!_confirmaFase) {
			_confirmaFase = true;
			destacar(&_botaoConfirmaFase);
		}
	}
	else {
		padronizar(&_botaoConfirmaFase);
	}
}

void MenuFases::executarUmJog()
{
	if (!_umJog && !_confirmaNomes) {
		// Destaco o botao "um jogador"
		_umJog = true;
		destacar(&_botaoUmJog);

		// Padronizo o botao "dois jogadores"
		_doisJog = false;
		padronizar(&_botaoDoisJog);
	}
}

void MenuFases::executarDoisJog()
{
	if (!_doisJog && !_confirmaNomes) {
		// Destaco o botao "dois jogadores"
		_doisJog = true;
		destacar(&_botaoDoisJog);

		// Padronizo o botao "um jogador"
		_umJog = false;
		padronizar(&_botaoUmJog);
	}
}

void MenuFases::executarCaixaTexto1()
{	
	if (!(_umJog ^ _doisJog) || _confirmaNomes) return;

	if (_primeiraVezCaixa1) {
		_primeiraVezCaixa1 = false;
		_nomeJog1.setString("");
	}

	destacar(&_caixaTexto1);

	_estaDigitandoCaixa1 = true;

	sf::Event event;
	while (_estaDigitandoCaixa1) {
		while (_pGraf->getWindow()->pollEvent(event)) {
			// Detecta se o usuário pressionou Enter ou Escape
			if 
			(
				event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Escape)
			) 
			{
				_estaDigitandoCaixa1 = false; // Sai do modo de digitação
			}

			// Captura o texto digitado
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 32) { // Casos específicos
					if (event.text.unicode == 8 && _nome1.size() > 0)
						// Apaga o ultimo caracter
						_nome1.pop_back();
				}
				else if (event.text.unicode < 128 && _nome1.size() < 9) { // Caso geral
					_nome1 += static_cast<char>(event.text.unicode);
				}
				_nomeJog1.setString(_nome1);
			}
		}
		_pGraf->clear();

		desenhar();

		_pGraf->display();
	}

	padronizar(&_caixaTexto1);
}

void MenuFases::executarCaixaTexto2()
{
	if (!_doisJog || _confirmaNomes) return;

	if (_primeiraVezCaixa2) {
		_primeiraVezCaixa2 = false;
		_nomeJog2.setString("");
	}

	destacar(&_caixaTexto2);

	_estaDigitandoCaixa2 = true;

	sf::Event event;
	while (_estaDigitandoCaixa2) {
		while (_pGraf->getWindow()->pollEvent(event)) {
			// Detecta se o usuário pressionou Enter ou Escape
			if
			(
				event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Escape)
			)
			{
				_estaDigitandoCaixa2 = false; // Sai do modo de digitação
			}

			// Captura o texto digitado
			if (event.type == sf::Event::TextEntered) {
				if (event.text.unicode < 32) { // Casos específicos
					if (event.text.unicode == 8 && _nome2.size() > 0)
						// Apaga o ultimo caracter
						_nome2.pop_back();
				}
				else if (event.text.unicode < 128 && _nome2.size() < 9) { // Caso geral
					_nome2 += static_cast<char>(event.text.unicode);
				}
				_nomeJog2.setString(_nome2);
			}
		}
		_pGraf->clear();

		desenhar();

		_pGraf->display();
	}

	padronizar(&_caixaTexto2);
}

void MenuFases::executarConfirmaNomes()
{
	if (_doisJog) {
		// Verifica se o botao ja foi clicado uma vez
		// Verifica se um dos dois nomes não foi preenchido
		// Verifica se o nome ja existe
		if 
		(
			!_confirmaNomes &&
			!_nome1.empty() && !_nome2.empty() && !_primeiraVezCaixa1 && !_primeiraVezCaixa2
		)
		{
			_confirmaNomes = true;
			destacar(&_botaoConfirmaNomes);
		}
	}
	else if (_umJog) {
		// Verifica se o botao ja foi clicado uma vez
		// Verifica se o nome não foi preenchido
		// Verifica se o nome ja existe
		if
		(
			!_confirmaNomes &&
			!_nome1.empty() && !_primeiraVezCaixa1
		)
		{
			_confirmaNomes = true;
			destacar(&_botaoConfirmaNomes);
		}
	}
	else {
		padronizar(&_botaoConfirmaNomes);
	}
}
