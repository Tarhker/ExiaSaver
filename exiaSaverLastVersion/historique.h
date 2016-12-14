#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED

void initialiserHistorique(FILE *fichierHistorique, int type);

struct tm* localtime (const time_t *secondes);
struct tm date;

#endif
