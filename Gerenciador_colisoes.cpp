#include "Gerenciador_Colisoes.h"
#include "Inimigo.h"

Gerenciadores::Gerenciador_Colisoes::Gerenciador_Colisoes(float gravidade) 
	: _listaInimigos(), _listaObstaculos(), _listaProjetil(), _gravidade(gravidade)
{
	_jogador1 = nullptr;
	_jogador2 = nullptr;
	
	_listaInimigos.clear();
	_listaObstaculos.clear();
	_listaProjetil.clear();
}

Gerenciadores::Gerenciador_Colisoes::~Gerenciador_Colisoes() 
{
	_jogador1 = nullptr;
	_jogador2 = nullptr;
	
}


void Gerenciadores::Gerenciador_Colisoes::setJogador1(Entidades::Jogador* pJogador) 
{
	if (pJogador == nullptr) 
	{
		std::cerr << "Ponteiro de jogador invalido. Impossivel incluir em G.Colisoes.\n";
		return;
	}

	_jogador1 = pJogador;
}

void Gerenciadores::Gerenciador_Colisoes::setJogador2(Entidades::Jogador* pJogador) {
	if (pJogador == nullptr) {
		std::cerr << "Ponteiro de jogador invalido. Impossivel incluir em G.Colisoes.\n";
		return;
	}

	_jogador2 = pJogador;
}

void Gerenciadores::Gerenciador_Colisoes::incluirInimigo(Entidades::Inimigo* pInimigo) {
	if (pInimigo == nullptr) {
		std::cerr << "Ponteiro de inimigo invalido. Impossivel incluir em G.Colisoes.\n" << std::endl;
		return;
	}

	_listaInimigos.push_back(pInimigo);
}

void Gerenciadores::Gerenciador_Colisoes::incluirObstaculo(Entidades::Obstaculo* pObstaculo) {
	if (pObstaculo == nullptr) {
		std::cerr << "Ponteiro de obstaculo invalido. Impossivel incluir em G.Colisoes.\n" << std::endl;
		return;
	}

	_listaObstaculos.push_back(pObstaculo);
}

void Gerenciadores::Gerenciador_Colisoes::incluirProjetil(Entidades::Projetil* pProjetil) {
	if (pProjetil == nullptr) {
		std::cerr << "Ponteiro de projetil invalido. Impossivel incluir em G.Colisoes.\n" << std::endl;
		return;
	}

	_listaProjetil.insert(pProjetil);
}

void Gerenciadores::Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
	// Caso 1: os dois jogadores foram criados
	if (_jogador1 != nullptr && _jogador2 != nullptr) {
		for (itObstaculo = _listaObstaculos.begin(); itObstaculo != _listaObstaculos.end(); itObstaculo++) 
		{
			if (verificarColisao(static_cast<Entidades::Entidade*>(*itObstaculo), static_cast<Entidades::Entidade*>(_jogador1))) 
			{
				(*itObstaculo)->obstacular(_jogador1);
				_jogador1->setGround(true);
			}

			if (verificarColisao(static_cast<Entidades::Entidade*>(*itObstaculo), static_cast<Entidades::Entidade*>(_jogador2))) 
			{
				(*itObstaculo)->obstacular(_jogador2);
				_jogador2->setGround(true);
			}
		}
	}
	// Caso 2: apenas um jogador foi criado
	else if (_jogador1 != nullptr) {
		for (itObstaculo = _listaObstaculos.begin(); itObstaculo != _listaObstaculos.end(); itObstaculo++) 
		{
			if (verificarColisao(static_cast<Entidades::Entidade*>(*itObstaculo), static_cast<Entidades::Entidade*>(_jogador1))) 
			{
				(*itObstaculo)->obstacular(_jogador1);
				_jogador1->setGround(true);
			}
		}
	}
}

void Gerenciadores::Gerenciador_Colisoes::tratarColisoesJogsInimgs() {
	// Caso 1: os dois jogadores foram criados
	if (_jogador1 != nullptr && _jogador2 != nullptr) {
		for (itInimigo = _listaInimigos.begin(); itInimigo != _listaInimigos.end(); itInimigo++) 
		{
			if (verificarColisao(static_cast<Entidades::Entidade*>(*itInimigo), static_cast<Entidades::Entidade*>(_jogador1))) 
			{
				// Jogador para de mover
				// Jogador toma dano, se preciso
				(*itInimigo)->danificar(_jogador1);
				
				// Inimigo para de mover
				// Inimigo toma dano, se preciso
			}

			if (verificarColisao(static_cast<Entidades::Entidade*>(*itInimigo), static_cast<Entidades::Entidade*>(_jogador2))) 
			{
				// Jogador para de mover
				// Jogador toma dano, se preciso
				(*itInimigo)->danificar(_jogador2);

				// Inimigo para de mover
				// Inimigo toma dano, se preciso
			}
		}
	}
	// Caso 2: apenas um jogador foi criado
	else if (_jogador1 != nullptr) {
		for (itInimigo = _listaInimigos.begin(); itInimigo != _listaInimigos.end(); itInimigo++) {
			if (verificarColisao(static_cast<Entidades::Entidade*>(*itInimigo), static_cast<Entidades::Entidade*>(_jogador1))) {
				// Jogador para de mover
				// Jogador toma dano, se preciso
				(*itInimigo)->danificar(_jogador1);

				// Inimigo para de mover
				// Inimigo toma dano, se preciso
			}
		}
	}

}

void Gerenciadores::Gerenciador_Colisoes::tratarColisoesJogsProjeteis() 
{
	// Caso 1: os dois jogadores foram criados
	if (_jogador1 != nullptr && _jogador2 != nullptr) {
		for (itProjetil = _listaProjetil.begin(); itProjetil != _listaProjetil.end(); itProjetil++) {
			if (verificarColisao(static_cast<Entidades::Entidade*>(*itProjetil), static_cast<Entidades::Entidade*>(_jogador1))) {
				// Jogador toma dano
				for (int i = 0; i < (*itProjetil)->getDano(); i++)
					_jogador1->operator--();
				// Projetil desaparece
				(*itProjetil)->~Projetil();
			}

			if (verificarColisao(static_cast<Entidades::Entidade*>(*itProjetil), static_cast<Entidades::Entidade*>(_jogador2))) {
				// Jogador toma dano
				for (int i = 0; i < (*itProjetil)->getDano(); i++)
					_jogador2->operator--();
				// Projetil desaparece
				(*itProjetil)->~Projetil();
			}

		}
	}
	// Caso 2: apenas um jogador foi criado
	else if (_jogador1 != nullptr) 
	{
		for (itProjetil = _listaProjetil.begin(); itProjetil != _listaProjetil.end(); itProjetil++) {
			if (verificarColisao(static_cast<Entidades::Entidade*>(*itProjetil), static_cast<Entidades::Entidade*>(_jogador1))) {
				// Jogador toma dano
				for (int i = 0; i < (*itProjetil)->getDano(); i++)
					_jogador1->operator--();
				// Projetil desaparece
				(*itProjetil)->~Projetil();
			}
		}
	}
}

const bool Gerenciadores::Gerenciador_Colisoes::verificarColisao(Entidades::Entidade* pEnt1, Entidades::Entidade* pEnt2) const
{
	if (pEnt1 == nullptr || pEnt2 == nullptr) 
	{
		std::cerr << "Ponteiro de entidade invalido. Impossivel verificar colisao.\n";
		return false;
	}

	return pEnt1->getBody().getGlobalBounds().intersects(pEnt2->getBody().getGlobalBounds());
}

void Gerenciadores::Gerenciador_Colisoes::aplicarGravidade() 
{
	// Caso 1: os dois jogadores foram criados
	if (_jogador1 != nullptr && _jogador2 != nullptr) 
	{
		if (!_jogador1->getOnGround())
		{
			_jogador1->sofrerGravidade(_gravidade);
		}
		
		if (!_jogador2->getOnGround())
		{
			_jogador2->sofrerGravidade(_gravidade);
		}

		
	}
	// Caso 2: apenas um jogador foi criado
	else if (_jogador1 != nullptr) 
	{

		if (!_jogador1->getOnGround())
		{
			_jogador1->sofrerGravidade(_gravidade);
		}
	}
}

void Gerenciadores::Gerenciador_Colisoes::executar()
{
	aplicarGravidade();
	tratarColisoesJogsObstacs();
	tratarColisoesJogsProjeteis();
	tratarColisoesJogsInimgs();
}
