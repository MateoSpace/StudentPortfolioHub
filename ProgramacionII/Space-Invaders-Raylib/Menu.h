#pragma once
#include "Lista.h"
#include "raylib.h"


class Menu
{
protected:
	Lista<string> listaOpciones;
	Lista<int (*)(int)> listaFunciones;

	Font Fuente;

	double interlineado; //entre una relacion porcentual
	int tamñanoDeFuente;
	int seleccion;
	Vector2 posicion;
	Color colorGeneral;
public:
	Menu(Lista<string> listaOpciones, Lista<int (*)(int)> listaFunciones, Font Fuente, double interlineado, int tamñanoDeFuente, int seleccion, Vector2 posicion, Color colorGeneral);
	Menu(Lista<string> listaOpciones, Lista<int (*)(int)> listaFunciones, int seleccion, Vector2 posicion);
	~Menu();

	Color& GetColor();
	Lista<string>& GetListaOpciones();
	Lista<int (*)(int)>& GetListaFunciones();

	void DrawMenu();
	virtual void Seleccion() = 0;
};

