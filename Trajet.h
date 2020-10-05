/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/

//------- Interface de la classe <Trajet> (fichier Trajet.h) -------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// La classe Trajet est une classe abstraite et mère de deux autres 
// classes : TrajetSimple et TrajetCompose.
// Elle ne possède aucun attribut et toutes ses méthodes sont rédéfinies
// dans les classes filles. 
//------------------------------------------------------------------------

class Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher( void ); 
    // Mode d'emploi :
    // Affiche un trajet.
    // Elle est redéfinie par les classes TrajetSimple et TrajetCompose.

    virtual char * GetDepart();
    // Mode d'emploi :
    // Affiche un trajet.
    // Elle est redéfinie par les classes TrajetSimple et TrajetCompose.
    
    virtual char * GetDestination();
    // Mode d'emploi :
    // Affiche un trajet.
    // Elle est redéfinie par les classes TrajetSimple et TrajetCompose.

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet ) = default;

    Trajet ( );
    // Mode d'emploi :
    // Constructeur d'un Trajet. 

    virtual ~Trajet ( );
    // Mode d'emploi :
    // Destructeur d'un Trajet. 

//------------------------------------------------------------------ PRIVE

protected:

};

#endif // TRAJET_H

