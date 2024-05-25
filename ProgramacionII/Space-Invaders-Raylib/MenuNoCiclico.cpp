#include "MenuNoCiclico.h"



MenuNoCiclico::MenuNoCiclico(Lista<string> listaOpciones, Lista<int(*)(int)>& listaFunciones, Font Fuente, double interlineado, int tamñanoDeFuente, Vector2 posicion, Color colorGeneral)
	: Menu(listaOpciones, listaFunciones, Fuente, interlineado, tamñanoDeFuente, seleccion, posicion, colorGeneral)
{

}

MenuNoCiclico::MenuNoCiclico(Lista<string> listaOpciones, Lista<int(*)(int)>& listaFunciones, Vector2 posicion)
	: Menu(listaOpciones, listaFunciones, Fuente, interlineado, tamñanoDeFuente, seleccion, posicion, colorGeneral)
{
}

MenuNoCiclico::~MenuNoCiclico()
{
}

void MenuNoCiclico::Seleccion()
{
	/*
	int seleccion = 0;
	char tecla = 0;
	do
	{
		system("cls");
		cout << "---------- Menu ----------" << endl;
		DrawMenu();

		if (IsKeyPressed(KEY_R))
		{
			if (seleccion > 0)
			{
				seleccion--;
			}
		} 
		if (IsKeyPressed(KEY_R))
		{
			if (seleccion < listaOpciones.tamano() - 1)
			{
				seleccion++;
			}
		}
		if (IsKeyPressed(KEY_R))
		{
			int retorno = listaFunciones[seleccion](seleccion);
			break;
		}
	} while (!(tecla == 13));
	*/
}

/*
//-CodigoMenu-----------------------CodigoMenu-----------------------CodigoMenu----------------------
void ImprimirMenu(string opciones[], int longOpciones, int seleccion)
{
	for (int indice = 0; indice < longOpciones; indice++)
	{
		if (indice == seleccion)
		{
			cout << ">" << opciones[indice] << endl;
		}
		else
		{
			cout << " " << opciones[indice] << endl;
		}
	}
	//cout << "----" << seleccion;
}

void MenuDeSelecion(string opciones[], int longOpciones, void (*PtrFuncion)(int, bool), bool condicionPtrFuncion)
{
	int seleccion = 0;
	char tecla = 0;
	do
	{
		system("cls");
		cout << "---------- Menu ----------" << endl;
		ImprimirMenu(opciones, longOpciones, seleccion);
		tecla = _getch();

		switch (tecla)
		{
		case 72:
			if (seleccion > 0)
			{
				seleccion--;
			}
			break;
		case 80:
			if (seleccion < longOpciones - 1)
			{
				seleccion++;
			}
			break;

		case 13:
			PtrFuncion(seleccion, condicionPtrFuncion);
			system("pause");
			break;
		}
	} while (!(tecla == 13 && seleccion == longOpciones - 1));
}
int MenuDeSelecionNoCiclico(string opciones[], int longOpciones, void (*PtrFuncion)(int, bool), bool condicionPtrFuncion)
{
	int seleccion = 0;
	char tecla = 0;
	do
	{
		system("cls");
		cout << "---------- Menu ----------" << endl;
		ImprimirMenu(opciones, longOpciones, seleccion);
		tecla = _getch();

		switch (tecla)
		{
		case 72:
			if (seleccion > 0)
			{
				seleccion--;
			}
			break;
		case 80:
			if (seleccion < longOpciones - 1)
			{
				seleccion++;
			}
			break;

		case 13:
			PtrFuncion(seleccion, condicionPtrFuncion);
			//system("pause");
			break;
		}
	} while (!(tecla == 13));
	return seleccion;
}
//-CodigoMenu-----------------------CodigoMenu-----------------------CodigoMenu----------------------
*/