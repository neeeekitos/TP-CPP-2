/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "ChainList.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"

//------------------------------------------------------------------ Types
typedef struct Bloc
{
    Trajet * blocData;
    int valeur;
} Bloc;

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Rechercher(char * depart, char * destination);
    // Mode d'emploi :
    //

    void Afficher(ChainList * tr);
    // Mode d'emploi :
    //

    void Afficher();
    // Mode d'emploi :
    //

    void Ajouter(Trajet * tr);
    // Mode d'emploi :
    //

    TrajetSimple * CreerTrajetSimple(char * depart, char * destination, char * moyenTransport);
    // Mode d'emploi :
    //

    TrajetCompose * CreerTrajetCompose();
    // Mode d'emploi :
    //

    bool RetirerTrajet(Trajet * tr);
    // Mode d'emploi :
    //  

    void isPossible(Bloc ** caseTab, int ligne, const char * destination, ChainList * trajetsPrecedents, int nbElem);
    // Mode d'emploi :
    //

    void RechercheAvance(char * depart, char * destination);
    // Mode d'emploi :
    //

//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //

    Catalogue ( );
    // Mode d'emploi :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    ChainList trajets;
};

#endif // CATALOGUE_H

