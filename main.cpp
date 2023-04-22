//Jonathas Meine, Mateus José da Silva
#include "monomio.hpp"
#include <Windows.h>
#include <locale.h>
using namespace std;

#define TAM 20

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Menu inicial
    string menu = "1. Criar polinômio\n2. Adicionar monômio ao polinômio\n3. Remover monômio do polinômio";
    menu += "\n4. Descobrir se um grau está presente no polinômio\n5. Operações\n6. Sair\n\n";
    // Menu de Operações
    string subMenu = "1. Somar polinômios\n2. Subtrair polinômios\n3. Multiplicar um polinômio por um escalar";
    subMenu += "\n4. Multiplicar dois polinômios\n5. Determinar o valor numérico de um polinômio\n6. Voltar\n\n";

    LDE polinomios[TAM];
    string escolhaX;
    int contador = 0, escolha, escolha2;
    string monomio;
    bool validado;
    while (true) {
        system("cls");
        cout << menu;
        // Mostrar polinômios
        if (contador != 0)
            cout << "Polinômios atuais:\n";
        for (int i = 0; i < contador; i++) {
            mostraLista(polinomios[i], to_string(i));
        }
        cout << "\nOpção: ";
        cin >> escolha;
        switch (escolha) {
            case 1: // Criar um polinômio
                system("cls");
                if (contador < TAM) {
                    inicializaLDE(polinomios[contador]);
                    contador++;
                    cout << "Novo polinômio criado";
                }
                else
                    cout << "O limite de polinômios foi atingido (20)";
                Sleep(2000);
                break;

            case 2: // Inserir monômio ao polinômio
                system("cls");
                if (contador == 0) {
                    cout << "Primeiro crie um polinômio!\n";
                    Sleep(3000);
                    break;
                }
                while (true) {
                    system("cls");
                    cout << "Inserção de monômio\n\nPolinômios disponíveis:\n\n";
                    for (int i = 0; i < contador; i++) {
                        mostraLista(polinomios[i], to_string(i));
                    }
                    cout << "\nx para voltar!\nEscolha em qual polinômio deseja inserir: ";
                    cin >> escolhaX;
                    if (escolhaX == "x" || escolhaX == "X") {
                        break;
                    }
                    escolha = stoi(escolhaX);
                    if (escolha >= contador) {
                        cout << "Escolha inválida";
                        Sleep(2000);
                        continue;
                    }
                    cout << "Digite o monômio: ";
                    cin >> monomio;
                    if (insereLista(polinomios[escolha], monomio))
                        cout << "Monômio inserido";
                    else
                        cout << "Monômio não pode ser inserido";
                    Sleep(2000);
                }
                break;

            case 3: // Remover monômio do polinômio
                system("cls");
                if (contador == 0) {
                    cout << "Primeiro crie um polinômio!\n";
                    Sleep(3000);
                    break;
                }
                while (true) {
                    system("cls");
                    cout << "Remoção de monômio\n\nPolinômios disponíveis:\n\n";
                    for (int i = 0; i < contador; i++) {
                        mostraLista(polinomios[i], to_string(i));
                    }
                    cout << "\nx para voltar!\nEscolha em qual polinômio deseja remover: ";
                    
                    cin >> escolhaX;
                    if (escolhaX == "x" || escolhaX == "X") {
                        break;
                    }
                    escolha = stoi(escolhaX);
                    if (escolha >= contador) {
                        cout << "Escolha inválida";
                        Sleep(2000);
                        continue;
                    }
                    cout << "Digite o grau do monômio: ";
                    cin >> escolha2;
                    if (retiraLista(polinomios[escolha], escolha2))
                        cout << "Monômio retirado";
                    else
                        cout << "Monômio não encontrado";
                    Sleep(2000);
                }
                break;

            case 4: // Descobrir se um grau está presente no polinômio
                system("cls");
                if (contador == 0) {
                    cout << "Primeiro crie um polinômio!\n";
                    Sleep(3000);
                    break;
                }
                while (true) {
                    system("cls");
                    cout << "Verificação de grau\n\nPolinômios disponíveis:\n\n";
                    for (int i = 0; i < contador; i++) {
                        mostraLista(polinomios[i], to_string(i));
                    }
                    cout << "\nx para voltar!\nEscolha o polinômio: ";

                    cin >> escolhaX;
                        if (escolhaX == "x" || escolhaX == "X") {
                            break;
                        }
                        escolha = stoi(escolhaX);
                    if (escolha >= contador) {
                        cout << "Escolha inválida";
                        Sleep(2000);
                        continue;
                    }
                    cout << "Digite o grau: ";
                    cin >> escolha2;
                    if  (descobrirExp(polinomios[escolha], escolha2) != NULL)
                        cout << "O grau " << escolha2 << " está presente";
                    else
                        cout << "O grau " << escolha2 << " não está presente";
                    Sleep(3000);
                }
                break;

            case 5: // SubMenu de operações
                
                validado = false;
                while (!validado) {
                    system("cls");
                    if (contador == 0) {
                        cout << "Primeiro crie um polinômio!\n";
                        Sleep(3000);
                        break;
                    }
                    cout << subMenu;
                    if (contador != 0)
                        cout << "Polinômios atuais:\n\n";
                    for (int i = 0; i < contador; i++) {
                        mostraLista(polinomios[i], to_string(i));
                    }
                    cout << "\nOpção: ";
                    cin >> escolha;
                    switch (escolha) {
                        case 1: // Somar polinômios
                            system("cls");
                            cout << "Soma de polinômios\n\nPolinômios disponíveis:\n\n";
                            for (int i = 0; i < contador; i++) {
                                mostraLista(polinomios[i], to_string(i));
                            }
                            cout << "\nEscolha o primeiro polinômio: ";
                            cin >> escolha;
                            while (escolha >= contador) {
                                cout << "Escolha inválida. Insira um valor válido: ";
                                cin >> escolha;
                            }
                            cout << "\nEscolha o segundo polinômio: ";
                            cin >> escolha2;
                            while (escolha2 >= contador) {
                                cout << "Escolha inválida. Insira um valor válido: ";
                                cin >> escolha2;
                            }
                            polinomios[contador] = somaPolinomios(polinomios[escolha], polinomios[escolha2]);
                            mostraLista(polinomios[contador], "\nResultado");
                            contador++;
                            
                            // validado = true;
                            cout << endl;
                            system("pause");
                            break;

                        case 2: // Subtrair polinômios
                            system("cls");
                            cout << "Subtração de polinômios\n\nPolinômios disponíveis:\n\n";
                            for (int i = 0; i < contador; i++) {
                                mostraLista(polinomios[i], to_string(i));
                            }
                            cout << "\nEscolha o primeiro polinômio: ";
                            cin >> escolha;
                            while (escolha >= contador) {
                                cout << "Escolha inválida. Insira um valor válido: ";
                                cin >> escolha;
                            }
                            cout << "\nEscolha o segundo polinômio: ";
                            cin >> escolha2;
                            while (escolha2 >= contador) {
                                cout << "Escolha inválida. Insira um valor válido: ";
                                cin >> escolha2;
                            }
                            polinomios[contador] = subtracaoPolinomio(polinomios[escolha], polinomios[escolha2]);
                            mostraLista(polinomios[contador], "\nResultado");
                            contador++;

                            // validado = true;
                            cout << endl;
                            system("pause");
                            break;

                        case 3: // Multiplicar por um escalar                        
                            system("cls");
                            cout << "Multiplicação de polinômio por escalar\n\nPolinômios disponíveis:\n\n";
                            for (int i = 0; i < contador; i++) {
                                mostraLista(polinomios[i], to_string(i));
                            }
                            cout << "\nEscolha o polinômio: ";
                            cin >> escolha;
                            while (escolha >= contador) {
                                cout << "Escolha inválida. Insira um valor válido: ";
                                cin >> escolha;
                            }
                            cout << "\nMultiplicar por: ";
                            cin >> escolha2;                 
                            polinomios[contador] = multiplicaEscalar(polinomios[escolha], escolha2);
                            mostraLista(polinomios[contador], "\nResultado");
                            contador++;
                            
                            // validado = true;
                            cout << endl;
                            system("pause");
                            break;
                            
                        case 4: // Multiplicar dois polinômios
                            system("cls");
                            cout << "Multiplicação de polinômios\n\nPolinômios disponíveis:\n\n";
                            for (int i = 0; i < contador; i++) {
                                mostraLista(polinomios[i], to_string(i));
                            }
                            cout << "\nEscolha o primeiro polinômio: ";
                            cin >> escolha;
                            while (escolha >= contador) {
                                cout << "Escolha inválida. Insira um valor válido: ";
                                cin >> escolha;
                            }
                            cout << "\nEscolha o segundo polinômio: ";
                            cin >> escolha2;
                            while (escolha2 >= contador) {
                                cout << "Escolha inválida. Insira um valor válido: ";
                                cin >> escolha2;
                            }
                            polinomios[contador] = multiplicacaoPolinomio(polinomios[escolha], polinomios[escolha2]);
                            mostraLista(polinomios[contador], "\nResultado");
                            contador++;

                            // validado = true;
                            cout << endl;
                            system("pause");
                            break;
                            
                        case 5: // Determinar o valor numérico de um polinômio
                            system("cls");
                            float x;
                            cout << "Determinar o valor numérico de um polinômio\n\nPolinômios disponíveis:\n\n";
                            for (int i = 0; i < contador; i++) {
                                mostraLista(polinomios[i], to_string(i));
                            }
                            cout << "\nEscolha o polinômio: ";
                            cin >> escolha;
                            while (escolha >= contador) {
                                cout << "Escolha inválida. Insira um valor válido: ";
                                cin >> escolha;
                            }
                            cout << "\nEscolha o valor numérico: ";
                            cin >> x;
                            inicializaLDE(polinomios[contador]);
                            insereLista(polinomios[contador], to_string(valorNumerico(polinomios[escolha], x)));
                            mostraLista(polinomios[contador], "Resultado");
                            contador++;

                            // validado = true;
                            cout << endl;
                            system("pause");
                            break;

                        case 6: // Voltar
                            validado = true;
                            break;

                        default:
                            cout << "Opção inválida";
                            Sleep(2000);
                            break;
                    }
                }
                break;

            case 6: // Sair do aplicativo
                system("cls");
                cout << "Tem certeza que deseja sair?\n1. Sim\nOutro número. Não\n";
                cin >> escolha;
                if (escolha == 1)
                    return 0;
                break;
                 
            default:
                break;
        }
    }
}
