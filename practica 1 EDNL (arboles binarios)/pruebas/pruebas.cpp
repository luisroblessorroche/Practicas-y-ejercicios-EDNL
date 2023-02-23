//pruebas de ejercicios

#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"
using namespace std;
typedef char tElto;
const tElto fin = '#'; // Fin de lectura.

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------EJERCICIO 1-------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
template <typename T> int num_nodos_abin(const Abin<T> &A)
{
	return num_nodos_abin_rec(A.raiz(),A);
}

template <typename T> int num_nodos_abin_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return 1 + num_nodos_abin_rec(A.hijoIzqdo(n),A) + num_nodos_abin_rec(A.hijoDrcho(n),A);
	}
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------EJERCICIO 2-------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
template <typename T> int altura_abin(const Abin<T> &A)
{
	return altura_abin_rec(A.raiz(),A);
}

template <typename T> int altura_abin_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + max(altura_abin_rec(A.hijoIzqdo(n),A),altura_abin_rec(A.hijoDrcho(n),A));
	}
}
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------EJERCICIO 3-------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
template <typename T> int profundidad_nodo_abin(typename Abin<T>::nodo n, const Abin<T> &A)
{
	return profundidad_nodo_abin_rec(n,A);
}

template <typename T> int profundidad_nodo_abin_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + profundidad_nodo_abin_rec(A.padre(n),A);
	}
}
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------EJERCICIO 6-------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
template <typename T> int desequilibrio_abin(const Abin<T> &A)
{
	return desequilibrio_abin_rec(A.raiz(),A);
}

template <typename T> int desequilibrio_abin_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return max(abs(altura_abin(A.hijoIzqdo(n),A) - altura_abin(A.hijoDrcho(n),A)), max(desequilibrio_abin_rec(A.hijoIzqdo(n),A), desequilibrio_abin_rec(A.hijoDrcho(n),A)));
	}
}

template <typename T> int altura_abin(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + max(altura_abin(A.hijoIzqdo(n),A),altura_abin(A.hijoDrcho(n),A));
	}
}
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------EJERCICIO 7-------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
template <typename T> bool abin_pseudocompleto(const Abin<T> &A)
{
	int altura = alt_abin(A.raiz(),A);
	return abin_pseudocompleto_rec(altura,A.raiz(),A);
}

template <typename T> bool abin_pseudocompleto_rec(int altura, typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		if(profundidad_nodo(n,A) == altura -1)
		{
			return cero_o_dos_hijos(n,A) && abin_pseudocompleto_rec(altura,A.hijoIzqdo(n),A) && abin_pseudocompleto_rec(altura,A.hijoDrcho(n),A);
		}
		else
		{
			return abin_pseudocompleto_rec(altura,A.hijoIzqdo(n),A) && abin_pseudocompleto_rec(altura,A.hijoDrcho(n),A);
		}
	}
}

template <typename T> int alt_abin(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + max(alt_abin(A.hijoIzqdo(n),A),alt_abin(A.hijoDrcho(n),A));
	}
}

template <typename T> int profundidad_nodo(typename Abin<T>::nodo n, const Abin<T> &A)
{
		if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + profundidad_nodo_abin_rec(A.padre(n),A);
	}
}

template <typename T> bool cero_o_dos_hijos(typename Abin<T>::nodo n, const Abin<T> &A)
{
	return(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO) ||
	(A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------PRUEBAS-----------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

int main ()
{
	
	Abin<tElto> A;
	cout << "*** Lectura del árbol binario A ***\n";
	rellenarAbin(A, fin); // Desde std::cin
	ofstream fs("abin.dat"); // Abrir fichero de salida.
	imprimirAbin(fs, A, fin); // En fichero.
	fs.close();
	cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";

	int num = num_nodos_abin(A);
	cout<< "el numero de nodos del arbol es: "<<num<<endl;
	int alt = altura_abin(A);
	cout<< "la altura del arbol es: "<<alt<<endl;
	Abin<char>::nodo n = A.hijoIzqdo(A.hijoIzqdo(A.hijoIzqdo(A.raiz())));
	int prof = profundidad_nodo_abin(n, A);
	cout<< "la profundidad del nodo es: "<<prof<<endl;
	int deseq = desequilibrio_abin(A);
	cout<<"el desequilibrio del arbol es: "<<deseq<<endl;
	bool pseudo = abin_pseudocompleto(A);
	if(pseudo)
	{
		cout<<"el arbol es pseudocompleto"<<endl;
	}
	else
	{
		cout<<"el arbol no es pseudocompleto"<<endl;
	}
}
