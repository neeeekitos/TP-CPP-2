/*************************************************************************
                           ChainList  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//------ Interface de la classe <ChainList> (fichier ChainList.h) --------
#if ! defined ( CHAINLIST_H )
#define CHAINLIST_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------ Types
typedef struct Element
{
    Trajet * data;
    Element * suivant;
    Element * precedent;
} Element;

//------------------------------------------------------------------------
// Rôle de la classe <ChainList>
//
//
//------------------------------------------------------------------------

class ChainList 
{
//----------------------------------------------------------------- PUBLIC

public:
    void AjouterElement(Trajet * trajet);
    // Mode d'emploi :
    //

    Element * RechercherElement(char * depart, char * destination);
    // Mode d'emploi :
    //

    Element * RechercherElement(Trajet * tr);
    // Mode d'emploi :
    //

    ChainList * RechercherParcours(char * depart, char * destination);
    // Mode d'emploi :
    //

    Element * GetSuivantElement(Element * elem);
    // Mode d'emploi :
    //

    Element * GetPremierElement();
    // Mode d'emploi :
    //

    Element * GetDernierElement();
    // Mode d'emploi :
    //

    ChainList * CopyList();
    // Mode d'emploi :
    //

    bool RetirerElement(Trajet * tr);
    // Mode d'emploi :
    //

    void RetirerAll();
    // Mode d'emploi :
    //

    void InsererListe(ChainList * listeAInserer);
    // Mode d'emploi :
    //

    int GetNbElements();

//-------------------------------------------- Constructeurs - destructeur
    ChainList ( const ChainList & unChainList ) = default;
    // Mode d'emploi (constructeur de copie) :
    //

    ChainList ( );
    // Mode d'emploi :
    //

    virtual ~ChainList ( );
    // Mode d'emploi :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    Element * tete, * queue;
    int nbElements = 0;
};


#endif // CHAINLIST_H

