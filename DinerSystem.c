#include <stdio.h>
/**
Comentario:
* se utilizo la biblioteca stdlib.h para que se puedan realizar las funciones como
* imprimirCodigo, y para llenar una matriz char con ' '.
* Y se utilizo la biblioteca time.h para poder realizar la funcion de fechaHora
*/
#include <stdlib.h>
#include <time.h>
/**
* @def NP : numero de platillos
* @def LONGCAD : logitud de las palabras
* @def NPED : numero de pedidos
* @def PASSWORD1 : contraseña del encargado
* @def PASSWORD2 : contraseña del tecnico
*/
#define NP 50
#define LONGCAD 15
#define NPED 200
#define PASSWORD1 270418
#define PASSWORD2 280499

/**
* @struct Pedido : estructura para los pedidos de los cientes
* @struct Platillo : estructura para los platillos
*/
struct Pedido{
	int platillo, precio, raciones, paraLlevar;
};

struct Platillo{
	char nombre[LONGCAD];
	int precio,disponibilidad;
};

void verMenuPrincipal(struct Pedido ped[],struct Platillo pla[], int num[]);
void verMenuEncargado(struct Pedido ped[],struct Platillo pla[]);
void verMenuCliente(struct Platillo pla[],struct Pedido ped[],int num[]);
void verMenuTecnico();
void administrar(int,struct Platillo pla[]);
void verPedidos(struct Platillo pla[],struct Pedido ped[]);
void ordenar(struct Pedido ped[],struct Platillo pla[], int num[]);
void imprimirCodigo();
void inicializarPedidos(struct Pedido ped[]);
void inicializarPlatillos(struct Platillo pla[]);
void verFechaHora();
void leer(int*);
int main() {
	struct Pedido pedidos[NPED];
	struct Platillo platillos[NP];
	int numeracion[1];
	inicializarPedidos(pedidos);
	inicializarPlatillos(platillos);
	verMenuEncargado(pedidos,platillos);
	verMenuPrincipal(pedidos,platillos,numeracion);
	return 0;
}

/**
* @brief recibe un vector de estructura platillo y la inicializa
* @param pla : es el vector de estructura platillo
*/
void inicializarPlatillos(struct Platillo pla[]){
	int i=0,j=0;
	for(i=0;i<NP;i++){
		pla[i].precio=0;
		pla[i].disponibilidad=0;
	}
	for(i=0;i<NP;i++){
		for(j=0;j<=LONGCAD;j++){
			pla[i].nombre[j]=' ';
		}
		
	}
}

/**
* @brief recibe un vector de estructura Pedido y lo inicializa
* @param ped :es el vector de estrutura Pedido
*/
void inicializarPedidos(struct Pedido ped[]){
	int i=0;
	for(i=0;i<NPED;i++){
		ped[i].platillo=0;
		ped[i].precio=0;
		ped[i].raciones=0;
		ped[i].paraLlevar=0;
	}
}

/**
* @brief imprime y administra el menu de inicio
* @param pla : vector de estrutura Platillo 
* @param ped : vector de estructura Pedido
* @param num : vector del numero del pedido
*/
void verMenuPrincipal(struct Pedido ped[],struct Platillo pla[], int num[]){
	int opcion, contrasenia, flag=1;
	while(flag){
		printf("\n");
		printf("Bienvenido a DynerSystem \n Escoja entre las 4 opciones \n 1)Encargado \n 2)Cliente \n 3)Tecnico \n 4)Salir \n");
		leer(&opcion);
		while(opcion<1 || opcion>4){
			printf("La opcion que ingreso no existe :( , vuelva a intentarlo \n");
			leer(&opcion);
		}
		if(opcion==1){
			system("cls");
			verMenuEncargado(ped,pla);
			system("pause");
			system("cls");
		}else{
			if(opcion==2){
				system("cls");
				verMenuCliente(pla,ped,num);
				system("pause");
				system("cls");
			}else{
				if(opcion==3){
					system("cls");
					verMenuTecnico();
					system("pause");
					system("cls");
				}else{
					if(opcion==4){
						printf("ingrese alguna de las contraseñas para finalizar el programa");
						leer(&contrasenia);
						if(contrasenia==PASSWORD1 || contrasenia==PASSWORD2){
							flag=0;
						}else{
							printf("la contraseña es incorrecta");
						}
					}
				}
			}
		}
	}
}
/**
*@brief lee una variable
*@param variable 
*/
void leer(int* variable){
	scanf("%i", variable);
}
/**
* @brief imprime y administra el menu del  usuario "encargado"
* @param pla : vector de estructura Platillo
* @param ped : vector de estructura Pedido
*/
void verMenuEncargado(struct Pedido ped[],struct Platillo pla[]){
	int contrasenia, opcion, plato, desicion;
	printf("\n ingrese la contraseña del encargado \n");
	leer(&contrasenia);
	if(contrasenia==PASSWORD1){
		printf("\n ¿Que accion desea realizar? \n 1)administrar platillos \n 2)acceder a los pedidos \n");
		leer(&opcion);
		while(opcion<1 || opcion>2){
			printf("por favor indique alguna de las opciones en pantalla, vuelva a intentarlo \n");
			leer(&opcion);
		}
		if(opcion==1){
			while(desicion!=2){
				printf("Que platillo desea administrar \n");
				leer(&plato);
				while(plato<=0){
					printf("No existe este platillo");
					leer(&plato);
				}
				administrar(plato,pla);
				printf("?desea seguir administrando? \n 1)si \n 2)no \n");
				leer(&desicion);
			}
		}else{
			if(opcion==2){
				verPedidos(pla,ped);
			}
		}
	}else{
		printf("La contraseña es incorrecta");
	}
}
/**
* @brief recibe el numero del platillo y el vector de estrucura Platillo para administrar los platillos
* @param i : el numero del platillo
* @param pla : vector de estructura Platillo
*/
void administrar(int i,struct Platillo pla[]){
	printf("ingrese el nombre del platillo \n");
	scanf(" %[^\n]",&pla[i].nombre);
	printf("ingrese el precio del platillo (en pesos) \n");
	scanf("%d",&pla[i].precio);
	printf("ingrese la disponibilidad del platillo \n 1)disponible \n 2)no disponible \n");
	scanf("%d", &pla[i].disponibilidad);
}
/**
* @brief recibe una matriz de caracteres, una matriz y un vector de enteros y los imprime
* @param pla : vector de estructura Platillo
* @param ped : vector de estructura Pedido
*/
void verPedidos(struct Platillo pla[],struct Pedido ped[]){
	int i=0,platillo=0,raciones=0,precio=0;
	for(i=1;i<NPED;i++){
		platillo=ped[i].platillo;
		raciones=ped[i].raciones;
		printf("Pedido: #%i ",i);
		printf("platillo: %s ", pla[platillo].nombre);
		precio=(pla[platillo].precio)*raciones;
		printf("$ %i ",precio);
		printf("raciones: %i ",raciones);
		printf("para llevar: ");
		if(ped[i].paraLlevar==1){
			printf("si");
		}else{
			printf("no");
		}
		printf("\n");
	}
}
/**
* @brief recibe un vector de estructura Platillo, vector de estructura Pedido y el vector del numero de pedidos
* @param pla : vector de estructura Platillo
* @param ped : vector de estructura Pedido
* @param num : vector del numero del pedidos
*/
void verMenuCliente(struct Platillo pla[],struct Pedido ped[],int num[]){
	int i=0, opcion=0;
	printf("Bienvenido al menu de la cafeteria \n");
	for(i=1;i<NP;i++){
		printf("Platillo %i)",i);
		printf(" %s ",pla[i].nombre);
		printf(" $%i ",pla[i].precio);
		if(pla[i].disponibilidad==1){
			printf(" disponible ");
		}else{
			printf(" no disponible ");
		}
		printf("\n");
	}
	ordenar(ped,pla,num);
	printf("¿Desea seguir oredenando? 1)si  2)no \n");
	leer(&opcion);
	while(opcion<1 || opcion>2){
		printf("Error, escoja unicamente entre las dos opciones \n");
		leer(&opcion);
	}
	if(opcion==1){
		ordenar(ped,pla,num);
	}
}
/**
* @brief recibe un vector de estructura Platillo, y lee el pedido del cliente usando numeros
* @param ped : vector de estructura Pedido
* @param pla : vector de estructura Platillo
* @param num : vector el numero de pedido actual
*/
void ordenar(struct Pedido ped[],struct Platillo pla[], int num[]){
	int i=0, opcion=2, platillo=0;
	num[0]=num[0]+1;
	i=num[0];
	while(opcion==2){
		printf("¿Que platillo desea ordenar? \n");
		leer(&ped[i].platillo);
		platillo=ped[i].platillo;
		while(pla[platillo].disponibilidad==2){
			printf("El platillo no esta disponible, por favor escoja otro \n");
			leer(&ped[i].platillo);
			platillo=ped[i].platillo;
		}
		printf("¿Cuantas raciones quiere del platillo? \n");
		leer(&ped[i].raciones);
		printf("¿Lo quiere para llevar? 1)si  2)no \n");
		leer(&ped[i].paraLlevar);
		while(ped[i].paraLlevar<1 || ped[i].paraLlevar>2){
			printf("Error, escoja unicamente entre las dos opciones \n");
			leer(&ped[i].paraLlevar);
		}
		printf("¿Esta seguro de su pedido? 1)si  2)no \n");
		leer(&opcion);
		while(opcion<1 || opcion>2){
			printf("Error, escoja unicamente entre las dos opciones \n");
			leer(&opcion);
		}
	}
	printf("Su orden es la: #%i \n",i);
	verFechaHora();
}
/**
* @brief lee e imprime la fecha y hora del sistema
* @param 
* @return
*/
void verFechaHora(){
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	char output[128];
	strftime(output,128,"%d/%m/%Y %H:%M:%S",tlocal);
	printf("%s\n",output);
}
/**
* @brief lee una contraseña y si coincide llama a la funcion imprimirCodigo
* @param 
* @return
*/
void verMenuTecnico(){
	int contrasenia;
	printf("ingrese la contraseña del tecnico \n");
	leer(&contrasenia);
	if(contrasenia==PASSWORD2){
		printf("\n El codigo es: \n");
		imprimirCodigo();
	}else{
		printf("La contraseña es incorrecta \n");
	}
}
/**
* @brief imprime el codigo del programa
* @param 
*/
void imprimirCodigo(){
	FILE *fp= fopen ( "DinerSystem.c", "rb" );
	if(fp==NULL){
		perror("error en la apertura del archivo");
	}
	char caracter;
	while (feof(fp)==0){
		caracter=fgetc(fp);
		printf("%c",caracter);
	}
	fclose ( fp );
	printf("\n\n se ha leido correctamente \n");
}
