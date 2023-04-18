//EJERCICIO febrero 2021

/*
Implemente una funcion generica que transforme un arbol binario de un tipo generico T, eliminando
los descendientes propios de todos aquellos nodos cuyo contenido sea, al mismo tiempo,
mayor o igual que el de sus ancestros propios y menor o igual que sus descendientes propios
*/

//supondremos que el tipo generico T tiene sobrecargado el operador <

template <typename T> void transformar_abin(Abin<T>& A)
{
	transformar_abin_rec(A.raiz(),A);
}


template <typename T> void transformar_abin_rec(typename Abin<T>::nodo n, Abin<T>& A)
{
	if(n != Abin<T>::NODO_NULO)
	{
		if(!nodo_es_raiz(n,A) && !nodo_es_hoja(n,A) && 
		ancestros_propios_menores(A.padre(n),A,A.elemento(n)) && 
		descendientes_propios_menores(A.hijoIzqdo(n),A,A.elemento(n)) && descendientes_propios_menores(A.hijoDrcho(n),A,A.elemento(n)))
		{
			podar_subarbol(n,A);
		}
		else
		{
			transformar_abin_rec(A.hijoIzqdo(n),A);
			transformar_abin_rec(A.hijoDrcho(n),A);
		}
	}
}

template <typename T> bool nodo_es_raiz(typename Abin<T>::nodo n, const Abin<T>& A)
{
	return n == A.raiz();
}

template <typename T> bool nodo_es_hoja(typename Abin<T>::nodo n, const Abin<T>& A)
{
	return A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO;
}

template <typename T> bool ancestros_propios_menores(Abin<T>::nodo n, const Abin<T>&A, T& e)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		return A.elemento(n) < e && ancestros_propios_menores(A.padre(n),A,e);
	}
}

template <typename T> bool descendientes_propios_menores(Abin<T>::nodo n, const Abin<T>& A, T& e)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		return e < A.elemento(n) && descendientes_propios_menores(A.hijoIzqdo(n),A,e) && descendientes_propios_menores(A.hijoDrcho(n),A,e);
	}
}

template <typename T> void podar_subarbol(Abin<T>::nodo n, Abin<T>&A)
{
	if(n != Abin<T>::NODO_NULO)
	{
		podar_subarbol(A.hijoIzqdo(n),A);
		podar_subarbol(A.hijoDrcho(n),A);
		
		if(!nodo_es_hoja(n,A))
		{
			A.eliminarhijoDrcho(n);
			A.eliminarhijoIzqdo(n);
		}
	}
}

