#pragma once

template<typename TIPO>
class Elemento
{
private:
    TIPO* pInfo;                      
    Elemento<TIPO>* next;             
    Elemento<TIPO>* prev;             

public:
    Elemento() : pInfo(nullptr), next(nullptr), prev(nullptr) {}

    ~Elemento() 
    {
        pInfo = nullptr;
    }

    
    Elemento<TIPO>* GetNext() const { return next; }
    Elemento<TIPO>* GetPrev() const { return prev; }
    TIPO* getInfo() const { return pInfo; }

    void setNext(Elemento<TIPO>* pNext) { if(pNext) next = pNext; }
    void setPrev(Elemento<TIPO>* pPrev) { if(pPrev) prev = pPrev; }
    void setInfo(TIPO* pInf) { if(pInf) pInfo = pInf; }
};
