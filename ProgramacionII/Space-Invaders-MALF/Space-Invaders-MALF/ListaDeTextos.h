#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class ListaDeTextos :
    public Text
{
private: 
    Text** listaTextos;
    int cantidadActual;
    int cantidadMaxima;
    Font fuenteGeneral;
    int tamañoDeCaracteres;
    int interLineado;
    Color colorGeneral;
    Vector2f posicion;
public:
    ListaDeTextos(string listaString[], int cantidadMaxima, Font fuenteGeneral,
        int tamañoDeCaracteres, int interLineado, 
        Color colorGeneral, Vector2f posicion);
    ~ListaDeTextos();

    int GetCantidadActual();
    int GetCantidadMaxima();
    Font GetFuenteGeneral();
    int GetTamañoDeCaracteres();
    int GetInterLineado();
    Color GetColorGeneral();
    Vector2f GetPosicion();

    void SetCantidadActual(int cantidadActual);
    void SetFuenteGeneral(Font fuenteGeneral);
    void SetTamañoDeCaracteres(int tamañoDeCaracteres);
    void SetInterLineado(int interLineado);
    void SetColorGeneral(Color colorGeneral);
    void SetPosicion(Vector2f posicion);

    void draw(RenderTarget &rt,RenderStates rs);
};

