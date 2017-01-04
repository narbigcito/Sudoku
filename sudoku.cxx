#include <bits/stdc++.h>
#include <queue>
using namespace std;


//Está es una estructura que tiene como atributo un arreglo bidimencional
//Se declaró como estructura para poder usarlo con "queue"
struct Estado{
	int tablero[9][9];
};

//Este tipo de dato nos permitirá usar sus funciones pull y push, las
//Cuales agregarán y eliminaran elemententos de la cola
queue <Estado> cola;
//Declramos la estructura previamente creada
Estado actual;
//Esto nos dirá en que casilla de las 81 disponibles estamos
int casilla=0;

//Esta función solamente pide los datos al  usuario

void generarTablero (){			
		for (int i = 0; i <9; i++)
			for(int j = 0; j <9; j++)
				cin >> actual.tablero[j][i];
}

//Con esto imrpimimos el tablero

void imprimirTablero(){
	cout <<"\n"<<"\n"<<"\n";	
	
	for (int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++)
			cout << actual.tablero[j][i] << " ";
	cout <<"\n";	
	}		
}

//Está función nos dice si se puede poner un numero en una casilla
//Es decir si no hay numeros repetidos, solocita el número que va a
//comparar y las coordenadas de su ubicación

bool isDisponible(int n, int x, int y){
	bool flag = 1;
	int rx,ry;
	
	for (int i = 0; i < 9; i++)
		if(actual.tablero[i][y] == n){
			flag =false;
			break;
		}
		
	if (flag)
		for (int i = 0; i < 9; i++)
			if(actual.tablero[x][i] == n){
				flag =false;
				break;
			}
			
	if(flag){		
		switch (x%3) {
		
			case 0 :
			
				rx = x;
				break;
				
			case 1 :
			
				rx = x - 1;
				break;
				
			case 2 :
			
				rx = x - 2;
				break;
				
			default :
			
				cout << "nonono";
		
		}
		
		switch (y%3) {
		
			case 0 :
			
				ry = y;
				break;
				
			case 1 :
			
				ry = y - 1;
				break;
				
			case 2 :
			
				ry = y - 2;
				break;
				
			default :
			
				cout << "soy default" <<"\n";
		
		}
		
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				if (!(ry + i == y && rx + j == x))
					if(actual.tablero[rx+j][ry+i] == n){
						flag = false;
						break;
					}
	}
		
	return flag;
}

//Esta es la función que busca recursiamente los número que se asignaran
//Es decir la que como tal resuelve el problema

void buscar(){
		
		if(cola.size() > 0){
			actual = cola.front();
			cola.pop();
		}
		
		for (int y = 0; y < 9; y++){

			for (int x = 0; x < 9; x++){
				
				if (actual.tablero[x][y]==0){
					casilla++;
					
					for(int i = 1; i <= 9; i++){
						
						if (isDisponible(i,x,y)){
							actual.tablero[x][y] = i;
							cola.push(actual); 	 	
						}
						
						else if (i == 9 && actual.tablero[x][y]==0){
						}
						
					}					
				buscar();
				}
			}
		}	
}

int main()
	{
		cin.tie(0);ios_base::sync_with_stdio(0);
		freopen("sudoku5.in", "r",stdin);
		
		//Si descomentamos la siguiente linea se generará un archivo con el resultado
	//	freopen("sudoku.out", "w",stdout);
		generarTablero();
		buscar();
		imprimirTablero();
		
		return 0;
	}

