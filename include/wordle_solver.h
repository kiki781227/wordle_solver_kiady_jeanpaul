#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#define NBMOTS 2309
#define Len_Mot 6


void Tab_mots(char Mots[][Len_Mot]);

void Sub_Filter(char sub[], char tab_mot[][Len_Mot]);

void Ajout_Lettre(char Lettres[], char Tab[][Len_Mot]);

void Retrait_Lettre(char Lettres[], char Tab[][Len_Mot]);

void Commence_Par(char Lettres[], char Tab[][Len_Mot]);
