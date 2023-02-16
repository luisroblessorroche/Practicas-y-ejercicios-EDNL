//ejercicio 3

/*
Implementa un subprograma que, dados un árbol binario y un nodo del mismo, determine
la profundidad de este nodo en dicho árbol. 
*/

template <typename T> int profundidad_nodo_abin(typename Abin<T>::nodo n, const Abin<T> &A)
{
	return profundidad_abin_rec(n,A);
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
