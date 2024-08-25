#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void estados_ahorcado(int &estado);

int main()
{
    int modo;
    cout << "\tAHORCADO\n";
    cout << "1. Un jugador\n";
    cout << "2. Dos jugadores jugador\n";
    cout << "Digite el modo de juego: ";
    cin >> modo;

    system("clear");
    cout << "EN ESTE JUEGO SOLO INGRESE LETRAS EN MINUSCULA\n\n ";
    system("sleep 3");
    system("clear");
    int estado = 0, intentos = 6, long_palabra = 0, l_e = 0;
    char letra;
    int palabra;
    bool letra_encontrada = false, seguir = true;
    const char palabras[10][13] = {{"computadora"}, {"programacion"}, {"desarrollo"}, {"tecnologia"}, {"ingenieria"}, {"algoritmo"}, {"informatica"}, {"inteligencia"}, {"aplicacion"}, {"programador"}};
    char palabra_Player[100];

    if (modo == 1)
    {
        srand(time(NULL));
        palabra = 0 + rand() % (9 + 1 - 0);

        long_palabra = strlen(palabras[palabra]);
    }
    else
    {
        cout << "Jugador uno\n";
        cout << "Digite la palabra que el jugador dos va a tener que adivinar: ";
        cin >> palabra_Player;

        long_palabra = strlen(palabra_Player);
    }

    int letras_encontradas[long_palabra];

    for (int i = 0; i < long_palabra; i++)
    {
        letras_encontradas[i] = 0;
    }

    while (seguir == true)
    {
        letra_encontrada = false;
        l_e = 0;
        system("clear");
        cout << "Intentos restantes: " << intentos << endl
             << endl;

        estados_ahorcado(estado);

        cout << endl;

        for (int i = 0; i < long_palabra; i++)
        {
            if (letras_encontradas[i] == 1)
            {
                if (modo == 1)
                {
                    cout << palabras[palabra][i] << " ";
                }
                else
                {
                    cout << palabra_Player[i] << " ";
                }
            }
            else
            {
                cout << "_ ";
            }
        }

        cout << "\n\nDigite una letra: ";
        cin >> letra;

        for (int i = 0; i < long_palabra; i++)
        {
            if (modo == 1)
            {
                if (palabras[palabra][i] == letra)
                {
                    letras_encontradas[i] = 1;
                    letra_encontrada = true;
                }
            }
            else
            {
                if (palabra_Player[i] == letra)
                {
                    letras_encontradas[i] = 1;
                    letra_encontrada = true;
                }
            }
        }
        if (letra_encontrada != true)
        {
            intentos -= 1;
            estado += 1;
        }

        for (int i = 0; i < long_palabra; i++)
        {
            if (letras_encontradas[i] == 1)
            {
                l_e += 1;
            }
        }

        if (l_e >= long_palabra)
        {
            seguir = false;
        }
        else if (intentos <= 0)
        {
            estado = 6;
            seguir = false;
        }
    }

    system("clear");
    cout << "Intentos restantes: " << intentos << endl
         << endl;
    estados_ahorcado(estado);

    cout << endl;
    for (int i = 0; i < long_palabra; i++)
    {
        if (letras_encontradas[i] == 1)
        {
            if (modo == 1)
            {
                cout << palabras[palabra][i] << " ";
            }
            else
            {
                cout << palabra_Player[i] << " ";
            }
        }
        else
        {
            cout << "_ ";
        }
    }

    if (l_e >= long_palabra)
    {
        if (modo == 1)
        {
            cout << "\n\n¡Felicidades! Has ganado. \nLa palabra era: " << palabras[palabra] << endl;
        }
        else
        {
            cout << "\n\n¡Felicidades! Has ganado. \nLa palabra era: " << palabra_Player << endl;
        }
    }
    else if (intentos <= 0)
    {
        if (modo == 1)
        {
            cout << "\n\n¡Has perdido! La palabra era: " << palabras[palabra] << endl;
        }
        else
        {
            cout << "\n\n¡Has perdido! La palabra era: " << palabra_Player << endl;
        }
    }

    cout << "\n\nJuego terminado\n\n";
    return 0;
}

void estados_ahorcado(int &estado)
{
    string sprite0 =
        "\t    +---+\n"
        "\t    |   |\n"
        "\t        |\n"
        "\t        |\n"
        "\t        |\n"
        "\t=========\n";

    string sprite1 =
        "\t    +---+\n"
        "\t    |   |\n"
        "\t    O   |\n"
        "\t        |\n"
        "\t        |\n"
        "\t=========\n";

    string sprite2 =
        "\t    +---+\n"
        "\t    |   |\n"
        "\t    O   |\n"
        "\t    |   |\n"
        "\t        |\n"
        "\t=========\n";

    string sprite3 =
        "\t    +---+\n"
        "\t    |   |\n"
        "\t    O   |\n"
        "\t   /|   |\n"
        "\t        |\n"
        "\t=========\n";

    string sprite4 =
        "\t    +---+\n"
        "\t    |   |\n"
        "\t    O   |\n"
        "\t   /|\\  |\n"
        "\t        |\n"
        "\t=========\n";

    string sprite5 =
        "\t    +---+\n"
        "\t    |   |\n"
        "\t    O   |\n"
        "\t   /|\\  |\n"
        "\t   /    |\n"
        "\t=========\n";

    string sprite6 =
        "\t    +---+\n"
        "\t    |   |\n"
        "\t    O   |\n"
        "\t   /|\\  |\n"
        "\t   / \\  |\n"
        "\t=========\n";

    switch (estado)
    {
    case 0:
        cout << sprite0;
        break;
    case 1:
        cout << sprite1;
        break;
    case 2:
        cout << sprite2;
        break;
    case 3:
        cout << sprite3;
        break;
    case 4:
        cout << sprite4;
        break;
    case 5:
        cout << sprite5;
        break;
    case 6:
        cout << sprite6;
        break;
    }
}
