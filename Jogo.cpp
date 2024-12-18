#include "Jogo.h"

Jogo::Jogo(std::string nome)
	:_GerenciadorGráfico()
{
	_jogador1 = new Entidades::Jogador(0, 0, _GerenciadorGráfico, nome);
	_florest = new Fases::Floresta(_GerenciadorGráfico, _jogador1);
}

Jogo::~Jogo()
{
	if (_jogador1)
	{
		delete _jogador1;
	}
	if (_GerenciadorGráfico)
	{
		delete _GerenciadorGráfico;
	}
	if (_florest)
	{
		delete _florest;
	}
}

void Jogo::executar()
{
}

void Jogo::Menu()
{

}
