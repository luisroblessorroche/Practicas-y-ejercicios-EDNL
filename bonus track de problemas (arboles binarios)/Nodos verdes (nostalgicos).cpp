//NODOS VERDES
//Contar el numero de nodos nostalgicos (mas pasado que futuro)
//Es decir que tenga mas antecesores que descendientes propios

template <typename T> int nodos_verdes_nostalgicos(const Abin<T> &A)
{
	return nodos_verdes_nostalgicos_rec(A.raiz(),A);
}

template <typename T> int nodos_verdes_nostalgicos_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(num_antecesores(n,A) > num_descendientes(n,A) -1)
		{
			return 1 + nodos_verdes_nostalgicos_rec(A.hijoIzqdo(n),A) + nodos_verdes_nostalgicos_rec(A.hijoDrcho(n),A);
		}
		else
		{
			return nodos_verdes_nostalgicos_rec(A.hijoIzqdo(n),A) + nodos_verdes_nostalgicos_rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> int num_antecesores(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + num_antecesores(A.padre(n),A);
	}
}

template <typename T> int num_descendientes(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return 1 + num_descendientes(A.hijoIzqdo(n),A) + num_descendientes(A.hijoDrcho(n),A);
	}
}
