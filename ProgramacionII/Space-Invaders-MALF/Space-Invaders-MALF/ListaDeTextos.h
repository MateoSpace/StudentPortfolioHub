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
    int tama�oDeCaracteres;
    int interLineado;
    Color colorGeneral;
    Vector2f posicion;
public:
    ListaDeTextos(string listaString[], int cantidadMaxima, Font fuenteGeneral,
        int tama�oDeCaracteres, int interLineado, 
        Color colorGeneral, Vector2f posicion);
    ~ListaDeTextos();

    int GetCantidadActual();
    int GetCantidadMaxima();
    Font GetFuenteGeneral();
    int GetTama�oDeCaracteres();
    int GetInterLineado();
    Color GetColorGeneral();
    Vector2f GetPosicion();

    void SetCantidadActual(int cantidadActual);
    void SetFuenteGeneral(Font fuenteGeneral);
    void SetTama�oDeCaracteres(int tama�oDeCaracteres);
    void SetInterLineado(int interLineado);
    void SetColorGeneral(Color colorGeneral);
    void SetPosicion(Vector2f posicion);

    void draw(RenderTarget &rt,RenderStates rs);
};

