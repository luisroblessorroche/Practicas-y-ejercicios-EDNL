//Ejercicio 3

/*
El TAD �rbol binario puede albergar expresiones matem�ticas mediante un �rbol de
expresi�n. Dentro del �rbol binario los nodos hojas contendr�n los operandos, y el resto
de los nodos los operadores.
a) Define el tipo de los elementos del �rbol para que los nodos puedan almacenar
operadores y operandos.
b) Implementa una funci�n que tome un �rbol binario de expresi�n (aritm�tica) y
devuelva el resultado de la misma. Por simplificar el problema se puede asumir que el
�rbol representa una expresi�n correcta. Los operadores binarios posibles en la expresi�n
aritm�tica ser�n suma, resta, multiplicaci�n y divisi�n.

Nota: En el programa de prueba podemos usar las funciones rellenarAbin() de abin_ES.h para introducir por teclado o desde un fichero el �rbol de expresi�n a evaluar. Sin
embargo, en este caso, ser� necesario sobrecargar los operadores utilizados internamente
en dichas funciones, es decir >>, << y != para el tipo de los elementos del �rbol.
*/

struct op
{
	double operando;
	char operador;
};


double abin_expresion(const Abin<op> &A)
{
	if(A.raiz() != Abin<op>::NODO_NULO)
	{
		return abin_expresion_rec(A.raiz(),A);	
	}
	else
	{
		return NULL;
	}
}

double abin_expresion_rec(Abin<op>::nodo n, const Abin<op> &A)
{
	if(n_es_nodo_hoja(n,A))
	{
		return A.elemento(n).operando;
	}
	else
	{
		switch (A.elemento(n).operador)
		{
			case +:
				return abin_expresion_rec(A.hijoIzqdo(n),A) + abin_expresion_rec(A.hijoDrcho(n),A);
				break;
			case -:
				return abin_expresion_rec(A.hijoIzqdo(n),A) - abin_expresion_rec(A.hijoDrcho(n),A);
				break;
			case *:
				return abin_expresion_rec(A.hijoIzqdo(n),A) * abin_expresion_rec(A.hijoDrcho(n),A);
				break;
			case /:
				return abin_expresion_rec(A.hijoIzqdo(n),A) / abin_expresion_rec(A.hijoDrcho(n),A);
				break;
		}
	}
}

bool n_es_nodo_hoja(typename Abin<T>::nodo n, const Abin<T> &A)
{
	return A.hijoIzqdo(n) == Abin<T>::NODO_NULO && A.hijoDrcho(n) == Abin<T>::NODO_NULO;
}


