/*
El laberinto N*N*N

Te dan:

	- N
	- lista de piedras (dos casillas donde hay una piedra)
	- casilla entrada
	- casilla salida
	
calcular camino mas corto y longitud
*/

struct obstaculo
{
	coor c1;
	coor c2;
}

struct coor
{
	int x;
	int y;
	int z;
}

struct coste_camino
{
	tCoste coste;
	vector<casilla> ruta;
}

template <typename tCoste> coste_camino laberinto_3D(int N, vector<obstaculo>& piedras, coor entrada, coor salida)
{
	matriz<tCoste> lab(N*N*N);
	
	for(int i = 0; i < N*N*N;i++)
	{
		for(int j = 0; j < N*N*N; j++)
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
	
	for(int i = 0; i < piedras.size();i++)
	{
		int a = piedras[i].c1.x*N + piedras[i].c1.y + piedras[i].c1.z*N*N; 
		int b = piedras[i].c2.x*N + piedras[i].c2.y + piedras[i].c2.z*N*N;
		lab[a][b] = GrafoP<tCoste>::INFINITO;
		lab[b][a] = GrafoP<tCoste>::INFINITO;
	}
	
	GrafoP<tCoste>::vertice origen = entrada.x*N + entrada.y + entrada.z*N*N;
	GrafoP<tCoste>::vertice destino = salida.x*N + salida.y + salida.z*N*N;
	
	vector<GrafoP<tCoste>::vertice> v;
	vector<tCoste> lab_dijkstra = dijkstra(lab,origen,v);
		
	coste_camino c;
	c.coste = lab_dijkstra[destino];
	
	while(destino != origen)
	{
		coor coord;
		coord.x = destino%N*N /N;
		coord.y = destino%N*N %N;
		coord.z = destino/N*N;
		c.ruta.push_front(coord)
		destino = v[destino];
	}
	return c;
}

int ady(int i, int j, int N)
{
	int x1 = i%N*N /N;
	int y1 = i%N*N %N;
	int z1 = i/N*N;
	int x2 = j%N*N /N;
	int y2 = j%N*N %N;
	int z2 = j/N*N;
	return abs(x1-x2) + abs(y1-y2) + abs(z1+z2);
}

int rellenar(int i, int j, int N)										// para sacar la coordenada a partir de i j será:
{																		// i = (i%N*N / N, i%N*N % N, i/N*N);
	int x1 = i%N*N /N;													// j = (j%N*N / N, j%N*N %N, j/N*N);
	int y1 = i%N*N %N;
	int z1 = i/N*N;
	int x2 = j%N*N /N;
	int y2 = j%N*N %N;
	int z2 = j/N*N;
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
}
