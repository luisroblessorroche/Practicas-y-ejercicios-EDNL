//EJERCICIOS juanfran

/*
Dado un árbol A, comprobar que todos los valores del subárbol izquierdo, son estrictamente 
menores que los valores del nodo raíz de A y, todos los valores del subárbol derecho, 
estrictamente mayores. Dicha condición se debe dar de igual modo en dichos subárboles.
*/


template <typename T> bool relacion_orden(const Abin<T>& A)
{
	if(A.vacio())
	{
		return true;
	}
	else
	{
		return relacion_orden_izqdo(A.hijoIzqdo(A.raiz()),A) && relacion_orden_drcho(A.hijoDrcho(A.raiz()),A);	
	}
}

template <typename T> bool relacion_orden_izqdo(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		return A.elemento(n) < A.elemento(A.padre(n)) && relacion_orden_izqdo(A.hijoIzqdo(n),A) && relacion_orden_drcho(A.hijoDrcho(n),A);
	}
}

template <typename T> bool relacion_orden_drcho(typename Abin<T>::nodo n, const Abin<T>& A)
{
	if(n == Abin<T>::NODO_NULO)
	{
		return true;
	}
	else
	{
		return A.elemento(n) > A.elemento(A.padre(n)) && relacion_orden_izqdo(A.hijoIzqdo(n),A) && relacion_orden_drcho(A.hijoDrcho(n),A);
	}
}
