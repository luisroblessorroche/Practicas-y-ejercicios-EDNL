#include <iostream>
#include <fstream>
#include "agen.hpp"
#include "agen_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

//------------------------------------------------EJERCICIO 1-------------------------------------------------

template <typename T> int grado_agen(const Agen<T> &A)
{
	return grado_agen_rec(A.raiz(),A);
}

template <typename T> int grado_agen_rec(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return max(contar_hijos(n,A),max(grado_agen_rec(A.hijoIzqdo(n),A),grado_agen_rec(A.hermDrcho(n),A)));
	}
}

template <typename T> int contar_hijos(typename Agen<T>::nodo n, const Agen<T> &A)
{
	int n_hijos = 0;
	typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
	while(hijo != Agen<T>::NODO_NULO)
	{
		n_hijos++;
		hijo = A.hermDrcho(hijo);
	}
	return n_hijos;
}


//--------------------------------------------------EJERCICIO 2----------------------------------------------

template <typename T> int profundidad_nodo(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + profundidad_nodo(A.padre(n),A);
	}
}


//--------------------------------------------------EJERCICIO 3----------------------------------------------

template <typename T> int desequilibrio_agen(const Agen<T> &A)
{
	return desequilibrio_agen_rec(A.raiz(),A);
}

template <typename T> int desequilibrio_agen_rec(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
		int desequilibrio = 0;
		while(hijo != Agen<T>::NODO_NULO)
		{
			int altura_max = altura_max(n,A);
			int altura_min = altura_min(n,A);
			desequilibrio = max(altura_max-altura_min,desequilibrio_agen_rec(A.hijoIzqdo(n),A));
			hijo = A.hermDrcho(n);
		}
		return desequilibrio;
	}
}

template <typename T> int altura_max(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + max(altura_max(A.hijoIzqdo(n),A),altura_max(A.hermDrcho(n),A));
	}
}

template <typename T> int altura_min(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + min(altura_min(A.hijoIzqdo(n),A),altura_min(A.hermDrcho(n),A));
	}
}

//--------------------------------------------------EJERCICIO 4----------------------------------------------

void poda(Agen<int>::nodo n, const Agen<int> &A)
{
	while(A.hijoIzqdo(n) != Agen<int>::NODO_NULO)
	{
		poda(A.hijoIzqdo(n),A);
		A.eliminarHijoIzqdo(n);
	}
}

void poda_agen_rec(Agen<int>::nodo n, int x, const Agen<int> &A)
{
	if(n != Agen<int>::NODO_NULO)
	{
		if(A.elemento(n) == x)
		{
			poda(n,A);
		}
		else
		{
			poda_agen_rec(A.hijoIzqdo(n),x,A);
			poda_agen_rec(A.hermDrcho(n),x,A);
		}
	}
}

void poda_agen(int x, const Agen<int> &A)
{
	poda_agen_rec(A.raiz(),x,A);
}





int main ()
{
	Agen<tElto> A(16);
	cout << "*** Lectura del árbol A ***\n";
	rellenarAgen(A, fin); // Desde std::cin
	ofstream fs("agen.dat"); // Abrir fichero de salida.
 	imprimirAgen(fs, A, fin); // En fichero.
 	fs.close();
 	cout << "\n*** Árbol A guardado en fichero agen.dat ***\n";

	int grado = grado_agen(A);
	cout << "el grado del arbol general es " <<grado<<endl;
	
	Agen<char>::nodo n = A.hijoIzqdo(A.hijoIzqdo(A.hijoIzqdo(A.hijoIzqdo(A.raiz()))));
	int profundidad = profundidad_nodo(n,A);
	cout<<"la profundidad del nodo  e es "<<profundidad<<endl;
	
	/*
	int desequilibrio = desequilibrio_agen(A);
	cout<<"el desequilibrio del arbol es "<<desequilibrio<<endl;
	
	cout<<"se va a proceder a podar el arbol cuya raiz es x"<<endl;
	
	poda_agen(n,A);
	*/
	ofstream fs("agen.dat"); // Abrir fichero de salida.
 	imprimirAgen(fs, A, fin); // En fichero
	
	
}
