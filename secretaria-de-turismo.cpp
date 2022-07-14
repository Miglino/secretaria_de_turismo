#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int opcionesMenu();
void cargarVectores(int*, char*, int*, int*, int, char, int, int, int);
void mostrarInformes(int*, char*, int*, int*, int i);

int main() {

int validarDia, validarCodigo , validarAcceso;
int diaDelMes, viaDeAcceso, cantidadTuristas;
int opcionSeleccionada;
char codigoCentro;
int vecDiaMes[10], vecVia[10], vecCantidad[10];
char vecCodigoCentro[10];
int i = 0, a;
int contAutoA = 0, contAutoB = 0, contAutoC = 0;

	for(a=0; a<10; a++) {
		vecDiaMes[a] = 0;
	}
	
	for(a=0; a<10; a++) {
		vecCodigoCentro[a] = 0;
	}
	
	
	for(a=0; a<10; a++) {
		vecVia[a] = 0;
	}
	
	for(a=0; a<10; a++) {
		vecCantidad[a] = 0;
	}



	opcionSeleccionada = opcionesMenu();
	system("cls");

while(opcionSeleccionada != 3) {

	switch(opcionSeleccionada) {
	case 1:
         validarDia = 0;
         while(validarDia == 0) {
            printf("Ingrese dia (del 1 al 31): ");
        	fflush(stdin);
        	scanf("%d", &diaDelMes);
        	system("cls");
        	if(diaDelMes <= 31 && diaDelMes != 0) {
                 validarDia = 1;
            }
          }
         
         validarCodigo = 0;
         while(validarCodigo == 0) {
        	printf("Ingrese codigo de centro turistico a - b - c: ");
        	fflush(stdin);
        	scanf("%c", &codigoCentro);
        	system("cls");
        	if(codigoCentro == 'a' || codigoCentro == 'b' || codigoCentro == 'c') {
                 validarCodigo = 1;
            }
          }
          
          validarAcceso = 0;
         while(validarAcceso == 0) {
        	printf("Indique via de acceso: \n 1: Auto \n 2: Avion \n 3: Micro \n 4: Tren \n ");
        	fflush(stdin);
        	scanf("%d", &viaDeAcceso);
        	system("cls");
        	if(viaDeAcceso <= 4 && viaDeAcceso != 0) {
                 validarAcceso = 1;
            }
          }
	
	printf("Ingrese cantidad de turistas que ingresaron: ");
	fflush(stdin);
	scanf("%d", &cantidadTuristas);
	system("cls");
	
	cargarVectores(vecDiaMes, vecCodigoCentro, vecVia, vecCantidad, diaDelMes, codigoCentro, viaDeAcceso, cantidadTuristas, i);
	i++;
	system("pause");
	system("cls");
	break;
	
	case 2:		
		mostrarInformes(vecDiaMes, vecCodigoCentro, vecVia, vecCantidad, i);
		break;
	}
		
		opcionSeleccionada = opcionesMenu();
		system("cls");
	}
}

int opcionesMenu() {

    int opcionMenu;
    int validarOpcion = 0;
    
    while(validarOpcion == 0) {
    
        printf("1: Ingresar Datos \n2: Mostrar Resultados \n3: Salir \n");
        fflush(stdin);
        scanf("%d", &opcionMenu);
        system("cls");
    
    if(opcionMenu <= 3 && opcionMenu != 0){
                      
       validarOpcion = 1;
    }
  }
    
    return opcionMenu;
}

void cargarVectores(int* vecDiaMes, char* vecCodigoCentro, int* vecVia, int* vecCantidad, int diaDelMes, char codigoCentro, int viaDeAcceso, int cantidadTuristas, int x){
	
    *(vecDiaMes + x) = diaDelMes;
    *(vecCodigoCentro + x) = codigoCentro;
    *(vecVia + x) = viaDeAcceso;
    *(vecCantidad + x) = cantidadTuristas;

}

void mostrarInformes(int* vecDiaMes, char* vecCodigoCentro, int* vecVia, int* vecCantidad, int i) {
	
	char codigoInforme;	
	int j;
	int cantidadA = 0, contAutoA = 0;
	int cantidadB = 0, contAutoB = 0;
	int cantidadC = 0, contAutoC = 0;
	
	
	printf("Ingrese codigo de informe a-b-c: ");
	fflush(stdin);
	scanf("%c", &codigoInforme);
	
	switch(codigoInforme) {
		case 'a':
			for(j=0;j<i;j++) {
				if(*(vecCodigoCentro + j) == 'a') {
					cantidadA = *(vecCantidad + j) + cantidadA;
				}
				if(*(vecCodigoCentro + j) == 'a'&& *(vecVia + j) == 1) {
					contAutoA = contAutoA +1;
				}
			}
			printf("La cantidad de turistas en una quincena el centro turistico a es: %d\n", cantidadA);
			printf("La cantidad de turistas en una quincena que ingresaron en auto en el centro a es: %d\n", contAutoA);
			system("pause");
			system("cls");
		break;
		case 'b':
			for(j=0;j<i;j++) {
				if(*(vecCodigoCentro + j) == 'b') {
					cantidadB = *(vecCantidad + j) + cantidadB;
				}
				if(*(vecCodigoCentro + j) == 'b'&& *(vecVia + j) == 1) {
					contAutoB = contAutoB +1;
				}
			}
			printf("La cantidad de turistas en una quincena en el centro turistico b es: %d\n", cantidadB);
			printf("La cantidad de turistas en una quincena que ingresaron en auto en el centro b es: %d\n", contAutoB);
			system("pause");
			system("cls");
		break;
		case 'c':
			for(j=0;j<i;j++) {
				if(*(vecCodigoCentro + j) == 'c') {
					cantidadC = *(vecCantidad + j) + cantidadC;
				}
				if(*(vecCodigoCentro + j) == 'c' && *(vecVia + j) == 1) {
					contAutoC = contAutoC +1;
				}
			}
			printf("La cantidad de turistas en una quincena el centro turistico c es: %d\n", cantidadC);
			printf("La cantidad de turistas en una quincena que ingresaron en auto en el centro c es: %d\n", contAutoC);
			system("pause");
			system("cls");
		break;
			
	}		
}


