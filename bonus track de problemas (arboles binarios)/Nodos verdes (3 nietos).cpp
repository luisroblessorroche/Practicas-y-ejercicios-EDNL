//NODOS VERDES
//Contar el número de nodos que tengan exactamente 3 nietos

template <typename T> int nodos_verdes_3_nietos(const Abin<T> &A)
{
	return nodos_verdes_3_nietos_rec(A.raiz(),A);
}

template <typename T> int nodos_verdes_3_nietos_rec(typename Abin<T>::nodo n, const Abin<T> &A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		if(contar_nietos(A.hijoIzqdo(n),A) + contar_nietos(A.hijoDrcho(n),A) == 3)
		{
			return 1 + nodos_verdes_3_nietos_rec(A.hijoIzqdo(n),A) + nodos_verdes_3_nietos__rec(A.hijoDrcho(n),A);
		}
		else
		{
			return nodos_verdes_3_nietos_rec(A.hijoIzqdo(n),A) + nodos_verdes_3_nietos__rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> int contar_nietos(typename Abin<T>::nodo n, const Abin<T> &A)
{
	int num_nietos = 0;
	if(n != Abin<T>::NODO_NULO)
	{
		if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
		{
			num_nietos++;
		}
		
		if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
		{
			num_nietos++;
		}
	}
	return num_nietos;
}
