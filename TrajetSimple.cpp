/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

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


//------------------------------------------------- Surcharge d'opérateurs
//TrajetSimple & TrajetSimple::operator = ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple ( char * dep, char * dest, char * moyenT ) : Trajet( ), destination(dest), depart(dep), moyenTransport(moyenT)
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
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
