#pragma once

template <typename T>
class ListaElementar
{
public:
	class Elemento
	{
	private:
		T* pInfo;
		Elemento* next;
		Elemento* prev;

	public:
		Elemento() : pInfo(nullptr), next(nullptr),prev(nullptr){}
		~Elemento() {
			pInfo = nullptr;
		}

		Elemento* GetNext() const { return next; }
		Elemento* GetPrev() const { return prev; }
		T* getInfo() const { return pInfo; }

		void setNext(Elemento* pNext) { next = pNext; }
		void setPrev(Elemento* pPrev) { prev = pPrev; }
		void setInfo(T* pInf) { pInfo = pInf; }
	};
	ListaElementar() : head(nullptr), tail(nullptr) {}

	~ListaElementar()
	{
		limpar();
	}

	void insert_front(T* pTipo);
	void insert_back(T* pTipo);
	void remove_front();
	void remove_back();
	void remove_ID(int id);

	void limpar();

	Elemento* getHead() const { return head; }
	Elemento* getTail() const { return tail; }
	void setHead(Elemento* elem) { if (elem) head = elem; }
	void setTail(Elemento* elem) { if (elem) tail = elem; }


	Elemento* operator[](int i)
	{
		if (i < 0) return nullptr;  // Índice negativo retorna nullptr

		Elemento* aux = getHead();
		int cont = 0;


		while (cont < i)
		{
			if (aux == nullptr)
			{
				std::cout << "Índice fora dos limites!" << std::endl;
				return nullptr;
			}

			aux = aux->GetNext();
			cont++;
		}

		return aux;
	}

private:
	Elemento* head;
	Elemento* tail;
};

template<typename T>
void ListaElementar<T>::insert_front(T* pTipo)
{
	if (pTipo != nullptr)
	{
		Elemento* novoElem = new Elemento();
		novoElem->setInfo(pTipo);
		if (getHead() == nullptr)
		{
			setHead(novoElem);
			setTail(novoElem);
		}
		else
		{
			novoElem->setNext(head);
			head->setPrev(novoElem);
			setHead(novoElem);
		}
	}
	else
	{
		std::cout << "Ponteiro Inválido" << std::endl;
	}
}

template<typename T>
void ListaElementar<T>::insert_back(T* pTipo)
{
	if (pTipo != nullptr)
	{
		Elemento* novoElem = new Elemento();
		novoElem->setInfo(pTipo);
		if (getTail() == nullptr)
		{
			setHead(novoElem);
			setTail(novoElem);
		}
		else
		{
			novoElem->setPrev(tail);
			tail->setNext(novoElem);
			setTail(novoElem);
		}
	}
	else
	{
		std::cout << "Ponteiro Inválido" << std::endl;
	}
}

template<typename T>
void ListaElementar<T>::remove_front()
{
	if (head == nullptr)
	{
		std::cout << "Não há o que remover" << std::endl;
	}
	else
	{
		Elemento* aux = head;
		setHead(head->GetNext());
		if (head != nullptr)
		{
			head->setPrev(nullptr);
		}
		delete aux;
	}
}

template<typename T>
void ListaElementar<T>::remove_back()
{
	if (tail == nullptr)
	{
		std::cout << "Não há o que remover" << std::endl;
	}
	else
	{
		Elemento* aux = tail;
		setTail(tail->GetPrev());
		if (tail != nullptr)
		{
			tail->setNext(nullptr);
		}
		delete aux;
	}
}

template<typename T>
void ListaElementar<T>::remove_ID(int id)
{
	Elemento* aux = head;

	// Procurar o elemento com o ID
	while (aux != nullptr && aux->getInfo()->getID() != id) {
		aux = aux->GetNext();
	}

	if (aux == nullptr) {
		std::cout << "Não é possível remover, ID inválido" << std::endl;
		return;
	}

	if (aux == head && aux == tail) {
		head = nullptr;
		tail = nullptr;
	}

	else if (aux == head) {
		head = aux->GetNext();
		head->setPrev(nullptr);
	}

	else if (aux == tail) {
		tail = aux->GetPrev();
		tail->setNext(nullptr);
	}
	else {
		aux->GetPrev()->setNext(aux->GetNext());
		aux->GetNext()->setPrev(aux->GetPrev());
	}

	delete aux;
}

template<typename T>
inline void ListaElementar<T>::limpar()
{
	Elemento* atual = head;
	while (atual) {
		Elemento* prox = atual->GetNext();
		delete atual;  // Libera a memória alocada
		atual = prox;
	}
	head = tail = nullptr;
}

