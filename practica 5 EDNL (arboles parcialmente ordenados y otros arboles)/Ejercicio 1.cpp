//Ejercicio 1 practica 5

/*
Dado un árbol binario de enteros donde el valor de cada nodo es menor que el de sus
hijos, implementa un subprograma para eliminar un valor del mismo preservando la
propiedad de orden establecida. Explica razonadamente la elección de la estructura de
datos.
 Nota: Se supone que en el árbol no hay elementos repetidos, y que el número de
nodos del mismo no está acotado
*/

Abin<int> eliminar_nodo_Abin(Abin<int> &A, int x)
{
	buscar_valor(A.raiz(),A,x);
	return A;
}

void buscar_valor(typename Abin<int>::nodo n, Abin<int> &A, int x)
{
	if(n != Abin<int>::NODO_NULO)
	{
		if(A.elemento(n) == x)
		{
			eliminar_nodo(n,A,x);
		}
		else
		{
			buscar_valor(A.hijoIzqdo(n),A,x);
			buscar_valor(A.hijoDrcho(n),A,x);
		}
	}
}


void eliminar_nodo(Abin<int>::nodo n, Abin<int> &A, int x)
{
	if(A.hijoIzqdo(n) == Abin<int>::NODO_NULO && A.hijoDrcho(n) == Abin<int>::NODO_NULO)
	{
		Abin<int>:nodo padre = A.padre(n);
		if(A.padre(n) == Abin<int>::NODO_NULO)
		{
			A.eliminarRaiz();
		}
		else
		{
			if(A.hijoIzqdo(padre) != Abin<int>::NOODO_NULO && A.elemento(A.hijoIzqdo(padre) == x))
			{
				 A.eliminarHijoIzqdo(padre);
			}
			else
			{
				A.eliminarHijoDrcho(padre);
			}
		}
	}
	else
	{
		int menor = menor_hijo(n,A);
		A.elemento(n) = menor;
		if(A.hijoIzqdo(n) != Abin<int>::NODO_NULO && A.elemento(A.hijoIzqdo(n)) == menor)
		{
			A.elemento(A.hijoIzqdo(n)) = x;
			eliminar_nodo(A.hijoIzqdo(n),A,x);
		}
		else
		{
			A.elemento(A.hijoDrcho(n)) = x;
			eliminar_nodo(A.hijoDrcho(n),A,x);
		}
	}
	
}

int menor_hijo(Abin<int>::nodo n; Abin<int> &A)
{
	if(A.hijoIzqdo(n) == Abin<int>::NODO_NULO)
	{
		return A.elemento(A.hijoDrcho(n));
	}
	else
	{
		if(A.hijoDrcho(n) == Abin<int>::NODO_NULO)
		{
			return A.elemento(A.hijoIzqdo(n));
		}
		else
		{
			if(A.elemento(A.hijoDrcho(n)) < A.elemento(A.hijoIzqdo(n)))
			{
				return A.elemento(A.hijoDrcho(n));
			}
			else
			{
				return A.elemento(A.hijoIzqdo(n));
			}
		}
	}
}

