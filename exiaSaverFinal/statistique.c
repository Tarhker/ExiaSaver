#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> //Permet de créer des chaines de caracteres
#include "statique.h"
#include "statistique.h"

void statistiques(){

    FILE* fichierHistorique = NULL;                             //Ouvre historique en lecture
    fichierHistorique = fopen ("historique.txt", "r");

    int type1 = 0;
    int type2 = 0;
    int type3 = 0;
    char buffer;
    char caractereLu;

    while((caractereLu = fgetc(fichierHistorique)) !=EOF){   //lit le fichier caractère par caractère

        if (caractereLu == ';'){                            //Quand il trouve le ; il regarde le chiffre d'après

            caractereLu = fgetc(fichierHistorique);

            if (caractereLu == '1'){                        //Et compte les occurences des types sortis
                type1++;
            }
            else if (caractereLu == '2'){
                type2++;
            }
            else if (caractereLu == '3'){
                type3++;
            }

            do{
                caractereLu = fgetc(fichierHistorique);
            } while (caractereLu != '\n');
        }
    }

    printf("il y a eu %d de types statiques\n", type1);
    printf("il y a eu %d de types dynamiques\n", type2);
    printf("il y a eu %d de types interractifs\n", type3);
}





/*void triParType (){

    FILE* fichierHistorique = NULL;                             //Ouvre historique en lecture
    fichierHistorique = fopen ("historique.txt", "r");
    FILE* fichierHistorique = NULL;                             //Ouvre historique en lecture
    fichierHistorique = fopen ("statistique.txt", "w");


    //int nLignes = 0;                        //Variable
    //char* buffer;
    //char* verifType;

    char buffer;
    char caractereLu;

    //int i;
    //int j;
    //char* buffer;



    /*if (fichierHistorique != NULL){                     //Trouve le nombres de lignes
            int c;
        while((c=fgetc(fichierHistorique)) != EOF)
        {
            if(c=='\n'){
            nLignes++;
            }
        }
    }
    else{
        printf("Erreur:le fichier est vide");           //Affiche une erreur si le fichier est vide
        exit(0);
    }
    printf("%d", nLignes);*/


    /*while ((buffer = getc (fichierHistorique)) != '\n'){ // lit le fichier ligne par ligne
        verifType = strstr(buffer, ";3;");
        if (verifType != NULL )//&& verifType[1]==3)
        {
            fprintf(fichierStatistique,"%d\n",buffer);
            type3++;
        }

    }*/



    /*while ((buffer = getc (fichierHistorique)) != '\n'){ // lit le fichier ligne par ligne
        verifType = strstr(buffer, ";2;");
        if (verifType != NULL && verifType[1]==2)
        {
            fprintf(fichierStatistique,"%d\n",buffer);
            type2++;
        }

    }


    while ((buffer = getc (fichierHistorique)) != '\n'){ // lit le fichier ligne par ligne
        verifType = strstr(buffer, ";1;");
        if (verifType != NULL && verifType[1]==1)
        {
            fprintf(fichierStatistique,"%d\n",buffer);
            type1++;
        }

    }

    fprintf (fichierStatistique,"\nIl y a eu %d types statiques, %d types dynamiques et %d types interractifs", type1, type2, type3); //compte les types exécutés
    fclose(fichierHistorique);
    fclose (fichierStatistique)
}





/*void triChronologique(){

    char buffer;
    char* verifType;
    int type1 = 0;
    int type2 = 0;
    int type3 = 0;


    FILE* fichierHistorique = NULL;                             //Ouvre historique en lecture
    fichierHistorique = fopen ("historique.txt", "r");

    FILE* fichierStatistique = NULL;                            //Ouvre statique en écriture
    fichierStatistique = fopen ("fichierStatistique.txt", "w");

    while ((buffer = getc (fichierHistorique)) != '\n'){ // lit le fichier ligne par ligne
            fprintf(fichierStatistique,"%d\n",buffer);  // ecrit dans le fichier statistique
            verifType = strtok (buffer, ";");

            switch (verifType){

                case 1:
                    type1++;
                    break;
                case 2:
                    type2++;
                    break;
                case 3:
                    type3++;
                    break;

            }
    }

    fprintf (fichierStatistique,"\nIl y a eu %d types statiques, %d types dynamiques et %d types interractifs", type1, type2, type3);

    fclose(fichierHistorique);
    fclose (fichierStatistique);
}
*/


