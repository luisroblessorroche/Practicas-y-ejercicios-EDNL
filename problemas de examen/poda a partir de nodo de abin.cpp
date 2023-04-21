template <typename T> void poda_abin(typename Abin<T>::nodo n, Abin<T>& A)
{
	if(n != NODO_NULO)
	{
		poda(A.hijoIzqdo(n),A);
		poda(A.hijoDrcho(n),A);
		
		if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
		{
			A.eliminarhijoIzqdo(n);	
		}
		
		if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
		{
			A.eliminarhijoDrcho(n);	
		}

	}
}


template <typename T> void poda_abin(typename Abin<T>::nodo n, Abin<T>& A)
{
	if(n != NODO_NULO)
	{
		if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
		{
			poda(A.hijoIzqdo(n),A);
			A.eliminarhijoIzqdo(n);
		}				
		if(A.hijoDrcho(n) != Abin<T>::NODO_NULO)
		{
			poda(A.hijoDrcho(n),A);
			A.eliminarhijoDrcho(n);	
		}

	}
}
