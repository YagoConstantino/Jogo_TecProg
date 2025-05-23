#include "ListaEntidades.h"
#include "Personagem.h"
#include "MortoVivoThread.h"
#include "Thread.h"
Listas::ListaEntidades::ListaEntidades() : List() {}

Listas::ListaEntidades::~ListaEntidades() 
{
    limpar();
}

void Listas::ListaEntidades::insert_front(Entidades::Entidade* enti) 
{
    List.insert_front(enti); 
}

void Listas::ListaEntidades::insert_back(Entidades::Entidade* enti) 
{
    List.insert_back(enti); 
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
        std::cout << "N�o � poss�vel remover, ID inv�lido" << std::endl;
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
            Entidades::MortoVivoThread* mortoTH = static_cast<Entidades::MortoVivoThread*>(ente);
            mortoTH->start();
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
            Entidades::MortoVivoThread* mortoTH = static_cast<Entidades::MortoVivoThread*>(ente);
            mortoTH->lockMutex();
            mortoTH->setRodar(false);
            mortoTH->setVivo(false);
            mortoTH->join();
            mortoTH->unlockMutex();
        }
    }
    delete it;
}

void Listas::ListaEntidades::registrarDados()
{
    Listas::ListaElementar<Entidades::Entidade>::Iterator* it = List.getIterator();
    while (it->hasPNext())
    {
        Entidades::Entidade* ente = it->Atual(); // Obter o ponteiro para Entidade
        if (ente != nullptr && ente->getVivo())
        {
            ente->registraDados();
        }

    }
    delete it;
}

void Listas::ListaEntidades::salvar(std::ofstream& arquivo)
{
    Listas::ListaElementar<Entidades::Entidade>::Iterator* it = List.getIterator();
    while (it->hasPNext())
    {
        Entidades::Entidade* ente = it->Atual(); // Obter o ponteiro para Entidade
        if (ente != nullptr && ente->getVivo())
        {
            ente->SalvarDataBuffer(arquivo);
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
            ente->executar(); 
            if(ente->getEhThread())
            {
                Entidades::MortoVivoThread* morto = static_cast<Entidades::MortoVivoThread*>(ente);
                morto->lockMutex();
                morto->setRodar(true);
                morto->unlockMutex();
            }
        }
        
    }
    delete it;
}
