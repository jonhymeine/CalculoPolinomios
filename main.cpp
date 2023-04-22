//Jonathas Meine, Mateus Jos� da Silva
#include "monomio.hpp"
#include <Windows.h>
#include <locale.h>
using namespace std;

#define TAM 20

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Menu inicial
    string menu = "1. Criar polin�mio\n2. Adicionar mon�mio ao polin�mio\n3. Remover mon�mio do polin�mio";
    menu += "\n4. Descobrir se um grau est� presente no polin�mio\n5. Opera��es\n6. Sair\n\n";
    // Menu de Opera��es
    string subMenu = "1. Somar polin�mios\n2. Subtrair polin�mios\n3. Multiplicar um polin�mio por um escalar";
    subMenu += "\n4. Multiplicar dois polin�mios\n5. Determinar o valor num�rico de um polin�mio\n6. Voltar\n\n";

    LDE polinomios[TAM];
    string escolhaX;
    int contador = 0, escolha, escolha2;
    string monomio;
    bool validado;
    while (true) {
        system("cls");
        cout << menu;
        // Mostrar polin�mios
        if (contador != 0)
            cout << "Polin�mios atuais:\n";
        for (int i = 0; i < contador; i++) {
            mostraLista(polinomios[i], to_string(i));
        }
        cout << "\nOp��o: ";
        cin >> escolha;
        switch (escolha) {
            case 1: // Criar um polin�mio
                system("cls");
                if (contador < TAM) {
                    inicializaLDE(polinomios[contador]);
                    contador++;
                    cout << "Novo polin�mio criado";
                }
                else
                    cout << "O limite de polin�mios foi atingido (20)";
                Sleep(2000);
                break;

            case 2: // Inserir mon�mio ao polin�mio
                system("cls");
                if (contador == 0) {
                    cout << "Primeiro crie um polin�mio!\n";
                    Sleep(3000);
                    break;
                }
                while (true) {
                    system("cls");
                    cout << "Inser��o de mon�mio\n\nPolin�mios dispon�veis:\n\n";
                    for (int i = 0; i < contador; i++) {
                        mostraLista(polinomios[i], to_string(i));
                    }
                    cout << "\nx para voltar!\nEscolha em qual polin�mio deseja inserir: ";
                    cin >> escolhaX;
                    if (escolhaX == "x" || escolhaX == "X") {
                        break;
                    }
                    escolha = stoi(escolhaX);
                    if (escolha >= contador) {
                        cout << "Escolha inv�lida";
                        Sleep(2000);
                        continue;
                    }
                    cout << "Digite o mon�mio: ";
                    cin >> monomio;
                    if (insereLista(polinomios[escolha], monomio))
                        cout << "Mon�mio inserido";
                    else
                        cout << "Mon�mio n�o pode ser inserido";
                    Sleep(2000);
                }
                break;

            case 3: // Remover mon�mio do polin�mio
                system("cls");
                if (contador == 0) {
                    cout << "Primeiro crie um polin�mio!\n";
                    Sleep(3000);
                    break;
                }
                while (true) {
                    system("cls");
                    cout << "Remo��o de mon�mio\n\nPolin�mios dispon�veis:\n\n";
                    for (int i = 0; i < contador; i++) {
                        mostraLista(polinomios[i], to_string(i));
                    }
                    cout << "\nx para voltar!\nEscolha em qual polin�mio deseja remover: ";
                    
                    cin >> escolhaX;
                    if (escolhaX == "x" || escolhaX == "X") {
                        break;
                    }
                    escolha = stoi(escolhaX);
                    if (escolha >= contador) {
                        cout << "Escolha inv�lida";
                        Sleep(2000);
                        continue;
                    }
                    cout << "Digite o grau do mon�mio: ";
                    cin >> escolha2;
                    if (retiraLista(polinomios[escolha], escolha2))
                        cout << "Mon�mio retirado";
                    else
                        cout << "Mon�mio n�o encontrado";
                    Sleep(2000);
                }
                break;

            case 4: // Descobrir se um grau est� presente no polin�mio
                system("cls");
                if (contador == 0) {
                    cout << "Primeiro crie um polin�mio!\n";
                    Sleep(3000);
                    break;
                }
                while (true) {
                    system("cls");
                    cout << "Verifica��o de grau\n\nPolin�mios dispon�veis:\n\n";
                    for (int i = 0; i < contador; i++) {
                        mostraLista(polinomios[i], to_string(i));
                    }
                    cout << "\nx para voltar!\nEscolha o polin�mio: ";

                    cin >> escolhaX;
                        if (escolhaX == "x" || escolhaX == "X") {
                            break;
                        }
                        escolha = stoi(escolhaX);
                    if (escolha >= contador) {
                        cout << "Escolha inv�lida";
                        Sleep(2000);
                        continue;
                    }
                    cout << "Digite o grau: ";
                    cin >> escolha2;
                    if  (descobrirExp(polinomios[escolha], escolha2) != NULL)
                        cout << "O grau " << escolha2 << " est� presente";
                    else
                        cout << "O grau " << escolha2 << " n�o est� presente";
                    Sleep(3000);
                }
                break;

            case 5: // SubMenu de opera��es
                
                validado = false;
                while (!validado) {
                    system("cls");
                    if (contador == 0) {
                        cout << "Primeiro crie um polin�mio!\n";
                        Sleep(3000);
                        break;
                    }
                    cout << subMenu;
                    if (contador != 0)
                        cout << "Polin�mios atuais:\n\n";
                    for (int i = 0; i < contador; i++) {
                        mostraLista(polinomios[i], to_string(i));
                    }
                    cout << "\nOp��o: ";
                    cin >> escolha;
                    switch (escolha) {
                        case 1: // Somar polin�mios
                            system("cls");
                            cout << "Soma de polin�mios\n\nPolin�mios dispon�veis:\n\n";
                            for (int i = 0; i < contador; i++) {
                                mostraLista(polinomios[i], to_string(i));
                            }
                            cout << "\nEscolha o primeiro polin�mio: ";
                            cin >> escolha;
                            while (escolha >= contador) {
                                cout << "Escolha inv�lida. Insira um valor v�lido: ";
                                cin >> escolha;
                            }
                            cout << "\nEscolha o segundo polin�mio: ";
                            cin >> escolha2;
                            while (escolha2 >= contador) {
                                cout << "Escolha inv�lida. Insira um valor v�lido: ";
                                cin >> escolha2;
                            }
                            polinomios[contador] = somaPolinomios(polinomios[escolha], polinomios[escolha2]);
                            mostraLista(polinomios[contador], "\nResultado");
                            contador++;
                            
                            // validado = true;
                            cout << endl;
                            system("pause");
                            break;

                        case 2: // Subtrair polin�mios
                            system("cls");
                            cout << "Subtra��o de polin�mios\n\nPolin�mios dispon�veis:\n\n";
                            for (int i = 0; i < contador; i++) {
                                mostraLista(polinomios[i], to_string(i));
                            }
                            cout << "\nEscolha o primeiro polin�mio: ";
                            cin >> escolha;
                            while (escolha >= contador) {
                                cout << "Escolha inv�lida. Insira um valor v�lido: ";
                                cin >> escolha;
                            }
                            cout << "\nEscolha o segundo polin�mio: ";
                            cin >> escolha2;
                            while (escolha2 >= contador) {
                                cout << "Escolha inv�lida. Insira um valor v�lido: ";
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
                            cout << "Multiplica��o de polin�mio por escalar\n\nPolin�mios dispon�veis:\n\n";
                            for (int i = 0; i < contador; i++) {
                                mostraLista(polinomios[i], to_string(i));
                            }
                            cout << "\nEscolha o polin�mio: ";
                            cin >> escolha;
                            while (escolha >= contador) {
                                cout << "Escolha inv�lida. Insira um valor v�lido: ";
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
                            
                        case 4: // Multiplicar dois polin�mios
                            system("cls");
                            cout << "Multiplica��o de polin�mios\n\nPolin�mios dispon�veis:\n\n";
                            for (int i = 0; i < contador; i++) {
                                mostraLista(polinomios[i], to_string(i));
                            }
                            cout << "\nEscolha o primeiro polin�mio: ";
                            cin >> escolha;
                            while (escolha >= contador) {
                                cout << "Escolha inv�lida. Insira um valor v�lido: ";
                                cin >> escolha;
                            }
                            cout << "\nEscolha o segundo polin�mio: ";
                            cin >> escolha2;
                            while (escolha2 >= contador) {
                                cout << "Escolha inv�lida. Insira um valor v�lido: ";
                                cin >> escolha2;
                            }
                            polinomios[contador] = multiplicacaoPolinomio(polinomios[escolha], polinomios[escolha2]);
                            mostraLista(polinomios[contador], "\nResultado");
                            contador++;

                            // validado = true;
                            cout << endl;
                            system("pause");
                            break;
                            
                        case 5: // Determinar o valor num�rico de um polin�mio
                            system("cls");
                            float x;
                            cout << "Determinar o valor num�rico de um polin�mio\n\nPolin�mios dispon�veis:\n\n";
                            for (int i = 0; i < contador; i++) {
                                mostraLista(polinomios[i], to_string(i));
                            }
                            cout << "\nEscolha o polin�mio: ";
                            cin >> escolha;
                            while (escolha >= contador) {
                                cout << "Escolha inv�lida. Insira um valor v�lido: ";
                                cin >> escolha;
                            }
                            cout << "\nEscolha o valor num�rico: ";
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
                            cout << "Op��o inv�lida";
                            Sleep(2000);
                            break;
                    }
                }
                break;

            case 6: // Sair do aplicativo
                system("cls");
                cout << "Tem certeza que deseja sair?\n1. Sim\nOutro n�mero. N�o\n";
                cin >> escolha;
                if (escolha == 1)
                    return 0;
                break;
                 
            default:
                break;
        }
    }
}
