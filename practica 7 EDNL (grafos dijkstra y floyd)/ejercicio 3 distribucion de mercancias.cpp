/*
Eres el orgulloso dueño de una empresa de distribución. Tu misión radica en
distribuir todo tu stock entre las diferentes ciudades en las que tu empresa dispone de
almacén.
Tienes un grafo representado mediante la matriz de costes, en el que aparece el coste
(por unidad de producto) de transportar los productos entre las diferentes ciudades del
grafo.
Pero además resulta que los Ayuntamientos de las diferentes ciudades en las que
tienes almacén están muy interesados en que almacenes tus productos en ellas, por lo
que están dispuestos a subvencionarte con un porcentaje de los gastos mínimos de
transporte hasta la ciudad. Para facilitar el problema, consideraremos despreciables los
costes de volver el camión a su base (centro de producción).
He aquí tu problema. Dispones de
? el centro de producción, nodo origen en el que tienes tu producto (no tiene
almacén),
? una cantidad de unidades de producto (cantidad),
? la matriz de costes del grafo de distribución con N ciudades,
? la capacidad de almacenamiento de cada una de ellas,
? el porcentaje de subvención (sobre los gastos mínimos) que te ofrece cada
Ayuntamiento.
Las diferentes ciudades (almacenes) pueden tener distinta capacidad, y además la
capacidad total puede ser superior a la cantidad disponible de producto, por lo que
debes decidir cuántas unidades de producto almacenas en cada una de las ciudades.
Debes tener en cuenta además las subvenciones que recibirás de los diferentes
Ayuntamientos, las cuales pueden ser distintas en cada uno y estarán entre el 0% y el
100% de los costes mínimos.
La solución del problema debe incluir las cantidades a almacenar en cada ciudad bajo
estas condiciones y el coste mínimo total de la operación de distribución para tu
empresa.
*/

struct coste_y_almacenamiento
{
	vector<tCoste> almacenamiento;
	tCoste coste_final;
}

template <typename tCoste> distribucion_mercancia(typename GrafoP<tCoste>::vertice origen,int stock, const GrafoP<tCoste>& C, std::vector<int> capacidad, std::vector<float> subvencion)
{
	
	vector<GrafoP<tCoste>::vertice>& P;
	vector<tCoste> almacenaje_por_ciudad(C.numVert());
	tCoste coste_total = 0;
	
	vector<bool> ciudades_repartidas(C.numVert());
	for(int i = 0; i < C.numVert())
	{
		ciudades_repartidas[i] = false;
	}
	
	while(stock != 0 && num_ciudades_repartidas(ciudades_repartidas,C.numVert()) != C.numVert())
	{
		vector<tCoste> ciudades_dijkstra = dijkstra(origen,C,P);
		for(int i = 0; i < C.numVert();i++)
		{
			ciudades_dijkstra[i] = ciudades_dijkstra[i] * stock * subvencion[i]/100;
		}
		
		vector<tCoste>::vertice menor_coste = 0;
		tCoste coste = ciudades_dijkstra[0];
		
		for(int i = 0; i < C.numVert();i++)
		{
			if(ciudades_dijkstra[i] < coste && ciudad_repartida[i] == false)
			{
				menor_coste = i;
				coste = ciudades_dijkstra[i];
			}
		}
		
		ciudad_repartida[menor_coste] = true;
		coste_total = coste_total + coste;
		if(capacidad[menor_coste] < stock)
		{
			almacenaje_por_ciudad[menor_coste] = capacidad;
			stock = stock - capacidad;	
		}
		else
		{
			almacenaje_por_ciudad[menor_coste] = stock;
			stock = 0;
		}		
	}
	
	coste_y_almacenamiento C_Y_A;
	C_Y_A.almacenamiento = 	almacenaje_por_ciudad;
	C_Y_A.coste_final = coste_total;
	
	return C_Y_A;
}

int num_ciudad_repartidas(vector<bool> ciudades, int N)
{
	int visitadas = 0;
	for(int i = 0; i < N; i++)
	{
		if(ciudades[i] == true)
		{
			visitados++;
		}
	}
	return visitados;
}
