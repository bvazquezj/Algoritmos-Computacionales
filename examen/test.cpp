#include <iostream>
#include<stdio.h>
#include <math.h>
#include <conio.h>
#include<fstream>
#include<string>
#include<time.h>

using namespace std;

struct Entrada {
		int valor;
} entrada;

struct Entrada1 {
		int valor1;
} entrada1;
int a[1000000];
int n,aux,k;
int izq;
int der;
int salvacn=0;
int numero = 0, divisor =0, resultado = 0, multiplicacion = 0;
int i = 0, j=0;
int arreglo [10] = {0};
int tamano = 9;
int nd=0, v=0;

string nombrearchivo;
string nombrearchivo1;
clock_t t_ini, t_fin;

void leer(){
    FILE *archivo1;
    string valorInt;

    printf("\n Teclea el nombre del archivo de entrada:   ");
	cin >> nombrearchivo;
	nombrearchivo+= ".txt";

	archivo1 = fopen(nombrearchivo.c_str(), "r");

	if(archivo1== NULL ){
		printf(" No se puede abrir el archivo ");
		exit(1);
	}
	else{
		printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo.c_str() );
    }
    n=0;
    for (int i=0; !feof(archivo1); i++) {
        fscanf (archivo1, "%i", &entrada.valor);
        a[i]=entrada.valor;
        n++;
	}
	printf("valor de n es:  %i\n",n-1);
	fclose(archivo1);

}

void ordenar(){
    int flg1,i,j;
    cout<<"<-selecciona una opcion-->"<<endl;
    cout<<"<-(0)De mayor a menor"<<endl;
    cout<<"<-(1)De menor a mayor"<<endl;
    cout<<"<------------------------>"<<endl;
    cin>>flg1;
    if(flg1==1){

            int j;
        printf("Ordenamiento por insercion\n");

        for (i=0; i < n; i++) {
            k = a[i];                 // k es el indice
            j = i-1;
            while (j >= 0 && a[j] > k) {
                a[j + 1] = a[j];
                j--;
            }
            a[j+1] = k;
        }
    }if(flg1==0){
        for (i=0; i < n; i++) {
            k = a[i];
            j = i-1;
            while (j >= 0 && a[j] < k) {
                a[j + 1] = a[j];
                j--;
            }
            a[j+1] = k;
        }
    }
}

void eliminaentero(){
    for(int l=i;l<n;l++){
        a[l]=a[+1];
    }
    n--;
}

void validadigito(){

	   if(arreglo[nd-1]==v){
        cout<< "\n el digito "<< nd<< " si es igual a "<< v;
        eliminaentero();
	   }
	   else {
        cout<< "\n el digito "<< nd<< " no es igual a "<< v;
	   }

}

void mostrar1 (){
	   // para mostrar el resultado


		for (i=0; i<tamano; i++){
			cout<<arreglo [i]<<"  ";

    	}
    	cout<<endl;
    	// termina con un fin de linea para hacer salto de lineas
}
int valida() {
        if (resultado > 9){
            cout<<"\nError el numero es mayor de longitud indicada"<< resultado;
            exit(0);
        }

}
void separar () {
	//For para separar dos digitos internos
	divisor = pow ( 10, 8);
	for (j=0; j<tamano; j++){
 		resultado = numero / divisor;
 		valida();
 		arreglo [j] = resultado;
        mostrar1();
        multiplicacion = resultado * divisor;
        numero = numero - multiplicacion;
        divisor = divisor / 10;

	}
}


void eliminar(){
    int flg2;
    cout<<"<-selecciona una opcion-->"<<endl;
    cout<<"<-(0)borrar impares"<<endl;
    cout<<"<-(1)borrar menores"<<endl;
    cout<<"<-(2)digitos"<<endl;
    cout<<"<------------------------>"<<endl;
    cin>>flg2;
    if(flg2==0){
        cout<<"<-Eliminar impares-->"<<endl;
        for(int i=0;i<n;i++){
            if(a[i]%2 != 0){
                a[i]=a[i+1];
                for(int k=i+1;k<n;k++){
                    a[k]=a[k+1];
                }
                n--;
                i--;
            }
        }
    }else if(flg2==1){
        int men;
        cout<<"<-Eliminar menores-->"<<endl;
        cout<<"<-introduce el valor minimo"<<endl;
        cin>>men;
         for(int i=0;i<n;i++){
            if(a[i]<men){
                a[i]=a[i+1];
                for(int k=i+1;k<n;k++){
                    a[k]=a[k+1];
                }
                n--;
                i--;
            }
        }
    }else if(flg2==2){
        cout<< "\n que digito valido ";
        cin>>nd;
        cout<< "\n valor del digito ";
        cin>>v;
        for(int i=0;i<n;i++){
            numero= a[i];
            cout<<"\nNumero capturado  "<<numero<<endl;
            separar();
            validadigito();
        }
    }
}
void mostrar(){
    cout<<"<------------------------>"<<endl;
    cout<<"<-impimir arreglo"<<endl;
    for(int i=0;i<n;i++){
        cout<<" ["<<a[i]<<"] "<<endl;
    }
}

int grabar(){
	FILE *archivo2;
    string valorInt;

    printf("\n Teclea el nombre del archivo de salida:   ");
	cin >> nombrearchivo1;
	nombrearchivo1+= ".txt";						 		// le agregarmos la extension ".txt"

	archivo2 = fopen(nombrearchivo1.c_str(), "w");		        // Abrimos archivo

	if(archivo2== NULL ){
		printf(" No se puede abrir el archivo ");
		exit(1);
	}
	else{
		printf(" Se abrio el archivo correctamente %s\n ", nombrearchivo1.c_str() );
    }
    aux=a[0];
    for (int i=0; i<=n; i++) {
        if (aux!=a[i]){
            entrada1.valor1=aux;
            aux=a[i];
            fprintf(archivo2, "%i\n", entrada1.valor1);
        }
    }
	printf("valor de n es:  %i\n",n-1);
	fclose(archivo2);
	return (0);
}

int main(){
    int flg,opt,cion=0;
    cout<<"Brandon Vazquez Juarez "<<endl;
    cout<<"Examen "<<endl;
    do{
        cout<<"BIENVENIDO A MI PROGRAMA "<<endl;
        cout<<"<------------------------>"<<endl;
        cout<<"<-(1)Leer"<<endl;
        cout<<"<-(2)Ordenar"<<endl;
        cout<<"<-(3)Eliminar"<<endl;
        cout<<"<-(4)Mostrar"<<endl;
        cout<<"<-(5)Grabar"<<endl;
        cout<<"<-(0)Cerrar"<<endl;
        cout<<"<------------------------>"<<endl;
        cout<<"<-selecciona una opcion-->"<<endl;
        cin>>flg;
        system("cls");

        if(cion==0){
            cout<<"la primer accion debe ser leer"<<endl;
        }
        switch(flg){
        case 1:
            leer();
            cion++;
            break;
        case 2:
            if(cion!=0&&flg!=5){
                ordenar();
                system("cls");
            }
            break;
        case 3:
            if(cion!=0&&flg!=5){
                eliminar();
                system("cls");
            }
            break;
        case 4:
            if(cion!=0&&flg!=5){
                mostrar();
            }
            break;
        case 5:
            if(cion!=0);
            grabar();
            return 0;
            break;
        default:
            cout<<"ingresa un valor valido"<<endl;
        }
    }while(flg!=0);
    return 0;
}
