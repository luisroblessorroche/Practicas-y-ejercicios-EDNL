//Ejercicio 1

/*
Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación,
es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho
similares. Implementa un subprograma que determine si dos árboles binarios son
similares.
*/

template <typename T> bool abin_similares(const Abin<T> &A, const Abin<T> &B)
{
	return abin_similares_rec(A.raiz(),B.raiz(),A,B);
}

template <typename T> bool abin_similares_rec(typename Abin<T>::nodo n1, typename Abin<T>::nodo n2, const Abin<T> &A, const Abin<T> &B)
{
	if(n1 == Abin<T>::NODO_NULO && n2 == Abin<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		if(n1 != Abin<T>::NODO_NULO && n2 != Abin<T>::NODO_NULO)
		{
			return abin_similares_rec(A.hijoIzqdo(n1),B.hijoIzqdo(n2),A,B) && abin_similares_rec(A.hijoDrcho(n1),B.hijoDrcho(n2),A,B);
		}
		else
		{
			return false;
		}
	}
}
