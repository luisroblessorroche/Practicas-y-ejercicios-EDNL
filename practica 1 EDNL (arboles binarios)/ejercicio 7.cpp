//Ejercicio 7

/*
Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
del mismo cada uno de los nodos tiene dos hijos o ninguno. 
*/

template <typename T> bool abin_pseudocompleto(const Abin<T> &A)
{
	int altura = altura_abin(A.raiz(),A);
	return abin_pseudocompleto_rec(altura,A.raiz(),A);
}

template <typename T> bool abin_pseudocompleto_rec(int altura,typename Abin<T>::nodo n, const Abin<T> &A)
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
