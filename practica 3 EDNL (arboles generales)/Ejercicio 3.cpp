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
		return -1;
	}
	else
	{
		Agen<T>::nodo hijo = A.hijoIzqdo(n);
		int altura_min = altura_nodo(hijo,A);
		int altura_max = altura_min;
		
		hijo = A.hermDrcho(hijo);
		
		while(hijo != Agen<T>::NODO_NULO)
		{
			int altura = altura_nodo(hijo,A);
			if(altura > altura_max)
			{
				altura_max = altura;
			}
			if(altura < altura_min)
			{
				altura_min = altura;
			}
			
			hijo = A.hermDrcho(hijo);
		}
		
		int dif = altura_max - altura_min;
		
		Agen<T>::nodo m = A.hijoIzqdo(n);
		
		while(m != Agen<T>::NODO_NULO)
		{
			return 
		}
	}
}


template <typename T> int desequilibrio_agen_rec(typename Agen<T>::nodo n, const Agen<T> &A)
{
	
}



