/*
Se dispone de un laberinto de NxN casillas del que se conocen las casillas de entrada
y salida del mismo. Si te encuentras en una casilla sólo puedes moverte en las siguientes
cuatro direcciones (arriba, abajo, derecha, izquierda). Por otra parte, entre algunas de las
casillas hay una pared que impide moverse entre las dos casillas que separa dicha pared
(en caso contrario no sería un verdadero laberinto).

Implementa un subprograma que dados
	- N (dimensión del laberinto),
	- la lista de paredes del laberinto,
	- la casilla de entrada, y
	- la casilla de salida,
	
calcule el camino más corto para ir de la entrada a la salida y su longitud.
*/

struct casilla
{
	int i;
	int j;
};

template <typename tCoste> tCoste laberinto(int N, std::vector<casilla> paredes, casilla inicio, casilla final)
{
	GrafoP G(N);
	
	for(int k = 0; k < paredes.size(); k++)
	{
		G[casilla[k].i][casilla[k].j] = GrafoP<tCoste>::INFINITO;
	}
	
	
	Grafo A(N);
	
	
	for(int i = 0; i < N, i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(G[i][j] != GrafoP<tCoste>::INFINITO)
			{
				G[i][j] = 1;
			}
		}
	}
	
	typename GrafoP<tCoste>::vertice ini = inicio.i;
	typename GrafoP<tCoste>::vertice fin = fin.j;
	
	vector<tCoste> v = dijkstra(A,ini,P);
	return v[fin];
}
