#ifndef PALETA_H
#define PALETA_H

#include <iostream>
#include <fstream>
#include <string>
#include "../sequencia/sequencia.h"
#include "cor.h"

using namespace std;

class Paleta {
private:
    Sequencia<Cor> cores;

    int hexCharParaInt(char c) {
        if(c >= '0' && c <= '9') return c - '0';
        if(c >= 'A' && c <= 'F') return 10 + (c - 'A');
        if(c >= 'a' && c <= 'f') return 10 + (c - 'a');
        return 0;
    }

    int hexParaInt(char a, char b) {
        return hexCharParaInt(a)*16 + hexCharParaInt(b);
    }

public:
    Paleta() : cores() {}

    Paleta(const string &nomeArquivo) : cores() {
        ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) return;

        string linha;
        while (getline(arquivo, linha)) {
            if (linha.size() >= 7 && linha[0] == '#') {
                int r = hexParaInt(linha[1], linha[2]);
                int g = hexParaInt(linha[3], linha[4]);
                int b = hexParaInt(linha[5], linha[6]);
                cores.adicionar(Cor(r, g, b));
            }
        }
    }

    int obterTamanho() {
        return cores.obterTamanho();
    }

    void adicionarCor(Cor c) {
        cores.adicionar(c);
    }

    Cor obterCor(int indice) {
        if (indice < 0 || indice >= cores.obterTamanho()) return Cor();
        return cores[indice];
    }
};

#endif
