/*
Este programa construye las palabras de longitud mayor (o de puntuación mayor) de un
diccionario a partir de una serie de letras seleccionadas de forma aleatoria. El programa
letras se deberá ejecutar en la línea de órdenes de la siguiente manera:
prompt%
letras spanish letras.txt 8 L
Los parámetros de entrada son los siguientes:
1. El nombre del fichero con el diccionario
2. El nombre del fichero con las letras
3. El numero de letras que se deben generar de forma aleatoria
4. Modalidad de juego:
• Longitud: Si el parámetro es L se buscará la palabra más larga.
• Puntuación: Si el parámetro es P se obtendrá la palabra de mayor puntuación.
*/

#include "BolsaLetras.h"
#include "Diccionario.h"
#include <utility>
#include <iomanip>      // std::setprecision

using namespace std;


void mostrarResultados(pair<list<string>, int> re){
  for(const_ite_lista r = re.first.cbegin(); r != re.first.cend(); r++){
    cout << (*r) << "\tPuntuacion: " << re.second << endl;
  }

}

bool buscarEnDiccionario(Diccionario& dic, string& pal){

  return dic.buscarPalabra(pal);

}

bool comprobarPalabra(BolsaLetras& bol, string& pal){
  bool bien = true;

  if(pal.size() <= bol.getNumLetras()){
    
    unsigned int diferente = 0;
    BolsaLetras b_aux;
    b_aux.setBolsa(bol.getBolsa());

    bool permitido;
    char caracter;
    for(unsigned int c = 0; c < pal.size() && bien; c++){ //Se coge un caracter
      permitido = false;
      diferente = 0;
      caracter = toupper(pal[c]); //Las letras en la bolsa están en mayúscula

      for(const_ite_bolsa iter = bol.cbegin(); iter != bol.cend() && !permitido; iter++){ //Se recorre la bolsa para cada caracter

        if(caracter != iter->getCaracter() ){
          diferente++;
        
        }else{ //Hay que comprobar que la Letra no haya sido usada más veces de las permitidas

          ite_bolsa usable; //Usado luego para borrarlo
          for(usable = b_aux.begin(); usable != b_aux.end() && !permitido; usable++){

            if( usable->getCaracter() == caracter){
              permitido = true;
              b_aux.removeLetra(usable);
            }

          }//FIN del FOR - Bolsa Auxiliar

          if(!permitido){//Si no está, simplemente es un fallo más
            diferente++;
          }

        }

      }

      if(diferente == bol.getNumLetras()){ //Para cada caracter
        //Basta con que se haya usado un caracter que no esté en la bolsa para ser una palabra incorrecta
        bien = false;
      }

    } //Fin del FOR - Caracteres de una palabra

  }else{
    bien = false;

  }
  

  return bien;

}

string pedirSolucion(Diccionario& dic, BolsaLetras& bol){
  bool correcto = false;
  string solucion;

  do{

    cout << "Dime tu solución: ";
    cin >> solucion;

    correcto = comprobarPalabra(bol, solucion);
    
    if(correcto){
      correcto = buscarEnDiccionario(dic, solucion);
    }

    if(!correcto){
      cout << "Su solución no existe o no fue formada con las letras de la Bolsa" << endl;

    }

  }while(!correcto); //Comprobar que la palabra usada es correcta

  return solucion;
}

pair<string, int> puntuarPalabra(BolsaLetras& bol, string& pal){
  
  pair<string, int> palabraPuntuada;
  
  bool puntuada;
  int puntuacion = 0;

  for(unsigned int s = 0; s < pal.size(); s++){
    puntuada = false;

    for(const_ite_bolsa ib = bol.cbegin(); ib != bol.cend() && !puntuada; ib++){

      if( toupper(pal[s]) == ib->getCaracter() ){
        puntuacion = puntuacion + ib->getPuntuacion();
        puntuada = true;
      }
    }

  }

  palabraPuntuada.first = pal;
  palabraPuntuada.second = puntuacion;

  return palabraPuntuada;

}

pair<list<string>, int> obtenerTodasSoluciones(Diccionario& diccio, BolsaLetras& bolsa, char modal){

  pair<list<string>, int> resultados;

  if(modal == 'L'){ //Se calculan las soluciones a razón de la LONGITUD
    unsigned int cantidadLetras = bolsa.getNumLetras();
    bool correcto;
    list<string> posibles;

    while(resultados.first.size() == 0 && cantidadLetras > 0){
      posibles = diccio.palabrasLongitud(cantidadLetras);
      
      resultados.second = posibles.begin()->size(); //Puntuacion máxima

      ite_lista pal;
      for(pal = posibles.begin(); pal != posibles.end(); pal++){

        string p = (*pal);
        correcto = comprobarPalabra(bolsa, p);

        if(correcto){
          resultados.first.push_back( (*pal) );
        }

      }//Fin del FOR - lista
      cantidadLetras--;

    }//Fin del While - posibles

    return resultados;


  }else{ //Se calculan las soluciones a razón de la PUNTUACION

    bool posible = false;
    
    pair<string, int> pareja;

    resultados.second = 0;


    for(ite_lista palDicc = diccio.begin(); palDicc != diccio.end(); palDicc++){

      posible = comprobarPalabra( bolsa, (*palDicc) );

      if(posible){

        pareja = puntuarPalabra(bolsa, (*palDicc) );

        if(pareja.second > resultados.second){
          resultados.second = pareja.second;

          resultados.first.clear(); //Si la puntuacion es mayor, ya no interesan las demás que hubiera guardadas

          resultados.first.push_back( pareja.first );
        
        }else{
        
          if(pareja.second == resultados.second){ //Si la puntuacion es la misma se guarda como otra posible solución
            resultados.first.push_back( (pareja.first) );
          }
        
        }

      }//Fin del IF - la palabra se puede crear con la bolsa de letras

    } //Fin del FOR - Recorrer el diccionario

    return resultados;

  }

}

vector<Frec> calcularFrecuencias(ostream& escritura, Diccionario& dic, ConjuntoLetras& conj){

  vector<Frec> frecuencias;

  Frec aux;
  //Esta muestra se usará para calcular las Frecuencias Relativas
  int muestra = 0;

  const_ite_conjunto letr;
  //Se guardan las letras de la A a la Z (sin Ñ) en un vector
  //Por cada letra, se recorre el diccionario completo y se comprueban las posiciones de cada letra
  for(letr = conj.begin(); letr != conj.end(); letr++){
    aux.letra = letr->getCaracter();
    aux.fre = 0;

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
          aux.fre++;
        }//Fin del IF - caracter
      
      }//Fin del FOR - recorre la palabra

    }//Fin del FOR - recorre el diccionario
    muestra = muestra + aux.fre;
    
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
    rel = ( (double) (frecuencias[v].fre) / muestra) * 100;

    escritura << frecuencias[v].letra << "\t" << frecuencias[v].fre << "\t" << setprecision(4) << rel << endl;
  }

  return frecuencias;
}

//################ PROGRAMA PRINCIPAL #################################

int main(int argc, char * argv[]){
  srand(time(0)); //Sin esto no se generan letras aleatorias cada vez que se ejecute el bin

  if (argc!=6){
    cout<<"Numero de argumentos incorrectos"<<endl;
    return 0;
  }
  //argv[0] = ejecutable
  //argv[1] = diccionario a leer
  //argv[2] = letras a leer
  //argv[3] = numero letras
  //argv[4] = salida frecuencias
  //argv[5] = modalidad de juego

  //Se abre el fichero de diccionario
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
  //dic.mostrarDiccionario();


  //Se abre el fichero de letras
  ifstream lectura_let (argv[2]);

  if (!lectura_let){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
 
   
  ConjuntoLetras conju;
  cout << "Cargando conjunto de letras...\n" << endl;

  lectura_let >> conju; //Cargamos en memoria el conjunto de letras
  
  cout << "Conjunto de Letras leído.\n" << endl;
  //cout << conju << endl;
  lectura_let.close();

  //Si el fichero ya existe (por ejemplo por una prueba anterior)
  //se machaca su contenido
  ofstream escritura (argv[3]);

  escritura << "#Letra\tFAbs\tFrel\tDiccionario: " << argv[1] << endl;

  vector<Frec> frecuencias = calcularFrecuencias(escritura, dic, conju);
  cout << "Frecuencias calculadas" << endl;

  int numLetras = atoi(argv[4]);
  cout << "Numero de Letras recogido: " << numLetras << endl;

  string modalidad = argv[5];
  char seguir = 'S';
  
  
  //Diccionario = dic;
  //ConjuntoLetras = conj;
  //BolsaLetra = bo;
  while(seguir == 'S'){
    BolsaLetras bo(numLetras, conju, frecuencias);

    cout << "Bolsa creada. Tamaño: " << bo.getNumLetras() << endl;

    cout << bo;
    string solucion;

    solucion = pedirSolucion(dic, bo);

    char m = toupper(modalidad[0]);

    if(m == 'L'){
      cout << "La Modalidad recogida es: Longitud" << endl;

      cout << solucion << "\tPuntuacion: " << solucion.size() << endl;
      
      //Obtener otras soluciones
      pair <list<string>, int> soluciones;

      cout << "Mis soluciones son: " << endl;
      soluciones = obtenerTodasSoluciones(dic, bo, m);

      mostrarResultados(soluciones);

      cout << "Mejor Resultado: " << soluciones.first.front() << endl;

    }else{
      cout << "La Modalidad recogida es: Puntuacion" << endl;
      pair<string, int> parejaPuntuada;
      
      parejaPuntuada = puntuarPalabra(bo, solucion);

      cout << parejaPuntuada.first << "\tPuntuacion: " << parejaPuntuada.second << endl;

      //Obtener otras soluciones
      pair <list<string>, int> soluciones;

      cout << "Mis soluciones son: " << endl;
      soluciones = obtenerTodasSoluciones(dic, bo, m);

      mostrarResultados(soluciones);

      cout << "Mejor Resultado: " << soluciones.first.front() << endl;
    }

    do{
      cout << "¿Quieres seguir jugando?[S/N]";
      cin >> seguir;

    }while(seguir != 'S' && seguir != 'N');

  }//Fin del While - Seguir Jugando
  
}
