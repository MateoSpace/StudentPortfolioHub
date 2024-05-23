/*#include "MenuNoCiclico.h"

MenuNoCiclico::MenuNoCiclico()
{

}

MenuNoCiclico::~MenuNoCiclico()
{
}

Color MenuNoCiclico::GetColor()
{
	return Color();
}

void MenuNoCiclico::SetColor()
{
}

void MenuNoCiclico::DrawMenu()
{
}

void MenuNoCiclico::Seleccion()
{
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