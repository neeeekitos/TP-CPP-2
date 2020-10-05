/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() 
{
    cout << "    Départ du trajet composé : " << GetDepart() << endl; 
    cout << "    Destination du trajet composé : " << GetDestination() << endl; 
    Element * trajet = trajetsSimples.GetPremierElement();

    while (trajet != nullptr)
    {
        cout << endl; 
        trajet->data->Afficher();
        trajet = trajet->suivant;
    }
}

char * TrajetCompose::GetDepart()
{
    return trajetsSimples.GetPremierElement()->data->GetDepart();
}

char * TrajetCompose::GetDestination()
{
    return trajetsSimples.GetDernierElement()->data->GetDestination();
}

void TrajetCompose::AjouterEscale(Trajet * tr)
{
    trajetsSimples.AjouterElement(tr);
}

bool TrajetCompose::RetirerEscale(Trajet * tr)
{
    return trajetsSimples.RetirerElement(tr);
}

bool TrajetCompose::EstValide() 
{
    Element * trajet = trajetsSimples.GetPremierElement();

    while (trajet != nullptr)
    {
        if(trajet->suivant != nullptr && strcmp(trajet->data->GetDestination(),trajet->suivant->data->GetDepart())) {
            return false; 
        }
        trajet = trajet->suivant;
    }
    return true; 
}



// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
