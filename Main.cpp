/*************************************************************************
                           Main  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $ANNEE$ par $AUTEUR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) -------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Main.h"
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

static Catalogue catalogue; 

//------------------------------------------------------ Fonctions privées

static void  BouclePrincipale() 
{
  bool doitContinuer = true;

  while(doitContinuer)
  {
    cout << endl; 
    cout << endl; 
    cout << endl; 
    AfficherMenu();
    doitContinuer = TraiterDemande(); // demander, exécuter, et retourne 0 si stop, 1 (ou autre) si continuer
  }
}

static void AfficherMenu() 
// Mode d'emploi : 
// Affiche le menu de l'application. 
{
  cout << "-------------------------------------------------------------------------" << endl; 
  cout << "Menu : " << endl; 
  cout << "1 - Ajouter un trajet au catalogue." << endl;
  cout << "2 - Afficher le catalogue." << endl;
  cout << "3 - Rechercher un trajet." << endl;
  cout << "4 - Quitter." << endl; 
  cout << "Veuillez entrer le numéro de l'action que vous souhaitez réaliser :" << endl; 
  cout << "-------------------------------------------------------------------------" << endl; 

}

static char ScannerChar() 
// Mode d'emploi : 
// Scanne un caractère.
{
  char test[150];
  cin.getline(test, 150);
  return test[0]; 
}

static int TraiterDemande() 
// Mode d'emploi : 
// Récupère l'option choisie par l'utilisateur et la traite. 
// Cette méthode raffiche le menu et se rappelle elle-même pour retraiter l'option choisie par l'utilisateur. 
{
  char optionChoisie = ScannerChar(); 
  switch (optionChoisie)
  {
    case '1':
      AjouterTrajet(); 
      break;
    case '2':
      cout << "Trajets du catalogue : " << endl; 
      catalogue.Afficher();
      break;
    case '3':
      RechercherTrajet(); 
      break;
    case '4':
      cout << "Au revoir !" << endl; 
      return 0;
    default:
      cout << "Action impossible. Veuillez choisir un numéro entre 1 et 4." << endl;
  }

  return 1;
}

static void AjouterTrajet() 
// Mode d'emploi : 
// Méthode qui gère les entrées et les sorties lors de la construction du catalogue
// Appelle différentes méthodes en fonction de si l'utilisateur souhaite ajouter un trajet simple ou un trajet complexe
{
  cout << "Voulez-vous ajouter un trajet simple ou un trajet composé ? Entrez S pour simple ou C pour composé." << endl;
  char typeTrajet = ScannerChar(); 
  switch (typeTrajet)
  {
    case 'S':
      AjouterTrajetSimple();
      break;

    case 'C':
      AjouterTrajetCompose();
      break;
    
    default:
      cout << "Les seuls options possibles sont S ou C. " << endl; 
      AjouterTrajet(); 
      break;
  }
  
}

static void AjouterTrajetSimple() 
// Mode d'emploi :
// Méthode appelée lorsque l'utilisateur souhaite ajouter un trajet simple au catalogue
// Récupère la ville de départ, la ville d'arrivée et le moyen de transport, puis appelle la méthode du catalogue pour rajouter le trajet 
{
  char * depart = new char[150];
  char * destination = new char[150]; 
  char * moyenTransport = new char[150]; 

  cout << "Départ du trajet : "; 
  cin.getline(depart,150);

  cout << "Destination du trajet : "; 
  cin.getline(destination,150);

  cout << "Moyen de transport du trajet du trajet : ";
  cin.getline(moyenTransport,150);

  //cout << "Trajet ajouté : " << endl << "    Départ : " << depart << endl << "    Destination : " << destination << endl << "    Moyen de transport : " << moyenTransport << endl; 

  catalogue.Ajouter(catalogue.CreerTrajetSimple(depart,destination,moyenTransport));
}

static void AjouterTrajetCompose() 
// Mode d'emploi :
// Méthode appelée lorsque l'utilisateur souhaite ajouter un trajet simple au catalogue
// Récupère la ville de départ, la ville d'arrivée puis chaque trajet simple
// Enfin, elle appelle la méthode du catalogue pour rajouter le trajet 
{
  char continuer = 'O';
  int nbEscales = 0;
  Trajet * pt_trajetCompose = catalogue.CreerTrajetCompose(); 

  while(continuer == 'O') {
    char * dep = new char[150];
    char * dest = new char[150]; 
    char * moyenTransport = new char[150];

    cout << "Départ de l'escale numéro " << nbEscales + 1 << " : ";
    cin.getline(dep,150);

    cout << "Destination de l'escale numéro : " << nbEscales + 1 << " : ";
    cin.getline(dest,150);

    cout << "Moyen de transport de l'escale numéro : " << nbEscales + 1 << " : ";
    cin.getline(moyenTransport,150);

    dynamic_cast<TrajetCompose*>(pt_trajetCompose)->AjouterEscale(catalogue.CreerTrajetSimple(dep,dest,moyenTransport));

    cout << "Voulez vous ajouter une autre escale ? O pour oui, N pour non." << endl;
    continuer = ScannerChar();
    while(continuer != 'O' && continuer != 'N'){
      cout << "Action impossible. Veuillez entrer O pour oui ou N pour non " << endl; 
      continuer = ScannerChar();
    }
    nbEscales++; 
  } 

  catalogue.Ajouter(pt_trajetCompose);
  /*if(pt_trajetCompose->EstValide()) {
    cout << "Votre voyage n'est pas valide." << endl; 
  }else {
    catalogue.Ajouter(pt_trajetCompose);
  }*/
}

static void RechercherTrajet() 
// Mode d'emploi
// Méthode appelée lorsque l'utilisateur souhaite rechercher un trajet 
// Récupère le départ et la destination, puis appelle la méthode RechercherTrajet dans le catalogue 
{
  char depart[150];
  char destination[150]; 

  cout << "D'où voulez-vous partir ?" << endl; 
  cin.getline(depart,150);

  cout << "Où voulez-vous aller ?" << endl; 
  cin.getline(destination,150);

  cout << "Vous pouvez prendre le(s) trajet(s) suivants : " << endl; 
  catalogue.Rechercher(depart, destination);
}


//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main() 
{
  /*char depart[10];
  char destination[10];
  char moyenTransport[10];

  cout << "D'où voulez-vous partir ?" << endl; 
  cin >> depart;
  cout << "Où voulez-vous aller ?" << endl; 
  cin >> destination; 
  cout << "Quel moyen de transport souhaitez-vous utiliser ?" << endl; 
  cin >> moyenTransport;

  Trajet * pt = new TrajetSimple(depart,destination,moyenTransport);
  pt->Afficher(); */
  
  BouclePrincipale();
  return 0; 
}
