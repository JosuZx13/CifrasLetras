#ifndef BolsaLetras_h
#define BolsaLetras_h

#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "Letra.h"
#include "ConjuntoLetras.h"
#include "Diccionario.h"

using namespace std;

typedef list<Letra>::iterator ite_bolsa;
typedef list<Letra>::const_iterator const_ite_bolsa;

/**
 * @brief Struct Auxiliar para guardar la Letra y su Frecuencia
 */
struct Frec{
  char letra;
  double fre;
};

/**
  *  @brief T.D.A. Bolsa de Letras
  *
  * Almacena una lista de caracteres (que pueden repetirse) usados para jugar.
  * Las letras son cogidas del Conjunto de Letras de forma aleatoria (atendiendo a su frecuencia).
  * Una letra podrá aparecer repetida tantas veces como su variable "Aparicion" indique.
  * El juego usará la Bolsa de Letras para jugar y obtener soluciones, así como para comprobar
  * que la solución del usuario es correcta (es decir, ha usado las letras que solo estaban permitidas)
  * 
  * BolsaLetras es un Tipo de Dato Abstracto que está compuesto por
  * un list (Pues se repiten las palabras), bolsa, de Letras
  * donde todas las letras son mayúsculas
  *
  *  @author Jose Manuel Osuna Luque
  *  @date Diciembre 2018
  */
class BolsaLetras {


private:

  list<Letra> bolsa;

public:

  /**
    * @brief Constructor por defecto de la clase
    */
  BolsaLetras();
  
  /**
    * @brief Constructor por parámetros de la clase
    * @param numLetras, numero de letras que tendrá la bolsa
    * @param conjunto, Conjunto de Letras con las que se juega
    * @param frecuencias, un vector donde se guarda una letra y su frecuencia
    * @pre numLetras no puede ser negativo
    * @pre conjunto no puede estar vacio
    * @pre frecuencias no puede estar vacio
    */
  BolsaLetras(int numLetras, ConjuntoLetras conjunto, vector<Frec>& frecuencias);

  /**
    * @brief Constructor de copia de la clase
    * @param origen un objeto de la clase BolsaLetras
    * @pre origen no puede ser nulo
    */
  BolsaLetras(const BolsaLetras& origen);

  /**
    * @brief Destructor de la clase
    */
  ~BolsaLetras();


//CONSULTORES

  /**
    * @brief Consultor de Letras
    * @return list<Letra>, el conjunto de letras no repetidas
    */
  const list<Letra> getBolsa() const;

  /**
    * @brief Consultor de Letras
    * @return list<Letra>, el conjunto de letras no repetidas
    */
  list<Letra>& getBolsa();

  /**
   * @brief Consultor del numero de letras que contiene el conjunto 
   * @return entero con el número de elementos del conjunto de Letras
   */
  const unsigned int getNumLetras() const;

//MODIFICADORES

  /**
   * @brief Modificador del atributo de la clase
   * @param lb, list<Letra> el nuevo valor del atributo
   */ 
  void setBolsa(list<Letra>& lb);


//METODOS

  /**
   * @brief Calcula las frecuencias con las que aparece una letra
   * @param conj, ConjuntoLetras usado para comprobar cada letra con esta
   * @param dic, un Diccionario de donde serán tomadas las palabras usadas para calcular la frecuencia
   * @return vector<Frec> un vector de frecuencias donde se guarda una letra y su frecuencia absoluta
   */ 
  vector<Frec> calcularFrecuencias(ConjuntoLetras& conj, Diccionario& dic);

  /**
    * @brief Añade un letra a la lista
    * @param le Letra que será añadido a la bolsa
    * @pre le no puede ser nulo o vacio
    */
  void addLetra(const Letra le);

  /**
  * @brief Elimina un letra de la lista
  * @param le Letra que será eliminada de la bolsa
  * @pre iter no puede ser nulo o vacio
  */
  void removeLetra(ite_bolsa iter);

  /**
   * @brief Busca una Letra en el list a través de un caracter 
   * @param c char, usado para buscar la letra en el conjunto
   * @pre c char no puede estar vacia
   */
  const Letra& buscarLetra(const char& c);

  /**
   * @brief Ordena la Bolsa de Letras
   * @return una variable aux con la bolsa (lista) ordenada
   */ 
  list<Letra> ordenarBolsa();

  /**
    * @brief Muestra por pantalla la bolsa de letras
    */
  void mostrarBolsa() const;


//ITERADORES

    /**
    * @brief Metodo begin de la Bolsa de Letras
    * @return devuelve un iterador de la primera posicion del list de bolsa de letras
    */
  ite_bolsa begin();

  /**
    * @brief Metodo begin de la Bolsa de letras
    * @return devuelve un iterador constante de la primera posicion del list de bolsa de letras
    */
  const_ite_bolsa cbegin() const;
  
  /**
    * @brief Metodo end de la Bolsa de Letras
    * @return devuelve un iterador a la siguiente posicion de la última del list de bolsa de letras
    */
  ite_bolsa end();
  
  /**
    * @brief Metodo end de la Bolsa de Letras
    * @return devuelve un iterador constante a la siguiente posicion de la última del list de bolsa de letras
    */
  const_ite_bolsa cend() const;


//OPERADORES

  /**
   * @brief Operador de asignacion
   * @param asginar, un objeto Bolsa de Letras que se asignara al atributo de la clase
   * @pre que el objeto asignar no sea nulo
   */ 
  void operator=(const BolsaLetras& asignar);

  /**
   * @brief Operador de igualdad
   * @param BolsaLetras comprob constante, el objeto usado con la clase para comprobar si son iguales o no 
   * @return bool, devuelve true si son iguales, false en caso contrario
   */
  bool operator==(BolsaLetras& comprob);

  /**
   * @brief Operador de desigualdad
   * @param BolsaLetras comprob constante, el objeto usado con la clase para comprobar si son iguales o no 
   * @return bool, devuelve true si son diferentes, false en caso contrario
   */
  bool operator!=(BolsaLetras& comprob);

  /**
   * @brief Operador mayor
   * @param BolsaLetras comprob constante, el objeto usado con la clase para comprobar si la letra es mayor 
   * @return bool, devuelve true si es mayor, false en caso contrario
   */
  bool operator>(BolsaLetras comprob) const;

  /**
   * @brief Operador menor
   * @param BolsaLetras comprob constante, el objeto usado con la clase para comprobar si la letra es menor 
   * @return bool, devuelve true si es menor, false en caso contrario
   */
  bool operator<(BolsaLetras comprob) const;


//FLUJOS

  /**
		* @brief Salida de un BolsaLetras a ostream
		* @param salida stream de salida
		* @param BolsaLetras fuente, a escribir
		* @return referencia a flujo de escritura
		*/
	friend ostream& operator<<(ostream& salida, const BolsaLetras& fuente);

	/*
		* @brief Entrada de un BolsaLetras desde istream
		* @param entrada stream de entrada
		* @param BolsaLetras destino, donde se guardará la BolsaLetras
		* @return referencia a flujo de lectura
		
	friend istream& operator>>(istream& entrada, BolsaLetras& destino);*/

};

#endif // BolsaLetras_h
