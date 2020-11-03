#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>

typedef int posicion;
const int CAPACIDAD_MINIMA = 25;
const posicion POSICION_ERROR=-1;

using namespace std;

/** @class Lista encargada de manejar los elementos con distintas operaciones
*/
template<class TipoElemento>
class Lista {
    TipoElemento* elementos;
    posicion ult;
    string nombre;
    int capacidad;
public:
    Lista(int capacidad,
          string nombre);
    Lista();
    ~Lista();
    void inserta(TipoElemento& x,
                 posicion p);
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
    bool mismo(TipoElemento& x,
               TipoElemento& y);
    int dameLongitud();
    int dameCapacidad();
    Lista<TipoElemento>* concatenar(Lista& l);
    void fijaNombre(string n);
    string dameNombre();
};

/** Metodo constructor encargado de definir una lista con capacidad inicial
 *  @param capacidad cantidad de elementos iniciales
 *  @param nombre nombre de la lista
*/
template<class TipoElemento>
Lista<TipoElemento>::Lista(int capacidad,
                           string nombre) {
    this->ult = POSICION_ERROR;
    this->nombre = nombre;
    this->elementos = new TipoElemento[this->capacidad = capacidad];
}

/** Metodo constructor encargado de definir una lista con capacacidad minima
*/
template<class TipoElemento>
Lista<TipoElemento>::Lista():
    Lista(CAPACIDAD_MINIMA) {
}

/** Metodo destructor
 */
template<class TipoElemento>
Lista<TipoElemento>::~Lista() {
    delete[] elementos;
}

/** Fijar el nombre de la lista
 *  @param n nombre de la lista a fijar
 */
template<class TipoElemento>
void Lista<TipoElemento>::fijaNombre(string n) {
    this->nombre = n;
}

/** Obtener el nombre de la lista
 * @return nombre de la lista tipo string
 */
template<class TipoElemento>
string Lista<TipoElemento>::dameNombre() {
    return nombre;
}

/** Insertar un elemento al final de la lista
 *  @param x elemento a insertar
 */
template<class TipoElemento>
void Lista<TipoElemento>::inserta(TipoElemento& x) {
    inserta(x,fin());
}

/** Obtener la posicion siguiente dada una posicion
 *  @param p posicion dada
 *  @return posición siguiente
 */
template<class TipoElemento>
posicion Lista<TipoElemento>::siguiente(posicion p) {
    posicion pos;
    if (p>=primero() && p<=ult) {
        pos = p+1;
    } else {
        imprimeError("Posicion siguiente no existe");
        pos = POSICION_ERROR;
    }
    return pos;
}

/** Obtener la posicion anterior dada una posicion
 *  @param p posicion dada
 *  @return posición anterior
 */ 
template<class TipoElemento>
posicion Lista<TipoElemento>::anterior(posicion p) {
    posicion pos;
    if (p>primero() && p<=fin()) {
        pos = p-1;
    } else {
        imprimeError("Posicion anterior no existe");
        pos = POSICION_ERROR;
    }
    return pos;
}

/** Obtener la posicion final
 */ 
template<class TipoElemento>
posicion Lista<TipoElemento>::fin() {
    return ult + 1;
}

/** Obtener la primera posicion
 */ 
template<class TipoElemento>
posicion Lista<TipoElemento>::primero() {
    posicion pos;
    if (!estaVacia()) {
        pos = 0;
    } else {
        pos = fin();
    }
    return pos;
}

/** Obtener la ultima posicion
 */ 
template<class TipoElemento>
posicion Lista<TipoElemento>::ultimo() {
    posicion pos;
    if (estaVacia()) {
        pos = POSICION_ERROR;
    } else {
        pos = anterior(fin());
    }
    return pos;
}

/** Valida si existe o no la lista
 */
template<class TipoElemento>
bool Lista<TipoElemento>::estaVacia() {
    return ult<0;
}

/** Valida si la lista esta llena o no
 */
template<class TipoElemento>
bool Lista<TipoElemento>::estaLlena() {
    return ult>=capacidad-1;
}

/** Imprimir un error ocasionado por el programador al usar la lista
 *  @param info mensaje a mostrar
 */
template<class TipoElemento>
void Lista<TipoElemento>::imprimeError(string info) {
    cout << "ERROR DEL PROGRAMADOR: " << info << endl;
}

/** Obtener la longitud de la lista
 */
template<class TipoElemento>
int Lista<TipoElemento>::dameLongitud() {
    return ult + 1;
}

/** Obtener la capacidad maxima de la lista
 */
template<class TipoElemento>
int Lista<TipoElemento>::dameCapacidad() {
    return capacidad;
}

/** Insertar un elemento en una posicion dada
 *  @param x elemento a insertar
 *  @param p posicion en donde se va a insertar
 */
template<class TipoElemento>
void Lista<TipoElemento>::inserta(TipoElemento& x,
                                  posicion p) {
    posicion q;
    if (estaLlena()) {
        imprimeError("La lista esta llena");
    } else if ((p<primero()) || (p>fin())) {
        imprimeError("La posicion a insertar no existe");
    } else {
        for (q=ult; q>=p; q--) {
            elementos[q+1] = elementos[q];
        }
        ult++;
        elementos[p] = x;
    }
}

/** Recuperar un elemento dada una posicion
 *  @param p posicion donde se encuentra
 *  @return elemento encontrado
 */ 
template<class TipoElemento>
TipoElemento* Lista<TipoElemento>::recupera(posicion p) {
    TipoElemento* elemento = 0;
    if (p>=primero() && p<=ult) {
        elemento = &(elementos[p]);
    }
    return elemento;
}

/** Localizar la posicion de un elemento en la lista
 *  @param x elemento a buscar
 *  @return posicion donde se encuentra el elemento
 */
template<class TipoElemento>
posicion Lista<TipoElemento>::localiza(TipoElemento* x){
    posicion p;
    posicion q;
    for(p=primero(),q=ult;p<=q;p++){
        if (*recupera(p)==*x) {
            break;
        }
    }
    return p;
}

/** Borrar un elemento de la lista dada una posicion
 *  @param p posicion del elemento a borrar
 */ 
template<class TipoElemento>
void Lista<TipoElemento>::suprime(posicion p) {
    posicion q;
    posicion r;
    if ((p<primero()) || (p>ult)) {
        imprimeError("La posicion a suprimir no existe");
    } else {
        r=--(ult);
        for(q=p; q<=r; q++) {
            elementos[q]=elementos[q+1];
        }
    }
}

/** Comparar si dos elementos son iguales
 *  @param x elemento 1 a comparar
 *  @param y elemento 2 a comparar
 *  @return Son iguales o no
 */ 
template<class TipoElemento>
bool Lista<TipoElemento>::mismo(TipoElemento& x,
               TipoElemento& y){
    return x == y;
}

#endif
