#pragma once

#include "Menu.h"


class MenuNoCiclico:public Menu
{
public:
	MenuNoCiclico(Lista<string> listaOpciones, Lista<int (*)(int)>& listaFunciones, Font Fuente, double interlineado, int tamñanoDeFuente, Vector2 posicion, Color colorGeneral);
	MenuNoCiclico(Lista<string> listaOpciones, Lista<int (*)(int)>& listaFunciones, Vector2 posicion);
	~MenuNoCiclico();

	void Seleccion();
};
