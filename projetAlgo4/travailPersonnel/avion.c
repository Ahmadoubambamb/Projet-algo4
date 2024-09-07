#include "monprojet.h"
ListeVol creer_maillonVol(int idVol,int idAvion,int idPilote ,chaine H_D,chaine H_A,int aero_D,int aero_A)
 {
    ListeVol m=(ListeVol)malloc(sizeof(VOL));
    if (m == NULL) {
        printf("Erreur d'allocation mémoire");
        exit(-1);
    }
    m->idVol = idVol;
    m->idAvion=idAvion ;
    m->idPilote=idPilote;
    strcpy(m->Heure_Depart, H_D);
    strcpy(m->Heure_Arrivee, H_A);
    m->aero_Depart=aero_D;
    m->aero_Arrivee=aero_A;
    m->next = NULL;
    return m;
}
void charger_Table_Vol(ListeVol* V) {
    FILE* fp4 = fopen("fichierVol.txt","r");
    if (fp4 == NULL) {
        printf("Erreur lors de l'ouverture du fichier");
        exit(-1);
    }
    int idVol,idAVion,idPilote ;
    chaine Heure_Depart, Heure_Arrivee;
    int aero_Depart,aero_Arrivee;
    ListeVol tmp=NULL;
    while (fscanf(fp4,"%d %d %d %s %s %d %d",&idVol,&idAVion,&idPilote,Heure_Depart,Heure_Arrivee,&aero_Depart,&aero_Arrivee) == 7)
        {
           if(*V==NULL)
                tmp=*V=creer_maillonVol(idVol,idAVion,idPilote,Heure_Depart,Heure_Arrivee,aero_Depart,aero_Arrivee);
           else{
            tmp->next=creer_maillonVol(idVol,idAVion,idPilote,Heure_Depart,Heure_Arrivee,aero_Depart,aero_Arrivee);
            tmp=tmp->next;
    }
  }
  fclose(fp4);
  printf("La table Vol a été chargée avec succès.\n");
}
int existeVol(ListeVol *V,int idVol) {
    ListeVol courant = *V;
    while (courant != NULL) {
        if (courant->idVol == idVol){
            return 1;
            }
        courant = courant->next;
    }
    return 0;
}
/*void insererVol(ListeVol* V,ListeAvion Av,ListePilote PL,int idVol,
                int idAvion,int idPilote,chaine H_D,chaine H_A,int aero_D,int aero_A) {
    if (!existeAvion(Av,idAvion)) {
        printf("Erreur : Avion avec Id %d introuvable.\n",idAvion);
        return;
    }
    if (!existePilote(PL, idPilote)){
        printf("Erreur : Pilote avec Id %d introuvable.\n",idPilote);
        return;
    }
    if(existeVol(*V,idVol)){
        printf("le vol avec id %d existe  deja.\n",idVol);
        return;
    }
    ListeVol nVol=creer_maillonVol(idVol,idAvion,idPilote,H_D,H_A,aero_D,aero_A);
    nVol->next=*V;
    *V= nVol;
}*/
void afficherVol(ListeVol V){
  ListeVol temp=V;
   printf("l'affichage de la liste des Vols:\n");
   printf("***********************************\n");
  while(temp!=NULL){
    printf("%d %d %d %s %s %d %d\n",temp->idVol,temp->idAvion,temp->idPilote,temp->Heure_Depart,temp->Heure_Arrivee,temp->aero_Depart,temp->aero_Arrivee);
    temp=temp->next;
  }
  printf("\n");
  printf("***********************************\n");
}
/*void supprimerVol(ListeVol V ,int idvol)
{
 ListeVol cour=V,prec=NULL,nex;
 if(cour==NULL)
  {
   printf("LA TABLE EST VIDE \n");
   return;
  }
  if(V->idVol==idvol)
  {
   prec=V;
   V=cour->next;
  }
    while(cour!=NULL)
     {
       nex=prec;
       prec=cour;
       cour=cour->next;
       if(prec->idVol==idvol)
           nex->next=cour;
     }
prec->next=NULL;
free(prec);
}
*/
