/*************************************************************************
                           Application  -  description
                             -------------------
    début                : 01/10/2020
    copyright            : (C) 2020 par Terekhov Nikita et Lecuyer Alison
    e-mail               : nikita.terekhov@insa-lyon.fr 
                         : alison.lecuyer@insa-lyon.fr
*************************************************************************/


//------ Interface du module <Application> (fichier Application.h) --------
#if ! defined ( APPLICATION_H )
#define APPLICATION_H

//------------------------------------------------------------------------
// Rôle du module <Application>
// Le module <Application> permet d'intéragir avec l'utilisateur et 
// les différentes classes de l'application, notamment avec le catalogue. 
//------------------------------------------------------------------------


//--------------------------------------------------- Interfaces utilisées
#include "Catalogue.h"

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
static void  BouclePrincipale(Catalogue &catalogue);
  // Mode d'emploi :
  // C'est la méthode qui est appelée lors du démarage de l'application.
  // Elle affiche le menu, appelle la méthode TraiterDemande et en 
  // en fonction de ce qu'à retourner cette méthode, elle affiche 
  // à nouveau le menu et rappelle la méthode ou bien quitte l'application.

static void AfficherMenu();
  // Mode d'emploi : 
  // Affiche le menu de l'application. 

static char ScannerChar();
  // Mode d'emploi : 
  // Scanne un caractère.

static int TraiterDemande(Catalogue &catalogue); 
  // Mode d'emploi : 
  // Récupère l'option choisie par l'utilisateur et la traite. 
  // Cette méthode retourne n'importe quel nombre si l'application doit 
  // continuer à tourner, et 0 si l'application doit s'arrêter. 

static void AjouterTrajet(Catalogue &catalogue); 
  // Mode d'emploi : 
  // Méthode qui gère les entrées/sorties lors de l'ajout d'un trajet.
  // Appelle différentes méthodes en fonction de si l'utilisateur  
  // souhaite ajouter un trajet simple ou un trajet complexe.

static void AjouterTrajetSimple(Catalogue &catalogue); 
  // Mode d'emploi :
  // Méthode appelée lorsque l'utilisateur souhaite ajouter un trajet 
  // simple au catalogue.
  // Récupère la ville de départ, la ville d'arrivée et le moyen de transport
  // puis appelle la méthode du catalogue pour rajouter le trajet.

static void AjouterTrajetCompose(Catalogue &catalogue); 
  // Mode d'emploi :
  // Méthode appelée lorsque l'utilisateur souhaite ajouter un trajet  
  // composé au catalogue.
  // Récupère pour chaque trajet simple qui compose le trajet composé
  // la ville de départ, la ville d'arrivée et le moyen de transport.
  // Enfin, elle appelle la méthode du catalogue pour rajouter le trajet.

static void RechercherTrajet(Catalogue &catalogue);
  // Mode d'emploi
  // Méthode appelée lorsque l'utilisateur souhaite rechercher un trajet.
  // Récupère le départ et la destination, 
  // puis appelle la méthode RechercherTrajet du catalogue 

static void RechercherTrajetAvance(Catalogue &catalogue);
  // Mode d'emploi
  // Méthode appelée lorsque l'utilisateur souhaite rechercher un trajet.
  // Récupère le départ et la destination, 
  // puis appelle la méthode RechercheAvance du catalogue 
  // Utilisation d'un algorithme plus poussé que la méthode RechercherTrajet. 

#endif // Application_H