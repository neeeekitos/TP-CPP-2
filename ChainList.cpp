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
#include <cstring>

//------------------------------------------------------ Include personnel
#include "ChainList.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void ChainList::AjouterElement(Trajet * trajet)
{
    Element * temp = new Element();
    temp->data = trajet;
    temp->suivant = nullptr;
    temp->precedent = nullptr;
    if (tete == nullptr) {
        tete = temp;
        queue = temp;
        temp = nullptr;
    } else {
        queue->suivant = temp;
        queue->suivant->precedent = queue;
        queue = temp;
    }
}

Element * ChainList::GetSuivantElement(Element * elem)
{
    return elem->suivant;
}

Element * ChainList::GetPremierElement()
{
    return tete;
}

Element * ChainList::RechercherElement(Trajet * tr)
{
    Element * trajet = GetPremierElement();

    /* surcharger "=" dans Trajetcpp
    strcmp(trajet->data->depart, depart) && !strcmp(trajet->data->destination, destination*/
    /*while (trajet != nullptr && *(trajet->data) != *tr)
    {
        trajet = GetSuivantElement(trajet);
    }*/

    return trajet;
}

ChainList * ChainList::RechercherParcours(char * depart, char * destination)
{
    int trajetCmt = 0;
    ChainList * resultat;
    Element * trajet = GetPremierElement();

    while (trajet != nullptr)
    {
        if (!strcmp(trajet->data->depart, depart) && !strcmp(trajet->data->destination, destination) && !strcmp(trajet->data->destination, destination))
        {
            trajetCmt++;
            resultat->AjouterElement(trajet->data);
        }
        trajet = GetSuivantElement(trajet);
    }
    return resultat;
}

bool ChainList::RetirerElement(Trajet * tr)
{
    Element * trajet = RechercherElement(tr);

    if (trajet == nullptr) return false;

    if (trajet->suivant != nullptr && trajet->precedent != nullptr)
    {
        trajet->precedent->suivant = trajet->suivant;
        trajet->suivant->precedent = trajet->precedent;
    } else if (trajet->suivant == nullptr)
    {
        queue = trajet->precedent;
        queue->suivant = nullptr;
    } else {
        tete = trajet->suivant;
        tete->precedent = nullptr;
    }
    
    return true;
}

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


ChainList::ChainList ()
{
#ifdef MAP
    cout << "Appel au constructeur de <ChainList>" << endl;
#endif
    tete = nullptr;
    queue = nullptr;
} //----- Fin de ChainList


ChainList::~ChainList ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ChainList>" << endl;
#endif
    /*Trajet * temp = tete;
    while (tete != queue)
    {
        if (tete = nullptr) break;
        else {
            temp = tete->suivant;
            temp->
        }
    }
    delete Trajet;*/
} //----- Fin de ~ChainList


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
