#include "monprojet.h"
int main()
{ListePilote p=NULL,Tl=NULL;
    ListeVol v=NULL;
    charger_Table_Vol(&v);
    afficherVol(v);
    charger_Table_Pilote(&p);
    afficher_Pilote(p);
    int id ; chaine nom ,prenom;
    printf("donner l'id le nom et le prenom: ");
    scanf("%d%s%s",&id,nom,prenom);
    inserer_Pilote(&p,id,nom,prenom);
    afficher_Pilote(p);
    tabPilote t=NULL; int n=0;
    t=tlt(p,&n);
    printf("apres transfert vers tableu :\n");
    afficher_tabpilote(t,n);
    trie(t,n);
    printf("Apres trie on a :\n");
    afficher_tabpilote(t,n);
    /*printf("apres transfert vers liste :\n");
    Tl=ttl(t,n);
    afficher_Pilote(Tl);
    printf("donner l'id a supprimer :");
    scanf("%d",&id);
   supprimerPilote(&p,v,id);
    afficher_Pilote(p);
   // decharger_Table_Pilote(p);
                           */
    return 0;
}
