/*
Al due�o de una agencia de transportes se le plantea la siguiente situaci�n. La
agencia de viajes ofrece distintas trayectorias combinadas entre N ciudades espa�olas
utilizando tren y autob�s. Se dispone de dos grafos que representan los costes (matriz de
costes) de viajar entre diferentes ciudades, por un lado en tren, y por otro en autob�s
(por supuesto entre las ciudades que tengan l�nea directa entre ellas). Adem�s coincide
que los taxis de toda Espa�a se encuentran en estos momentos en huelga general, lo que
implica que s�lo se podr� cambiar de transporte en una ciudad determinada en la que,
por casualidad, las estaciones de tren y autob�s est�n unidas.
Implementa una funci�n que calcule la tarifa m�nima (matriz de costes m�nimos) de
viajar entre cualesquiera de las N ciudades disponiendo del grafo de costes en autob�s,
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
