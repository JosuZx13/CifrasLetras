#ifndef Letra_h
#define Letra_h

#include <string>
#include <iostream>

using namespace std;

/**
  *  @brief T.D.A. Letra
  *
  * Letra es un Tipo de Dato Abstracto que está compuesto por
  * un char caracter que identifica a la letra
  * un entero aparicion que guarda las veces que aparece dicha letra
  * un double puntuacion que almacena los puntos a los que equivale la letra
  *
  *  @author Jose Manuel Osuna Luque
  *  @date Diciembre 2018
  */
class Letra {


private:

  char caracter;
  int aparicion;
  double puntuacion;

public:

  /**
    * @brief Constructor por defecto de la clase
    */
  Letra();

  /**
    * @brief Constructor por parámetros de la clase
    * @param car char, caracter que representa a la Letra
    * @param apar int, numero de veces que aparece la palabra
    * @param punt double, valor de la puntuacion asociada a la letra
    * @pre pal distinto de vacio o nada
    */
  Letra(const char& car, const int& apar, const double& punt);

  /**
    * @brief Constructor de copia de la clase
    * @param origen un objeto de la clase Letra
    * @pre origen no puede ser nulo
    */
  Letra(const Letra & origen);

  /**
    * @brief Destructor de la clase
    */
  ~Letra();


//CONSULTORES

  /**
    * @brief Consultor de Caracter
    * @return char, el caracter asociado a la letra
    */
  const char& getCaracter() const;
 
  /**
    * @brief Consultor de Aparicion
    * @return int, el numero de veces que puede aparecer la letra
    */
  const int& getAparicion() const;

  /**
    * @brief Consultor de Puntuacion
    * @return double, la puntuación que corresponde a la letra
    */
  const double& getPuntuacion() const;


  //MODIFICADORES

  /**
    * @brief Modificador de Caracter
    * @param char c, el nuevo valor del caracter asociado a la letra
    * @pre char c no debe estar vacio
    */
  void setCaracter(const char& c);
 
  /**
    * @brief Modificador de Aparicion
    * @param int a, el nuevo valor de las veces que aparece la palabra
    * @pre int a no puede ser menor que cero
    */
  void setAparicion(const int& a);

  /**
    * @brief Modificador de Puntuacion
    * @param double p, la nueva puntuacion asociada a la letra
    * @pre double p no puede ser menor que cero
    */
  void setPuntuacion(const double& p);


//METODOS

  /**
    * @brief Muestra por pantalla la Letra, incluyendo el caracter, las veces que aparece y su puntuacion
    */
  void mostrarLetra() const;


//OPERADORES

  /**
   * @brief Operador de igualdad
   * @param Letra comprob constante, el objeto usado con la clase para comprobar si son iguales o no 
   * @return bool, devuelve true si son iguales, false en caso contrario
   */
  bool operator==(const Letra comprob) const;

  /**
   * @brief Operador de desigualdad
   * @param Letra comprob constante, el objeto usado con la clase para comprobar si son iguales o no 
   * @return bool, devuelve true si son diferentes, false en caso contrario
   */
  bool operator!=(const Letra comprob) const;

  /**
   * @brief Operador mayor
   * @param Letra comprob constante, el objeto usado con la clase para comprobar si la letra es mayor 
   * @return bool, devuelve true si es mayor, false en caso contrario
   */
  bool operator>(const Letra comprob) const;

  /**
   * @brief Operador menor
   * @param Letra comprob constante, el objeto usado con la clase para comprobar si la letra es menor 
   * @return bool, devuelve true si es menor, false en caso contrario
   */
  bool operator<(const Letra comprob) const;


//FLUJOS

  /**
		* @brief Salida de un Letra a ostream
		* @param salida stream de salida
		* @param Letra fuente, a escribir
		* @return referencia a flujo de escritura
		*/
	friend ostream& operator<<(ostream& salida, const Letra& fuente);

	/**
		* @brief Entrada de un Letra desde istream
		* @param entrada stream de entrada
		* @param Letra destino, donde se guardará la Letra
		* @return referencia a flujo de lectura
		*/
	friend istream& operator>>(istream& entrada, Letra& destino);

};

  /**
   * @brief Metodo propio usado para dividir una linea leida por el stream 
   * @param un string que será dividido
   * @return una Letra creada a partir de la lectura de dicha linea
   */
  Letra separarLinea(string& linea);

#endif // Letra_h
