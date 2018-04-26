#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NP 50
#define LONGCAD 30
#define M 200
void leer(int*);
void menuPrincipal(char pla[NP][LONGCAD],int pre[NP], int dis[NP], int ped[M][3], int num[2]);
void encargado(char pla[NP][LONGCAD],int pre[NP], int dis[NP], int ped[M][3]);
void cliente(char pla[NP][LONGCAD],int pre[NP], int dis[NP], int pedidos[M][3],int num[2]);
void tecnico();
void imprimirCadenas(char[][LONGCAD]);
void administrar(int,char pla[NP][LONGCAD],int pre[NP], int dis[NP]);
void verPedidos(char pla[NP][LONGCAD],int pre[NP],int ped[M][3]);
void ordenar(int ped[][3], int num[2],int dis[NP]);
void imprimirCodigo();
void inicializarInt(int a[NP]);
void llenar(int a[][3]);
void fechaHora();
int main() {
	char platillos[NP][LONGCAD]={' '};
	int precio[NP];
	int disponibilidad[NP];
	int pedidos[M][3];
	int numeracion[2];
	inicializarInt(precio);
	inicializarInt(disponibilidad);
	llenar(pedidos);
	inicializarInt(numeracion);
	menuPrincipal(platillos,precio,disponibilidad,pedidos,numeracion);
	
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


void imprimirCadenas(char cadena[][LONGCAD]){
	int i;
	for(i=0; i<NP; i++){
		printf("%s", cadena[i]);
		printf(" \n");
	}
}

void menuPrincipal(char pla[][LONGCAD],int pre[NP], int dis[NP], int ped[][3], int num[2]){
	int opcion int contrasenia,flag=1;
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
			encargado(pla,pre,dis,ped);
			system("pause");
			system("cls");
		}else{
			if(opcion==2){
				system("cls");
				cliente(pla,pre,dis,ped,num);
				system("pause");
				system("cls");
			}else{
				if(opcion==3){
					system("cls");
					tecnico();
					system("pause");
					system("cls");
				}else{
					if(opcion==4){
						printf("ingrese alguna de las contraseñas para finalizar el programa");
						leer(&contrasenia);
						if(contrasenia==270418 || contrasenia==280499){
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

void leer(int* variable){
	scanf("%i", variable);
}

void encargado(char pla[][LONGCAD],int pre[NP], int dis[NP], int ped[][3]){
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
				while(platillo==0){
					printf("No existe este platillo");
					leer(&platillo);
				}
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
void administrar(int i,char pla[][LONGCAD],int pre[NP], int dis[NP]){
	printf("ingrese el nombre del platillo \n");
	scanf(" %[^\n]", pla[i]);
	printf("ingrese el precio del platillo (en pesos) \n");
	scanf("%i",&pre[i]);
	printf("ingrese la disponibilidad del platillo \n 1)disponible \n 2)no disponible \n");
	scanf("%i", &dis[i]);
}

void verPedidos(char pla[][LONGCAD],int pre[NP],int ped[][3]){
	int i=0,platillo=0,raciones=0,precio=0;
	for(i=1;i<M;i++){
		platillo=ped[i][0];
		raciones=ped[i][1];
		printf("Pedido: #%i ",i);
		printf("platillo: %s ", pla[platillo]);
		precio=pre[platillo]*raciones;
		printf("$ %i ",precio);
		printf("raciones: %i ",raciones);
		printf("para llevar: ");
		if(ped[i][2]==1){
			printf("si");
		}else{
			printf("no");
		}
		printf("\n");
	}
}

void cliente(char pla[][LONGCAD],int pre[NP], int dis[NP], int ped[][3], int num[2]){
	int i=0, opcion=0;
	printf("Bienvenido al menu de la cafeteria \n");
	for(i=1;i<NP;i++){
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
	ordenar(ped,num,dis);
	printf("¿Desea seguir oredenando? 1)si  2)no \n");
	leer(&opcion);
	while(opcion<1 || opcion>2){
		printf("Error, escoja unicamente entre las dos opciones \n");
		leer(&opcion);
	}
	if(opcion==1){
		ordenar(ped,num,dis);
	}
}

void ordenar(int ped[][3], int num[2],int dis[NP]){
	int i=0, opcion=2, platillo=0;
	num[0]=num[0]+1;
	i=num[0];
	while(opcion==2){
		printf("¿Que platillo desea ordenar? \n");
		leer(&ped[i][0]);
		platillo=ped[i][0];
		while(dis[platillo]==2){
			printf("El platillo no esta disponible, por favor escoja otro \n");
			leer(&ped[i][0]);
			platillo=ped[i][0];
		}
		printf("¿Cuantas raciones quiere del platillo? \n");
		leer(&ped[i][1]);
		printf("¿Lo quiere para llevar? 1)si  2)no \n");
		leer(&ped[i][2]);
		while(ped[i][2]<1 || ped[i][2]>2){
			printf("Error, escoja unicamente entre las dos opciones \n");
			leer(&ped[i][2]);
		}
		printf("¿Esta seguro de su pedido? 1)si  2)no \n");
		leer(&opcion);
		while(opcion<1 || opcion>2){
			printf("Error, escoja unicamente entre las dos opciones \n");
			leer(&opcion);
		}
    }
	printf("Su orden es la: #%i \n",i);
	fechaHora();
}

void fechaHora(){
	time_t tiempo = time(0);
	struct tm *tlocal = localtime(&tiempo);
	char output[128];
	strftime(output,128,"%d/%m/%Y %H:%M:%S",tlocal);
	printf("%s\n",output);
}	

	

void tecnico(){
	int contrasenia;
	printf("ingrese la contraseña del tecnico \n");
	leer(&contrasenia);
	if(contrasenia==280499){
		printf("\n El codigo es: \n");
		imprimirCodigo();
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
