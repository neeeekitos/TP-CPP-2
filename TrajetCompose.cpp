/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) -

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() 
{
    cout << "    Départ du trajet composé : " << GetDepart() << endl; 
    cout << "    Destination du trajet composé : ";
    cout << GetDestination() << endl; 
    Element * trajet = trajetsSimples.GetPremierElement();
    int nbEscales = 1; 

    while (trajet != nullptr)
    {
        cout << endl; 
        cout << "Escale numéro " << nbEscales << " : " << endl;
        trajet->data->Afficher();
        trajet = trajet->suivant;
        nbEscales++; 
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
        if(trajet->suivant != nullptr && 
        strcmp(
            trajet->data->GetDestination(),
            trajet->suivant->data->GetDepart())) {
            return false; 
        }
        trajet = trajet->suivant;
    }
    return true; 
}


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~TrajetCompose
