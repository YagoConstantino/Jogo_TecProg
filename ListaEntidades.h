#pragma once
#include "Lista.h"
#include "Entidade.h"

namespace Listas
{
	class ListaEntidades
	{
	private:
		Listas::ListaElementar<Entidades::Entidade> List;

	public:
		ListaEntidades();
		~ListaEntidades();

		void insert_front(Entidades::Entidade* enti);
		void insert_back(Entidades::Entidade* enti);
		void remove_front();
		void remove_back();
		void remove_ID(int id);
		void limpar();

		bool empty();

		void percorrer();
		void startThread();
		void joinThread();
		void registrarDados();
		void salvar(std::ofstream& arquivo);
		void executar();

	};
}