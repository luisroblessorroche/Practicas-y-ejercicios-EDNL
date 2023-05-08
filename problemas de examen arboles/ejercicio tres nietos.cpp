//EJERCICIO contar nodos con 3 nietos

/*
Dado un arbol binario, contar el numero de nodos que tienen exactamente 3 nietos
*/

template <typename T> int contar_nodos_tres_nietos(const Abin<T>& A)
{
	return contar_nodos_tres_nietos_rec(A.raiz(),A);
}

template <typename T> int contar_nodos_tres_nietos_rec(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(contar_nietos(n,A,profundidad(n,A)) == 3)
		{
			return 1 + contar_nodos_tres_nietos_rec(A.hijoIzqdo(n),A) + contar_nodos_tres_nietos_rec(A,hijoDrcho(n),A);
		}
		else
		{
			return 0 + contar_nodos_tres_nietos_rec(A.hijoIzqdo(n),A) + contar_nodos_tres_nietos_rec(A,hijoDrcho(n),A);
		}
	}
}

template <typename T> int profundidad(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + profundidad(A.padre(n),A);
	}
}

template <typename T> int contar_nietos(typename Abin<T>::nodo n, const Abin<T>& A, int prof)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(profundidad(n,A) == prof + 2)
		{
			return 1 + contar_nietos(A.hijoIzqdo(n),A,prof) + contar_nietos(A.hijoDrcho(n),A,prof);
		}
		else
		{
			return 0 + contar_nietos(A.hijoIzqdo(n),A,prof) + contar_nietos(A.hijoDrcho(n),A,prof);
		}
	}
}
