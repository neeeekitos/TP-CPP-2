/*************************************************************************
                           ChainList  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ChainList> (fichier ChainList.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "ChainList.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ChainList::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//ChainList & ChainList::operator = ( const ChainList & unChainList )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ChainList::ChainList ( const ChainList & unChainList )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ChainList>" << endl;
#endif
} //----- Fin de ChainList (constructeur de copie)


ChainList::ChainList ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ChainList>" << endl;
#endif
} //----- Fin de ChainList


ChainList::~ChainList ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ChainList>" << endl;
#endif
} //----- Fin de ~ChainList


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
