SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all:

testDiccionario: 	$(BIN)/testDiccionario

testConjunto:			$(BIN)/testConjuntoLetras

testCantidad:			$(BIN)/cantidadLetras

juego:						$(BIN)/cifrasLetras

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Compilación de módulos ************
$(BIN)/testDiccionario:$(OBJ)/testDiccionario.o $(OBJ)/Diccionario.o
	$(CXX) -o $(BIN)/TestDiccionario $(OBJ)/testDiccionario.o $(OBJ)/Diccionario.o

$(BIN)/testConjuntoLetras:$(OBJ)/testConjuntoLetras.o $(OBJ)/Letra.o $(OBJ)/ConjuntoLetras.o
	$(CXX) -o $(BIN)/TestConjuntoLetras $(OBJ)/testConjuntoLetras.o $(OBJ)/Letra.o $(OBJ)/ConjuntoLetras.o

$(BIN)/cantidadLetras:$(OBJ)/CantidadLetras.o $(OBJ)/Letra.o $(OBJ)/ConjuntoLetras.o $(OBJ)/Diccionario.o
	$(CXX) -o $(BIN)/CantidadLetras $(OBJ)/CantidadLetras.o $(OBJ)/Letra.o $(OBJ)/ConjuntoLetras.o $(OBJ)/Diccionario.o

$(BIN)/cifrasLetras:$(OBJ)/juego.o $(OBJ)/BolsaLetras.o $(OBJ)/Letra.o $(OBJ)/Diccionario.o $(OBJ)/ConjuntoLetras.o
	$(CXX) -o $(BIN)/cifrasLetras $(OBJ)/juego.o $(OBJ)/BolsaLetras.o $(OBJ)/Letra.o $(OBJ)/Diccionario.o $(OBJ)/ConjuntoLetras.o

$(OBJ)/testDiccionario.o: $(SRC)/testDiccionario.cpp $(INC)/Diccionario.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testDiccionario.o $(SRC)/testDiccionario.cpp

$(OBJ)/testConjuntoLetras.o: $(SRC)/testConjuntoLetras.cpp $(INC)/ConjuntoLetras.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/testConjuntoLetras.o $(SRC)/testConjuntoLetras.cpp

$(OBJ)/CantidadLetras.o: $(SRC)/CantidadLetras.cpp $(INC)/Diccionario.h $(INC)/ConjuntoLetras.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/CantidadLetras.o $(SRC)/CantidadLetras.cpp

$(OBJ)/Diccionario.o: $(SRC)/Diccionario.cpp $(INC)/Diccionario.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Diccionario.o  $(SRC)/Diccionario.cpp

$(OBJ)/Letra.o: $(SRC)/Letra.cpp $(INC)/Letra.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Letra.o  $(SRC)/Letra.cpp

$(OBJ)/ConjuntoLetras.o: $(SRC)/ConjuntoLetras.cpp $(INC)/ConjuntoLetras.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/ConjuntoLetras.o  $(SRC)/ConjuntoLetras.cpp

$(OBJ)/BolsaLetras.o: $(SRC)/BolsaLetras.cpp $(INC)/BolsaLetras.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/BolsaLetras.o  $(SRC)/BolsaLetras.cpp

$(OBJ)/juego.o: $(SRC)/juego.cpp $(INC)/BolsaLetras.h $(INC)/Diccionario.h
	$(CXX) $(CPPFLAGS) -o $(OBJ)/juego.o $(SRC)/juego.cpp

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
