#include "../include/wordle_solver.h"


void Tab_mots(char Mots[][Len_Mot]) {
    FILE* Fichier = fopen("../ressources/bdd_wordle.txt", "r");
    
    int iMot = -1;
    for (char Car = 'A'; Car <= 'Z'; Car++) { // 'Car' prend en valeur 'A', puis 'B', puis 'C', ect jusqu'à 'Z'
		
		if ( Car == 'X' ) continue; // Il n'y a pas de mot en X donc on passe
		
		while ( (fgetc(Fichier) != Car) || (fgetc(Fichier) != 13) ); // On vérifie si le caractère qu'on lit est la lettre majuscule correspondante et si le caractère suivant est un retour à la ligne
		
		for (int i = 0; i < 7; i++) fgetc(Fichier); // On passe les 7 caractères qui sont après la lettre Majuscule
		
		do {
			iMot += 1;
			fgets(Mots[iMot], Len_Mot, Fichier); // On lie un mot de Len_Mot caractères (les 5 lettres et le '\0')
			fgetc(Fichier); // On passe l'espace qui suit
		} while ( isalpha(Mots[iMot][0]) ); // On vérifie si le premier caractère lu est une lettre, si non on sait qu'il ne s'agit pas d'un mot, on j'arrete donc là
		
		iMot -= 1; // On revient à l'indice précédent car la dernière chaine de caractère lu n'est pas un mot;
	}
	
	fclose(Fichier);

}

void Sub_Filter(char sub[], char tab_mot[][Len_Mot]) {
	
	for (int i = 0 ; i < NBMOTS; i++)	
		if ( strstr(tab_mot[i], sub) == NULL )
			tab_mot[i][0] = '\0';	
}


void Ajout_Lettre(char Lettres[], char Tab[][Len_Mot]) {
	
	int ifLettre;
	for ( int iMot = 0; iMot < NBMOTS; iMot++) {
		ifLettre = 0;
		
		for (unsigned int i = 0; i < strlen(Lettres); i++ )
			if ( strchr(Tab[iMot], Lettres[i]) == NULL ) {
				ifLettre = 1;
				break;
			}
		
		if ( ifLettre ) Tab[iMot][0] = '\0';
	}
}

void Retrait_Lettre(char Lettres[], char Tab[][Len_Mot]) {
	
	for (int iMot = 0; iMot < NBMOTS; iMot++)
		
		for (unsigned int i = 0; i < strlen(Lettres); i++ )
			if ( strchr(Tab[iMot], Lettres[i]) != NULL ) {
				Tab[iMot][0] = '\0';
				break;
			}
}

void Commence_Par(char Lettres[], char Tab[][Len_Mot]) {
	
	int nbLettres = strlen(Lettres);
	char mot[nbLettres+1];
	
	for ( int iMot = 0; iMot < NBMOTS; iMot++) {
		
		for (int i = 0; i < nbLettres; i++)
			mot[i] = Tab[iMot][i];
		mot[nbLettres] = '\0';
		
		if ( strcmp(mot, Lettres) ) Tab[iMot][0] = '\0';
	}

}
