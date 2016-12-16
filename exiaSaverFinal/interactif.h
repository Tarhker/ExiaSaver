#ifndef INTERACTIF_H_INCLUDED
#define INTERACTIF_H_INCLUDED
#define NB_COLONNES 80
#define NB_LIGNES 23

void afficherAvion(int x, int y, FILE *fichierPbm);
void initialiserAvion(FILE *fichierPbm, int x, int y);
void deplacerAvion(int x, int y, FILE *fichierPbm);

#endif
