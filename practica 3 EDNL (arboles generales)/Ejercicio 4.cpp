//Ejercicio 4

/*
Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
la poda de A a partir de x. Se asume que no hay elementos repetidos en A. 
*/

void poda_agen(int x, const Agen<int> &A)
{
	poda_agen_rec(A.raiz(),x,A);
}

void poda_agen_rec(Agen<int>::nodo n, int x, const Agen<int> &A)
{
	if(n != Agen<int>::NODO_NULO)
	{
		if(A.elemento(n) == x)
		{
			poda(n,A);
		}
		else
		{
			typename Agen<int>::nodo hijo = A.hijoIzqdo(n);
			while(hijo != Agen<int>::NODO_NULO)
			{
				poda_agen_rec(hijo,A);
				hijo = hermDrcho(n);
			}
		}
	}
}

void poda(Agen<int>::nodo n, const Agen<int> &A)
{
	while(A.hijoIzqdo(n) != Agen<int>::NODO_NULO)
	{
		poda(A.hijoIzqdo(n),A);
		A.eliminarHijoIzqdo(n);
	}
}


