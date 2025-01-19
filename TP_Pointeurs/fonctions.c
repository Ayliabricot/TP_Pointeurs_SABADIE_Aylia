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
			continuer = 0;
		}
		else if (choix > 0 && choix < app->nb_menus + 1) {
			printf("Vous avez selectionne : %s\n\n", app->menus[choix - 1].option);
		}
	}
}

void runPhone(Application* app1, Application* app2) {
	int choix = 10;
	while (choix > 0)
	{
		printf("--- Applications ---\n");
		printf("1. %s\n2. %s\n3. Modifier le menu de '%s'\n4. Modifier l'application '%s'\n0. Quitter\nVotre action : ", app1->nom, app2->nom, app1->nom, app2->nom);
		scanf_s("%d", &choix);

		if (choix == 1) {
			system("cls");
			runApplication(app1);
		}
		else if (choix == 2) {
			system("cls");
			runApplication(app2);
		}
		else if (choix == 3) {
			system("cls");
			displayMenu(app1);
			int menuIndex;
			char newOption[100];
			printf("Choisissez l'index du menu a modifier : ");
			scanf_s("%d", &menuIndex);
			printf("Choisissez la nouvelle option : ");
			getchar();
			fgets(newOption, sizeof(newOption), stdin);
			newOption[strcspn(newOption, "\n")] = 0;
			updateMenu(app1, menuIndex, strdup(newOption));
		}
		else if (choix == 4) {
			system("cls");
			char nomApp[100];
			char option[100];
			int i = 1;
			int nbMenus = 0;
			Menu nouveauMenus[100];

			printf("Quel est le nom de l'application : ");
			getchar();
			fgets(nomApp, sizeof(nomApp), stdin);
			nomApp[strcspn(nomApp, "\n")] = 0;

			while (1) {
				printf("Choisissez l'option %d du menu (ou 0 pour quitter) : ", i);
				fgets(option, sizeof(option), stdin);
				option[strcspn(option, "\n")] = 0;
				if (option[0] == '0') {
					break;
				}
				nouveauMenus[i - 1].option = strdup(option);
				i++;
			}
			nbMenus = i - 1;
			updateApplication(app2, strdup(nomApp), nouveauMenus, nbMenus);
		}
		else if (choix == 0) {
			system("cls");
			printf("Vous avez quitte.");
		}
	}
}

void updateMenu(Application* app, int menuIndex, const char* newOption) {
	while (1) {
		if (menuIndex <= 0 || menuIndex > app->nb_menus) {
			printf("L'index est invalide : veuillez entrer un nombre entre 1 et %d\n", app->nb_menus);
			continue;
		}
		app->menus[menuIndex - 1].option = newOption;
		printf("L'option a ete mise a jour.\n");
		break;
	}
}

void updateApplication(Application* app, const char* newName, Menu* newMenus, int newMenuCount) {
	app->nom = newName;
	app->menus = newMenus;
	app->nb_menus = newMenuCount;
	printf("L'application a ete mise a jour.\n");
}