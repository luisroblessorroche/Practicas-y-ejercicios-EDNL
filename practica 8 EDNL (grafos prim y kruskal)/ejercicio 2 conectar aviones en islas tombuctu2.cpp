/*
El archipiélago de Tombuctú2 está formado por un número desconocido de islas,
cada una de las cuales tiene, a su vez, un número desconocido de ciudades, las cuales
tienen en común que todas y cada una de ellas dispone de un aeropuerto. Sí que se
conoce el número total de ciudades del archipiélago (podemos llamarlo N, por ejemplo).
Dentro de cada una de las islas existen carreteras que permiten viajar entre todas
las ciudades de la isla. No existen puentes que unan las islas y se ha decidido que la
opción de comunicación más económica de implantar será el avión.
Se dispone de las coordenadas cartesianas (x, y) de todas y cada una de las
ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en el que se
indica si existe carretera directa entre cualesquiera dos ciudades del archipiélago. El
objetivo de nuestro problema es encontrar qué líneas aéreas debemos implantar para
poder viajar entre todas las ciudades del archipiélago, siguiendo los siguientes criterios:
1) Se implantará una y sólo una línea aérea entre cada par de islas.
2) La línea aérea escogida entre cada par de islas será la más corta entre todas
las posibles.
Así pues, dados los siguientes datos:
• Lista de ciudades de Tombuctú2 representada cada una de ellas por sus
coordenadas cartesianas.
• Matriz de adyacencia de Tombuctú que indica las carreteras existentes en
dicho archipiélago
*/


struct distribucion_y_costes_minimos
{
	Particion p;
	Grafo<tCoste> G_floyd;
}

template <typename tCoste> tombuctu2(vector<ciudades> &coord_ciudades, matriz<bool> &carreteras)
{
	int N = coord_ciudades.size();
	GrafoP<tCoste> G_directos(N);
	
	for(int i = 0; i < N; i++)
	{
		for( int j = 0; j < N; j++)
		{
			if(carreteras[i][j] == true)
			{
				G_directos[i][j] = sqrt(pow(i-j,2)+pow(i-j,2));
			}
		}
	}
	
	Particion particion(N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(G_directos[i][j] != GrafoP<tCoste>::INFINITO && particion.encontrar(i) != particion.encontrar(j))
			{
				particion.unir(i,j);
			}
		}
	}
	
	GrafoP<tCoste> g(N);
	Apo<arista>A(n*n);
	
	for(vertice u = 0; u <= n-2;u++)
	{
		for(vertice v = u+1; v <= n-1;v++)
		{
			if(G_directo[u][v] == GrafoP<tCoste>::INFINITO)
			{
				A.insertar(arista(u,v,sqrt(pow(u-v,2) + pow(u-v,2))));
			}
		}
	}
	
	size_t i = 1;
	while (i <= n-1)
	{
		arista a = A.cima();
		A.suprimir();
		vertice u = particion.encontrar(a.orig);
		vertice v = particion.encontrar(a.dest);
		
		if(u != v)
		{
			particion.unir(u,v);
			
			G_directos[a.orig][a.dest] = a.coste;
			i++;
		}
	}
	
	
	distribucion_y_costes_minimos tumbuctu2;
	
	tumbuctu2.p = particion;
	tumbuctu2.G_floyd = floyd(G_directos);
	
	return tumbuctu2;
}
