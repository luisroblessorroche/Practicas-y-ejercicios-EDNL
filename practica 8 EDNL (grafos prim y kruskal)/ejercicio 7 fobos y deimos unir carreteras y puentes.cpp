/*
7. El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas,
Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2
ciudades son costeras (obviamente C1 = N1 y C2 = N2 ). Se dispone de las coordenadas
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
2. Lista de ciudades de Deimos representadas mediante sus coordenadas
cartesianas.
3. Lista de ciudades costeras de Fobos.
4. Lista de ciudades costeras de Deimos.
5. Ciudad origen del viaje.
6. Ciudad destino del viaje.
*/


struct ciudades
{
	int x;
	int y;
}

struct coste_y_camino
{
	tCoste coste_minimo;
	vector<GrafoP<tCoste>::vertice> ruta;
}

//costeras_fobos y costeras_deimos serán dos vectores de tamaño fobos.size() y deimos.size() donde si costera[i] es true significa que fobos[i] o deimos[i] es costera

template <typename tCoste> tCoste zuelandia(vector<ciudades>& Fobos, vector<ciudades>& Deimos, vector<bool>& costeras_fobos, vector<bool>& costeras_deimos,
GrafoP<tCoste>::vertice origen, GrafoP<tCoste>::vertice destino)
{
	int N1 = Fobos.size();
	GrafoP<tCoste> fobos_directo(N1);
	
	for(int i = 0; i < N1; i++)
	{
		for(int j = 0; j < N1;j++)
		{
			fobos_directo[i][j] = sqrt(pow(fobos[i].x - fobos[j].x,2)+pow(fobos[i].y - fobos[j].y,2));
		}
	}
	
	GrafoP<tCoste> fobos_kruskall = kruskall(fobos_directo);
	
	int N2 = Deimos.size();
	GrafoP<tCoste> deimos_directo(N2);
	for(int i = 0; i < N2; i++)
	{
		for(int j = 0; j < N2; j++)
		{
			deimos_directo[i][j] = sqrt(pow(deimos[i].x - deimos[j].x,2)+pow(deimos[i].y - deimos[j].y,2));
		}
	}
	
	Grafo<tCoste> deimos_kruskall = kruskall(deimos_directo);
	
	Grafo<tCoste> fobos_y_deimos(N1+N2);
	
	for(int i = 0; i < N1; i++)
	{
		for(int j = 0; j < N1; j++)
		{
			fobos_y_deimos[i][j] = fobos_kruskall[i][j];
		}
	}
	
	for(int i = N1; i < N1+N2; i++)
	{
		for(int j = N1; j < N1+N2; j++)
		{
			fobos_y_deimos[i][j] = deimos_kruskall[i-N1][j-N1];
		}
	}
	
	for(int i = 0; i<N1;i++)
	{
		for(int j = 0; j <N2; j++)
		{
			if(costeras_fobos[i] == true && costeras_deimos[j] == true)
			{
				fobos_y_deimos[i][j+N1] = sqrt(pow(fobos[i].x - deimos[j].x,2)+pow(fobos[i].y - deimos[j].y,2));
				fobos_y_deimos[j+N1][i] = fobos_y_deimos[i][j+N1];
			}
		}
	}
	
	GrafoP<tCoste> fobos_deimos_kruskall = kruskall(fobos_y_deimos);
	
	vector<GrafoP<tCoste>::vertice> P;
	vector<tCoste> dijkstra_fobos_deimos = dijkstra(fobos_deimos_kruskall,origen,P);
	
	coste_y_camino C;
	C.ruta = P;
	C.coste_minimo = dijkstra_fobos_deimos[destino];
	
	return C;
	
}
