#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include <vector>
#include <map>
#include "Ente.h"
#include "Gerenciador_Grafico.h"

class Menu : public Entidades::Ente 
{
private:
	// State Num
	int stateNum;
	
	sf::Mouse _mouse;
	bool _houveClique;

	sf::Text _titulo;

	std::map<int, sf::Text> _botoes;
	std::vector<std::string> _textosBotoes;

	sf::Font _fonte;

	std::map<int, std::function<void()> > _funcoesBotoes;

public:
	Menu(Gerenciadores::Gerenciador_Grafico* _pGraf = nullptr);
	~Menu();
	
	void carregarFonte();

	void criarBotoes();
	void criarTitulo();
	void criarBackground();
	
	void verificarMouse();
	void verificarMovimento();

	void destacarTexto(sf::Text& texto);
	void reposicionarTexto(sf::Text& texto);
	void padronizar(sf::Text& texto, int id);

	void executarJogar();
	void executarRanking();
	void executarSair();

	void executar();

	const int getStateNum() const;
};