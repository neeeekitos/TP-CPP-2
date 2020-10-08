/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//---- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher(ChainList * tr)
{
    if (tr == nullptr) return; 
    Element * trajet = tr->GetPremierElement();

    if (trajet == nullptr && trajet->data == nullptr) cout << "Aucun trajet" << endl;
    else {
        while (trajet != nullptr)
        {
            cout << "    --------------------------------" << endl; 
            trajet->data->Afficher();
            cout << "    --------------------------------" << endl; 
            trajet = trajet->suivant;
        }
    }
}

void Catalogue::Afficher()
{
    this->Afficher(&trajets);
}

void Catalogue::Rechercher(char * depart, char * destination)
{
    ChainList * resultatTrajets = trajets.RechercherParcours(depart, destination);
    Afficher(resultatTrajets);
    resultatTrajets->RetirerAll();
    delete resultatTrajets;
    delete[] depart;
    delete[] destination;
}

void Catalogue::RechercheAvance(char * depart, char * destination)
{
    if (trajets.GetPremierElement() == nullptr) 
    {
        delete[] depart;
        delete[] destination;
        return;
    }
    
    ChainList * trajetsPrecedents = new ChainList;
    int nbElem = trajets.GetNbElements();
    int nbLignes = nbElem;
    int nbColonnes = nbLignes + 2;

    Bloc ** caseTab = new Bloc*[nbLignes];
    int colCount = 10;
    for(int i = 0; i < nbLignes; ++i)
    {
        caseTab[i] = new Bloc[nbColonnes];
        for (int j = 0; j < nbColonnes; j++)
        {
            caseTab[i][j].valeur = 0;
        }
    }

    int lastDepRempli = 0;
    int lastDestRempli = 0;
    bool destEstChange = false;
    bool depEstChange = false;
    int depIndex = 0;
    int destIndex = 0;
    int ligneInit = -1;
    int colonneInit = -1;

    /*ajout du premier element*/
    Element * temp = trajets.GetPremierElement();
    if (!strcmp(temp->data->GetDepart(), depart)) ligneInit = depIndex;
    caseTab[0][2].valeur = 1;
    caseTab[0][2].blocData = temp->data;
    lastDestRempli+=2;
    
    temp = trajets.GetSuivantElement(temp);

    while (temp != nullptr)
    {
        /* Rechercher si le meme depart / destination pour un autre trajet existe déjà*/
        for (int i = 0; i < lastDepRempli; i++)
        {
            for (int j = 1; j < lastDestRempli; j++)
            {
                if (caseTab[i][j].blocData != nullptr)
                {
                    if (!strcmp(caseTab[i][j].blocData->GetDepart(), temp->data->GetDepart()))
                    {
                        depEstChange = true;
                        depIndex = i;
                    }

                    if (!strcmp(caseTab[i][j].blocData->GetDestination(), temp->data->GetDestination()))
                    {
                        destEstChange = true;
                        destIndex = j;
                    }
                }
            }
        }

        if (!destEstChange && !depEstChange)
        {
            lastDepRempli++;
            lastDestRempli++;
            depIndex = lastDepRempli;
            destIndex = lastDestRempli;
        }
        caseTab[depIndex][destIndex].valeur = 1;
        caseTab[depIndex][destIndex].blocData = temp->data;
        destEstChange = depEstChange = false;

        if (!strcmp(temp->data->GetDepart(), depart)) ligneInit = depIndex;
        temp = trajets.GetSuivantElement(temp);
    }

    if (ligneInit == -1) 
    {
        cout << "Pas de trajets disponibles" << endl;
        return;
    }

    for (int i = 0; i < nbLignes; i++)
    {
        for (int j = 0; j < nbColonnes; j++)
        {
            cout << caseTab[i][j].valeur << "  ";
        }
        cout << endl;
    }

    isPossible(caseTab, ligneInit, destination, trajetsPrecedents, nbElem);

    for(int i = 0; i < nbLignes; i++)
        delete[] caseTab[i];
    delete[] caseTab;
    delete[] depart;
    delete[] destination;
}

void Catalogue::isPossible(Bloc ** caseTab, int ligne, const char * destination, ChainList * trajetsPrecedents, int nbElem)
{
    int nbColonnes = nbElem + 2;
    int nbLignes = nbElem;

    /*tester si on a déjà parcouru cette ligne (i)*/ 
    if (ligne >= nbLignes || caseTab[ligne][0].valeur==1) 
    {
        trajetsPrecedents->RetirerAll();
        delete trajetsPrecedents;
        return;
    }
    else caseTab[ligne][0].valeur = 1;


    for (int j = 1; j < nbColonnes; j++)
    {
        if (caseTab[ligne][j].valeur == 1)
        {
            if (!strcmp(caseTab[ligne][j].blocData->GetDestination(), destination))
            {
                //trjPreced.AjouterElement(caseTab[ligne][j].blocData);
                /*Afficher(&trjPreced);
                while (get suivant existe dans trajetPreced)*/
                ChainList * trjPreced = trajetsPrecedents->CopyList();

                ChainList * tr = trajets.RechercherParcours(caseTab[ligne][j].blocData->GetDepart(), caseTab[ligne][j].blocData->GetDestination());


                Afficher(trjPreced);
                trjPreced = nullptr;
            } else {
                ChainList * trjPreced = trajetsPrecedents->CopyList();
                trjPreced->AjouterElement(caseTab[ligne][j].blocData);
                isPossible(caseTab, j-1, destination, trjPreced, nbElem);
                trjPreced = nullptr;
            }
        }
    }   
}

void Catalogue::Ajouter(Trajet * tr)
{
    trajets.AjouterElement(tr);
}

TrajetSimple * Catalogue::CreerTrajetSimple(char * depart, char * destination, char * moyenTransport)
{
    return new TrajetSimple(depart, destination, moyenTransport);
}

TrajetCompose * Catalogue::CreerTrajetCompose()
{
    return new TrajetCompose();
}

bool Catalogue::RetirerTrajet(Trajet * tr)
{
    return trajets.RetirerElement(tr);
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue