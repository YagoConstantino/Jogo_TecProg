#include "Jogador.h"

Entidades::Jogador::Jogador(float inlX, float inY, float H, float W, Gerenciadores::Gerenciador_Grafico* pgra)
	:Personagem(inlX,inY,H,W,pgra),_pontos(0)
{
	//_pGraf->desenhar(this);
}

Entidades::Jogador::~Jogador()
{
	_pGraf = nullptr;
	_body = nullptr;
	setTexture(nullptr);
	Position.x = 0.0;
	Position.y = 0.0;
	Size.x = 0.0;
	Size.y = 0.0;
}

void Entidades::Jogador::executar(sf::Event* ev)
{

}

void Entidades::Jogador::salvar()
{
}

void Entidades::Jogador::render()
{
}
