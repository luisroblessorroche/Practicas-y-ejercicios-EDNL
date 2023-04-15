//Ejercicio 3

/*
3. Implementa una operación de orden logarítmico para eliminar el elemento máximo de
un montículo min-max definido como en el problema anterior.
*/

template <typename T> class Apo_Min_Max {
	public:
		explicit Apo(size_t maxNodos); // constructor
		void insertar(const T& e);
		void suprimir();
		void suprimir_max()
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
		nodo max();
		int nivelNodo(nodo i);
		void flotar(nodo i);
		void hundir(nodo i);
};

template <typename T> inline void Apo_Min_Max<T>::suprimir_max()
{
	assert(numNodos > 0);
	nodo max = 0;
	if(numNodos == 1)
	{
		numNodos = 0;
	}
	else
	{
		max = buscar_max(1);
		nodos[max] = nodos[numNodos -1];
		if(numNodos > 1)
		{
			hundir(max);
		}
	}
}

template<typename T> int Apo_Min_Max<T>::buscar_max(nodo i)
{
	int max = nodos[pow(2,i) -1];
	for(int x = pow(2,i) -1; x < pow(2,i+1) -1;x++)
	{
		if( x < maxNodos && nodos[x] > max)
		{
			max = nodos[x];
		}
	}
	return max;
}

template <typename T> inline void Apo_Min_Max<T>::hundir(nodo i)
{
	if(nivelNodo(numNodos - 1) - nivelNodo(i) >= 2)
	{
		int max = buscar_max(nivelNodo(i) + 2);
		T e = nodos[i];
		nodos[i] = nodos[max];
		nodos[max] = e;
		hundir(i);
	}
	else
	{
		if(nivelNodo(numNodos -1) - nivelNodo(i) == 1)
		{
			int max = buscar_max(nivelNodo(i) + 1);
			T e = nodos[i];
			nodos[i] = nodos[max];
			nodos[max] = e;
			hundir(i);
		}
		else
		{
			int max = buscar_max(nivelNodo(i));
			T e = nodos[i];
			nodos[i] = nodos[max];
			nodos[max] = e;
			numNodos--;
		}	
	}
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
