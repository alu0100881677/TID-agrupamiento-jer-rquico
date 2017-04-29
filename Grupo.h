//
//  Grupo.h
//  AgrupamientoJerarquico
//
//  Created by Guillermo Esquivel González on 27/04/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#ifndef Grupo_h
#define Grupo_h

#pragma once

#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#define DIMENSION 3

namespace TID {

    class Grupo {
    private:
        std::vector < std::vector<double> > data;
        std::vector<double> centroide;

    public:
        Grupo();
        ~Grupo();

        std::vector<double> getCentroide();
        std::vector<std::vector<double> > getData();

        void addVector(std::vector<double>);

        void addGrupo(Grupo grupazo);

        void calculateCentroide();
        double distancia(Grupo);


    };
}


#endif /* Grupo_h */
