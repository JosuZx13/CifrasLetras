#include "Diccionario.h"

#include <string.h>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
    cout<<"Dime el nombre del fichero con el diccionario"<<endl;
    return 0;
  }

  /*ifstream lectura (argv[1]);
  if (!lectura){
  cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
  return 0;
  }*/

  
  char fichero[30]; //Variable usada para guardar la ruta completa donde se encuentra el fichero
  strcpy(fichero, "../datos/"); //Copia al inicio del char fichero esa ruta
  strcat(fichero, argv[1]); //Concatena a lo que ya hay en fichero, el nombre del texto pasado por argumento

  ifstream lectura (fichero);

  if (!lectura){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }else{
     cout << "FICHERO ABIERTO" << endl;
 }
 
   
  Diccionario dic;
  cout << "Cargando diccionario..." << endl;

  lectura >> dic; //Cargamos en memoria el diccionario
  
  cout << "Diccionario leído..." << endl;

  cout << dic << endl;

  int longitud;

  cout << "Dime la longitud de las palabras que quieres ver" << endl;
  cin >> longitud;

  list<string> lista_l = dic.palabrasLongitud(longitud);

  cout << "Palabras de Longitud " << longitud << endl;

  for(const_ite_lista c_lista = lista_l.begin(); c_lista != lista_l.end(); c_lista++){
    cout << (*c_lista) << endl;
  }

  string p;
  cout << "Dime una palabra: ";
  cin >> p;

  if(dic.buscarPalabra(p)){
    cout << "La palabra sí existe" << endl;
  }else{
    cout << "Esta palabra no existe" << endl;
  }

}
