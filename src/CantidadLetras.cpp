#include "Diccionario.h"
#include "ConjuntoLetras.h"
#include <vector>
#include <iomanip>      // std::setprecision

using namespace std;

struct pareja{
  char letra;
  int veces;
};

/*
./bin/ejecutable [parametros...]
./bin/testConjuntoLetras datos/letras.txt, por ejemplo
*/
int main(int argc, char * argv[]){


  if (argc!=4){
    cout<<"Numero de argumentos incorrectos"<<endl;
    return 0;
  }
  //argv[0] = ejecutable
  //argv[1] = diccionario a leer
  //argv[2] = letras a leer
  //argv[3] = fichero donde escribir

  //Se abre el fichero de escritura
  ifstream lectura_dic (argv[1]);

  if (!lectura_dic){
  cout<<"No puedo abrir el fichero "<< argv[1] << endl;
  return 0;
  }
 
   
  Diccionario dic;
  cout << "Cargando diccionario...\n" << endl;

  lectura_dic >> dic; //Cargamos en memoria el diccionario
  
  cout << "Diccionario leído..." << endl;

  lectura_dic.close(); //Cierro el flujo de lectura

  dic.mostrarDiccionario();


  ifstream lectura_let (argv[2]);

  if (!lectura_let){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }else{
     cout << "FICHERO ABIERTO" << endl;
 }
 
   
  ConjuntoLetras conj;
  cout << "Cargando conjunto de letras...\n" << endl;

  lectura_let >> conj; //Cargamos en memoria el conjunto de letras
  
  cout << "conjunto de letras leído.\n" << endl;

  cout << conj << endl;

  lectura_let.close();


  //Si el fichero ya existe (por ejemplo por una prueba anterior)
  //se machaca su contenido
  ofstream escritura (argv[3]);

  escritura << "#Letra\tFAbs\tFrel\tDiccionario: " << argv[1] << endl;

  vector<pareja> frecuencias;

  pareja aux;
  //Esta muestra se usará para calcular las Frecuencias Relativas
  int muestra = 0;

  const_ite_conjunto letr;
  //Se guardan las letras de la A a la Z (sin Ñ) en un vector
  //Por cada letra, se recorre el diccionario completo y se comprueban las posiciones de cada letra
  for(letr = conj.begin(); letr != conj.end(); letr++){
    aux.letra = letr->getCaracter();
    aux.veces = 0;

    //El diccionario está guardado en una lista
    ite_lista ite;
    //Se recorre todo el diccionario
    for(ite = dic.begin(); ite != dic.end(); ite++){

      //Se guarda en mayuscula 
      string pal = (*ite);
      //Se recorren todos los caracteres que componen el string
      for(unsigned int p = 0; p < pal.size(); p++){

        //Si un caracter en concreto coincide con la letra que estamos analizando, se suma en 1 la variable que lo contabiliza
        //toupper(char), pasa a mayúscula el char de no estarlo
        if(toupper(pal[p]) == (aux.letra)){
          aux.veces++;
        }//Fin del IF - caracter
      
      }//Fin del FOR - recorre la palabra

    }//Fin del FOR - recorre el diccionario
    muestra = muestra + aux.veces;
    
    frecuencias.push_back(aux);
  
  }//Fin del FOR - A a la Z

  /*
  FAbs, es el numero de veces. Es decir, eso ya lo tengo
  muestra = total de apariciones de las letras
  FRel = (nºVeces / muestra) * 100
  */

  //En el código ASCII, 65 es 'A' y 90 'Z'; 97 es 'a' y 122 es 'z'
  double rel = 0;

  for(unsigned int v = 0; v<frecuencias.size(); v++){
    rel = ( (double) (frecuencias[v].veces) / muestra) * 100;

    escritura << frecuencias[v].letra << "\t" << frecuencias[v].veces << "\t" << setprecision(4) << rel << endl;
  }

  escritura.close(); //Cierro el flujo de escritura

  cout << "Frecuencias recogida" << endl;
}
