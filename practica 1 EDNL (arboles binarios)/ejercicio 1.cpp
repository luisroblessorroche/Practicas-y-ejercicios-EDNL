//Ejercicio 1

/*
Implementa un subprograma que calcule el número de nodos de un árbol binario. 
*/

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
