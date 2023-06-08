/*
El archipi�lago de Tombuct�2 est� formado por un n�mero desconocido de
islas, cada una de las cuales tiene, a su vez, un n�mero desconocido de
ciudades, las cuales tienen en com�n que todas y cada una de ellas dispone de
un aeropuerto. S� que se conoce el n�mero total de ciudades del archipi�lago
(podemos llamarlo N, por ejemplo). Dentro de cada una de las islas existen
carreteras que permiten viajar entre todas las ciudades de la isla. No existen
puentes que unan las islas y se ha decidido que la opci�n de comunicaci�n
m�s econ�mica de implantar ser� el avi�n. Se dispone de las coordenadas
cartesianas (x, y) de todas y cada una de las ciudades del archipi�lago.
Se dispone de un grafo (matriz de adyacencia) en el que se indica si existe
carretera directa entre cualesquiera dos ciudades del archipi�lago. El objetivo
de nuestro problema es encontrar qu� l�neas a�reas debemos implantar para
poder viajar entre todas las ciudades del archipi�lago, siguiendo los siguientes
criterios:

	1)Se implantar� una y s�lo una l�nea a�rea entre cada par de islas.
	
	2)La l�nea a�rea escogida entre cada par de islas ser� la m�s corta entre todas
	  las posibles.

As� pues, dados los siguientes datos:

	�Lista de ciudades de Tombuct�2 representada cada una de ellas por sus
	 coordenadas cartesianas.
	 
	�Matriz de adyacencia de Tombuct� que indica las carreteras existentes en
	dicho archipi�lago,
	
Implementen un subprograma que calcule y devuelva las l�neas a�reas
necesarias para comunicar adecuadamente el archipi�lago siguiendo los
criterios anteriormente expuestos.
*/

struct ciudades
{
	int x;
	int y;
}

struct arista
{
	int i;
	int j;
	int dist;
}

template <typename tCoste> tombuctu2(vector<ciudades>& c, matriz<bool>&carreteras)
{
	int N = c.size();
	
	Particion p(N);
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(carreteras[i][j] && p.encontrar(i) != p.encontrar(j))
			{
				p.unir(i,j);
			}
		}
	}
	
	matriz<tCoste> aerolineas(N);
	Apo A(N*(N-1));
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(p.encontrar(i) != p.encontrar(j))
			{
				arista a;
				a.i = i;
				a.j = j;
				a.dist = sqrt(pow(c[i].x - c[j].x,2)+pow(c[i].y - c[j].y,2));
				A.insertar(a);
			}
		}
	}
	
	while(!A.vacio())
	{
		arista a = A.cima();
		A.suprimir();
		if(aerolineas[a.i][a.j] == Grafo<tCoste>::INFINITO)
		{
			aerolineas[a.i][a.j] = a.dist;
		}
	}
	
	return aerolineas;
	
}
