//Leonardo Edivaldo Santos de Souza
//WASHINGTON ALVES JUNIOR

#include <iostream>
#include <string>

using namespace std;

int main() {

    int opcao;
    int base;
    long long numero;

    // Variavel que armazena os digitos utilizados nas conversoes
    // Os caracteres A ate F representam os valores de 10 ate 15
    string digitos = "0123456789ABCDEF";

    // Exibe o menu de conversoes
    cout << "===== CONVERSOR DE BASES =====" << endl;
    cout << "1 - Decimal para Binario" << endl;
    cout << "2 - Decimal para Octal" << endl;
    cout << "3 - Decimal para Hexadecimal" << endl;
    cout << "4 - Binario para Decimal" << endl;
    cout << "5 - Octal para Decimal" << endl;
    cout << "6 - Hexadecimal para Decimal" << endl;

    // Recebe a opcao escolhida pelo usuario
    cout << "\nEscolha uma opcao: ";
    cin >> opcao;

    switch (opcao) {

        case 1:
        case 2:
        case 3: {

            // Define a base de acordo com a opcao escolhida
            if (opcao == 1) {
                base = 2;
            }
            else if (opcao == 2) {
                base = 8;
            }
            else {
                base = 16;
            }

            // Recebe o numero decimal
            cout << "Digite um numero decimal: ";
            cin >> numero;

            // Variavel que armazena o resultado
            string resultado = "";

            // Verifica se o numero e zero
            if (numero == 0) {
                resultado = "0";
            }

            // Realiza a conversao dividindo pela base escolhida
            while (numero > 0) {

                // Calcula o resto da divisao
                // O resto representa um digito da nova base
                int resto = numero % base;

                // Adiciona o digito no inicio do resultado
                resultado = digitos[resto] + resultado;

                // Divide o numero pela base para continuar
                numero = numero / base;
            }

            // Exibe o resultado da conversao
            cout << "Resultado: " << resultado << endl;

            break;
        }

        case 4:
        case 5:
        case 6: {

            // Define a base do numero digitado
            if (opcao == 4) {
                base = 2;
            }
            else if (opcao == 5) {
                base = 8;
            }
            else {
                base = 16;
            }

            string entrada;

            // Recebe o numero na base escolhida
            cout << "Digite o numero: ";
            cin >> entrada;

            // Variavel que armazenara o resultado decimal
            numero = 0;

            bool valido = true;

            // Percorre cada digito do numero digitado
            for (int i = 0; i < entrada.length(); i++) {

                int valor;

                // Verifica se o caractere e um numero de 0 a 9
                if (entrada[i] >= '0' && entrada[i] <= '9') {
                    valor = entrada[i] - '0';
                }

                // Verifica se o caractere e uma letra de A ate F
                else if (entrada[i] >= 'A' && entrada[i] <= 'F') {
                    valor = entrada[i] - 'A' + 10;
                }

                // Caso o caractere nao seja reconhecido
                else {
                    valido = false;
                    break;
                }

                // Verifica se o digito pertence a base escolhida
                if (valor >= base) {
                    valido = false;
                    break;
                }

                // Multiplica o resultado pela base e soma o digito
                numero = numero * base + valor;
            }

            // Verifica se o numero digitado e valido
            if (valido) {
                cout << "Resultado em decimal: " << numero << endl;
            }
            else {
                cout << "Numero invalido para essa base!" << endl;
            }

            break;
        }

        default:

            // Informa quando a opcao escolhida nao existe
            cout << "Opcao invalida!" << endl;
    }

    // Finaliza o programa
    return 0;
}
