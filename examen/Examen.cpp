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
int imp=1, may=1,par=1, menr=1;
int salvacn=0;
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

void eliminar(){
    int flg2;
    cout<<"<-selecciona una opcion-->"<<endl;
    cout<<"<-(0)borrar duplicados"<<endl;
    cout<<"<-(1)digitos"<<endl;
    cout<<"<-(2)borrar mayores"<<endl;
    cout<<"<-(3)borrar menores"<<endl;
    cout<<"<-(4)borrar pares"<<endl;
    cout<<"<-(5)borrar impares"<<endl;
    cout<<"<------------------------>"<<endl;
    cin>>flg2;
    if((may==0)&&((flg2==2)||(flg2==3))){
        cout<<"no se puede realizar esta accion, mayores borrados \n";
        eliminar();
    }else if((menr==0)&&((flg2==2)||(flg2==3))){
        cout<<"no se puede realizar esta accion, menores borrados \n";
        eliminar();
    }else if((par==0)&&((flg2==4)||(flg2==5))){
        cout<<"no se puede realizar esta accion, pares borrados \n";
        eliminar();
    }else if((imp==0)&&((flg2==4)||(flg2==5))){
        cout<<"no se puede realizar esta accion, impares borrados \n";
        eliminar();
    }
    if(flg2==0){
        system("cls");
        cout<<"<- borrar duplicados"<<endl;
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j]){
                    a[j]=a[j+1];
                for(int k=j+1;k<n;k++){
                    a[k]=a[k+1];
                }
                n--;
                j--;
            }
            }
        }
    }else if(flg2==1){
        system("cls");
        int pos,valor,arreglo[9]={0}, j=0, divisor, multiplicacion=0, resultado=0,num=0;

        cout<<"<-Eliminar el valor si esta el digito-->"<<endl;
        cout<<"<-selecciona la posicion->"<<endl;
        cin>>pos;
        cout<<"<-introduce el valor del digito"<<endl;
        cin>>valor;


        for(int i=0;i<n;i++){
            num=a[i];
            divisor = pow(10, 8);
            for (j=0; j<9; j++){
                resultado = num / divisor;
                arreglo[j] = resultado;
                multiplicacion = resultado * divisor;
                num = num - multiplicacion;
                divisor = divisor / 10;
            }
            if(arreglo[pos-1]==valor){
                a[i]=a[i+1];
                for(int k=i+1;k<n;k++){
                    a[k]=a[k+1];
                }
                n--;
                i--;
            }
        }
    }else if((flg2==2)&&(may==1)){
        int men;
        system("cls");
        cout<<"<-Eliminar mayores-->"<<endl;
        cout<<"<-introduce el valor maximo"<<endl;
        cin>>men;
         for(int i=0;i<n;i++){
            if(a[i]<=men){
                a[i]=a[i+1];
                for(int k=i+1;k<n;k++){
                    a[k]=a[k+1];
                }
                n--;
                i--;
            }
        }may=0;
    }else if((flg2==3)&&(may==1)){
        int men;
        system("cls");
        cout<<"<-Eliminar menores-->"<<endl;
        cout<<"<-introduce el valor minimo"<<endl;
        cin>>men;
         for(int i=0;i<n;i++){
            if(a[i]>=men){
                a[i]=a[i+1];
                for(int k=i+1;k<n;k++){
                    a[k]=a[k+1];
                }
                n--;
                i--;
            }
        }menr=0;
    } if((flg2==4)&&(imp==1)){
        system("cls");
        cout<<"<-Eliminar pares-->"<<endl;
        for(int i=0;i<n;i++){
            if(a[i]%2 == 0){
                a[i]=a[i+1];
                for(int k=i+1;k<n;k++){
                    a[k]=a[k+1];
                }
                n--;
                i--;
            }
        }
            par=0;
    }else if((flg2==5)&&(imp==1)){
        system("cls");
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
            imp=0;
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
	//printf("valor de n es:  %i\n",n-1);
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
