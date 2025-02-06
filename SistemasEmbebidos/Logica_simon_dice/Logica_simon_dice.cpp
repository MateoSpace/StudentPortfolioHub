#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   

void _delay(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / 1000);
};

int main() {
    std::vector<int> listaSimon;

    int contadorRonda = 1;
    int tiempoDisparo = 1000;

    bool gameOver = false;
    bool runGame = false;
    
    while (true)
    {
        std::srand(std::time(0));
        if (contadorRonda==1 || !gameOver)
        {
            int valor = std::rand() % 4;
            listaSimon.push_back(valor);
        }

        for (int i = 0; i < listaSimon.size();i++) {
            std::cout << listaSimon[i]<<" ";
            _delay(tiempoDisparo);
            system("cls");
            _delay(tiempoDisparo*0.1);
        }
        //std::cout << "\n------" << std::endl;
        std::cout << std::endl;

        for (int valor : listaSimon)
        {
            int aux;
            std::cin >> aux;
            if (aux != valor) {
                gameOver = true;
                break;
            }
        }
        contadorRonda++;
        system("cls");
        if (contadorRonda < 6)
        {
            tiempoDisparo -= 100;
            std::cout << "tiempo disparo " << tiempoDisparo << ": "<< contadorRonda<<std::endl;
        }
        _delay(tiempoDisparo * 1.5);
        system("cls");
        if (gameOver == true)
        {
            std::cout << "---------- YOU LOST ----------" << std::endl;
            _delay(4000);
            gameOver == false;
            tiempoDisparo = 1500;
            contadorRonda = 0;
        }
    }
    return 0;
}
