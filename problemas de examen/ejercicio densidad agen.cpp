//EJERCICIO desidad agen

/*
Calcular la densidad de un arbol general.
La densidad es el grado maximo de un arbol entre el numero de nodos hojas del arbol
*/

template <typename T> double densidad_agen(const Agen<T>& A)
{
	if(A.vacio())
	{
		return 0; //o std::invalid_argument("el arbol no puede estar vacio");
	}
	else
	{
		return max_grado_agen(A.raiz(),A) / num_hojas_agen(A.raiz(),A);
	}
}


template <typename T> int max_grado_agen(typename Agen<T>::nodo n, const Agen<T>& A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		int grado = calcular_grado(n,A);
		Agen<T>::nodo hijo = A.hijoIzqdo(n);
		while(hijo != Agen<T>::NODO_NULO)
		{
			grado = std::max(grado, max_grado_agen(hijo,A));
			hijo = A.hermDrcho(hijo);	
		}
		return grado;
	}
}

template <typename T> int calcular_grado(typename Agen<T>::nodo n, const Agen<T>& A)
{
	Agen<T>::nodo hijo = A.hijoIzqdo(n);
	int cont = 0;
	while(hijo != Agen<T>::NODO_NULO)
	{
		cont++;
		hijo = A.hermDrcho(hijo);
	}
	
	return cont;
}

template <typename T> int num_hojas_agen(typename Agen<T>::nodo n, const Agen<T>& A)
{
	if(n == Agen<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		int num_hojas = 0;
		Agen<T>::nodo hijo = A.hijoIzqdo(n);
		while(hijo != Agen<T>::NODO_NULO)
		{
			if(nodo_es_hoja(hijo,A))
			{
				num_hojas = 1 + num_hojas + num_hojas_agen(hijo,A);
			}
			else
			{
				num_hojas = num_hojas + num_hojas_agen(hijo,A);
			}
			
			hijo = A.hermDrcho(hijo);
		}
	}
	return num_hojas;
}
