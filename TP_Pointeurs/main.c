#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {
	Menu menu = { "appel" };
	Application appli = {"Instagram",{&menu}, 1};

	printf("%s %s %s %d", menu.option, appli.nom, appli.menus[0].option, appli.nb_menus);
	return 0;
}