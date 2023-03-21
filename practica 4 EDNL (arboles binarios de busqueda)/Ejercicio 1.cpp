//Ejercicio 1

/*
Implementa una nueva operaci�n del TAD Abb que tomando un elemento del mismo
elimine al completo el sub�rbol que cuelga de �l.
*/

//-------------SOLUCION COMO OPERACION DEL TAD----------------------

void poda(const T& e)
{
	typename Abb<T> A;
	A = buscar(e);
	while(!A.vacio())
	{
		A.eliminar(A.elemento())
	}
}


//---------------------SOLUCION SIN SER UNA OPERACION DEL TAD--------------

template <typename T> void poda(const T& e, Abb<T> &A)
{
	A = A.buscar(e);
	while(!A.vacio())
	{
		A.eliminar(A.elemento());
	}
}

