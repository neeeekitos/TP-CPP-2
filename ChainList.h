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
    /**
     * Ajoute un trajet passé en paramètre dans une liste chainée
     *  
     * @param trajet de Trajet, le trajet à ajouter.
     */

    Element * RechercherElement(char * depart, char * destination);
    /**
     * Recherche une structure Element avec un Trajet
     * correspondant au depart et à la destination
     * passés en paramètre.
     *  
     * @param depart depart du trajet.
     * @param destination l'arriveé du trajet.
     * @return Element avec un attribut data contenant le trajet
     */

    Element * RechercherElement(Trajet * tr);
    /**
     * Recherche une structure Element avec un Trajet
     * correspondant à un trajet passé en paramètre. 
     * Cette méthode compare le départ et la destination 
     * du trajet.
     *  
     * @param tr Instance du type Trajet
     * @return Element avec un attribut data contenant le trajet
     */

    ChainList * RechercherParcours(char * depart, char * destination);
    /**
     * Recherche et retourne une liste de trajets qui ont le départ 
     * et la destination corresponants à ceux passés dans les 
     * paramètres.
     *  
     * @param depart depart du trajet.
     * @param destination l'arriveé du trajet.
     * @return liste chainée du type ChainList avec les trajets recherchés.
     */

    Element * GetSuivantElement(Element * elem);
    /**
     * Retourne un élement suivant dans la liste après 
     * celui passé dans le paramètre.
     *  
     * @param elem Instance du Type Element contenant un trajet.
     * @return Element suivant avec un attribut data contenant le trajet.
     */

    Element * GetPremierElement();
    /**
     * Retourne un premier élement de la liste.
     *  
     * @return un premier élement de la liste du type Element.
     */

    Element * GetDernierElement();
    /**
     * Retourne un premier élement de la liste.
     *  
     * @return un premier élement de la liste du type Element.
    */

    ChainList * CopyList();
    /**
     * Fait une copie en surface de la liste qui invoque la méthode.
     * Tous les élements d"un nouvelle liste pointent sur les élements
     * de l'ancienne, donc avant de l'effacer il faut appeler une méthode 
     * RetirerAll(), afin de ne pas effacer les élements de la liste de base.
     *  
     * @return une liste chainée du type ChainList
    */

    bool RetirerElement(Trajet * tr);
    /**
     * Retire un struct Element dont l'attribut data contenant
     * un trajet correspond à un trajet passé en paramètre
     * (si le départ et destination sont égaux).
     *  
     * @param tr Instance du type Trajet à retirer de la liste
     * @return bool , true si un élement à été trouvé et retiré, false sinon.
    */

    void RetirerAll();
    /**
     * Retire tous les élements de la liste, sans les détruire.
    */

    void InsererListe(ChainList * listeAInserer);
    /**
     * Insère une liste dans celle qui appelle la méthode.
     *  
     * @param listeAInserer liste à insérer.
    */
   

    int GetNbElements();
    /**
     * Retoune le nombre d'éléments dans la liste.
     * @return le nombre d'éléments.
    */
   

//-------------------------------------------- Constructeurs - destructeur
    ChainList ( );
    // Constructeur de TrajetCompose. 

    virtual ~ChainList ( );
    // Destructeur de TrajetCompose. 

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    Element * tete, * queue;
    int nbElements = 0;
};


#endif // CHAINLIST_H

