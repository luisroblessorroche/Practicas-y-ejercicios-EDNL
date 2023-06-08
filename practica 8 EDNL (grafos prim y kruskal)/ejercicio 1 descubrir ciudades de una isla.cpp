/*
El archipi�lago de Tombuct�, est� formado por un n�mero indeterminado de islas,
cada una de las cuales tiene, a su vez, un n�mero indeterminado de ciudades. En
cambio, s� es conocido el n�mero total de ciudades de Tombuct� (podemos llamarlo N,
por ejemplo).
Dentro de cada una de las islas existen carreteras que permiten viajar entre todas
las ciudades de la isla. Se dispone de las coordenadas cartesianas (x, y) de todas y cada
una de las ciudades del archipi�lago. Se dispone de un grafo (matriz de adyacencia) en
el que se indica si existe carretera directa entre cualesquiera dos ciudades del
archipi�lago. El objetivo de nuestro problema es encontrar qu� ciudades de Tombuct�
pertenecen a cada una de las islas del mismo y cu�l es el coste m�nimo de viajar entre
cualesquiera dos ciudades de una misma isla de Tombuct�.
As� pues, dados los siguientes datos:
- Lista de ciudades de Tombuct� representada cada una de ellas por sus
coordenadas cartesianas.
- Matriz de adyacencia de Tombuct�, que indica las carreteras existentes en
dicho archipi�lago.
Implementen un subprograma que calcule y devuelva la distribuci�n en islas de las
ciudades de Tombuct�, as� como el coste m�nimo de viajar entre cualesquiera dos
ciudades de una misma isla del archipi�lago.
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
