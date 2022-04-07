
/*

cd "C:\Users\Inspiron 15\Desktop\ed.proyecto1"
g++ -std=c++17 -Wall -Wextra -Wpedantic proyecto.cpp -o proyecto
./proyecto

*/

#include <iostream>
#include <string>
#include <cstdlib> // int std::rand(); [0,32767] 
#include <cmath>
#include <time.h>       /* time_t, struct tm, time, localtime */
#include <ctime>
#include <limits>
#include <bits/stdc++.h>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::rand; // int r = rand() % e; // 0 <= r <= (e - 1)
using std::time;
using std::getline;

class Partida
{
	private:
			
	public:
		Partida(int puntaje,int pasos, string nombre)
		{
			this->puntaje = puntaje;
			this->pasos = pasos ;
			this->nombre = nombre ;
		}
		Partida *ptrAnt{nullptr};
		Partida *ptrSig{nullptr};
		int pasos{0}, puntaje{0};
		string nombre;
		//horaInicio
		//duracion
		
};
//char nombre[]
//this->nombre = nombre ;
//char *nombre;

class Resultados
{
	public:
	Resultados(){};
	Partida *ptrIni{nullptr};
	Partida *ptrFin{ptrIni};
	
	int res{0};
	
	void agregarPartida(Partida *ptrNew)
	{
		if(ptrIni == nullptr)
		{
			ptrIni = ptrNew;
			ptrFin = ptrNew;
		}
			else
			{			
				ptrFin->ptrSig = ptrNew;
				ptrNew->ptrAnt = ptrFin;
				ptrFin = ptrNew;
			}
		res++;
	}
	void acomodarPosicion()
	{
		int posRes = 0;
		// se calcula en que posicion de la lista de resutados esta
		Partida *ptrGuia{ptrIni};
		while(ptrGuia != ptrFin)
		{
			if(ptrGuia->puntaje <= ptrFin->puntaje)
			{
				posRes++;
			}
			ptrGuia = ptrGuia->ptrSig;
		}
		cout << "[?] logro alcanzar la posicion: " << res - posRes << "\n";
	}

};
/*
    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
              << result << " seconds since the Epoch\n";
*/

class Casilla
{
	private:
		
	public:
		Casilla(){};
		Casilla(int num)
		{
			this->num = num;
		};

		int num{-1};
		Casilla *ptrAnt{nullptr};
		Casilla *ptrSig{nullptr};
};
// mientras no se ingrese una letra en pantalla entonces
// se crea un objeto casilla y se le asigna el numero ingresado en pantalla

class Nodo
{
	private:
	
	
	public:
		Nodo(){};
		Nodo(int fil, int col)
		{
			this->fil = fil;
			this->col = col;
		};
				
		int fil = -1;
		int col = -1;
		
		int ficha = -1;
				
		Nodo *ptrAnt{nullptr};
		Nodo *ptrSig{nullptr};
		Nodo *ptrArr{nullptr};
		Nodo *ptrAbj{nullptr};
		Nodo *ptrDel{nullptr};
		Nodo *ptrTra{nullptr};
};

class Orden
{
	private:
		int cas{1}; //capacidad
				
	public:
		Orden(){}; // por defecto siempre tiene 1 casilla
		
		Casilla *ptrIni{new Casilla{}};
		Casilla *ptrFin{ptrIni};
		
		int getCapacidad();
		void agregarCasilla(int num);
		void agregarCasillas(int cas);
		void printOrden();
		void ordenAleatorio();
		void ordenManual(int cas);
};

// F I N A L I Z A D O
void Orden::agregarCasillas(int cas)
{
	for(int i = 1; i <= cas; i++)
	{
		agregarCasilla(i);
	}
}

// F I N A L I Z A D O
int Orden::getCapacidad()
{
	// hallar la cantidad de elementos en la lista
	int cas = 0;
	Casilla *ptrGuia{ptrIni};
	while(ptrGuia != nullptr)
	{
		cas++;
		ptrGuia = ptrGuia->ptrSig;
	}
	return cas;
}

void Orden::agregarCasilla(int num)
{
	Casilla *ptrCasilla = new Casilla{num};
	ptrFin->ptrSig = ptrCasilla;
	ptrCasilla->ptrAnt = ptrFin;
	ptrFin = ptrCasilla;
	cas++;
}
void Orden::printOrden()
{
	Casilla *ptrGuia{ptrIni};
	while(ptrGuia != nullptr)
	{
		cout << ptrGuia->num << " ";
		ptrGuia = ptrGuia->ptrSig;
	}
	cout << "\n";
}


class Tablero3D
{
	// unico nodo del cual se puede acceder a los demas nodos de la lista ligada
	private:
		Nodo *ptrIni{new Nodo{1,1}}; // inicial
		Nodo *ptrFin{ptrIni}; // final
		Nodo *ptrMax{nullptr}; // posicion sin numero
		
		Orden ord{}; // inicialmente tiene 1 casilla
		
		int fil{1};
		int col{1};
		int tbl{1};
		
		void tableroInicial(int fil, int col);
		void aderirTablero();
		void tableroMultiple(int fil, int col, int tbl);
		
	
	public:
		Tablero3D(int fil, int col){ tableroInicial(fil,col); };
		Tablero3D(int fil, int col, int tbl)
		{
			tableroMultiple(fil,col, tbl);
		};
		
		void tableroManual();
		int calcularPuntaje();
		void jugarPartida();
		void tableroAleatorio();
		void incrustarNumeros(Orden o);
		void elegirPosicionVacia(int fil,int col,int tbl);
		void moverPosicionVacia(char key);
		void printTablero();
		void cambiarPosicionVacia();
};

// F I N A L I Z A D O
void Tablero3D::tableroMultiple(int fil,int col,int tbl)
{
	// agregar opcion
	// SI ya existe una lista entonces borrarla y crear una nueva
	// SINO crear una nueva
	if(fil <= 0 || col <= 0 || tbl <= 0 || (fil == 1 && col == 1))
	{
		cout << "[!] Nodos insuficientes para crear una lista\n";	
	}
		else
		{
			this->fil = fil;
			this->col = col;
			this->tbl = tbl;
			
			tableroInicial(fil,col);
			
			if(tbl != 1)
			{
				for(int i = 1; i <= tbl - 1; i++)
				{
					aderirTablero();
				}
			}
		}
}

// la dirferencia entre tableroAleatorio() y tableroManual() es que 
// en el primero se relizan dos pasos para incrustar el orden al tablero: 1) se agrega casillas a la lista 
// y 2) se ordenan esas casillas de forma aleatoria
// en cambio para el segundo se agrega una casilla a la lista e inmediatamente se pide ingresar 
// el numero de esa casilla, repitiendo este proceso hasta alcanzar la cantidad de posiciones del tablero

void Tablero3D::tableroAleatorio()
{
	ord.agregarCasillas(fil*col*tbl - 1); // casillas del tablero - 1 casilla
	ord.ordenAleatorio();
	
	incrustarNumeros(ord);
}

void Tablero3D::tableroManual()
{
	ord.ordenManual(fil*col*tbl);
	
	incrustarNumeros(ord);
}

// F I N A L I Z A D O
void Tablero3D::tableroInicial(int fil, int col) 
{
	Nodo *ptrGuia{nullptr}, *ptrAuxAnt{nullptr}, *ptrAuxArr{nullptr}, *ptrAuxCol{nullptr};
	
	for(int ifil=1; ifil<= fil; ifil++)
	{
		for(int icol=1; icol <= col; icol++)
		{
			if(1 == icol && 1 == ifil)
			{
				//*ptrIni = Nodo{1,1};
				ptrGuia = ptrIni;
				ptrAuxCol = ptrIni;
			}
				else
				{
					if(1 == ifil)
					{
						ptrAuxAnt = ptrGuia; // ptrGuia de la iteracion anterior
						
						ptrGuia = new Nodo{ifil,icol}; // ptrGuia nuevo
						ptrGuia->ptrAnt = ptrAuxAnt;
						
						ptrAuxAnt->ptrSig = ptrGuia;
					}
						else
						{
							if(1 == icol)
							{
								ptrGuia = new Nodo{ifil,icol}; 
								ptrGuia->ptrArr = ptrAuxCol;
								
								ptrAuxCol->ptrAbj = ptrGuia;
								
								ptrAuxArr = ptrAuxCol;
								ptrAuxCol = ptrGuia;
							}
								else
								{
									ptrAuxAnt = ptrGuia; // ptrGuia de la iteracion anterior
									ptrAuxArr = ptrAuxArr->ptrSig;
								
									ptrGuia = new Nodo{ifil,icol}; // ptrGuia nuevo
									ptrGuia->ptrAnt = ptrAuxAnt;
									ptrGuia->ptrArr = ptrAuxArr;
									
									ptrAuxAnt->ptrSig = ptrGuia;
									ptrAuxArr->ptrAbj = ptrGuia;
								}
						}
				}
			/*
			ptrGuia->ptrAnt = ptrAuxAnt;
			ptrGuia->ptrArr = ptrAuxArr;
			*/
		}
		//cout << "   \\n\n";
	}
}


void Tablero3D::aderirTablero()
{
	Tablero3D lista2{fil,col};
	Nodo *ptrGuia1{ptrFin}, *ptrGuia2{lista2.ptrIni};
	Nodo *ptrAuxSig1{nullptr}, *ptrAuxSig2{nullptr};
		
	while (ptrGuia1 != nullptr)
	{
		ptrAuxSig1 = ptrGuia1;
		ptrAuxSig2 = ptrGuia2;
		while (ptrAuxSig1 != nullptr)
		{
			// acceder a datos de nodo con ptrAuxSig1->datos
			ptrAuxSig1->ptrTra = ptrAuxSig2;
			ptrAuxSig2->ptrDel = ptrAuxSig1;
			
			//printPoint(*(ptrAuxSig1->ptrTra));
			//printPoint(*(ptrAuxSig2->ptrDel));
			
			ptrAuxSig1 = ptrAuxSig1->ptrSig;
			ptrAuxSig2 = ptrAuxSig2->ptrSig;
		}
		//cout << "   \\n\n";
		ptrGuia1 = ptrGuia1->ptrAbj;
		ptrGuia2 = ptrGuia2->ptrAbj;
	}
	
	ptrFin = lista2.ptrIni; // para finalizar cambiamos ptrFin hacia el nuevo tablero
}

void Orden::ordenManual(int cas)
{
	cout << ">> para poblar el tablero completamente ingrese " << cas << " numeros en el orden:\n";
	cout << "   de izq. a der., de arriba hacia abajo, y de frente hacia atras\n";

	cout << "-> ";
	int m;
	cin >> m;
	ptrIni = new Casilla{m};
	ptrFin = ptrIni;
	
	for(int i = 2; i <= cas; i++)
	{
		cout << "-> ";
		int n;
		cin >> n;
		agregarCasilla(n);
	}
}

// F I N A L I Z A D O
void Orden::ordenAleatorio()
{	
	// hallar la cantidad de elementos en la lista
	int elementos = getCapacidad();
	
	Casilla *ptrGuia{ptrIni}, *ptrAux{ptrGuia};
	while(ptrGuia != nullptr)
	{
		bool iterar = true;
		while(iterar)
		{
			// miestras exista el numero en las casillas anteriores
			// se detiene la iteracion y se vuelve a iniciar
			// se crea otro random y se evalua
			ptrAux = ptrGuia->ptrAnt;
			bool existe = false;
			int r = rand() % elementos + 1; // 0 <= r <= (elementos - 1)
			while(ptrAux != nullptr)
			{
				if(ptrAux->num == r)
				{
					existe = true;
					break;
				}
				
				ptrAux = ptrAux->ptrAnt;
			}
			if(!existe)
			{
				ptrGuia->num = r;
				iterar = false;
			}
		}
				
		ptrGuia = ptrGuia->ptrSig;
	}
	// printOrden();
}

void Tablero3D::incrustarNumeros(Orden o)
{
	// verificar que hayan tantas posiciones como nodos
	int nodos = fil*col*tbl;
	int p = o.getCapacidad();
	
	if(p == nodos)
	{
		Nodo *ptrCol{ptrIni}, *ptrFil{ptrIni}, *ptrTbl{ptrIni};
		Casilla *ptrCasilla{o.ptrIni};
				
		for(int i = 1; i <= tbl; i++)
		{
			for(int j = 1; j <= fil; j++)
			{
				for(int k = 1; k <= col; k++)
				{
					//cout << k<< "," << j<< "," << i ;
					ptrCol->ficha = ptrCasilla->num;
					if(p == ptrCol->ficha)
					{
						ptrMax = ptrCol;
					}
					ptrCasilla = ptrCasilla->ptrSig;
					//cout << ":" << ptrCol->ficha << " ";
					
					ptrCol = ptrCol->ptrSig;
				}
				ptrFil = ptrFil->ptrAbj;
				ptrCol = ptrFil;
				//cout << "\n";
			}
			ptrTbl = ptrTbl->ptrTra;
			ptrFil = ptrTbl;
			ptrCol = ptrTbl;
			//cout << "\n";
		}		
	}
		else
		{
			cout << "[!] posiciones requeridas para esta partida: " << nodos << ", ingresadas: "<< p <<"\n";
		}
}

int digitos(int num) 
{
   return int(log10(num) + 1);
}

void Tablero3D::printTablero()
{
	int max = digitos(fil*col*tbl);

	Nodo *ptrCol{ptrIni}, *ptrFil{ptrIni}, *ptrTbl{ptrIni};
			
	for(int i = 1; i <= tbl; i++)
	{
		for(int j = 1; j <= fil; j++)
		{
			for(int k = 1; k <= col; k++)
			{
				if(ptrCol->ficha == ptrMax->ficha)
				{
					for(int c = 1; c <= max; c++)
					{
						cout << "_";
					}					
					cout << " | ";
				}
					else
					{
						int act = digitos(ptrCol->ficha);
						
						if(act < max)
						{
							for(int c = 1; c <= max - act; c++)
							{
								cout << " ";
							}
						}
						cout << ptrCol->ficha << " | ";
					}

				ptrCol = ptrCol->ptrSig;
			}
			ptrFil = ptrFil->ptrAbj;
			ptrCol = ptrFil;
			cout << "\n";
		}
		ptrTbl = ptrTbl->ptrTra;
		ptrFil = ptrTbl;
		ptrCol = ptrTbl;
		cout << "\n";
	}		
}

// ingresar al programa las coordenadas de la posicion vacia y 
// este buscara la casilla con el numero mayor y la intercambiara
// con la posicion elegida y vice versa, dejando el numero mayor en la posicion  elegida
// luego se elemina el numero mayor (que esta en la posicion elegida)
void Tablero3D::elegirPosicionVacia(int fil,int col,int tbl)
{
	bool cond1 = fil <= 0 || col <= 0 || tbl <= 0;
	bool cond2 = this->fil < fil || this->col < col || this->tbl < tbl; 

	if(cond1 || cond2)
	{
		cout << "[!] posicion inexistente\n";	
	}
		else
		{
			Nodo *ptrGuia{ptrIni};
			
			int itbl = 1, ifil = 1, icol = 1;
			while(icol < col)
			{
				ptrGuia = ptrGuia->ptrSig;
				icol++;
			}
			while(itbl < tbl)
			{
				ptrGuia = ptrGuia->ptrTra;
				itbl++;
			}
			while(ifil < fil)
			{
				ptrGuia = ptrGuia->ptrAbj;
				ifil++;
			}
			int max = ptrMax->ficha; // this->fil*this->col*this->tbl;
			ptrMax->ficha = ptrGuia->ficha;
			ptrGuia->ficha = max;
			ptrMax = ptrGuia;
		}
}

void Tablero3D::cambiarPosicionVacia()
{
	cout << ">> desea cambiar la posicion vacia\n";
	cout << "[1] si\n";
	cout << "[2] no\n";
	
	int o;
	cin >> o;
	if(o == 1)
	{
		cout << ">> ingrese la nueva posicion (<fila> <columna> <tablero>): ";

		int fil,col,tbl;
		cin >> fil >> col >> tbl;

		elegirPosicionVacia(fil,col,tbl);
		printTablero();
	}
}

// donde esta el pointer maximo entonces no se imprime esa casilla (se deja como __ )en el metodo de imprimir tablero
// pero su valor seguira alli
void Tablero3D::moverPosicionVacia(char key)
{
	Nodo *ptrAux{nullptr};
	
	switch(key)
	{
		case 'w':
		{
			if(ptrMax->ptrArr != nullptr)
			{
				ptrAux = ptrMax->ptrArr;
				
				int max = ptrMax->ficha;
				ptrMax->ficha = ptrAux->ficha;
				
				ptrAux->ficha = max;
				ptrMax = ptrAux;
			}
				else
				{
					cout << "[!] intercambio hacia arriba ya no es posible\n";
				}
			break;
		}
		case 's':
		{
			if(ptrMax->ptrAbj != nullptr)
			{
				ptrAux = ptrMax->ptrAbj;
				
				int max = ptrMax->ficha;
				ptrMax->ficha = ptrAux->ficha;
				
				ptrAux->ficha = max;
				ptrMax = ptrAux;
			}
				else
				{
					cout << "[!] intercambio hacia abajo ya no es posible\n";
				}
			break;
		}
		case 'a':
		{
			if(ptrMax->ptrAnt != nullptr)
			{
				ptrAux = ptrMax->ptrAnt;
				
				int max = ptrMax->ficha;
				ptrMax->ficha = ptrAux->ficha;
				
				ptrAux->ficha = max;
				ptrMax = ptrAux;
			}
				else
				{
					cout << "[!] intercambio hacia la izquierda ya no es posible\n";
				}
			break;
		}
		case 'd':
		{
			if(ptrMax->ptrSig != nullptr)
			{
				ptrAux = ptrMax->ptrSig;
				
				int max = ptrMax->ficha;
				ptrMax->ficha = ptrAux->ficha;
				
				ptrAux->ficha = max;
				ptrMax = ptrAux;
			}
				else
				{
					cout << "[!] intercambio hacia la derecha ya no es posible\n";
				}
			
			break;
		}
		case 'q':
		{
			if(ptrMax->ptrDel != nullptr)
			{
				ptrAux = ptrMax->ptrDel;
				
				int max = ptrMax->ficha;
				ptrMax->ficha = ptrAux->ficha;
				
				ptrAux->ficha = max;
				ptrMax = ptrAux;
			}
				else
				{
					cout << "[!] intercambio hacia delante ya no es posible\n";
				}
			
			break;
		}
		case 'e':
		{
			if(ptrMax->ptrTra != nullptr)
			{
				ptrAux = ptrMax->ptrTra;
				
				int max = ptrMax->ficha;
				ptrMax->ficha = ptrAux->ficha;
				
				ptrAux->ficha = max;
				ptrMax = ptrAux;
			}
				else
				{
					cout << "[!] intercambio hacia atras ya no es posible\n";
				}
			break;
		}
	}
}

int Tablero3D::calcularPuntaje()
{
	// verificar que hayan tantas posiciones como nodos
	int z{1}, puntaje{0};
		
	Nodo *ptrCol{ptrIni}, *ptrFil{ptrIni}, *ptrTbl{ptrIni};
			
	for(int i = 1; i <= tbl; i++)
	{
		for(int j = 1; j <= fil; j++)
		{
			for(int k = 1; k <= col; k++)
			{
				if(ptrCol->ficha == z)
				{
					puntaje = puntaje + 2;
				}
				
				z++;
				
				ptrCol = ptrCol->ptrSig;
			}
			ptrFil = ptrFil->ptrAbj;
			ptrCol = ptrFil;
			//cout << "\n";
		}
		ptrTbl = ptrTbl->ptrTra;
		ptrFil = ptrTbl;
		ptrCol = ptrTbl;
		//cout << "\n";
	}
	
	return puntaje;
}

Resultados res{};
 
void Tablero3D::jugarPartida()
{
	int pasos = 0;
	string nombre;
	
	cout << ">> ingrese su nombre:\n"; //##############################################################################
	cin.ignore();
	getline(cin, nombre);
	
	//cin >> nombre;
	
	cout << "[?] para mover la casilla vacia presione:\n";
	cout << "    w (hacia arriba), s (hacia abajo),\n";
	cout << "    a (hacia la izq.), d (hacia la der.),\n";
	cout << "    q (hacia delante) y e (hacia atras)\n";
	cout << "[?] presione 'c' para reiniciar y 'x' para abandonar\n";
	printTablero();
	cambiarPosicionVacia();
	
	while(true)
	{
		char c;
		cout << ">> tecla: ";
		cin >> c;
		
		if(c=='x')
		{
			cout << "\n<<<( PARTIDA TERMINADA )>>>\n";
			cout << ">> nombre: " << nombre << "\n";
			int puntaje = calcularPuntaje();
			cout << ">> puntaje: " << puntaje << "\n";
			cout << ">> pasos: " << pasos << "\n";

			Partida *ptrNew = new Partida{puntaje,pasos,nombre};
			res.agregarPartida(ptrNew);
			res.acomodarPosicion();
			break;
		}
		if(c=='c')
		{
			// llamar a incrustarNumeros(Orden) porque el objeto Orden de este Tablero3D 
			// aun tiene su orden inicial de antes de la partida
			incrustarNumeros(ord);
			pasos = 0;
			cout << "[?] partida reiniciada\n";
		}

		if(c=='w'||c=='s'||c=='a'||c=='d'||c=='q'||c=='e')
		{
			moverPosicionVacia(c);
			printTablero();
			pasos++;
		}
	}
	calcularPuntaje();
}

void iu()
{
	while(true)
	{
		cout << "\n<<<( JUEGO DEL 15 )>>>\n";
		cout << "[1] nueva partida\n";
		cout << "[2] salir\n";
		int i = 0;
		cin >> i;
		if(i == 1)
		{
			cout << "\n<<<( NUEVA PARTIDA )>>>\n";
			cout << ">> ingrese las dimensiones (<filas> <columnas> <tableros>): ";
			int fil,col,tbl;
			cin >> fil >> col >> tbl;
			
			cout << ">> metodo de ingreso de las posiciones de los numeros: \n";
			cout << "[1] aleatorio\n";
			cout << "[2] archivo\n";
			cout << "[3] manual\n";
			// crear metodo para ingrear todos los datos del usuario en un array
			int j = 0;
			cin >> j;
			if(j == 1)
			{
				Tablero3D tabl{fil,col,tbl};
				tabl.tableroAleatorio();
				tabl.jugarPartida();
			}
			if(j == 2)
			{
				cout << ":( disculpe los inconvenientes, pronto estara disponible esta caracteristica\n";
			}
			
			if(j == 3)
			{
				Tablero3D tabl{fil,col,tbl};
				tabl.tableroManual();
				tabl.jugarPartida();
			}
			
		}
		if(i == 2)
		{
			break;
		}
	}
}

int main()
{
	iu();
	return 0;
}
