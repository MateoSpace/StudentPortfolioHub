#include "Menu.h"



Menu::Menu(Lista<string> listaOpciones, Lista<int(*)(int)> listaFunciones, Font Fuente, double interlineado, int tamñanoDeFuente, int seleccion, Vector2 posicion, Color colorGeneral)
{
	this->listaOpciones = listaOpciones;
	this->listaFunciones = listaFunciones;
	this->Fuente = Fuente;
	this->interlineado = interlineado;
	this->posicion = posicion;
	this->tamñanoDeFuente = tamñanoDeFuente;
	this->colorGeneral = colorGeneral;
	this->seleccion = 0;
}

Menu::Menu(Lista<string> listaOpciones, Lista<int(*)(int)> listaFunciones, int seleccion, Vector2 posicion): listaOpciones(), listaFunciones()
{
	this->listaOpciones = listaOpciones;
	this->listaFunciones = listaFunciones;
	this->Fuente = LoadFont("Recursos/Fuentes/ka1.ttf");
	this->interlineado = 1;
	this->posicion = posicion;
	this->tamñanoDeFuente = 20;
	this->colorGeneral = Color(WHITE);
	this->seleccion = 0;
}

Menu::~Menu()
{
}

Color& Menu::GetColor()
{
	return colorGeneral;
}

Lista<string>& Menu::GetListaOpciones()
{
	return listaOpciones;
}

Lista<int(*)(int)>& Menu::GetListaFunciones()
{
	return listaFunciones;
}



void Menu::DrawMenu()
{
	stringstream ss;
	for (int indice = 0; indice < listaOpciones.tamano(); indice++)
	{
		if (indice == seleccion)
		{
			ss << ">" << listaOpciones[indice];
			DrawText(TextFormat("> ",ss.str()), posicion.x / 2.5, posicion.y / 2.5 + (20 * interlineado * indice), 20, LIGHTGRAY);
		}
		else
		{
			ss << " " << listaOpciones[indice];
		}
	}
}
