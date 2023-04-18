//Ejercicio 4

/*
Un árbol es estrictamente ternario si todos sus nodos son hojas o tienen tres hijos.
Escribe una función que, dado un árbol de grado arbitrario, nos indique si es o no
estrictamente ternario.
*/

template <typename T> bool agen_ternario(const Agen<T> &A)
{
	return agen_ternario_rec(A.raiz(),A);
}

template <typename T> bool agen_ternario_rec(typename Agen<T>::nodo n, const Agen<T> &A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		bool ternario = num_hijos(n,A);
		Agen<T>::nodo hijo = A.hijoIzqdo(n);
		while(hijo != Agen<T>::NODO_NULO)
		{
			ternario = ternario && agen_ternario_rec(hijo,A);
			hijo = A.hermDrcho(hijo);
		}
		return ternario;
	}
}

template <typename T> bool num_hijos(typename Agen<T>::nodo n, const Agen<T> &A)
{
	int cont = 0;
	Agen<T>::nodo hijo = A.hijoIzqdo(n);
	while(hijo != Agen<T>::NODO_NULO)
	{
		cont++;
		hijo = A.hermDrcho(hijo);
	}
	
	return (cont == 0 || cont == 3);
}
