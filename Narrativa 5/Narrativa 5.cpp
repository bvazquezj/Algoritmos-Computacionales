/*
busqueda lineal con archivo
*/

#include<stdio.h>
#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>

using namespace std;

int arr[10];
int dato,i,val,flg=0;
fstream archivo;
string nomarch,line;

void obtenarr(){
    cout<<"introduce el nombre del archivo"<<endl;
    cin>>nomarch;
    nomarch+=".txt";
    archivo.open(nomarch.c_str(),fstream::out);
    if(!archivo.is_open()){
            cout<<"El archivo no se abrio correctamente"<<endl;
        }
    for(int i=0;i<10;i++){
        cout<<"dato numero "<<i+1<<endl;
        cin>>val;
        archivo<<val<<endl;
    }
    cout<<"archivo creado correctamente"<<endl;
    archivo.close();
    system("cls");
}
int obtenvalbus(){
    cout<<"introduce el valor a buscar"<<endl;
    cin>>dato;
    return dato;
}
void buscar(int dato){
    ifstream archivo(nomarch.c_str());
    while(getline(archivo,line)){
        i=0;
        arr[i]=stoi(line);
        if(arr[i]==dato){
            flg++;
        }
        i++;
    }
    }

void mostrar(int dato){
    cout<<"el dato "<<dato<<" esta "<<flg<<" veces en el arreglo"<< endl;
}
main(){
    obtenarr();
    obtenvalbus();
    buscar(dato);
    mostrar(dato);
    getch();
    return 0;
}
