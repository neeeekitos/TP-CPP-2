#Makefile du TP1
CFLAGS= -g -Wall -Wextra


Application: Application.o Catalogue.o ChainList.o Trajet.o TrajetSimple.o TrajetCompose.o
	@g++ -o Application Application.o Catalogue.o ChainList.o Trajet.o TrajetSimple.o TrajetCompose.o 

Application.o : Application.h Application.cpp
	@g++ -c Application.cpp

Catalogue.o : Catalogue.h Catalogue.cpp
	@g++ -c Catalogue.cpp

ChainList.o : ChainList.h ChainList.cpp
	@g++ -c ChainList.cpp

Trajet.o : Trajet.h Trajet.cpp
	@g++ -c Trajet.cpp

TrajetSimple.o : TrajetSimple.h TrajetSimple.cpp
	@g++ -c TrajetSimple.cpp

TrajetCompose.o : TrajetCompose.h TrajetCompose.cpp
	@g++ -c TrajetCompose.cpp

run: Application
	@echo "Lancement de l'application !" 
	@./Application

clean:
	@echo "Nettoyage du fichier Application et de tous les .o..."
	@rm -f Application
	@rm -f *.o