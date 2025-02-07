#include "Ranking.h"

Ranking::Ranking() : leaderbord(), arquivoEntrada(),arquivoSaida()
{
    recuperaDados();
    ordenaVetor();
}

Ranking::~Ranking()
{
    salvarDados();
}

void Ranking::trocar(pair<string, int>& v1, pair<string, int>& v2)
{
    pair<string, int> aux = v1;
    v1 = v2;
    v2 = aux;
}

void Ranking::ordenaVetor()
{
    vector<pair<string, int>>::iterator it1;
    vector<pair<string, int>>::iterator it2;
    vector<pair<string, int>>::iterator maior;

    for (it1 = leaderbord.begin(); it1 != leaderbord.end(); ++it1)
    {
        maior = it1;
        for (it2 = it1 + 1; it2 != leaderbord.end(); ++it2)
        {
            if (it2->second > maior->second)
            {
                maior = it2;
            }
        }

        trocar(*it1, *maior);
    }
}

void Ranking::imprimirLeaderboard()
{
    vector<pair<string, int>>::iterator aux;
    for (aux = leaderbord.begin(); aux != leaderbord.end(); ++aux)
    {
        cout << aux->first << ".........." << aux->second << endl;
    }
}

void Ranking::recuperaDados()
{
    try
    {
        arquivoEntrada.open("Ranking.txt");
        if (!arquivoEntrada.is_open())
        {
            throw runtime_error("Erro ao abrir o arquivo para leitura.");
        }

        leaderbord.clear();
        string nome;
        int pontos;
        while (arquivoEntrada >> nome >> pontos)
        {
            pair<string, int> par = { nome, pontos };
            leaderbord.push_back(par);
        }

        arquivoEntrada.close();
    }
    catch (const exception& e)
    {
        cerr << "Exceção em recuperarDados: " << e.what() << endl;
    }
}

void Ranking::salvarDados()
{
    try
    {
        arquivoSaida.open("Ranking.txt");
        if (!arquivoSaida.is_open())
        {
            throw runtime_error("Erro ao abrir o arquivo para escrita.");
        }

        vector<pair<string, int>>::iterator aux;
        for (aux = leaderbord.begin(); aux != leaderbord.end(); ++aux)
        {
            arquivoSaida << aux->first << " " << aux->second << endl;
        }

        arquivoSaida.close();
    }
    catch (const exception& e)
    {
        cerr << "Exceção em salvarDados: " << e.what() << endl;
    }
}

void Ranking::atualizaLeaderboard(Entidades::Jogador* pJog)
{
    if (pJog == nullptr)
    {
        cerr << "Ponteiro de Jogador Nulo\n" << endl;
        return;
    }

    string nome = pJog->getNome();
    int pontos = pJog->getPontos();
    bool encontrado = false;
    int i;
    for (i = 0; i < leaderbord.size() && !encontrado; i++)
    {
        if (leaderbord[i].first == nome)
        {
            leaderbord[i].second = pontos;
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        pair<string, int> par = { nome,pontos };
        leaderbord.push_back(par);
    }
    ordenaVetor();
}

void Ranking::verificaPontos(Entidades::Jogador* pJog)
{
    if (!pJog)
    {
        cerr << "Ponteiro para Jogador Nulo\n" << endl;
        return;
    }
    int i;
    for (i = 0; i < leaderbord.size(); i++)
    {
        if (pJog->getNome() == leaderbord[i].first)
        {
            pJog->SetPontos(leaderbord[i].second);
            return;
        }
    }
    cerr << "Jogador não encontrado no ranking.\n" << endl;
}

vector<pair<string, int>> Ranking::getVector() const
{
    return leaderbord;
}
