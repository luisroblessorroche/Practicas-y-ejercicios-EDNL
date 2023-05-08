//EJERCICIO nodos reflejados
/*
Contar el número de nodos reflejados (nodos que siendo hermanos entre si,
son raices de dos subarboles refleados)
*/

template <typename T> int nodos_reflejados(const Abin<T>& A)
{
	return nodos_reflejados_rec(A.raiz(),A);
}

template <typename T> int nodos_reflejados_rec(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(!nodo_es_hoja(n,A) && subarbol_reflejo(A.hijoIzqdo(n),A.hijoDrcho(n),A))
		{
			return 2 + nodos_reflejados_rec(A.hijoIzqdo(n),A) + nodos_reflejados_rec(A.hijoDrcho(n),A);
		}
		else
		{
			return 0 + nodos_reflejados_rec(A.hijoIzqdo(n),A) + nodos_reflejados_rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> bool nodo_es_hoja(typename Abin<T>::nodo n, const Abin<T>& A)
{
	return(A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO);
}

template <typename T> bool subarbol_reflejado(typename Abin<T>::nodo n1, typename Abin<T>::nodo n2, const Abin<T>& A)
{
	if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		if((n1 == Abin<T>::NODO_NULO && n2 != Abin<T>::NODO_NULO) || (n1 != Abin<T>::NODO_NULO && n2 != Abin<T>::NODO_NULO))
		{
			return false;
		}
		else
		{
			return A.elemento(n1) == A.elemento(n2) && subarbol_reflejado(A.hijoIzqdo(n1),A.hijoDrcho(n2),A) && subarbol_reflejado(A.hijoIzqdo(n2),A.hijoDrcho(n1),A);
		}
	}
}
