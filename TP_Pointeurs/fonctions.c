#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void displayMenu(const Application* app) {
	printf("--- %s ---\n", app->nom);
	for (int i = 0; i < app->nb_menus; i++) {
		printf("%d. %s\n", i + 1, app->menus[i].option);
	}
}

void runApplication(const Application* app) {
	int continuer = 10;
	while (continuer == 10) {
		displayMenu(app);
		int choix;
		printf("Choisissez une option (0 pour quitter) : ");
		scanf_s("%d", &choix);
		if (choix == 0) {
			system("cls");
			printf("Vous avez quitte.");
			continuer = 0;
		}
		else if (choix > 0 && choix < app->nb_menus + 1) {
			printf("Vous avez selectionne : %s\n\n", app->menus[choix - 1].option);
		}
	}
}