
/*

cd "C:\Users\Inspiron 15\Desktop\ed.proyecto1"
g++ -std=c++17 -Wall -Wextra -WpedptrAntic proyecto.cpp -o proyecto
./proyecto

*/

#include <iostream>

class Nodo
{
	public:
		Nodo(){};
		Nodo(int fil, int col)
		{
			this->fil = fil;
			this->col = col;
		};
		
		int fil = -1;
		int col = -1;
		
		int numFicha = -1;
		
		Nodo *ptrAnt{nullptr};
		Nodo *ptrSig{nullptr};
		
		Nodo *ptrArr{nullptr};
		Nodo *ptrAbj{nullptr};
};

class ListaLigada
{
	// unico nodo del cual se puede acceder a los demas nodos de la lista ligada
	Nodo inicio{1,1};
	
	
	public:
		ListaLigada(){};
		
		int fil{0};
		int col{0};

		
		void crearLista(int fil, int col);
		void verificar(int fil, int col);
		void agregarNodos(int fil, int col);
		void borrarLista();
};

void ListaLigada::crearLista(int fil,int col)
{
	verificar(fil,col);
}

void ListaLigada::verificar(int fil,int col)
{
	if(fil <= 0 || col <= 0 || (fil == 1 && col == 1))
	{
		std::cout << "[!] Nodos insuficientes para crear una lista\n";
	}
		else
		{
			this->fil = fil;
			this->col = col;
			agregarNodos(fil,col);
		}
}

void printID(Nodo nd)
{
	int id = -1;
	if(1 == nd.fil)
	{
		id = nd.col;
	}
	if(2 <= nd.fil)
	{
		id = nd.fil * nd.col + nd.col;
	}
	std::cout << " id=\'" << id << "\'";
}

void ListaLigada::agregarNodos(int fil, int col)
{
	Nodo *ptrActu{nullptr}, *ptrActuAnt{nullptr}, *ptrActuArr{nullptr}, *ptrCol1{nullptr};
	//ptrActu = &inicio; // ptrActu debe inicializarse con algun &nodo, podria ser diferente al &inicio
	
	for(int iFil=1; iFil<= fil; iFil++)
	{
		for(int iCol=1; iCol <= col; iCol++)
		{
			if(1 == iCol && 1 == iFil)
			{
				ptrActu = &inicio;
				ptrCol1 = &inicio;
				printID(*ptrActu);
			}
				else
				{
					if(1 == iFil)
					{
						ptrActuAnt = ptrActu; // ptrActu de la iteracion anterior
						
						ptrActu = new Nodo{iFil,iCol}; // ptrActu nuevo
						ptrActu->ptrAnt = ptrActuAnt;
						
						printID(*ptrActu);
					}
						else
						{
							if(1 == iCol)
							{
								ptrActu = new Nodo{iFil,iCol}; // ptrActu nuevo
								ptrActu->ptrArr = ptrCol1; // ptrActu->ptrArr = ptrActuArr;
								
								printID(*ptrActu);
								
								if(2 == iFil)
								{
									ptrActuArr = &inicio;
								}
								
								ptrCol1 = ptrActu;
							}
								else
								{
									ptrActuAnt = ptrActu; // ptrActu de la iteracion anterior
									ptrActuArr = ptrActuArr->ptrSig;
								
									ptrActu = new Nodo{iFil,iCol}; // ptrActu nuevo
									ptrActu->ptrAnt = ptrActuAnt;
									ptrActu->ptrArr = ptrActuArr;
									
									printID(*ptrActu);
								}
						}
				}
			/*
			ptrActu->ptrAnt = ptrActuAnt;
			ptrActu->ptrArr = ptrActuArr;
			*/
		}
		std::cout << "\n";
	}
}

// hacer un ptrArrra con la cptrAntidad de nodos que seran inicios de tptrAbjlero
// pptrArra cada nodo de inicio se va a hacer un recorrido pptrArra imprimir o acceder a las casillas, etc

int main()
{
	ListaLigada temp{};
	
	temp.verificar(-3,3);
	temp.verificar(1,1);
	
	//temp.verificar(1,3);
	
	temp.verificar(2,3);
	return 0;
}

