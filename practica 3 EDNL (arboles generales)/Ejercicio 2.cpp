//Ejercicio 2

/*
Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine
la profundidad de éste nodo en el árbol. 
*/


template <typename T> int profundidad_nodo(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + profundidad_nodo(A.padre(n),A);
	}
}



