/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//-- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "ChainList.h"

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// La classe TrajetCompose hérite de la classe Trajet.
// Un trajet composé possède une chainlist de trajets. 
// Dans notre implémentation, la chainlist ne peut être composée que 
// de trajets simples. 
// Les trajets simples qui composent le trajet composé sont appelées
// escales dans notre code. 
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher();
    // Mode d'emploi (constructeur de copie) :
    // Affiche un TrajetCompose : 
    // Au début, affiche le depart et la destination du TrajetCompose.
    // Puis pour chaque escale qui compose le TrajetCompose affiche le
    // départ, la destination et le moyen de transport de l'escale. 
    // Redéfinie la méthode Afficher() de Trajet.

    char * GetDepart();
    // Mode d'emploi (constructeur de copie) :
    // Retourne le départ du TrajetCompose.

    char * GetDestination();
    // Mode d'emploi (constructeur de copie) :
    // Retourne la destination du TrajetCompose.

    void AjouterEscale(Trajet * tr);
    // Mode d'emploi (constructeur de copie) :
    // Ajoute l'escale tr au TrajetCompose. 
    // Contrat :
    // tr doit être un TrajetSimple.

    bool RetirerEscale(Trajet * tr);
    // Mode d'emploi (constructeur de copie) :
    // Retire l'escale tr du TrajetCompose. 
    // Retourne true si l'escale a bien été retirée, false sinon 
    // Contrat :
    // tr doit être un TrajetSimple.

    bool EstValide();
    // Mode d'emploi (constructeur de copie) :
    // Vérifie si le trajet composé est valide c'est-à-dire si 
    // la destination d'une escale correspond au départ
    // de l'escale suivante. 

//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const TrajetCompose & unTrajetCompose ) = default;

    TrajetCompose ( );
    // Mode d'emploi :
    // Constructeur de TrajetCompose. 

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    // Destructetur de TrajetCompose. 

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
    ChainList trajetsSimples;
};


#endif // TRAJETCOMPOSE_H

