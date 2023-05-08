//EJERCICIO ab = avl

/*
Construye una función que, dado un Árbol Binario, devuelva true si es un AVL y false en el caso contrario.
NOTA:
Un avl es un abb equilibrado
*/

//Asumiremos que los elementos T tienen sobrecargados el operador <

template <typename T> bool abin_avl(const Abin<T>& A)
{
	return (abin_equilibrado(A.raiz(),A) == 1 || abin_equilibrado(A.raiz(),A) == 0) && abin_relacion_orden(A.raiz(),A);
}


template <typename T> int abin_equilibrado(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return 0;
	}
	else
	{
		return std::max(std::abs(altura_nodo(A.hijoIzqdo(n),A) - altura_nodo(A.hijoDrcho(n),A)), max(abin_equilibrado(A.hijoIzqdo(n),A),abin_equilibrado(A.hijoDrcho(n),A)));
	}
}

template <typename T> int altura_nodo(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		return 1 + std::max(altura_nodo(A.hijoIzqdo(n)),altura_nodo(A.hijoDrcho(n),A));
	}
}

//En vez de comprobar que el nodo sea mayor o menor que el hijo, lo haremos comprobando que el hijo sea mayor o menor que el padre
template <typename T> bool abin_relacion_orden(typename Abin<T>::nodo raiz, const Abin<T>& A)
{
	if(raiz == Abin<T>::NODO_NULO)
	{
		return true;	
	}
	else
	{
		return abin_relacion_orden_rec_izqdo(A.hijoIzqdo(raiz),A) && abin_relacion_orden_rec_drcho(A.hijoDrcho(raiz),A);
	}
}

template <typename T> bool abin_relacion_orden_rec_izqdo(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return true;	
	}
	else
	{
		return A.elemento(n) < A.elemento(A.padre(n)) && abin_relacion_orden_rec_izqdo(A.hijoIzqdo(n),A) && abin_relacion_orden_rec_drcho(A.hijoDrcho(n),A);
	}	
}

template <typename T> bool abin_relacion_orden_rec_drcho(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return true;	
	}
	else
	{
		return A.elemento(A.padre(n)) < A.elemento(n) && abin_relacion_orden_rec_izqdo(A.hijoIzqdo(n),A) && abin_relacion_orden_rec_drcho(A.hijoDrcho(n),A);
	}	
}








