#ifndef MONPROJET_H_INCLUDED
#define MONPROJET_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char chaine[255];

typedef struct Vol{
  int idVol;
  int idAvion;
  int idPilote;
  chaine Heure_Depart;
  chaine Heure_Arrivee;
  int aero_Depart;
  int aero_Arrivee;
  struct Vol* next;
}VOL;
typedef VOL* ListeVol;

void charger_Table_Vol(ListeVol* V);
ListeVol creer_maillonVol(int idVol,int idAVion,int idPilote, chaine H_D,chaine H_A,int aero_D,int aero_A);
int existeVol(ListeVol *V,int idVol);
//void insererVol(ListeVol *V,ListeAvion Av,ListePilote P,int idVol,int idAVion,int idPilote, chaine H_D,chaine H_A,int aero_D,int aero_A);
//void supprimerVol(ListeVol V ,int idVol);
void afficherVol(ListeVol);


typedef struct Pilote{
  int idPilote;
  chaine nom;
  chaine prenom;
struct Pilote* next;
}PILOTE;
typedef PILOTE* ListePilote;
typedef struct tPilote{
  int idPilote;
  chaine nom;
  chaine prenom;
}tPILOTE;
typedef tPILOTE* tabPilote;
int existePilote(ListePilote ,int);
ListePilote creer_maillonPilote(int,chaine,chaine );
int existePiloteVole(ListeVol, int);
void supprimerPilote(ListePilote *,ListeVol,int);
void afficher_tabpilote(tabPilote ,int );
void charger_Table_Pilote(ListePilote *);
void afficher_Pilote(ListePilote );
void inserer_Pilote(ListePilote*,int,chaine,chaine);
int longList(ListePilote);
tabPilote tlt(ListePilote ,int *);
ListePilote ttl(tabPilote , int);
void trie(tabPilote , int );
//void decharger_Table_Pilote(ListePilote);
//********************************

#endif
