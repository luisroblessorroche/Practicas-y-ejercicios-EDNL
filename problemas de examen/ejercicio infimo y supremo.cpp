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

template <typename T> T& infimo_abb(const Abb<T>& A, T& x)
{
	bool arbol_menor_igual_x = buscar_menor_igual_x(A,x);
	
	if(!arbol_menor_igual_x)
	{
		return minimo(A);
	}
	else
	{
		return buscar_infimo(A,x);
	}
}

template <typename T> bool buscar_menor_igual_x(const Abb<T>&A, T& x)
{
	if(A.vacio())
	{
		return false;
	}
	else
	{
		return A.elemento() <= x || buscar_menor_igual_x(A.izqdo(),x);
	}
}

template <typename T> T& minimo(Abb<T>&A)
{
	//no hace falta que comprobemos que el nodo es vacio ya que el abb no es vacio nunca
	if(A.izqdo().vacio())
	{
		return A.elemento();
	}
	else
	{
		return minimo(A.izqdo());
	}
}

template <typename T> T buscar_infimo(const Abb<T>& A, T x)
{
	//no hace falta que comprobemos que el nodo es vacio ya que el abb no es vacio nunca
	if(!A.izqdo().vacio() && A.elemento() < x)
	{
		return buscar_infimo(A.izqdo(),x);
	}
	else
	{
		if(!A.drcho().vacio() && A.elemento() > x)
		{
			return buscar_infimo(A.drcho(),A);
		}
		else
		{
			return A.elemento();
		}
	}
}





template <typename T> T& supremo_abb(const Abb<T>& A, T& x)
{
	bool arbol_mayor_igual_x = buscar_mayor_igual_x(A,x);
	
	if(!arbol_meayor_igual_x)
	{
		return minimo(A);
	}
	else
	{
		return buscar_infimo(A,x);
	}
}


template <typename T> bool buscar_mayor_igual_x(const Abb<T>&A, T& x)
{
	if(A.vacio())
	{
		return false;
	}
	else
	{
		return A.elemento() >= x || buscar_mayor_igual_x(A.Drcho(),x);
	}
}


template <typename T> T& maximo(Abb<T>&A)
{
	//no hace falta que comprobemos que el nodo es vacio ya que el abb no es vacio nunca
	if(A.drcho().vacio())
	{
		return A.elemento();
	}
	else
	{
		return maximo(A.drcho());
	}
}

template <typename T> T buscar_supremo(const Abb<T>& A, T x)
{
	//no hace falta que comprobemos que el nodo es vacio ya que el abb no es vacio nunca
	if(!A.izqdo().vacio() && A.elemento() > x)
	{
		return buscar_supremo(A.izqdo(),x);
	}
	else
	{
		if(!A.drcho().vacio() && A.elemento() < x)
		{
			return buscar_supremo(A.drcho(),A);
		}
		else
		{
			return A.elemento();
		}
	}
}


