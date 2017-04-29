//
//  Grupo.cpp
//  AgrupamientoJerarquico
//
//  Copyright © 2017 Guillermo Esquivel González. All rights reserved.

#include "Grupo.h"

#include <stdio.h>
#include <iostream>

namespace TID {

    Grupo::Grupo() {}

    Grupo::~Grupo() {}

    void Grupo::addVector(std::vector<double> vector) {
        data.push_back(vector);
        this->calculateCentroide();
    }

    std::vector<std::vector<double>> Grupo::getData() {
        return data;
    }

    std::vector<double> Grupo::getCentroide() {
        return centroide;
    }

    void Grupo::calculateCentroide() {
        if (data.empty())
            return;
        if (data.size() == 1) {
            centroide = data[0];
            return;
        }

        std::vector<double> gravityCenter;
        gravityCenter.push_back(0.0);
        gravityCenter.push_back(0.0);
        gravityCenter.push_back(0.0);
        for (int i = 0; i < data.size(); i++) {
            gravityCenter[0] += data[i][0];
            gravityCenter[1] += data[i][1];
            gravityCenter[2] += data[i][2];
        }
        for (int i = 0; i < gravityCenter.size(); i++) {
            gravityCenter[i] /= data.size();
        }

        centroide = *new std::vector<double>(gravityCenter);
    }

    double Grupo::distancia(Grupo otroGrupo) {
        double distancia = 0.0;
        for (int i = 0; i < this->getCentroide().size(); i++)
            distancia += pow(this->getCentroide()[i] - otroGrupo.getCentroide()[i], 2);
        return sqrt(distancia);
    }

    void Grupo::addGrupo(Grupo grupazo) {
        for(int i = 0; i < grupazo.getData().size(); i++){
        	data.push_back(grupazo.getData()[i]);
        }
        calculateCentroide();
    }

}

//END
