//NODOS VERDES
//Contar el número de nodos reflejados (nodos que siendo hermanos entre si,
//son raices de dos subarboles refleados)

template <typename T> int nodos_verdes_reflejados(const Abin<T> &A)
{
	return nodos_verdes_reflejados_rec(A.raiz(),A);
}

template <typename T> int nodos_verdes_reflejados_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(existe_subarbol_izqdo_y_drcho(n,A) && reflejo(A.hijoIzqdo(n),A.hijoDrcho(n),A))
		{
			return 2 + nodos_verdes_reflejados_rec(A.hijoIzqdo(n),A) + nodos_verdes_reflejados_rec(A.hijoDrcho(n),A);
		}
		else
		{
			return nodos_verdes_reflejados_rec(A.hijoIzqdo(n),A) + nodos_verdes_reflejados_rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> bool existe_subarbol_izqdo_y_drcho(typename Abin<T>::nodo n, const Abin<T> &A)
{
	return A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO;
}

template <typename T> bool reflejo(typename Abin<T>::nodo n1, typename Abin<T>::nodo n2, const Abin<T> &A)
{
	if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		if((n1 == Abin<T>::NODO_NULO && n2 != Abin<T>::NODO_NULO) || (n1 != Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO))
		{
			return false;
		}
		else
		{
			return A.elemento(n1) == A.elemento(n2) && reflejo(A.hijoIzqdo(n1),A.hijoDrcho(n2),A) && reflejo(A.hijoIzqdo(n2), A.hijoDrcho(n1),A); 
		}
	}
}
