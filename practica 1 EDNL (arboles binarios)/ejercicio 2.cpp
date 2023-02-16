//Ejercicio 2

/*
Implementa un subprograma que calcule la altura de un árbol binario. 
*/

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
