#include "fonction.c"

int main() {
	
	char tab[NBMOTS][Len_Mot], Lettres[Len_Mot];
	int choix_filter, choix = 1, nbAff;
	Tab_mots(tab);
	
	printf("Voilà tous les mots présents dans la base de donnée : \n");
	for (int i = 0; i < NBMOTS; i++) {
		if ( i % 10 == 0) printf("\n");
		printf("%s\t", tab[i]);
	}
	
	printf("\n\n");
	
	while(choix) {
		
		printf("Quel filtre voulez vous utilisez ?\n");
		printf("Taper 1 (filtre ajout lettre), 2 (Filtre retrait lettre), 3 (Filtre Substring) ou 4 (Commence par) : ");
		scanf("%d", &choix_filter);
		
		switch(choix_filter) {
			case 1: 
				printf("Entrer la ou les lettre(s) : ");
				scanf("%s", Lettres);
				for (int i = 0; i < (int)strlen(Lettres); i++) Lettres[i] = tolower(Lettres[i]);
				Ajout_Lettre(Lettres, tab);
				break;
			
			case 2: 
				printf("Entrer la ou les lettre(s) : ");
				scanf("%s", Lettres);
				for (int i = 0; i < (int)strlen(Lettres); i++) Lettres[i] = tolower(Lettres[i]);
				Retrait_Lettre(Lettres, tab);
				break;
				
			case 3: 
				printf("Entrer la ou les lettre(s) : ");
				scanf("%s", Lettres);
				for (int i = 0; i < (int)strlen(Lettres); i++) Lettres[i] = tolower(Lettres[i]);
				Sub_Filter(Lettres, tab);
				break;
			
			case 4: 
				printf("Entrer la ou les lettre(s) : ");
				scanf("%s", Lettres);
				for (int i = 0; i < (int)strlen(Lettres); i++) Lettres[i] = tolower(Lettres[i]);
				Commence_Par(Lettres, tab);	
				break;
					
			default: 
				printf("\nChoix invalide.\n\n");
				continue;
		}
		
		printf("\nVoilà tous les mots valident après avoir passé ce filtre : \n");
		
		nbAff = 0;
		for (int i = 0; i < NBMOTS; i++) {
			
			if ( tab[i][0] != '\0' ) {
				
				if ( nbAff % 10 == 0)
					printf("\n");
				
				printf("%s\t", tab[i] );
				nbAff += 1;
			}
		}
		
		printf("\n\n");
		
		
		printf("Voulez vous continuer le filtre ? (1 pour oui et 0 pour non) : ");
		scanf("%d", &choix );
		printf("\n");
		
	}
}
