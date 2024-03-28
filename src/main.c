int main()
{
	char tab[NBMOTS][Len_Mot], NewTab[][Len_Mot], char Lettres[];
	int choix_filter, choix=1;
	Tab_mots(tab);
	
	for(int= 0; i<NBMOTS; i++) printf("%s\t", tab[i]);
	
	while(choix)
	{
		printf("Quel filtre voulez vous utilisez ? \n");
		printf("Taper 1 (filtre ajout lettre), 2 (Filtre retrait lettre), 3 (Filtre Substring) ou 4 (Commence par): ");
		scanf("%d", choix_filter);
		
		switch(choix_filter)
		{ 	case 1: printf("Entrer la ou les lettre(s): ");
					scanf("%s", Lettres);
					Ajout_Lettre(Lettres, tab);
					break;
			
			case 2: printf("Entrer la ou les lettre(s): ");
					scanf("%s", Lettres);
					Retrait_Lettre(Lettres, tab);
					break;
					
			case 3: printf("Entrer la ou les lettre(s): ");
					scanf("%s", Lettres);
					Sub_Filter(Lettres, tab);
					break;
			
			case 4: printf("Entrer la ou les lettre(s): ");
					scanf("%s", Lettres);
					Ajout_Lettre(Lettres, tab);	
					
			default: printf("Choix invalide");					
		
		}
		
		Lettres= NULL;
		
		for(int i=0; i<NBMOTS; i++) printf("%s/t", tab ); printf("\n");
		
		printf("Voulez vous continuer le filtre ? (1 pour oui et 0 pour non: )");
		scanf("%d", choix ); printf("\n);
	}
}
