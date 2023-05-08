/*
Al dueño de una agencia de transportes se le plantea la siguiente situación. La
agencia de viajes ofrece distintas trayectorias combinadas entre N ciudades españolas
utilizando tren y autobús. Se dispone de dos grafos que representan los costes (matriz de
costes) de viajar entre diferentes ciudades, por un lado en tren, y por otro en autobús
(por supuesto entre las ciudades que tengan línea directa entre ellas). Además coincide
que los taxis de toda España se encuentran en estos momentos en huelga general, lo que
implica que sólo se podrá cambiar de transporte en una ciudad determinada en la que,
por casualidad, las estaciones de tren y autobús están unidas.
Implementa una función que calcule la tarifa mínima (matriz de costes mínimos) de
viajar entre cualesquiera de las N ciudades disponiendo del grafo de costes en autobús,
del grafo de costes en tren, y de la ciudad que tiene las estaciones unidas
*/

template <typename tCoste> matriz<tCoste> tarifa_minima(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& autobus, typename GrafoP<tCoste>::vertice transbordo)
{
	
	typename matriz<GrafoP<tCoste>::vertice> P;
	typename matriz<GrafoP<tCoste>::vertice> Q;
	matriz<tCoste> floyd_tren = Floyd(tren, P);
	matriz<tCoste> floyd_autobus = Floyd(autobud, Q);
	
	matriz<tCoste> tarifa_minima(tren.numVert());
	
	for(int i = 0; i < tarifa_minima.numVert();i++)
	{
		for(int j = 0; j < tarifa_minima.numVert();j++)
		{
			tarifa_minima[i][j] = std::min(std::min(suma(floyd_tren[i][transbordo],floyd_autobus[transbordo][j]),suma(floyd_autobus[i][transbordo],floyd_tren[transbordo][j])),std::min(tren[i][j],autobus[i][j]));
		}
	}
	return tarifa_minima;
}
