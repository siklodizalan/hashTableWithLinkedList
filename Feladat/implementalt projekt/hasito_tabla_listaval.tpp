#include "hasito_tabla_listaval.h"
#include <iostream>
#include <math.h>

using namespace std;

// ==============================
//            LISTA
// ==============================

template <typename T1, typename T2>
Lista<T1, T2>::Lista() {

    str1 = new elem<T1, T2>;
    str2 = new elem<T1, T2>;
    str1->utan = str2;
    str2->utan = NULL;
}

template <typename T1, typename T2>
Lista<T1, T2>::~Lista() {

    while (str1->utan != str2) {

        TorlesHatul();
    }
    delete str1;
    delete str2;
}

template <typename T1, typename T2>
elem<T1, T2>* Lista<T1, T2>::LetrehozElem(T1 ujKulcs, T2 ujErtek) {

    elem<T1, T2>* p = new elem<T1, T2>;
    p->kulcs = ujKulcs;
    p->ertek = ujErtek;
    p->utan = NULL;
    return p;
}

template <typename T1, typename T2>
void Lista<T1, T2>::FelszabaditElem(elem<T1, T2>* p) {

    delete p;
}

template <typename T1, typename T2>
elem<T1, T2>* Lista<T1, T2>::ElsoElem() {

    return str1->utan;
}

template <typename T1, typename T2>
elem<T1, T2>* Lista<T1, T2>::UtolsoElem() {

    elem<T1, T2>* tmp = str1;
    while (tmp->utan != str2) {

        tmp = tmp->utan;
    }
    return tmp;
}

template <typename T1, typename T2>
void Lista<T1, T2>::BeszurEle(elem<T1, T2>* p, T1 ujKulcs, T2 ujErtek) {

    elem<T1, T2>* q = LetrehozElem(ujKulcs, ujErtek);
    q->utan = p->utan;
    q->kulcs = p->kulcs;
    q->ertek = p->ertek;
    p->utan = q;
    p->kulcs = ujKulcs;
    p->ertek = ujErtek;
}

template <typename T1, typename T2>
void Lista<T1, T2>::BeszurUtan(elem<T1, T2>* p, T1 ujKulcs, T2 ujErtek) {

    elem<T1, T2>* q = LetrehozElem(ujKulcs, ujErtek);
    q->utan = p->utan;
    p->utan = q;
}

template <typename T1, typename T2>
void Lista<T1, T2>::VegereSzur(T1 ujKulcs, T2 ujErtek) {

    elem<T1, T2>* p = str2;
    str2 = new elem;
    p->kulcs = ujKulcs;
    p->ertek = ujErtek;
    p->utan = str2;
}

template <typename T1, typename T2>
void Lista<T1, T2>::ElejereSzur(T1 ujKulcs, T2 ujErtek) {

    elem<T1, T2>* p = LetrehozElem(ujKulcs, ujErtek);
    p->utan = str1->utan;
    str1->utan = p;
}

template <typename T1, typename T2>
void Lista<T1, T2>::TorlesElol() {

    if (Ures()) {

        throw "Ures a lista, nem lehetseges a torles!";
    }
    else {

        elem<T1, T2>* tmp = ElsoElem();
        TorolElem(tmp->kulcs);
    }
}

template <typename T1, typename T2>
void Lista<T1, T2>::TorlesHatul() {

    if (Ures()) {

        throw "Ures a lista, nem lehetseges a torles!";
    }
    else {

        elem<T1, T2>* tmp = UtolsoElem();
        TorolElem(tmp->kulcs);
    }
}

template <typename T1, typename T2>
void Lista<T1, T2>::TorolElem(T1 torlendo) {

    elem<T1, T2>* p = ElsoElem();

    if (p == str2) {

        throw "Ures a lista, nem lehetseges a torles!";
    }

    while (p->kulcs != torlendo && p != UtolsoElem()) {

        p = p->utan;
    }

    if (p->kulcs != torlendo && p == UtolsoElem()) {

        throw "A megadott kulccsal rendelkezo elem nincs a hasitotablaban!";
    }
    else {

        elem<T1, T2>* r = p;

        if (r != UtolsoElem()) {

            r = p->utan;
            p->utan = r->utan;
            p->kulcs = r->kulcs;
            p->ertek = r->ertek;
            FelszabaditElem(r);
        }
        else {

            elem<T1, T2>* tmp = str1;

            while (tmp->utan != UtolsoElem()) {

                tmp = tmp->utan;
            }

            tmp->utan = str2;
            FelszabaditElem(r);
        }
    }
}

template <typename T1, typename T2>
vector<T2> Lista<T1, T2>::Kereses(T1 keresendo) {

    vector<T2> k;

    elem<T1, T2>* tmp = ElsoElem();

    int i = 0;
    while (tmp != str2) {

        if (tmp->kulcs == keresendo) {
            
            k.resize(i + 1);
            k[i] = tmp->ertek;
            i++;
        }
        tmp = tmp->utan;
    }

    return k;
}

template <typename T1, typename T2>
void Lista<T1, T2>::BejarElejerol() {

    elem<T1, T2>* p = ElsoElem();

    while (p != str2) {

        cout << "(" << p->kulcs << ", " << p->ertek << ") ";
        p = p->utan;
    }
    cout << endl;
}

template <typename T1, typename T2>
bool Lista<T1, T2>::Ures() {

    return (str1->utan == str2);
}

// ==============================
//       PLUSSZ FUGGVENYEK
// ==============================

bool prim_e(int n)
{
    if (n <= 1) {

        return false;
    }
    if (n <= 3) {

        return true;
    }

    if (n % 2 == 0 || n % 3 == 0) {

        return false;
    }

    for (int i = 5; i * i <= n; i = i + 6) {

        if (n % i == 0 || n % (i + 2) == 0) {

            return false;
        }
    }

    return true;
}

int meretKereses(int n) {
    
    int N = 1.3 * n;

    if (N <= 1) {

        return 2;
    }

    int prim = N;
    bool talalt = false;

    while (!talalt) {

        prim++;
        if (prim_e(prim)) {

            talalt = true;
        }
    }

    return prim;
}

// ==============================
//     HASITO TABLA LISTAVAL
// ==============================

template <typename T1, typename T2>
double HasitoTablaListaval<T1, T2>::Telitettseg() {

    return (double)elemekSzama / meret;
}

template <typename T1, typename T2>
int HasitoTablaListaval<T1, T2>::HasitoFuggveny(T1& ujKulcs) {
    
    uint32_t kulcsMeret = sizeof(ujKulcs);
    const uint8_t* byte = reinterpret_cast<const uint8_t*>(&ujKulcs);

    uint32_t index = 0;
    for (uint32_t i = 0; i < kulcsMeret; i++) {
        
        index += byte[i] << (23 * i % 24);
        index += byte[i] << (23 * (kulcsMeret - i) % 24);
    }

    return index % meret;
}

template <typename T1, typename T2>
HasitoTablaListaval<T1, T2>::HasitoTablaListaval() {

    meret = 0;
    elemekSzama = 0;
    H.resize(meret);
    for (int i = 0; i < meret; i++) {

        H[i] = new Lista<T1, T2>();
    }
}

template <typename T1, typename T2>
HasitoTablaListaval<T1, T2>::~HasitoTablaListaval () {
    
    H.clear();
}

template <typename T1, typename T2>
HasitoTablaListaval<T1, T2>::HasitoTablaListaval(int m) {

    meret = meretKereses(m);
    elemekSzama = 0;
    H.resize(meret);
    for (int i = 0; i < meret; i++) {

        H[i] = new Lista<T1, T2>();
    }
}

template <typename T1, typename T2>
void HasitoTablaListaval<T1, T2>::BeallitMeret(int m) {

    meret = meretKereses(m);
    elemekSzama = 0;
    H.resize(meret);
    for (int i = 0; i < meret; i++) {

        H[i] = new Lista<T1, T2>();
    }
}

template <typename T1, typename T2>
void HasitoTablaListaval<T1, T2>::UjraHasheles() {
    
    int regiMeret = meret;
    meret = (meret * 2) + 1;
    elemekSzama = 0;

    vector<Lista<T1, T2>*> ujH;
    ujH.resize(meret);
    for (int i = 0; i < meret; i++) {

        ujH[i] = new Lista<T1, T2>();
    }

    elem<T1, T2>* tmp;

    for (int i = 0; i < regiMeret; i++) {
        
        tmp = H[i]->ElsoElem();
        while (tmp->utan != NULL) {

            int i = HasitoFuggveny(tmp->kulcs);
            ujH[i]->ElejereSzur(tmp->kulcs, tmp->ertek);
            elemekSzama++;

            tmp = tmp->utan;
        }
    }

    H.clear();
    H.resize(meret);
    for (int i = 0; i < meret; i++) {
    
        H[i] = new Lista<T1, T2>();
    }
    H = ujH;
}

template <typename T1, typename T2>
void HasitoTablaListaval<T1, T2>::Beszur(T1 ujKulcs, T2 ujErtek) {

    if (Telitettseg() > 0.75) {
        
        UjraHasheles();
    }

    int i = HasitoFuggveny(ujKulcs);
    H[i]->ElejereSzur(ujKulcs, ujErtek);
    elemekSzama++;
}

template <typename T1, typename T2>
void HasitoTablaListaval<T1, T2>::Torol(T1 torlendo) {

    int i = HasitoFuggveny(torlendo);
    H[i]->TorolElem(torlendo);
    elemekSzama--;
}

template <typename T1, typename T2>
vector<T2> HasitoTablaListaval<T1, T2>::Keres(T1 keresendo) {

    int i = HasitoFuggveny(keresendo);
    vector<T2> keresendoAdat = H[i]->Kereses(keresendo);
    return keresendoAdat;
}

template <typename T1, typename T2>
void HasitoTablaListaval<T1, T2>::Kiir() {

    for (int i = 0; i < meret; i++) {
        
        H[i]->BejarElejerol();
    }
}