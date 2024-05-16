#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int main()
{
    // Crear la ventana principal
    RenderWindow window(VideoMode(800, 600), "SFML-Space-Invaders-MALF");

    // Cargar un sprite para mostrar
   /*Texture texture;
    if (!texture.loadFromFile("cute_image.jpg"))
        return EXIT_FAILURE;
    Sprite sprite(texture);
    */
    // Crear un texto gráfico para mostrar

    window.setFramerateLimit(60);
    
    Font font;
    if (!font.loadFromFile("ka1.ttf"))
        return EXIT_FAILURE;
    Text text("Hello SFML", font, 50);
    /*
    // Cargar una música para reproducirla
    Music music;
    if (!music.openFromFile("nice_music.ogg"))
        return EXIT_FAILURE;

    // Pon la música
    music.play();
*/
    // Iniciar el bucle del juego
    while (window.isOpen())
    {
        // Eventos de proceso
        Event event;
        while (window.pollEvent(event))
        {
            // Cerrar ventana: salir
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        // Pantalla limpiar
        window.clear(Color(10,11,10));

        // Dibuja el sprite
        //window.draw(sprite);

        // Tira de la cuerda
        //window.draw(text);

        // Actualizar la ventana
        window.display();
    }
    return 0;
}