#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "header.h"

int main() {
	Menu menu1 = { "Regarder une photo" };
	Menu menu2 = { "Prendre une photo" };
	Menu photoMenus[] = {menu1, menu2};
	Application photoApp = {"Photos",photoMenus, 2};

	runApplication(&photoApp);

	return 0;
}