#pragma once
/*
Codigo inspirado na aula apresentada por Jean Simão durante a disciplina de Técnicas de Programação
na UTFPR no semestre 2024/2
Link para a aula : https://pessoal.dainf.ct.utfpr.edu.br/jeansimao/Fundamentos2/ThreadsPosix/Fundamentos1-2-SlidesC++18C.htm
*/
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <stdexcept>
using namespace std;

class ThreadCPP
{
private:
    thread _thread;

    static mutex* _mutex;

protected:
    static void* runThread(void* pthread);
    virtual void run() = 0;
    void printError(const string& msg)const;

public:
    ThreadCPP();
    ~ThreadCPP();
    void start();
    void yield();
    void join();

    void lockMutex();
    void unlockMutex();

};