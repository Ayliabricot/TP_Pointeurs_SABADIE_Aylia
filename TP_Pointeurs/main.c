#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "header.h"

int main() {
	Menu menuPhotos1 = { "Regarder une photo" };
	Menu menuPhotos2 = { "Prendre une photo" };
	Menu photoMenus[] = {menuPhotos1, menuPhotos2};
	Application photoApp = {"Photos",photoMenus, 2};

	Menu menuMessages1 = { "Lire un message" };
	Menu menuMessages2 = { "Envoyer un message" };
	Menu messageMenus[] = { menuMessages1, menuMessages2 };
	Application messageApp = { "Messages",messageMenus, 2 };

	runPhone(&photoApp,&messageApp);

	return 0;
}