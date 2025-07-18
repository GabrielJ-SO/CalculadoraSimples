#include <iostream>
using namespace std;

int main()
{
    float saida = 0, memoria[2] = { 0 };
    int entrada_int = 0, i = 0, j;
    char entrada;
    bool continuar = true, ponto = false;

    while (continuar) {
        system("cls");
        cout << saida << endl;

        cout << "Digite: " << endl;
        cout << "\n 7    8    9   X ";
        cout << "\n 4    5    6   + ";
        cout << "\n 1    2    3   - ";
        cout << "\n      0    .   = ";
        cout << endl;
		cin >> entrada;

        switch (entrada)
        {
        case '1':   case '2':  case '3':    case '4':   case '5':   
        case '6':   case '7':  case '8':    case '9':   case '0':

			entrada_int = entrada - '0'; // converte char para int
			memoria[i] = memoria[i] * 10 + entrada_int; // acumula o dígito
			saida = memoria[i];
            break;

        case '.':
            ponto = true;
			break;

        case '+':

            break;

        case '-':
            break;

        case 'X': case 'x':
            break;

        case '/':
			break;

        case '=':
            cout << "Resultado: " << saida << endl;
            continuar = false;
            break;

        default:
			cout << "Digite caracteres validos!" << endl;
			system("pause");
            break;
        }

    }

    return 0;
}
