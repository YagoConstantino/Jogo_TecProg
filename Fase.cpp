#include "Fase.h"
#define LARGURAPLAT 468

Fases::Fase::Fase(Gerenciadores::Gerenciador_Grafico* pgra,Entidades::Jogador* j)
	:_GG(pgra),_jog(j),maxCavaleiros(7),maxPlataformas(6)
{
	_GC = new Gerenciadores::Gerenciador_Colisoes(0.005f);
	_Lista = new Listas::ListaEntidades();
}

Fases::Fase::~Fase()
{
	//Desaloco o Gerenciador de Colisoes e a ListaEntidades
	if (_GC)
		delete _GC;

	if (_Lista)
		delete _Lista;

	//Seto como nulo os ponteiros para o Gerenciador gráfico e jogador
	_GG = nullptr;
	_jog = nullptr;
	
}

void Fases::Fase::gerenciarColisoes()
{
	_GC->executar();
}

void Fases::Fase::criarCavaleiros()
{
	
	int n = rand()% maxCavaleiros; // Quantidade varia de 3 a 7
    if (n < 3) n = 3;

	float x = 150.f;           //Posicao inicial
    float anteriorX = x;
	int larguraJanela = _GG->getWindow()->getSize().x; // Largura da janela para testar se nao saiu depois

	for (int i = 0; i < n; i++)
	{
		Entidades::Cavaleiro* cav = new Entidades::Cavaleiro(x, 630, _GG, _jog, 4); // Novo cav na posicao x
		_Lista->insert_back(static_cast<Entidades::Entidade*>(cav)); // inserir na lista
		_GC->incluirInimigo(static_cast<Entidades::Inimigo*>(cav)); // inserir no Gerenciador de colisoes
		float larguraCavaleiro = cav->getBody().getGlobalBounds().width; // tamanho do cavaleiro

        x = rand() % (_GG->getWindow()->getSize().x)+150;
        if (x == anteriorX)
        {
            x = (rand() % _GG->getWindow()->getSize().x)+150;
        }
		if (x +115+larguraCavaleiro>larguraJanela) // testo se o tamanho do cavaleiro + 115 nao sai da janela
            x = (rand() % _GG->getWindow()->getSize().x) + 150; 

        anteriorX = x;
	}

}

void Fases::Fase::criarPlataformas()
{
    srand(time(NULL));
    int n = rand() % maxPlataformas;        // Quantidade de plataformas: entre 3 e 10
    if (n < 3) n = 3;

	int i;
    
}

void Fases::Fase::criarCenario()
{
	//Implementar depois 
}


