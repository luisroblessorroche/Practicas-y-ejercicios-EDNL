//Ejercicio 3

/*
Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas
de los subárboles más bajo y más alto de cada nivel. Implementa un subprograma que calcule
el grado de desequilibrio de un árbol general.
*/

template <typename T> int desequilibrio_agen(const Agen<T> &A)
{
	return desequilibrio_agen_rec(A.raiz(),A);
}


template <typename T> int desequilibrio_agen_rec(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		Agen<T>::nodo hijo = A.hijoIzqdo(n);
		
		while(hijo != Agen<T>::NODO_NULO)
		{
			int altura_max = altura_max(n,A);
			int altura_min = altura_min(n,A);
			
			int desequilibrio = max(altura_max-altura_min, desequilibrio_agen_rec(A.hijoIzqdo(n),A));
		int altura_max = altura_max(n,A);
		int altura_min = altura_min(n,A);
		Agen<T>::nodo hijo = A.hijoIzqdo(n);
		while(hijo != Agen<T>::NODO_NULO)
		{
			int desequilibrio = max(altura_max-altura_min,desequilibrio_agen_rec(hijo,A));
			hijo = A.hermDrcho(n);
		}
		return desequilibrio;
	}
}

template <typename T> int altura_max(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + max(altura_max(A.hijoIzqdo(n),A),altura_max(A.hermDrcho(n),A));
	}
}

template <typename T> int altura_max

template <typename T> int altura_min(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + min(altura_min(A.hijoIzqdo(n),A),altura_min(A.hermDrcho(n),A));
	}
}



