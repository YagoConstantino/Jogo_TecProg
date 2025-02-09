#include "Fase.h"
#include "Jogo.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <utility>
#include "Constantes.h"
#include "Jogo.h"
#include"MortoVivoThread.h"
/*Implementar posteriormente:
Posso fazer um vector de pair<pair<float,float>,bool>(Esses vectores para plataforma e cavaleiro ficariam no .h)
uso o pair de float para as coordenadas e o booleano para saber
se a plataforma ja foi gerada, dai posso randomizar melhor os obstaculos dificeis e medios, al�m de ter mais de 5

op��es de plataformas, ou seja gero umas 10 posi��es, algumas plataformas podem se sobrepor a outras, portanto antes de
gerar elas verifico se outra plataforma muito proxima ja foi gerada, o mesmo pode ser feito para inimigos,posso gerar
todas as plataformas e depois verifico quais foram geradas e posso colocara inimigos em todas elas ao inves de me

limitar ao ch�o, pois � at� o momento a unica parte que certamente vai ser gerada
*/

Fases::Fase::Fase(Gerenciadores::Gerenciador_Grafico* pgra, Entidades::Jogador* j1, Entidades::Jogador* j2, Jogo* jog)
	:Ente(pgra), _GG(pgra), _jog1(j1), _jog2(j2), maxCavaleiros(Constantes::MAX_CAVALEIROS),
	maxPlataformas(Constantes::MAX_PLATAFORMA), _mudouEstado(false), _hudJog1(nullptr), _hudJog2(nullptr), _menuPause(nullptr),
	_arquivoFase(), _terminada(false), _TipoFase(0),_jogo(jog)
{
	_GC = Gerenciadores::Gerenciador_Colisoes::getInstancia();
	_Lista = new Listas::ListaEntidades();
	if (_jog1)
	{
		_GC->setJogador1(_jog1);
		_hudJog1 = new Hud(_jog1);
		
	}
	if (_jog2)
	{
		_GC->setJogador2(_jog2);
		_hudJog2 = new Hud(_jog2);
		
	}
	
}

Fases::Fase::~Fase()
{
	//Desaloco o Gerenciador de Colisoes e a ListaEntidades
	/*if (_GC)
		delete _GC;
		*/
	if (_Lista) 
	{
		_Lista->joinThread();
		delete _Lista;
	}
	if (_hudJog1)
	{
		delete _hudJog1;
		_hudJog1 = nullptr;
	}
	if (_hudJog2)
	{
		delete _hudJog2;
		_hudJog2 = nullptr;
	}
	if (_menuPause)
	{
		delete _menuPause;
		_menuPause = nullptr;
	}
		

	//Seto como nulo os ponteiros para o Gerenciador gr�fico e jogador
	//_GG = nullptr;
	_jog1 = nullptr;
	_jog2 = nullptr;

	_GC->resetar();
}

void Fases::Fase::gerenciarColisoes()
{
	_GC->executar();
}

void Fases::Fase::criarPlataformas()
{

	int n = (rand() % 4) + 5;        // Quantidade de plataformas: entre 3 e 8
	int i;

	std::vector<std::pair<float, float>> posicoes =
	{
		{0.f, 710.f},										// Plataforma 1
		{468.f, 710.f},										// Plataforma 2 
		{936.f, 710.f},										// Plataforma 3
		{0.f, 530.f},										// Plataforma 4
		{_GG->getWindow()->getSize().x - 468.f, 530.f},		// Plataforma 5
		{450.f, 360.f},										// Plataforma 6
		{0.f, 200.f},										// Plataforma 7
		{_GG->getWindow()->getSize().x - 468.f, 200.f}		// Plataforma 8
	};

	for (i = 0; i < n; i++)
	{
		float x = posicoes[i].first;
		float y = posicoes[i].second;

		Entidades::Plataforma* plat = new Entidades::Plataforma(x, y, _GG);
		_GC->incluirObstaculo(static_cast<Entidades::Obstaculo*>(plat));
		_Lista->insert_back(static_cast<Entidades::Entidade*>(plat));

	}

}

void Fases::Fase::criarCenario()
{
	//Implementar depois 
}

void Fases::Fase::pause()
{
	if (_menuPause != nullptr) return;

	// Executo o pause
	_menuPause = new Menus::MenuPause(_GG, &_body);
	_menuPause->setFase(this);
	_menuPause->executar();

	// verifico se volto para a fase ou para o menu principal
	verificarSaidaPause();

	delete _menuPause;
	_menuPause = nullptr;

	// Conserto as cores do background
	_body.setColor(sf::Color(255, 255, 255));
}

void Fases::Fase::verificarSaidaPause()
{
	if (!_menuPause->getVoltaFase()) 
	{
		Jogo::mudarStateNum(Constantes::STATE_MENU);
		_mudouEstado = true;
	}
}

void Fases::Fase::SalvarEntidades()
{
	//Apaga tudo no Arquivo
	_arquivoFase.open("Salvamento.txt", std::ios::trunc);
	_arquivoFase.close();

	//Salva
	_arquivoFase.open("Salvamento.txt", std::ios::app);
	_arquivoFase << _terminada<<" "<< _TipoFase << "\n";
	_arquivoFase.close();
		
	if (_jog1) 
	{
		_jog1->registraDados();
		_jog1->SalvarDataBuffer(_arquivoFase);
	}
	if (_jog2) 
	{
		_jog2->registraDados();
		_jog2->SalvarDataBuffer(_arquivoFase);
	}
	_Lista->registrarDados();
	_Lista->salvar(_arquivoFase);


}

void Fases::Fase::LimpaArquivo()
{
	try
	{
		_arquivoFase.open("Salvamento.txt", std::ios::trunc);

		if (!_arquivoFase.is_open())
		{
			throw std::runtime_error("Erro ao abrir o arquivo para limpeza.");
		}

		_arquivoFase << 0;
		_arquivoFase.close();
		std::cout << "Arquivo limpo com sucesso!\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exceção em LimpaArquivo: " << e.what() << std::endl;
	}
}

void Fases::Fase::verificarJogadores()
{
	// ------ >> verifica se o(s) jogador(es) estao morto(s)

	// Caso 1: os dois jogadores foram criados
	if (_jog1 != nullptr && _jog2 != nullptr) 
	{
		if (!_jog1->getVivo() && !_jog2->getVivo()) 
		{
			// Finaliza o jogo
			Jogo::mudarStateNum(30);
			_mudouEstado = true;
		}
	}
	// Caso 2: apenas o jogador 1 foi criado
	else if (_jog1 != nullptr) 
	{
		if (!_jog1->getVivo()) 
		{
			// Finaliza o jogo
			Jogo::mudarStateNum(30);
			_mudouEstado = true;
		}
	}
	// Caso 3: apenas o jogador 2 foi criado
	else if (_jog2 != nullptr) 
	{
		if (!_jog2->getVivo()) 
		{
			// Finaliza o jogo
			Jogo::mudarStateNum(30);
			_mudouEstado = true;
		}
	}
}

void Fases::Fase::verificaInimigosVivos()
{
	_terminada = _GC->verificaInimigos();
	if (!_terminada) 
	{
		LimpaArquivo();
		Jogo::mudarStateNum(Constantes::STATE_FIM_JOGO);
		_mudouEstado = true;
	}
}

void Fases::Fase::setTipoFase(int i)
{
	_TipoFase = i;
}

void Fases::Fase::recuperarFase() 
{
	int flagJogador1 = 1;
	std::ifstream arquivoFase("Salvamento.txt", std::ios::in);
	std::vector<Entidades::Mago*> magos;
	int ma = 0;

	if (!arquivoFase) 
	{
		std::cerr << "Erro: Não foi possível abrir o arquivo de salvamento." << std::endl;
		return;
	}

	
	int recupera, terminado;

	if (!(arquivoFase >> recupera >> terminado)) 
	{
		std::cerr << "Erro: Arquivo de salvamento corrompido ou vazio." << std::endl;
		return;
	}
	

	while (!arquivoFase.eof()) 
	{
		int _Tipo;
		bool _ehThread, _onGround;
		float posX, posY, speedX, speedY;

		if (!(arquivoFase >> _Tipo >> _ehThread >> _onGround >> posX >> posY >> speedX >> speedY)) 
		{
			break;
		}

		
		if (_Tipo == Constantes::TIPO_JOGADOR)
		{
			int vidas, direcao;
			std::string nome = " ";
			bool ehJog1;

			if (!(arquivoFase >> vidas >> direcao >> nome >> ehJog1)) 
			{
				std::cerr << "Erro ao ler dados do Jogador." << std::endl;
				continue;
			}

			Entidades::Jogador* jog = new Entidades::Jogador(posX, posY, _GG, nome);
			jog->setDirecao(direcao);
			jog->setVidas(vidas);
			jog->setGround(_onGround);

			if (flagJogador1) 
			{
				_jog1 = jog;
				_GC->setJogador1(jog);
				_jogo->setJogador1(_jog1);
				Ranking* rank = _jogo->getRanking();
				rank->verificaPontos(jog);
				_hudJog1 = new Hud(_jog1);
				flagJogador1 = 0;
			}
			else 
			{
				_jog2 = jog;
				_GC->setJogador2(_jog2);
				_jogo->setJogador2(jog);
				Ranking* rank = _jogo->getRanking();
				rank->verificaPontos(jog);
				_hudJog2 = new Hud(jog);
			}
		}
		else if (_Tipo == Constantes::TIPO_CAVALEIRO)
		{
			int vidas, direcao, inX, inY, louc;

			if (!(arquivoFase >> vidas >> direcao >> inX >> inY >> louc)) 
			{
				std::cerr << "Erro ao ler dados do Cavaleiro." << std::endl;
				continue;
			}

			Entidades::Cavaleiro* cav = new Entidades::Cavaleiro(posX, posY, _GG, _jog1, _jog2, vidas);
			cav->setDirecao(direcao);
			cav->setGround(_onGround);
			cav->setSpeed(speedX, speedY);
			cav->setLoucura(louc);

			_Lista->insert_back(static_cast<Entidades::Entidade*>(cav));
			_GC->incluirInimigo(static_cast<Entidades::Inimigo*>(cav));
		}
		else if (_Tipo == Constantes::TIPO_MORTOVIVO)
		{
			int vidas, direcao, inX, inY, energ;
			if (!(arquivoFase >> vidas >> direcao >> inX >> inY >> energ))
			{
				std::cerr << "Erro ao ler dados do MortoVivo" << std::endl;
				continue;
			}

			Entidades::MortoVivo* mort = new Entidades::MortoVivo(posX, posY, _GG, _jog1, _jog2, vidas);
			mort->setDirecao(direcao);
			mort->setGround(_onGround);
			mort->setSpeed(speedX, speedY);
			mort->setEnergetico(energ);

			_Lista->insert_back(static_cast<Entidades::Entidade*>(mort));
			_GC->incluirInimigo(static_cast<Entidades::Inimigo*>(mort));
			
			
		}
		else if (_Tipo == Constantes::TIPO_MORTOVIVO_THREAD)
		{
			int vidas, direcao, inX, inY, energ;
			if (!(arquivoFase >> vidas >> direcao >> inX >> inY >> energ))
			{
				std::cerr << "Erro ao ler dados do MortoVivoThread" << std::endl;
				continue;
			}

			Entidades::MortoVivoThread* mort = new Entidades::MortoVivoThread(posX, posY, _GG, _jog1, _jog2, vidas);
			mort->setDirecao(direcao);
			mort->setGround(_onGround);
			mort->setSpeed(speedX, speedY);
			mort->setEnergetico(energ);

			_Lista->insert_back(static_cast<Entidades::Entidade*>(mort));
			_GC->incluirInimigo(static_cast<Entidades::Inimigo*>(mort));
			
		}
		else if (_Tipo == Constantes::TIPO_MAGO)
		{
			int vidas, direcao, inX, inY, vidasPerdidas;
			float secs;
			if (!(arquivoFase >> vidas >> direcao >> inX >> inY >> secs>>vidasPerdidas))
			{
				std::cerr << "Erro ao ler dados do Mago" << std::endl;
				continue;
			}
			Entidades::Mago* mag = new Entidades::Mago(posX, posY, _GG, _jog1, _jog2, vidas);
			mag->setDirecao(direcao);
			mag->setGround(_onGround);
			mag->setSpeed(speedX, speedY);
			mag->setVidasPerdidas(vidasPerdidas);
			mag->setSegIntervalo(secs);
			_Lista->insert_back(static_cast<Entidades::Entidade*>(mag));
			_GC->incluirInimigo(static_cast<Entidades::Inimigo*>(mag));
			magos.push_back(mag);
		}
		else if (_Tipo == Constantes::TIPO_PLATAFORMA)
		{
			bool danoso;
			if (!(arquivoFase >> danoso))
			{
				std::cerr << "Erro ao ler dados de Plataforma" << std::endl;
				continue;
			}
			Entidades::Plataforma* plat = new Entidades::Plataforma(posX, posY, _GG);
			_Lista->insert_back(static_cast<Entidades::Entidade*>(plat));
			_GC->incluirObstaculo(static_cast<Entidades::Obstaculo*>(plat));
		}
		else if (_Tipo == Constantes::TIPO_BARRA_MAGICA)
		{
			float duracaoParalisia;
			bool danoso;
			if (!(arquivoFase >> danoso >> duracaoParalisia))
			{
				std::cerr << "Erro ao ler dados de BarraMagica" << std::endl;
				continue;
			}
			Entidades::BarraMagica* bar = new Entidades::BarraMagica(posX, posY, _GG);
			_Lista->insert_back(static_cast<Entidades::Entidade*>(bar));
			_GC->incluirObstaculo(static_cast<Entidades::Obstaculo*>(bar));
		}
		else if (_Tipo == Constantes::TIPO_ESPINHO)
		{
			int dano;
			bool danoso;
			if (!(arquivoFase >> danoso >> dano))
			{
				std::cerr << "Erro ao ler dados de Espinho" << std::endl;
				continue;
			}
			Entidades::Espinho* esp = new Entidades::Espinho(dano,posX, posY, _GG);
			_Lista->insert_back(static_cast<Entidades::Entidade*>(esp));
			_GC->incluirObstaculo(static_cast<Entidades::Obstaculo*>(esp));
		
		}
		else if (_Tipo == Constantes::TIPO_PROJETIL)
		{
			int dano;
			bool lancar;
			
			if (!(arquivoFase >> dano>>lancar))
			{
				std::cerr << "Erro ao ler dados de Projetil" << std::endl;
				continue;
			}
			Entidades::Projetil* proj = new Entidades::Projetil(posX,posY,_GG);
			_Lista->insert_back(static_cast<Entidades::Entidade*>(proj));
			_GC->incluirProjetil(static_cast<Entidades::Projetil*>(proj));
			proj->setDano(dano);
			proj->setLancar(lancar);
			if (ma >= magos.size())
			{
				std::cerr << "Erro: Índice 'ma' fora dos limites do vetor magos." << std::endl;
				delete proj; // Evita vazamento de memória
				break;
			}

			// Define o projetil para o mago correspondente
			magos[ma]->setProjetil(proj);
			ma++;
		}
		else
		{
			std::cerr << "Erro: Tipo de entidade desconhecido (" << _Tipo << ")." << std::endl;
			continue;
		}
	}

	arquivoFase.close();
	Entidades::Jogador::setContador(0);
	LimpaArquivo();
}
void Fases::Fase::setJogo(Jogo* jo)
{
	_jogo = jo;
}
