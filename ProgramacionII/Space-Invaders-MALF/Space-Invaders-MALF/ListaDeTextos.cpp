#include "ListaDeTextos.h"


ListaDeTextos::ListaDeTextos(string listaString[], int cantidadMaxima, Font fuenteGeneral, int tama�oDeCaracteres, int interLineado, Color colorGeneral, Vector2f posicion)
{
	this->cantidadMaxima = cantidadMaxima;
	cantidadActual = cantidadMaxima;
	listaTextos = new Text * [cantidadMaxima];
	this->fuenteGeneral = fuenteGeneral;
	this->tama�oDeCaracteres = tama�oDeCaracteres;
	this->interLineado = interLineado;
	this->colorGeneral = colorGeneral;
	this->posicion = posicion;
	for (int i = 0; i < cantidadActual; i++)
	{
		listaTextos[i]->setString(listaString[i]);
	}

}

ListaDeTextos::~ListaDeTextos()
{
}

int ListaDeTextos::GetCantidadActual()
{
	return cantidadActual;
}

int ListaDeTextos::GetCantidadMaxima()
{
	return cantidadMaxima;
}

Font ListaDeTextos::GetFuenteGeneral()
{
	return fuenteGeneral;
}

int ListaDeTextos::GetTama�oDeCaracteres()
{
	return tama�oDeCaracteres;
}

int ListaDeTextos::GetInterLineado()
{
	return interLineado;
}

Color ListaDeTextos::GetColorGeneral()
{
	return colorGeneral;
}

Vector2f ListaDeTextos::GetPosicion()
{
	return posicion;
}

void ListaDeTextos::SetCantidadActual(int cantidadActual)
{
	this->cantidadActual = cantidadActual;
}

void ListaDeTextos::SetFuenteGeneral(Font fuenteGeneral)
{
	this->fuenteGeneral = fuenteGeneral;
}

void ListaDeTextos::SetTama�oDeCaracteres(int tama�oDeCaracteres)
{
	this->tama�oDeCaracteres = tama�oDeCaracteres;
}

void ListaDeTextos::SetInterLineado(int interLineado)
{
	this->interLineado = interLineado;
}

void ListaDeTextos::SetColorGeneral(Color colorGeneral)
{
	this->colorGeneral = colorGeneral;
}

void ListaDeTextos::SetPosicion(Vector2f posicion)
{
	this->posicion = posicion;
}

void ListaDeTextos::draw(RenderTarget& rt, RenderStates rs)
{
//	int x = posicion.x;
//	int y = posicion.y;

	for (int i = 0; i < cantidadActual; i++)
	{
		listaTextos[i]->setFont(fuenteGeneral);
		listaTextos[i]->setCharacterSize(tama�oDeCaracteres);
		listaTextos[i]->setColor(colorGeneral);
		listaTextos[i]->setPosition(Vector2f(posicion.x, posicion.y + (i * (interLineado + tama�oDeCaracteres))));
	}
}
