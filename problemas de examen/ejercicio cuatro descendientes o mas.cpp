//EJERCICIO contarDescendientes

/*
Dado un arbol binario, cuenta el numero de nodos que tienen cuatro descendientes o mas
*/

template <typename T> int contar_nodos_cuatro_descendientes(const Abin<T>& A)
{
	return contar_nodos_cuatro_descendientes_rec(A.raiz(),A);
}


template <typename T> int contar_nodos_cuatro_descendientes_rec(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(contar_descendientes(n,A) >= 4)
		{
			return 1 + contar_nodos_cuatro_descendietnes_rec(A.hijoIzqdo(n),A) + contar_nodos_cuatro_descendientes_rec(A.hijoDrcho(n),A);
		}
		else
		{
			return 0 + contar_nodos_cuatro_descendietnes_rec(A.hijoIzqdo(n),A) + contar_nodos_cuatro_descendientes_rec(A.hijoDrcho(n),A);
		}
	}
}


template <typename T> int contar_descendientes(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return 1 + contar_descendientes(A.hijoIzqdo(n),A) + contar_descendientes(A.hijoDrcho(n),A);
	}
}
