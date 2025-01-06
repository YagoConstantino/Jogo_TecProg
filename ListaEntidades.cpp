#include "ListaEntidades.h"
#include "Personagem.h"
#include "BruxaThread.h"
Listas::ListaEntidades::ListaEntidades() : List() {}

Listas::ListaEntidades::~ListaEntidades() 
{
    limpar();
}

void Listas::ListaEntidades::insert_front(Entidades::Entidade* enti) {
    List.insert_front(enti); // Passa o ponteiro diretamente
}

void Listas::ListaEntidades::insert_back(Entidades::Entidade* enti) {
    List.insert_back(enti); // Passa o ponteiro diretamente
}

void Listas::ListaEntidades::remove_front() {
    List.remove_front();
}

void Listas::ListaEntidades::remove_back() {
    List.remove_back();
}

void Listas::ListaEntidades::remove_ID(int id) 
{
   Listas::ListaElementar<Entidades::Entidade>::Elemento* aux = List.getHead();

    // Procurar o elemento com o ID
    while (aux != nullptr && aux->getInfo() != nullptr && (aux->getInfo())->getId() != id) {
        aux = aux->GetNext();
    }

    if (aux == nullptr) {
        std::cout << "Não é possível remover, ID inválido" << std::endl;
        return;
    }

    if (aux == List.getHead() && aux == List.getTail()) {
        List.setHead(nullptr);
        List.setTail(nullptr);
    }
    else if (aux == List.getHead()) {
        List.setHead(aux->GetNext());
        if (List.getHead() != nullptr) {
            List.getHead()->setPrev(nullptr);
        }
    }
    else if (aux == List.getTail()) {
        List.setTail(aux->GetPrev());
        if (List.getTail() != nullptr) {
            List.getTail()->setNext(nullptr);
        }
    }
    else 
    {
        aux->GetPrev()->setNext(aux->GetNext());
        aux->GetNext()->setPrev(aux->GetPrev());
    }
    Entidades::Entidade* perso = aux->getInfo();
    delete perso;
    --List; // Decrementa o tamanho da lista
}

void Listas::ListaEntidades::limpar() 
{
    List.limpar();
}


bool Listas::ListaEntidades::empty()
{
    return List.getSize();
}

void Listas::ListaEntidades::percorrer() {
    Listas::ListaElementar<Entidades::Entidade>::Elemento* aux = List.getHead();
    while (aux != nullptr) 
    {
        Entidades::Entidade* ente = aux->getInfo(); // Obter o ponteiro para Entidade
        if (ente != nullptr) 
        {
            std::cout << "ID da Entidade: " << ente->getId() << '\n';
        }
        aux = aux->GetNext();
    }
}

void Listas::ListaEntidades::startThread()
{
    Listas::ListaElementar<Entidades::Entidade>::Iterator* it = List.getIterator();
    while (it->hasPNext())
    {
        Entidades::Entidade* ente = it->Atual(); // Obter o ponteiro para Entidade
        if (ente->getEhThread())
        {
            Entidades::BruxaThread* bruxaTH = static_cast<Entidades::BruxaThread*>(ente);
            bruxaTH->start();
        }

    }
    delete it;
}

void Listas::ListaEntidades::joinThread()
{
    Listas::ListaElementar<Entidades::Entidade>::Iterator* it = List.getIterator();
    while (it->hasPNext())
    {
        Entidades::Entidade* ente = it->Atual(); // Obter o ponteiro para Entidade
        if (ente->getEhThread())
        {
            Entidades::BruxaThread* bruxaTH = static_cast<Entidades::BruxaThread*>(ente);
            bruxaTH->join();
        }
    }
    delete it;
}

void Listas::ListaEntidades::executar() 
{
    Listas::ListaElementar<Entidades::Entidade>::Iterator* it = List.getIterator();
    while (it->hasPNext()) 
    {
        Entidades::Entidade* ente = it->Atual(); // Obter o ponteiro para Entidade
        if (ente != nullptr && ente->getVivo()) 
        {
            ente->executar(); // Executa a ação da entidade
            if (ente->getEhThread())
            {
                ente->desenhar();
            }
        }
        
    }
    delete it;
}
