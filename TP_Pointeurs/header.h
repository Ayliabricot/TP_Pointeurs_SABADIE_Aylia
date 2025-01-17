#ifndef TELEPHONE
#define TELEPHONE

typedef struct {
	const char* option;
}Menu;

typedef struct {
	const char* nom;
	Menu* menus;
	int nb_menus;
}Application;

#endif
