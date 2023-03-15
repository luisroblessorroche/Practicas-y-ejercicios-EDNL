//Ejercicio 2

/*
Implementa un subprograma que dados un �rbol y un nodo dentro de dicho �rbol determine
la profundidad de �ste nodo en el �rbol. 
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



