/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//-- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetSimple::Afficher() 
{
    cout << "    Départ : " << depart << endl;
    cout << "    Destination : " << destination << endl;
    cout << "    Moyen de transport : " << moyenTransport << endl;
    cout << endl; 
}

char * TrajetSimple::GetDestination()
{
    return destination;
}

char * TrajetSimple::GetDepart()
{
    return depart;
}

char * TrajetSimple::GetMoyenTransport() 
{
    return moyenTransport; 
}

bool TrajetSimple::EstEgal(Trajet * t) 
{
    if (dynamic_cast<TrajetSimple*>(t) != nullptr) {
        if(strcmp(depart,t->GetDepart())==0 && strcmp(destination,t->GetDestination())==0 && strcmp(moyenTransport,dynamic_cast<TrajetSimple*>(t)->GetMoyenTransport())==0)  
            return true; 
    } 
    return false;

}



//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ) : Trajet()
{
    strcpy(depart, unTrajetSimple.depart);
    strcpy(destination, unTrajetSimple.destination);
    strcpy(moyenTransport, unTrajetSimple.moyenTransport);
    cout << "child constructor trajet simple is working" <<endl;
}

TrajetSimple::TrajetSimple ( char * dep, char * dest, char * moyenT ) : 
Trajet( ), destination(dest), depart(dep), moyenTransport(moyenT)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete[] depart;
    delete[] destination;
    delete[] moyenTransport;
} //----- Fin de ~TrajetSimple