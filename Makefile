#Makefile du TP1

Main: Main.o Catalogue.o ChainList.o Trajet.o TrajetSimple.o TrajetCompose.o
	g++ -o Main Main.o Catalogue.o ChainList.o Trajet.o TrajetSimple.o TrajetCompose.o -lm

Main.o : Main.h Main.cpp
	g++ -c Main.cpp

Catalogue.o : Catalogue.h Catalogue.cpp
	g++ -c Catalogue.cpp

ChainList.o : ChainList.h ChainList.cpp
	g++ -c ChainList.cpp

Trajet.o : Trajet.h Trajet.cpp
	g++ -c Trajet.cpp

TrajetSimple.o : TrajetSimple.h TrajetSimple.cpp
	g++ -c TrajetSimple.cpp

TrajetCompose.o : TrajetCompose.h TrajetCompose.cpp
	g++ -c TrajetCompose.cpp

run: Main
	./Main

clean:
	rm -f *.o

