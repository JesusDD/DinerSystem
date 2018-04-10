#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NP 100
#define LONGCAD 30
#define M 200
void leer(int*);
void menuPrincipal(char pla[NP][LONGCAD],int pre[NP], int dis[NP], int ped[M][3]);
void encargado(char pla[NP][LONGCAD],int pre[NP], int dis[NP], int ped[M][3]);
void cliente(char pla[NP][LONGCAD],int pre[NP], int dis[NP], int pedidos[M][3]);
void tecnico();
void imprimirCadenas(char[][LONGCAD]);
void administrar(int,char pla[NP][LONGCAD],int pre[NP], int dis[NP]);
void verPedidos(char pla[NP][LONGCAD],int pre[NP],int ped[M][3]);
void imprimirCodigo();
void inicializarChar(char a[][LONGCAD]);
void inicializarInt(int a[NP]);
void llenar(int a[][3]);
int main() {
	char platillos[NP][LONGCAD];
	int precio[NP];
	int disponibilidad[NP];
	int pedidos[M][3];
	inicializarChar(platillos);
	inicializarInt(precio);
	inicializarInt(disponibilidad);
	llenar(pedidos);
	menuPrincipal(platillos,precio,disponibilidad,pedidos);
	
	return 0;
}

void llenar(int a[][3]){
	int i=0, j=0;
	for(i=0;i<M;i++){
		for(j=0;j<3;j++){
			a[i][j]=0;
		}
	}
}

void inicializarInt(int a[NP]){
	int i=0;
	for(i=0;i<NP;i++){
		a[i]=0;
	}
}

void inicializarChar(char a[][LONGCAD]){
	int i=0, j=0;
	for(i=0;i<NP;i++){
		for(j=0;j<1;j++){
			a[i][j]='-';
		}
	}
}

void imprimirCadenas(char cadena[][LONGCAD]){
	int i;
	for(i=0; i<NP; i++){
		printf("%s", cadena[i]);
		printf(" \n");
	}
}

void menuPrincipal(char pla[NP][LONGCAD],int pre[NP], int dis[NP], int ped[NP][3]){
	int opcion;
	while(opcion!=4){
		printf("\n");
		printf("Bienvenido a DynerSystem \n Escoja entre las 4 opciones \n 1)Encargado \n 2)Cliente \n 3)Tecnico \n 4)Salir \n");
		leer(&opcion);
		while(opcion<1 || opcion>4){
			printf("La opcion que ingreso no existe :( , vuelva a intentarlo \n");
			leer(&opcion);
		}
		if(opcion==1){
			encargado(pla,pre,dis,ped);
		}else{
			if(opcion==2){
				cliente(pla,pre,dis,ped);
			}else{
				if(opcion==3){
					tecnico();
				}
			}
		}
	}
}

void leer(int* variable){
	scanf("%i", variable);
}

void encargado(char pla[NP][LONGCAD],int pre[NP], int dis[NP], int ped[M][3]){
	int contrasenia, opcion, platillo, desicion;
	printf("\n ingrese la contraseña del encargado \n");
	leer(&contrasenia);
	if(contrasenia==270418){
		printf("\n ¿Que accion desea realizar \n 1)administrar platillos \n 2)acceder a los pedidos \n");
		leer(&opcion);
		while(opcion<1 || opcion>2){
			printf("por favor indique alguna de las opciones en pantalla, vuelva a intentarlo \n");
			leer(&opcion);
		}
		if(opcion==1){
			while(desicion!=2){
				printf("Que platillo desea administrar \n");
				leer(&platillo);
				administrar(platillo,pla,pre,dis);
				printf("¿desea seguir administrando? \n 1)si \n 2)no \n");
				leer(&desicion);
			}
		}else{
			if(opcion==2){
				verPedidos(pla,pre,ped);
			}
		}
	}else{
		printf("La contraseña es incorrecta");
	}
}
void administrar(int i,char pla[NP][LONGCAD],int pre[NP], int dis[NP]){
	printf("ingrese el nombre del platillo \n");
	scanf(" %[^\n]", pla[i]);
	printf("ingrese el precio del platillo (en pesos) \n");
	scanf("%i",&pre[i]);
	printf("ingrese la disponibilidad del platillo \n 1)disponible \n 2)no disponible \n");
	scanf("%i", &dis[i]);
}

void verPedidos(char pla[NP][LONGCAD],int pre[NP],int ped[M][3]){
	int i=0,platillo=0,raciones=0;
	for(i=0;i<M;i++){
		platillo=ped[i][1];
		raciones=ped[i][2];
		printf("Pedido: # %i ",i);
		printf("platillo: %s ", pla[platillo]);
		printf("$ %i ",pre[platillo]);
		printf("raciones: %i",raciones);
		printf("para llevar: ");
		if(ped[i][3]==1){
			printf("si");
		}else{
			printf("no");
		}
		printf("\n");
	}
	system("pause");
}

void cliente(char pla[NP][LONGCAD],int pre[NP], int dis[NP], int pedidos[M][3]){
	int i=0;
	printf("Bienvenido al menu de la cafeteria \n");
	for(i=0;i<NP;i++){
		printf("Platillo %i)",i);
		printf(" %s ",pla[i]);
		printf(" %i ",pre[i]);
		if(dis[i]==1){
			printf(" disponible ");
		}else{
			printf(" no disponible ");
		}
		printf("\n");
	}
	printf("Que desea ordenar \n");
	
}

void tecnico(){
	int contrasenia;
	printf("ingrese la contraseña del tecnico \n");
	leer(&contrasenia);
	if(contrasenia==280499){
		printf("\n El codigo es: \n");
		imprimirCodigo();
		system("pause");
	}else{
		printf("La contraseña es incorrecta \n");
	}
}

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
