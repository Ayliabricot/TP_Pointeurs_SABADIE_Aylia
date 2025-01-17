#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void displayMenu(const Application* app){
	printf("--- %s ---\n",app->nom);
	for (int i = 0; i < app->nb_menus; i++) {
		printf("%d. %s\n",i+1, app->menus[i].option);
	}
}

int main() {
	Menu menu1 = { "Regarder une photo" };
	Menu menu2 = { "Prendre une photo" };
	Menu photoMenus[] = {menu1, menu2};
	Application photoApp = {"Photos",photoMenus, 2};

	displayMenu(&photoApp);

	return 0;
}