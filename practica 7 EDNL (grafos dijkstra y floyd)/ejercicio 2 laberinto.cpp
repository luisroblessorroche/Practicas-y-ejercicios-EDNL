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


struct paredes
{
	casilla c1;
	casilla c2;
}

struct casilla
{
	int x;
	int y;
}

struct coste_ruta
{
	tCoste coste;
	vector<casillas> ruta;
}

template <typename tCoste> tCoste laberinto(int N, std::vector<paredes> paredes, casilla inicio, casilla final)
{
	matriz<tCoste> lab(N*N);
	
	for(int i = 0; i < N*N;i++)
	{
		for(int j = 0; j < N*N; j++)
		{
			if(ady(i,j) == 1 || ady(i,j) == 0)
			{
				lab[i][j] = rellenar(i,j,N);
			}
			else
			{
				lab[i][j] = GrafoP<tCoste>::INFINITO;
			}
		}
	}
	
	for(int i = 0; i < paredes.size();i++)
	{
		int a = paredes[i].c1.x*N + paredes[i].c1.y;
		int b = paredes[i].c2.x*N + paredes[i].c2.y;
		
		lab[a][b] = Grafo<tCoste>::INFINITO;
		lab[b][a] = Grafo<tCoste>::INFINITO;	
	}
	
	GrafoP<tCoste>::vertice origen = inicio.x*N + inicio.y;
	GrafoP<tCoste>::Vertice destino = final.x*N + final.y;
	
	vector<GrafoP<tCoste>::vertice> P;
	
	matriz dijkstra_lab = dijkstra(lab,origen,P);
	
	coste_ruta cr;
	cr.coste = dijkstra_lab[destino];
	
	vector<GrafoP<tCoste>::vertice> v;
	
	while(destino != origen)
	{
		casilla c;
		c.x = destino/N;
		c.y = destino%N;
		v.push_front(c);
		destino = P[destino];
	}
	
	return cr;
}

int ady(int i, int j, int N)
{
	int x1 = i/N;
	int y1 = i%N;
	int x2 = j/N;
	int y2 = j%N;
	return abs(x1-x2) + abs(y1-y2);
}


float rellenar(int a,int b,int N)						// para sacar la la coordenada del laberinto dado a y b
{														// a = (a/N,a%N)
	int x1 = a/N;										// b = (b/N,b%N)
	int x2 = b/N;										// distancia euclidea de a y b
	int y1 = a%N;
	int y2 = b%N;
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}


