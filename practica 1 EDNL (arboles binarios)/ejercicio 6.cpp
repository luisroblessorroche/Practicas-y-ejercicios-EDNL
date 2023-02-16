//Ejercicio 6

/*
Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
define como la diferencia entre las alturas de los subárboles del mismo. 
*/

template <typename T> int desequilibrio_abin(const Abin<T> &A)
{
	return desequilibrio_abin_rec(A.raiz(),A);
}

template <typename T> int desequilibrio_abin_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return max3(abs(altura_abin(A.hijoIzqdo(n),A) - altura_abin(A.hijoDrcho(n),A)), desequilibrio_abin_rec(A.hijoIzqdo(n),A), desequilibrio_abin_rec(A.hijoDrcho(n),A));
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
