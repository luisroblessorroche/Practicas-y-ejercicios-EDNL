//Ejercicio 5

/*
Una forma de representar una figura plana en blanco y negro consiste en utilizar un
árbol cuaternario en el que cada nodo o tiene exactamente cuatro hijos, o bien es una
hoja. Un nodo hoja puede ser blanco o negro y un nodo interno no tiene color.
Una figura dibujada dentro de un cuadrado de lado 2k se representa de la forma siguiente: 

Se divide el cuadrado en cuatro cuadrantes y cada uno se representa como un
hijo del nodo raíz. Si un cuadrante está completamente negro corresponde a una hoja
negra; si, por el contrario, el cuadrante está completamente blanco, éste corresponde a
una hoja blanca; y si un cuadrante está parcialmente ocupado por negro y blanco,
entonces corresponde a un nodo interno del árbol y este cuadrante se representa
siguiendo el mismo método subdividiéndolo en otros cuatro cuadrantes. Como ejemplo
se muestra una figura en blanco y negro y su árbol asociado, tomando los cuadrantes en
el sentido de las agujas del reloj a partir del cuadrante superior izquierdo.

Implementa una función que dado un árbol de esta clase, con k+1 niveles,
devuelva la figura asociada, representada como una matriz cuadrada de tamaño 2k en la
que cada celda representa un punto blanco o negro.

 Nota: Por simplificar el problema, se asume que en cada nodo del árbol se
incluyen las coordenadas de la esquina superior izquierda y de la esquina inferior
derecha del cuadrante que representa.
*/

struct figura;
{
	char val; // 'B','N' o ' '
	int coor_s_i_x;
	int coor_s_i_y;
	int coor_i_d_x;
	int coor_i_d_y;
}

class Invalida
{
	public:
		Invalida(char* error): msg{error}{}
		char* motivo() const{return msg;}
	private:
		char* msg;
}



char** figura_blanco_y_negro(const Agen<figura>& A)
{
	if(!agen_cuaternario(A.raiz(),A))
	{
		throw Invalida("El arbol debe ser cuaternario");
	}
	
	int k = altura_agen(A.raiz(),A);
	
	if(k == -1)
	{
		throw Invalida("El arbol no puede ser vacio");
	}
	
	char** matriz = new char[pow(2,k)][pow(2,k)];
	rellenar_matriz(A.raiz(),A,matriz);
	
	return matriz;
}

bool agen_cuaternario(typename Agen<figura>::nodo n, const Agen<figura> &A)
{
	if(n == Agen<figura>::NODO_NULO)
	{
		return true;
	}
	else
	{
		bool cuaternario = num_hijos(n,A);
		Agen<figura>::nodo hijo = A.hijoIzqdo(n);
		while(hijo != Agen<figura>::NODO_NULO)
		{
			cuaternario = cuaternario && agen_cuaternario(hijo,A);
			hijo = A.hermDrcho(hijo);
		}
		return cuaternario;
	}
}

bool num_hijos(typename Agen<figura>::nodo n, const Agen<figura> &A)
{
	int cont = 0;
	while(n != Agen<figura>::NODO_NULO)
	{
		cont++;
		n = A.hermDrcho(n);
	}
	
	return (cont == 0 || cont == 4);
}

int altura_agen(typename Agen<figura>::nodo n, const Agen<figura> &A)
{
	if(n == Agen<figura>::NODO_NULO)
	{
		return -1;
	}
	else
	{
		int altura = -1;
		Agen<figura>::nodo hijo = A.hijoIzqdo(n);
		while(hijo != Agen<figura>::NODO_NULO)
		{
			altura = max(altura,altura_agen(hijo,A));
			hijo = A.hermDrcho(hijo); 
		}
		return altura + 1;
	}
}

void rellenar_matriz(Agen<figura>::nodo n, const Agen<figura> &A, char** &matriz)
{
	
	if(!(A.elemento(n).val == 'B' || A.elemento(n).val == 'N' || A.elemento(n) == ' '))
	{
		throw Invalida("los caracteres del arbol son invalidos");
	}
	
	//tambien habria que comprobar las coordenadas de cada nodo pero me da pereza
	
	if(A.elemento(n).val == 'B')
	{
		rellenar_huecos(n,A,matriz,'B');
	}
	else
	{
		if(A.elemento(n).val == 'N')
		{
			rellenar_huecos(n,A,matriz,'N');
		}
		else
		{
			Agen<figura>::nodo hijo = A.hijoIzqdo(n);
			while(hijo != Agen<figura>::NODO_NULO)
			{
				rellenar_matriz(hijo,A,matriz);
				hijo = A.hermDrcho(hijo);
			}
		}
	}
}

void rellenar_huecos(Agen<figura>::nodo n, const Agen<figura> &A, char** &matriz, char c)
{
	for(int i = A.elemento(n).coor_s_i_x; i <= A.elemento(n).coor_s_d_x)
	{
		for(int j = A.elemento(n).coor_i_i_y; j <= A.elemento(n).coor_i_d_y)
		{
			matriz[i][j] = c;
		}
	}
}

