//EJERCICIO 

/*
Dado un �rbol A y un valor x, compruebe si dicho valor se encuentra o no en el �rbol.
Si es as�, devuelva el camino desde el nodo ra�z hasta dicho nodo.
Puede suponer que no hay ning�n elemento repetido en el �rbol que recibe como par�metro.
*/


template <typename T> std::vector<Abin<T>::nodo> camino(const Abin<T>&A, const T& e)
{
	std::vector<Abin<T>::nodo> v;
	buscar_nodo(A.raiz(),A,e,v);
	return v;
}


template <typename T> void buscar_nodo(Abin<T>::nodo n, const Abin<T>& A, const T& e,std::vector<Abin<T>::nodo>& v)
{
	if(n!= Abin<T>::NODO_NULO)
	{
		if(A.elemento(n) == e)
		{
			formar_camino(n,A,v);
		}
		else
		{
			buscar_nodo(A.hijoIzqdo(n),A,e,v);
			buscar_nodo(A.hijoDrcho(n),A,e,v);
		}
	}
}


template <typename T> void formar_camino(Abin<T>::nodo n, const Abin<T>& A, std::vector<Abin<T>::nodo>& v)
{
	while(n != Abin<T>::NODO_NULO)
	{
		v.push_front(n);
		n = A.padre(n);
	}
}
