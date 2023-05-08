/*
Se necesita hacer un estudio de las distancias mínimas necesarias para viajar entre
dos ciudades cualesquiera de un país llamado Zuelandia. El problema es sencillo pero
hay que tener en cuenta unos pequeños detalles:
a) La orografía de Zuelandia es un poco especial, las carreteras son muy estrechas
y por tanto solo permiten un sentido de la circulación.
b) Actualmente Zuelandia es un país en guerra. Y de hecho hay una serie de
ciudades del país que han sido tomadas por los rebeldes, por lo que no pueden
ser usadas para viajar.
c) Los rebeldes no sólo se han apoderado de ciertas ciudades del país, sino que
también han cortado ciertas carreteras, (por lo que estas carreteras no pueden ser
usadas).
d) Pero el gobierno no puede permanecer impasible ante la situación y ha exigido
que absolutamente todos los viajes que se hagan por el país pasen por la capital
del mismo, donde se harán los controles de seguridad pertinentes.
Dadas estas cuatro condiciones, se pide implementar un subprograma que dados

• el grafo (matriz de costes) de Zuelandia en situación normal
• la relación de las ciudades tomadas por los rebeldes
• la relación de las carreteras cortadas por los rebeldes
• y la capital de Zuelandia

calcule la matriz de costes mínimos para viajar entre cualesquiera dos ciudades
zuelandesas en esta situación.
*/


/*
Para representar las ciudades tomadas lo representaremos mediante un
vector de booleanos. Si un valor es true signifoca que el vertice(indice del vector)
es una ciudad tomada por los rebeldes

Para representar las carreteras cortadas usaremos una matriz de booleanos. Si el valor es
true significa que la carretera ij esta cortada.
*/
template <typename tCoste> GrafoP<tCoste> zuelandia(const GrafoP<tCoste>& G,
std::vector<bool> ciudades, std::vector<std::vector<bool>> carreteras,
typename GrafoP<tCoste>::vertice capital)
{
	for(int i = 0; i < ciudades.size();i++)
	{
		if(ciudades[i] == true)
		{
			for(j = 0; j < G.numvert();j++)
			{
				G[i][j] = GrafoP<tCoste>::INFINITO;
				G[j][i] = GrafoP<tCoste>::INFINITO;
			}
		}
	}
	
	for(int x = 0; x < G.numvert();x++)
	{
		for(int y = 0; y < G.numvert();y++)
		{
			if(carreteras[x][y] == true)
			{
				G[x][y] = GrafoP<tCoste>::INFINITO;
			}
		}
	}
	
	vector<tCoste> ciudad_a_capital = dijkstraInv(G,capital);
	vector<tCoste> capital_a_ciudad = dijkstra(G,capital);
	
	for(int i = 0; i < G.numvert();i++)
	{
		for(int j = 0; j < G.numvert();j++)
		{
			G[i][j] = suma(ciudad_a_capital[i],capital_a_ciudad[j]);
		}
	}
	
	return G;
	
}
