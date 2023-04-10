//Ejercicio 2

/*
Un montículo min-max tiene una estructura similar a la de un montículo ordinario
(árbol parcialmente ordenado), pero la ordenación parcial consiste en que los elementos
que se encuentran en un nivel par (0, 2, 4,...) son menores o iguales que sus elementos
descendientes, mientras que los elementos que se encuentran en un nivel impar (1, 3,
5,...) son mayores o iguales que sus descendientes. Esto quiere decir que para cualquier
elemento e de un nivel par se cumple abuelo = e = padre y para cualquier elemento e de
un nivel impar padre = e = abuelo.
 Implementa una operación de orden logarítmico para añadir un elemento a un
montículo min-max almacenado en un vector de posiciones relativas.
*/

template <typename T> class Apo_Min_Max {
	public:
		explicit Apo(size_t maxNodos); // constructor
		void insertar(const T& e);
		void suprimir();
		const T& cima() const;
		bool vacio() const;
		Apo(const Apo<T>& A); // ctor. de copia
		Apo<T>& operator =(const Apo<T>& A); // asignación de apo
		~Apo(); // destructor
		
		
	private:
		typedef size_t nodo; // índice del vector
		// entre 0 y maxNodos-1
		T* nodos; // vector de nodos
		size_t maxNodos; // tamaño del vector
		size_t numNodos; // último nodo del árbol
		nodo padre(nodo i) const { return (i-1)/2; }
		nodo hIzq(nodo i) const { return 2*i+1; }
		nodo hDer(nodo i) const { return 2*i+2; }
		int nivelNodo(nodo i);
		void flotar(nodo i);
		void flotar_Apo(nodo i);
		void hundir(nodo i);
};


template <typename T> inline void Apo_Min_Max<T>::insertar(const T& e)
{
	assert (numNodos < maxNodos);
	nodos[numNodos] = e;
	numNodos++;
	
	if(numNodos ==2 || numNodos == 3)
	{
		flotar_Apo(numNodos - 1);
	}
	else
	{
		flotar(numNodos - 1);
	}
}

template <typename T>void Apo<T>::flotar_Apo(nodo i)
{
	T e = nodos[i];
	while (i > 0 && e < nodos[padre(i)])
	{
		nodos[i] = nodos[padre(i)];
		i = padre(i);
	}
	nodos[i] = e;
}

template <typename T> void Apo_Min_Max<T>::flotar(nodo i)
{
	int nivel = nivelNodo(i);
	
	T e = nodos[i];
	
	if(i == 1 || i == 2)
	{
		int ind = buscar_min(i-1);
		if(e < nodos[ind])
		{
			nodos[i] = nodos[ind];
			i = ind;
			nodos[i] = e;
			flotar(i);
		}
	}
	else
	{
		if(i > 2 && nivelNodo(i)%2 == 0)
		{
			int indice = buscar_min(i-2);
			if(e < nodos[indice])
			{
				nodos[i] = nodos[indice];
				i = indice;
				nodos[i] = e;
				flotar(i);
			}
			else
			{
				int indice2 = buscar_min(i-1);
				if(e > nodos[indice2])
				{
					nodos[i] = nodos[indice2];
					i = indice2;
					nodos[i] = e;
					flotar(i);
				}
			}
		}
		else
		{
			if(i > 2 && nivelNodo(i)%2 == 1)
			{
				int indice = buscar_min(i-2);
				if(e > nodos[indice])
				{
					nodos[i] = nodos[indice];
					i = indice;
					nodos[i] = e;
					flotar(i);
				}
				else
				{
					int indice2 = buscar_min(i-1);
					if(e < nodos[indice2])
					{
						nodos[i] = nodos[indice2];
						i = indice2;
						nodos[i] = e;
						flotar(i);
					}
				}
			}
		}
	}	
}

template<typename T> int buscar_min(nodo i)
{
	int min = nodos[pow(2,i) -1];
	for(int x = pow(2,i) -1; x < pow(2,i+1) -1;x++)
	{
		if(nodos[x] < min)
		{
			min = nodos[x];
		}
	}
	return min;
}

template <typename T> int Apo_Min_Max<T>::nivelNodo(nodo i)
{
	int x = i;
	int nivel = -1;
	while(x > 0)
	{
		nivel++;
		x = x/2;
	}
	return nivel;
}
