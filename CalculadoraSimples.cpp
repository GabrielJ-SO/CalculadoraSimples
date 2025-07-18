#include <iostream>
using namespace std;

int main()
{
    double resultado = 0, saida = 0, operandos[2] = { 0 }, memoria[5] = { 0 }, decimal[2] = { 0 };
    int entrada_int = 0, i = 0, j = 0, m = 0, k = 10;
    char entrada, operador = ' ';
    bool continuar = true, ponto = false, mais = false, menos = false, vezes = false, dividido = false;

    while (continuar) 
    {
        system("cls");
		cout << " ----------------------" << endl; 
		cout << "|  " << operandos[0] <<" " << operador << " " << operandos[1] << " = " << resultado << endl; // exibe o resultado
        cout << " ----------------------" << endl;
		cout << "   -----------------";
        cout << "\n  | C               |";
        cout << "\n  | 7    8    9   X |";
        cout << "\n  | 4    5    6   + |";
        cout << "\n  | 1    2    3   - |";
        cout << "\n  | 0    .    /   = |";
        cout << "\n   -----------------";
        cout << endl;
		cin >> entrada;

        switch (entrada)
        {
        case '1':   case '2':  case '3':    case '4':   case '5':   
        case '6':   case '7':  case '8':    case '9':   case '0':

            if (ponto) 
            {

				operandos[i] -= decimal[i];
				entrada_int = entrada - '0';
				decimal[i] = decimal[i] * k + entrada_int;
				k *= 10; // multiplica k por 10 para o próximo dígito
                j++;
                decimal[i] = decimal[i] / pow(10, j); // converte o número do vetor decimal para decimal
				operandos[i] += decimal[i]; // adiciona o número decimal ao operando

            }
            else 
            {
                entrada_int = entrada - '0'; // converte char para int
                operandos[i] = operandos[i] * 10 + entrada_int; // acumula o dígito

            }


            break;

        case '.':
			decimal[i] = 0; // reinicia o número decimal
            j = 0;
            k = 10;
            ponto = true;
			break;

        case '+':
			operador = '+';
			ponto = false;
			mais = true;

            // atribui o valor do resultado para o operando 0, caso usuário digitar um operador
            if (saida != 0)
            {
                operandos[0] = resultado;
                operandos[1] = 0;
                resultado = 0;
            }

            // passa para o próximo operando se i < 1;
            if (i < 1) 
            {
                i++;
            } 
            break;

        case '-':
			operador = '-';
			ponto = false;
            menos = true;

            if (saida != 0)
            {
                operandos[0] = resultado;
                operandos[1] = 0;
                resultado = 0;
            }

            if (i < 1) 
            {
                i++;
            }
            break;

        case 'X': case 'x':
			operador = 'X';
			vezes = true;
			ponto = false;

            if (saida != 0)
            {
                operandos[0] = resultado;
                operandos[1] = 0;
                resultado = 0;
            }

            if (i < 1) 
            {
                i++;
            }
            break;

        case '/':
			operador = '/';
			dividido = true;
            ponto = false;

            if (saida != 0)
            {
                operandos[0] = resultado;
                operandos[1] = 0;
                resultado = 0;
            }

            if(i < 1) 
            {
                i++;
            }
			break;

        case '=':
            if (mais) {
                resultado = operandos[0] + operandos[1];
                saida = resultado;
				mais = false; // reseta a operação após o cálculo
            }
            else if (menos) 
            {
                resultado = operandos[0] - operandos[1];
                saida = resultado;
                menos = false;
            }
            else if (vezes) 
            {
                resultado = operandos[0] * operandos[1];
                saida = resultado;
                vezes = false;
            }
            else if (dividido) {
                resultado = operandos[0] / operandos[1];
                saida = resultado;
                dividido = false;
            }
			
			i = 0;
            break;

        case 'c': case 'C':
            // Limpa todos os operandos, resultado e memória
            for (int n = 0; n < 2; n++) 
            {
                operandos[n] = 0;
            }
			operador = ' ';
            resultado = 0;
            i = 0;
            j = 0;
            k = 10;
			ponto = false;
            break;

        default:
            cout << "Digite caracteres validos!" << endl;
            system("pause");
            break;

        }
        
    }

    return 0;
}
