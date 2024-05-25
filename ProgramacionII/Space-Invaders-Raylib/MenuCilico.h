#pragma once
#include "Menu.h"
class MenuCilico : public Menu
{
private:

public:
	MenuCilico(Lista<string> listaOpciones, Lista<int (*)(int)>& listaFunciones, Font Fuente, double interlineado, int tamñanoDeFuente, Vector2 posicion, Color colorGeneral);
	MenuCilico(Lista<string> listaOpciones, Lista<int (*)(int)>& listaFunciones, Vector2 posicion);
	~MenuCilico();

	void Seleccion();
};

