/*
El archipiélago de Grecoland (Zuelandia) está formado únicamente por tres islas,
Fobos, Deimos y Europa, que tienen N1,N2 y N3 ciudades, respectivamente, de las cuales C1, C2 y C3
ciudades son costeras (obviamente C1 <= N1, C2 <= N2 y C3 <= N3). Se dispone de las coordenadas
cartesianas (x, y) de todas y cada una de las ciudades del archipiélago. El huracán
Isadore acaba de devastar el archipiélago, con lo que todas las carreteras y puentes
construidos en su día han desaparecido. En esta terrible situación se pide ayuda a la
ONU, que acepta reconstruir el archipiélago (es decir volver a comunicar todas las
ciudades del archipiélago) siempre que se haga al mínimo coste.
 De cara a poder comparar costes de posibles reconstrucciones se asume lo
siguiente:
1. El coste de construir cualquier carretera o cualquier puente es proporcional a su
longitud (distancia euclídea entre las poblaciones de inicio y fin de la carretera o
del puente).
2. Cualquier puente que se construya siempre será más caro que cualquier carretera
que se construya.
 De cara a poder calcular los costes de VIAJAR entre cualquier ciudad del
archipiélago se considerará lo siguiente:
1. El coste directo de viajar, es decir de utilización de una carretera o de un puente,
coincidirá con su longitud (distancia euclídea entre las poblaciones origen y
destino de la carretera o del puente).
 En estas condiciones, implementa un subprograma que calcule el coste mínimo
de viajar entre dos ciudades de Grecoland, origen y destino, después de haberse
reconstruido el archipiélago, dados los siguientes datos:
1. Lista de ciudades de Fobos representadas mediante sus coordenadas cartesianas.
2. Lista de ciudades de Deimos representadas mediante sus coordenadas cartesianas.
3. Lista de ciudades de Europa representadas mediante sus coordenadas cartesianas.
4. Lista de ciudades costeras de Fobos.
5. Lista de ciudades costeras de Deimos.
6. Lista de ciudades costeras de Europa.
7. Ciudad origen del viaje.
8. Ciudad destino del viaje.
*/

struct ciudades
{
	int x;
	int y;
}

template <typename tCoste> tCoste Grecoland(vector<ciudades>& Fobos, vector<ciudades>& Deimos, vector<ciudades>& Europa,
vector<bool>& c_Fobos, vector<bool>& c_Deimos, vector<bool>& c_Europa, GrafoP<tCoste>::vertice origen, GrafoP<tCoste>::vertice destino)
{
	int NF = Fobos.size();
	int ND = Deimos.size();
	int NE = Europa.size()
	
	GrafoP<tCoste> Fobos_directo(NF);
	GrafoP<tCoste> Deimos_directo(ND);
	GrafoP<tCoste> Europa_directo(NE);
	
	for(int i = 0; i < NF; i++)
	{
		for(int j = 0; j < NF; j++)
		{
			Fobos_directo[i][j] = sqrt(pow(Fobos[i].x - Fobos[j].x,2) + pow(Fobos[i].y - Fobos[j].y,2));
		}
	}
	
	for(int i = 0; i < ND; i++)
	{
		for(int j = 0; j < ND; j++)
		{
			Deimos_directo[i][j] = sqrt(pow(Deimos[i].x - Deimos[j].x,2) + pow(Deimos[i].y - Deimos[j].y,2));
		}
	}
	
	for(int i = 0; i < NE; i++)
	{
		for(int j = 0; j < NE; j++)
		{
			Europa_directo[i][j] = sqrt(pow(Europa[i].x - Europa[j].x,2)+pow(Europa[i].y - Europa[j].y,2));
		}
	}
	
	GrafoP<tCoste> kruskall_Fobos = kruskall(Fobos_directo);
	GrafoP<tCoste> kruskall_Deimos = kruskall(Deimos_directo);
	GrafoP<tCoste> kruskall_Europa = kruskall(Europa_directo);
	
	GrafoP<tCoste> Grecolando(NF+ND+NE);
	
	for(int i = 0; i < NF; i++)
	{
		for(int j = 0; j < NF; j++)
		{
			Grecoland[i][j] = kruskall_Fobos[i][j];
		}
	}
	
	for(int i = NF; i < NF+ND; i++)
	{
		for(int j = NF; j < NF+ND; j++)
		{
				Grecoland[i][j] = kruskall_Deimos[i-NF][j-NF];
		}
	}
	
	for(int i = NF+ND; i < NF+ND+NE; i++)
	{
		for(int j = NF+ND; j < NF+ND+NE;j++)
		{
			Grecoland[i][j] = kruskall_Europa[i-NF+ND][j-NF+ND];
		}
	}
	
	for(int i = 0; i < NF;i++)
	{
		for(int j = 0; j < ND;j++)
		{
			if(c_Fobos[i] && c_Deimos[j])
			{
				Grecoland[i][j] = sqrt(pow(Fobos[i].x - Deimos[j].x,2)+pow(Fobos[i].y - Deimos[j].y,2));
				Grecoland[j][i] = Grecoland[i][j];
			}
		}
	}
	
	for(int i = 0; i < NF; i++)
	{
		for(int j = 0; j< NE; i++)
		{
			if(c_Fobos[i] && c_Europa[i])
			{
				Grecoland[i][j+NF+ND] = sqrt(pow(Fobos[i].x - Europa[j].x,2)+pow(Fobos[i].y - Europa[j].y,2));
				Grecoland[j+NF+ND][i] = Grecoland[i][j+NF+ND];
			}
		}
	}
	
	for(int i = 0; i < ND; i++)
	{
		for(int j = 0; j < NE;j++)
		{
			Grecoland[i+NF][j+NF+ND] = sqrt(pow(Deimos[i].x-Europa[j].x,2)+pow(Deimos[i].y - Europa[j].y,2));
			Grecoland[j+NF+ND][i+NF] = Grecoland[i+NF][j+NF+ND];
		}
	}
	
	GrafoP<tCoste> kruskall_grecoland = kruskall(Grecoland);
	
	vector<Grafo<tCoste>::vertice> P;
	vector<tCoste> dijkstra_grecoland = dijkstra(kruskall_grecoland,origen,P);
	return dijkstra_grecoland[destino];
	
}
