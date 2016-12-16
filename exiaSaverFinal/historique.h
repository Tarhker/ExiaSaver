#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED

void initialiserHistoriqueStatique(FILE *fichierHistorique, int type, char imageChoisie[12]);
void initialiserHistoriqueInteractif(FILE *fichierHistorique, int type, int x, int y);

struct tm* localtime (const time_t *secondes);
struct tm date;

#endif
