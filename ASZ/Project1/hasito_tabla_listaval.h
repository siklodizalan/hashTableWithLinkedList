#pragma once

//#ifndef LISTA_H_INCLUDED
//#define LISTA_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

// ==============================
//            ELEM
// ==============================

template<typename T1, typename T2>
struct elem {

    T1 kulcs;
    T2 ertek;
    elem* utan;
};

// ==============================
//            LISTA
// ==============================

template<typename T1, typename T2>
class Lista {

    elem<T1, T2>* str1;
    elem<T1, T2>* str2;

public:
    Lista();
    ~Lista();

    elem<T1, T2>* LetrehozElem(T1, T2);
    void FelszabaditElem(elem<T1, T2>* p);

    void BeszurEle(elem<T1, T2>* p, T1, T2);
    void BeszurUtan(elem<T1, T2>* p, T1, T2);
    void VegereSzur(T1, T2);
    void ElejereSzur(T1, T2);

    void TorlesElol();
    void TorlesHatul();
    void TorolElem(T1);

    void BejarElejerol();

    vector<T2> Kereses(T1);

    elem<T1, T2>* ElsoElem();
    elem<T1, T2>* UtolsoElem();
    bool Ures();
};

// ==============================
//     HASITO TABLA LISTAVAL
// ==============================

template<typename T1, typename T2>
class HasitoTablaListaval {

    int meret;
    int elemekSzama;
    vector<Lista<T1, T2>*> H;

    double Telitettseg();
    int HasitoFuggveny(T1&);
    void UjraHasheles();

public:

    HasitoTablaListaval();
    ~HasitoTablaListaval();
    HasitoTablaListaval(int);
    void BeallitMeret(int);
    void Beszur(T1, T2);
    void Torol(T1);
    vector<T2> Keres(T1);
    void Kiir();
};

// ==============================
//       PLUSSZ FUGGVENYEK
// ==============================

int meretKereses(int n);
bool prim_e(int n);

#include "hasito_tabla_listaval.tpp"

//#endif /* LISTA_H_INCLUDED */
