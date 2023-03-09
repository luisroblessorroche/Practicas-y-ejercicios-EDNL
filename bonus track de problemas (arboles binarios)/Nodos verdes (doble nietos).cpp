//NODOS VERDES
//Contar el número de nodos que tengan el doble de nietos que de bisnietos

template <typename T> int nodos_verdes_doble_nietos_bisnietos(const Abin<T> &A)
{
	return nodos_verdes_doble_nietos_bisnietos_rec(A.raiz(),A);
}

template <typename T> int nodos_verdes_doble_nietos_bisnietos(Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		int profundidad = profundidad_nodo(n,A);
		int num_nietos = calcular_nietos(profundidad,n,A);
		int num_bisnietos = calcular_bisnietos(profundidad,n,A);
		if(num_nietos == 2*num_bisnietos)
		{
			return 1 + nodos_verdes_doble_nietos_bisnietos(A.hijoIzqdo(n),A) + nodos_verdes_doble_nietos_bisnietos(A.hijoDrcho(n),A);
		}
		else
		{
			return nodos_verdes_doble_nietos_bisnietos(A.hijoIzqdo(n),A) + nodos_verdes_doble_nietos_bisnietos(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> int profundidad_nodo(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + profundidad_nodo(A.padre(n),A);
	}
}

template <typename T> int calcular_nietos(int profundidad, typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(profundidad_nodo(n,A) - profundidad == 2)
		{
			return 1 + calcular_nietos(profundidad, A.hijoIzqdo(n),A) + calcular_nietos(profundidad,A.hijoDrcho(n),A);
		}
		else
		{
			return calcular_nietos(profundidad, A.hijoIzqdo(n),A) + calcular_nietos(profundidad,A.hijoDrcho(n),A);
		}
	}
}

template <typename T> int calcular_bisnietos(int profundidad, typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(profundidad_nodo(n,A) - profundidad == 3)
		{
			return 1 + calcular_bisnietos(profundidad, A.hijoIzqdo(n),A) + calcular_bisnietos(profundidad,A.hijoDrcho(n),A);
		}
		else
		{
			return calcular_bisnietos(profundidad, A.hijoIzqdo(n),A) + calcular_bisnietos(profundidad,A.hijoDrcho(n),A);
		}
	}
}
