// Ejercicio 1

/*
Implementa un subprograma que dado un árbol general nos calcule su grado.
*/

//----------version clasica (haciendolo parecido a arboles binarios)------------

template <typename T> Agen<T> int grado_agen(const Agen<T> &A)
{
	return grado_agen_rec(A.raiz(),A);
}

template <typename T> Agen<T> int grado_agen_rec(typename Agen<T>::nodo n, const Agen<T> &A)
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

template <typename T> Agen<T> int contar_hijos(typename Agen<T>::nodo n, const Agen<T> &A)
{
	int n_hijos = 0;
	Abin<T>::nodo hijo = A.hijoIzqdo(n);
	while(hijo != Agen<T>::NODO_NULO)
	{
		n_hijos++;
		hijo = A.hermDrcho(hijo);
	}
	return n_hijos;
}

