//Ejercicio 4

/*
Una posible representaci�n del TAD �rbol Binario consiste en almacenar los
elementos del �rbol en un vector cuyo tama�o, N = 2 (elevado a H+1) - 1 , depende de la altura
m�xima H que pueda llegar a alcanzar el �rbol. Cada nodo del �rbol se corresponde con
una �nica posici�n del vector, la cual viene determinada por el recorrido en inorden del
�rbol. Es decir, en el vector aparecen primero los nodos del sub�rbol izquierdo en inorden,
luego la ra�z y a continuaci�n los nodos del sub�rbol derecho tambi�n en inorden. Por
ejemplo, el �rbol de la figura se representa como el vector
(-, -, -, n, -, -, -, a, f, l, -, b, -, d, -, h, -, -, -, -, -, -, -, m, -, c, -, j, -, -, -),
donde �-� representa una posici�n vac�a.

Los hijos izquierdo y derecho de un nodo n corresponden, respectivamente, a las
posiciones n - 2 (elevado a h -1) y n + 2 (elevado a h) -1, donde h es la altura m�xima que puede alcanzar n, la
cual se puede calcular a partir de la profundidad p de n y de la altura m�xima del �rbol,
h = H - p. Por tanto, el padre de un nodo n se calcula de la siguiente forma:

			 n + 2 (elevado a h) si n es hijo izquierdo
padre(n) = 
			 n - 2 (elevado a h) si n es hijo derecho

Un nodo n es hijo izquierdo de su padre si se cumple la igualdad
n mod 2 (elevado a h+2) = 2 (elevado a h) - 1.

a)	Define la clase gen�rica Abin<T> para esta representaci�n.
b)	Implementa una funci�n miembro privada que calcule la altura de un nodo de un
	�rbol binario representado de la forma descrita.
c) 	Para esta representaci�n implementa, al menos, el constructor de �rboles vac�os y
	las operaciones insertarRaiz(), insertarHijoIzqdo() y padre(), seg�n la
	especificaci�n del TAD �rbol Binario vista en clase.
*/

template <typename T> class Abin
{
	public:
		typedef size_t nodo;
		static const nodo NODO_NULO;
		Abin(int n);
		void insertarRaiz(T& e);
		void insertarHijoIzqdo(nodo n, T& e);
		void padre(T& e);
		int altura_abin();
	private:
		std::vector<T> vec;
		T ELTO_NULO;
}

template <typename T> Abin(int n)
{
	int num = pow(2,n+1) -1;
	vec = new std::vector<T>(num);
	
	std::vector<T>::iterator it = vec.begin();
	while(it != vec.end())
	{
		(*it)->ELTO_NULO;
		++it;
	}
}

template <typename T> void insertarRaiz(T& e)
{
	assert(vec.at(vec.size()/2) == ELTO_NULO);
	vec.at(vec.size()/2) = e;
}

template <typename T> void insertarHijoIzqdo(nodo n, T& e)
{
	assert(n>0 && n<vec.size());
	assert(vec.at(n) != ELTO_NULO);
	int altura = altura_nodo(n);
	assert(n - pow(2,altura) >= 0);
	assert(vec.at(n - pow(2,altura)) == ELTO_NULO);
	
	vec.at(n-pow(2,altura)) = e;
}

template <typename T> nodo padre(nodo n)
{
	assert(n >= 0 && n< vec.size());
	int altura = altura_nodo(n);
	if(n % pow(2,altura + 2) == pow(2,altura) -1)
	{
		return n + pow(2,h);
	}
	else
	{
		return n - pow(2,h);
	}
}

template <typename> int altura_abin()
{
	int H = -1;
	int tam_vector = vec.size() + 1;
	while(tam_vector != 1)
	{
		tam_vector = tam_vector/2;
		H++;
	}
	return H;
}

int profundidad_nodo(nodo n, int tam_vec)
{
	return produndidad_nodo_rec(n,(tam_vec-1)/2,0,tam_vec-1); 
}

int profundidad_nodo_rec(nodo n,int centro int ini, int fin)
{
	if(n == (centro)
	{
		return 0;
	}
	else
	{
		centro = (fin+ini)/2;
		id(n<centro)
		{
			return 1 + profundidad_nodo_rec(n,ini,medio-1);
		}
		else
		{
			return 1 + profundidad_nodo_rec(n,medio+1,fin);
		}
	}
}

