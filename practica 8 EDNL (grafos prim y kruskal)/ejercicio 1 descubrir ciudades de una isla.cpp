/*
El archipiélago de Tombuctú, está formado por un número indeterminado de islas,
cada una de las cuales tiene, a su vez, un número indeterminado de ciudades. En
cambio, sí es conocido el número total de ciudades de Tombuctú (podemos llamarlo N,
por ejemplo).
Dentro de cada una de las islas existen carreteras que permiten viajar entre todas
las ciudades de la isla. Se dispone de las coordenadas cartesianas (x, y) de todas y cada
una de las ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en
el que se indica si existe carretera directa entre cualesquiera dos ciudades del
archipiélago. El objetivo de nuestro problema es encontrar qué ciudades de Tombuctú
pertenecen a cada una de las islas del mismo y cuál es el coste mínimo de viajar entre
cualesquiera dos ciudades de una misma isla de Tombuctú.
Así pues, dados los siguientes datos:
- Lista de ciudades de Tombuctú representada cada una de ellas por sus
coordenadas cartesianas.
- Matriz de adyacencia de Tombuctú, que indica las carreteras existentes en
dicho archipiélago.
Implementen un subprograma que calcule y devuelva la distribución en islas de las
ciudades de Tombuctú, así como el coste mínimo de viajar entre cualesquiera dos
ciudades de una misma isla del archipiélago.
*/

struct ciudades
{
	int x;
	int y;
}

struct archipielago
{
	Particion particion_archipielago;
	GrafoP<tCoste> costes_archipielago;
}


template <typename tCoste> archipielago tombuctu(matriz<bool>carreteras,vector<ciudades>coord_ciudades)
{
	int N = coord_ciudades.size();
	GrafoP<tCoste> costes_directos(N);
	Particion part_archipielago(N);
	Matriz<GrafoP<tCoste>::vertice> P;
	
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(carreteras[i][j] == true)
			{
				costes_directos[i][j] = sqrt(pow(coord_ciudades[i].x - coord_ciudades[j].x,2)+pow(coord_ciudades[i].y - coord_ciudades[j].y,2));
				
				if(part_archipielago.encontrar[i] != part_archipielago.encontrar[j])
				{
					part_archipielago.unir(i,j);
				}
			}
		}
	}
	
	GrafoP<tCoste> floyd_archipielago = Floyd(costes_directos,P);
	
	archipielago tombuctu;
	tombuctu.particion_archipielago = part_archipielago;
	costes_archipielago = floyd_archipielago;
	
	return tombuctu;
	
}
