#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>

typedef int posicion;
const posicion POSICION_ERROR=-1;

using namespace std;

template<class TipoElemento>
class Lista {
    TipoElemento* elementos;
    posicion ult;
    string nombre;
    int capacidad;
public:
    Lista(int capacidad);
    Lista();
    ~Lista();
    void inserta(TipoElemento& x, posicion p);
    void inserta(TipoElemento& x);
    posicion localiza(TipoElemento& x);
    TipoElemento* recupera(posicion p);
    void suprime(posicion p);
    posicion siguiente(posicion p);
    posicion anterior(posicion p);
    posicion primero();
    void imprimeLista();
    posicion fin();
    posicion ultimo();
    bool estaVacia();
    bool estaLlena();
    void imprimeError(string info);
    bool mismo(TipoElemento& x,TipoElemento& y);
    int dameLongitud();
    int dameCapacidad();
    Lista<TipoElemento>* concatenar(Lista& l);
    void fijaNombre(string n);
    string dameNombre();
};

#endif
