//Jonathas Meine, Mateus José da Silva
#include <string>
#include <iostream>
#include <math.h>

struct No {
    float k;
    char letra;
    int exp;
    No* eloA;
    No* eloP;
};

struct LDE {
    No* comeco;
    No* fim;
};

void inicializaLDE(LDE& lista) {
    lista.comeco = NULL;
    lista.fim = NULL;
}
//Separa as informações do monômio passado
void identificaMonomio(std::string monomio, float& k, char& letra, int& exp) {
    int procura = monomio.find('^', 1);
    k = 1;
    bool temK = true;
    if (monomio[0] >= 97 && monomio[0] <= 122)
        temK = false;

    if (monomio[0] == '-' && monomio[1] >= 97 && monomio[1] <= 122) {
        temK = false;
        k = -1;
    }
    if (procura != -1) {
        if (temK)
            k = std::stof(monomio.substr(0, procura - 1));
        exp = std::stoi(monomio.substr(procura + 1));
        if (exp != 0)
            letra = monomio[procura - 1];
        else
            letra = NULL;
    }
    else {
        int tam = monomio.length();
        procura = monomio[tam - 1];
        if (procura >= 97 && procura <= 122) {
            if (temK)
                k = std::stof(monomio.substr(0, tam - 1));
            letra = char(procura);
            exp = 1;
        }
        else {
            k = std::stof(monomio);
            letra = NULL;
            exp = 0;
        }
    }
}
//Verifica se existe o monômio com o expoente exp no polinômio lista (se existir)
No* descobrirExp(LDE lista, int exp) {
    No* aux = lista.comeco;
    while (aux != NULL) {
        if (aux->exp == exp)
            return aux;
        aux = aux->eloP;
    }
    return NULL;
}
//Insere monômio no polinômio lista
bool insereLista(LDE& lista, std::string monomio) {
    No* novo = new No;

    if (novo == NULL)
        return false;

    float k;
    char letra;
    int exp;

    novo->eloA = NULL;
    novo->eloP = NULL;

    identificaMonomio(monomio, k, letra, exp);

    novo->k = k;
    novo->letra = letra;
    novo->exp = exp;

    //Insere se vazia
    if (lista.comeco == NULL) {
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }

    //Insere ao expoente igual
    No* aux = descobrirExp(lista, exp);
    if (aux != NULL) {
        aux->k += k;
        return true;
    }

    //Insere no começo
    if (exp > lista.comeco->exp) {
        novo->eloP = lista.comeco;
        lista.comeco->eloA = novo;
        lista.comeco = novo;
        return true;
    }

    //Insere no final
    if (exp < lista.fim->exp) {
        lista.fim->eloP = novo;
        novo->eloA = lista.fim;
        lista.fim = novo;
        return true;
    }

    //Insere no meio
    aux = lista.comeco;
    while (exp < aux->exp && aux->eloP->exp > exp) {
        aux = aux->eloP;
    }
    novo->eloP = aux->eloP;
    novo->eloA = aux;
    aux->eloP->eloA = novo;
    aux->eloP = novo;

    return true;
}
//Retira monômio do polinômio através do expoente 
bool retiraLista(LDE& lista, int exp) {
    No* aux = descobrirExp(lista, exp);
    if (aux == NULL)
        return false;

    //Retira do começo
    if (aux == lista.comeco) {
        if (aux->eloP != NULL)
            aux->eloP->eloA = NULL;
        lista.comeco = aux->eloP;
    }

    //Retira do final
    else if (aux == lista.fim) {
        aux->eloA->eloP = NULL;
        lista.fim = aux->eloA;
    }

    //Retira do meio
    else {
        aux->eloP->eloA = aux->eloA;
        aux->eloA->eloP = aux->eloP;
    }
    delete aux;

    return true;
}
//Imprime polinômio
void mostraLista(LDE lista, std::string desc) {
    std::cout << desc << ": ";
    if (lista.comeco == NULL)
        std::cout << "expressão vazia";

    No* aux = lista.comeco;

    while (aux != NULL) {
        if (aux->k != 1 && aux->k != -1)
            if (aux->k < 0 && aux != lista.comeco)
                std::cout << aux->k * -1;
            else
                std::cout << aux->k;
        else if (aux->k == -1)
            std::cout << '-';
        else if (aux->exp == 0)
            std::cout << aux->k;

        if (aux->letra != NULL)
            std::cout << aux->letra;

        if (aux->exp > 1)
            std::cout << '^' << aux->exp;

        if (aux->eloP != NULL)
            if (aux->eloP->k < 0)
                std::cout << " - ";
            else
                std::cout << " + ";

        aux = aux->eloP;
    }
    std::cout << std::endl;
}
//soma dos polinômios lista1 e lista2
LDE somaPolinomios(LDE lista1, LDE lista2) {
    LDE res;
    inicializaLDE(res);

    if (lista1.comeco != NULL && lista2.comeco == NULL)
        return lista1;
    if (lista2.comeco != NULL && lista1.comeco == NULL)
        return lista2;
    if (lista1.comeco == NULL && lista2.comeco == NULL)
        return res;

    No* aux1 = lista1.comeco, * aux2 = NULL;

    float k;
    char letra;
    int exp;

    while (aux1 != NULL) {
        k = aux1->k;
        letra = aux1->letra;
        exp = aux1->exp;
        aux2 = descobrirExp(lista2, exp);
        if (aux2 != NULL) {
            k += aux2->k;
        }
        std::string monomio = std::to_string(k);

        if (letra != NULL)
            monomio += letra;

        if (exp > 1)
            monomio += '^' + std::to_string(exp);

        insereLista(res, monomio);
        aux1 = aux1->eloP;
    }

    aux2 = lista2.comeco;
    while (aux2 != NULL) {
        exp = aux2->exp;
        if (descobrirExp(res, exp) == NULL) {
            k = aux2->k;
            letra = aux2->letra;

            std::string monomio = std::to_string(k);
            if (letra != NULL)
                monomio += letra;
            if (exp > 1)
                monomio += '^' + std::to_string(exp);
            insereLista(res, monomio);
        }
        aux2 = aux2->eloP;
    }
    return res;
}
//Multiplica um polinômio por um número real
LDE multiplicaEscalar(LDE lista, float num) {
    LDE res;
    inicializaLDE(res);

    if (lista.comeco == NULL || num == NULL)
        return res;

    No* aux = lista.comeco;

    while (aux != NULL) {
        std::string monomio = std::to_string(aux->k * num);
        if (aux->letra != NULL)
            monomio += aux->letra;
        if (aux->exp > 1)
            monomio += '^' + std::to_string(aux->exp);

        insereLista(res, monomio);
        aux = aux->eloP;
    }
    return res;
}
//subtração do polinômio lista1 pelo lista2
LDE subtracaoPolinomio(LDE lista1, LDE lista2) {
    LDE res;
    inicializaLDE(res);

    if (lista1.comeco == NULL || lista2.comeco == NULL)
        return res;
	//A - B = A + (-B)
    lista2 = multiplicaEscalar(lista2, -1);
    res = somaPolinomios(lista1, lista2);
    return res;
}
//Substituição da letra por um número e resolução da expressão
float valorNumerico(LDE lista, float num) {
    float res = NULL;

    if (lista.comeco == NULL || num == NULL)
        return res;

    res = 0;

    No* aux = lista.comeco;
    while (aux != NULL) {
        res += aux->k * std::pow(num, aux->exp);
        aux = aux->eloP;
    }
    return res;
}
//Multiplica os polinômios lista1 e lista2
LDE multiplicacaoPolinomio(LDE lista1, LDE lista2) {
    LDE res;
    inicializaLDE(res);

    if (lista1.comeco == NULL || lista2.comeco == NULL)
        return res;

    No* aux1 = lista1.comeco, * aux2 = NULL;

    while (aux1 != NULL) {
        aux2 = lista2.comeco;
        while (aux2 != NULL) {
            float k = aux1->k * aux2->k;
            char letra = aux1->letra;
            int exp = aux1->exp + aux2->exp;
            std::string monomio = std::to_string(k);

            if (letra != NULL)
                monomio += letra;

            if (exp > 1)
                monomio += '^' + std::to_string(exp);

            insereLista(res, monomio);
            aux2 = aux2->eloP;
        }
        aux1 = aux1->eloP;
    }
    return res;
}