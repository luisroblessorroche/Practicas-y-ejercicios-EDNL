/*
Dado un conjunto ordenado no vacio A, se define el infimo de x como el mayor 
elemento de A menor o igual que x, si existe. Análogamente, el supremo de x 
en A, si existe, es el menor elemento de A mayor o igual que x.

Implementa dos funciones de O(log n) en promedio que dados un valor x cualquiera
y un ABB A no vacio devuelvan, respectivamente, el infimo y el supremo de x en A. 
Si no existe el infimo de x en A, la funcion correspondiente devolvera el minimo 
de A. Asi mismo, la otra funcion devolvera el maximo de A, en el caso de que no 
existe el supremo.

Nota: Es absolutamente necesario definir todos los tipos de datos implicados en 
la resulucion del ejercicio, asi como los prototipos de las operaciones 
utilizadas de los TADs conocidos.
*/


//infimo
template <typename T> T& infimo_abb(const Abb<T>& A,T& x)
{
	bool existe = existe_infimo(A,x);
	if(!existe)
	{
		return minimo(A);
	}
	else
	{
		Abb<T> B = A.buscar(x);
		if(B.izqdo().vacio())
		{
			return B.elemento();
		}
		else
		{
			return infimo(B.izqdo());
		}
	}
}

template <typename T> bool existe_infimo(const Abb<T>& A, x)
{
	Abb<T> B = A.buscar(x);
	return !B.vacio();
}


template <typename T> T& minimo(const Abb<T>& A)
{
	if(!A.izqdo().vacio() && A.izqdo().elemento() < A.elemento())
	{
		return minimo(A.izqdo());
	}
	else
	{
		return A.elemento();
	}
}

template <typename T> T& infimo(Abb<T>& A)
{
	if(!A.drcho())
	{
		return infimo(A.drcho());
	}
	else
	{
		return A.elemento();
	}
}




//supremo
template <typename T> T& supremo_abb(const Abb<T>& A,T& x)
{
	bool existe = existe_supremo(A,x);
	if(!existe)
	{
		return maximo(A);
	}
	else
	{
		Abb<T> B = A.buscar(x);
		if(B.drcho().vacio())
		{
			return B.elemento();
		}
		else
		{
			return supremo(B.drcho());
		}
	}
}

template <typename T> bool existe_supremo(const Abb<T>& A, x)
{
	Abb<T> B = A.buscar(x);
	return !B.vacio();
}


template <typename T> T& supremo(const Abb<T>& A)
{
	if(!A.drcho().vacio() && A.Drcho().elemento() > A.elemento())
	{
		return maximo(A.drcho());
	}
	else
	{
		return A.elemento();
	}
}

template <typename T> T& supremo(Abb<T>& A)
{
	if(!A.drcho())
	{
		return supremo(A.izqdo());
	}
	else
	{
		return A.elemento();
	}
}


