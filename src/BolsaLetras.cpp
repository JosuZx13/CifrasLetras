#include "BolsaLetras.h"
#include <utility>

using namespace std;


//list<Letra> bolsa;

BolsaLetras::BolsaLetras(){
  /*Letra N;
    N.setCaracter('N');
    N.setAparicion(0);
    N.setPuntuacion(1);

  addLetra(N);

  Letra S;
    S.setCaracter('S');
    S.setAparicion(0);
    S.setPuntuacion(1);

  addLetra(S);

  Letra A;
    A.setCaracter('A');
    A.setAparicion(0);
    A.setPuntuacion(1);
    
  addLetra(A);
  addLetra(A);
  
  Letra O;
    O.setCaracter('O');
    O.setAparicion(0);
    O.setPuntuacion(1); 
  
  addLetra(O);
  addLetra(O);

  Letra T;
    T.setCaracter('T');
    T.setAparicion(0);
    T.setPuntuacion(1);

  addLetra(T);

  Letra I;
    I.setCaracter('I');
    I.setAparicion(0);
    I.setPuntuacion(1);

  addLetra(I);*/
  
}

BolsaLetras::BolsaLetras(int numLetras, ConjuntoLetras conjunto, vector<Frec>& frecuencias){
  
  bolsa.clear(); //Por si se vuelve a jugar
  
  int sumaAbsoluta = 0;
  for(unsigned int i = 0; i<frecuencias.size(); i++){
    sumaAbsoluta = sumaAbsoluta + frecuencias[i].fre;
  }
  /*
    Sacar un número de 0 al total de Frecuencias Absolutas
    Ir iterando, sumando las frecuencias absolutas de cada letra
    Cada vez que llegas a una letra, y no suma el número (es < aun) se incrementa el acumulado

    Ejemplo:
      Si quieres la letra 50, pues se va contando:
        La primera, fabs = 20, aun no es >= 50,
        La segunda, fabs = 5 más anterior, 25 < 50, sumas
        La tercera, fabs 30, más anterior, 55, entonces coges esa letra porque es >= 50
  */
  int alea;
  int sumaElegida;

  for(int i = 1; i <= numLetras; i++){
    alea = -1;
    sumaElegida = 0;
    Letra aux;

    alea = rand() % sumaAbsoluta; //Aleatorio entre 0 y Suma Total de Frecuencias Absolutas
    bool added = false;

    for(unsigned int v = 0; v<frecuencias.size() && !added; v++){

      sumaElegida = sumaElegida + frecuencias[v].fre;

      if(sumaElegida >= alea){
        aux = conjunto.buscarLetra(frecuencias[v].letra);
        
        if(aux.getAparicion() > 0){
          bolsa.push_back( aux );
          //Modifico los valores de la aparicion de la letra para que no coja letras de mas
          conjunto.setValoresLetra(frecuencias[v].letra, aux.getAparicion()-1, aux.getPuntuacion());
          added = true;
        }

      }

    }

  }


}

BolsaLetras::BolsaLetras(const BolsaLetras& origen){
  *this = origen;
}

BolsaLetras::~BolsaLetras(){

}


    //CONSULTORES

const list<Letra> BolsaLetras::getBolsa() const{
  return bolsa;
}

list<Letra>& BolsaLetras::getBolsa(){
  return bolsa;
}

const unsigned int BolsaLetras::getNumLetras() const{
  return bolsa.size();
}


    //MODIFICADORES

void BolsaLetras::setBolsa(list<Letra>& lb){
  bolsa = lb;
}


    //METODOS

vector<Frec> BolsaLetras::calcularFrecuencias(ConjuntoLetras& conj, Diccionario& dic){
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
    frecuencias[v].fre = rel;
  }

  return frecuencias;
}

void BolsaLetras::addLetra(const Letra le){
  bolsa.push_back(le);
}

void BolsaLetras::removeLetra(ite_bolsa iter){
  bolsa.erase(iter);
}

const Letra& BolsaLetras::buscarLetra(const char& c){
  const_ite_bolsa iter;
  char c_mayus = toupper(c);

  for(iter = cbegin(); iter != cend(); iter++){
    if(iter->getCaracter() == c_mayus){
      return (*iter);
    }
  }

  return (*iter);
}

list<Letra> BolsaLetras::ordenarBolsa(){
  list<Letra> aux = bolsa;
  //Se ordenan, posbile gracias al operator< que hay en la clase Letra
  aux.sort();

  return aux;
}

void BolsaLetras::mostrarBolsa() const{
  cout << *this << endl;
}


    //ITERADORES

ite_bolsa BolsaLetras::begin(){
  return bolsa.begin();
}
  
const_ite_bolsa BolsaLetras::cbegin() const{
  return bolsa.cbegin();
}

ite_bolsa BolsaLetras::end(){
  return bolsa.end();
}

const_ite_bolsa BolsaLetras::cend() const{
  return bolsa.cend();
}


    //OPERADORES

void BolsaLetras::operator=(const BolsaLetras& asignar){

  //Se vacía la bolsa
  bolsa.clear();
  
  const_ite_bolsa asig;
    
  for(asig = asignar.cbegin(); asig != asignar.cend(); asig++){
    bolsa.push_back( (*asig) );
  }

}

bool BolsaLetras::operator==(BolsaLetras& comprob){
  if(getNumLetras() == comprob.getNumLetras()){
    
    list<Letra> aux_esta;
    list<Letra> aux_comp;

    aux_esta = ordenarBolsa();
    aux_comp = comprob.ordenarBolsa();

    const_ite_bolsa esta;
    const_ite_bolsa comp;

    for(esta = aux_esta.cbegin(), comp = aux_comp.cbegin(); esta != aux_esta.cend(), comp != aux_comp.cend(); esta++, comp++){
      if( (*esta) != (*comp) ){
        return false;
      }
    }
    //Solo si se han recorrido todos los objetos y no ha devuelto falso, entonces las bolsas contienen lo mismo
    return true;

  }

  //Si el tamaño no es igual, no son la misma bolsa
  return false;
}

bool BolsaLetras::operator!=(BolsaLetras& comprob){
  if( *this == comprob ){
    return false;
  }
  return true;
}

bool BolsaLetras::operator>(BolsaLetras comprob) const{
  return getNumLetras() > comprob.getNumLetras();
}

bool BolsaLetras::operator<(BolsaLetras comprob) const{
  return getNumLetras() < comprob.getNumLetras();
}


    //FLUJOS

ostream& operator<<(ostream& salida, const BolsaLetras& fuente){
  salida << "Bolsa de Letras:" << endl;
  const_ite_bolsa mostrar;
  
  for(mostrar = fuente.cbegin(); mostrar != fuente.cend(); mostrar++){
    salida << "\t" << (*mostrar).getCaracter();
  }
  salida << endl;

  return salida;
}

//istream& operator>>(istream& entrada, BolsaLetras& destino){}