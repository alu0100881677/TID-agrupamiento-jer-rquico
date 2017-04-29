//
//  main.cpp
//  AgrupamientoJerarquico
//
//  Created by Guillermo Esquivel González on 27/04/2017.
//  Copyright © 2017 Óscar Darias Plasencia. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Grupo.h"

void mostrarVector(std::vector<double> vector) {
    std::cout << " Centroide  = { \33[34m";
    for (int i = 0; i < vector.size(); i++)
        std::cout << vector[i] << "  ";
    std::cout << "\33[m}" << std::endl;
}


std::ostream& operator << (std::ostream &out, TID::Grupo &gr) {
    out << "{ \33[32m";
    for(int i = 0; i < gr.getData().size(); i++){
    	for(int j = 0; j < gr.getData()[i].size(); j++){
    		out << gr.getData()[i][j] << "  ";
    	}
    	if(i < gr.getData().size() - 1)
    		out << "\33[m| \33[32m";
    }
    out << "\33[m}";
    return out;
}


void mostrarGrupos(std::vector<TID::Grupo> grupos) {
    for (int i = 0; i < grupos.size(); i++) {
        std::cout << "Grupo " << i << " " << grupos[i];
        mostrarVector(grupos[i].getCentroide());
    }
}



int main(int argc, const char * argv[]) {
    std::vector<TID::Grupo> grupos;

    std::vector<double> ej1 = {2.1, 2.5, 3.5};
    TID::Grupo grupo1;
    grupo1.addVector(ej1);
    grupos.push_back(grupo1);

    std::vector<double> ej2 = {3.2, 5.2, 3.5};
    TID::Grupo grupo2;
    grupo2.addVector(ej2);
    grupos.push_back(grupo2);

    std::vector<double> ej3 = {4.5, 4.6, 3.6};
    TID::Grupo grupo3;
    grupo3.addVector(ej3);
    grupos.push_back(grupo3);

    std::vector<double> ej4 = {3.6, 2.9, 2.9};
    TID::Grupo grupo4;
    grupo4.addVector(ej4);
    grupos.push_back(grupo4);

    std::vector<double> ej5 = {3.7, 2.9, 2.7};
    TID::Grupo grupo5;
    grupo5.addVector(ej5);
    grupos.push_back(grupo5);

    std::vector<double> ej6 = {3.4, 3.5, 3.4};
    TID::Grupo grupo6;
    grupo6.addVector(ej6);
    grupos.push_back(grupo6);

    std::vector<double> ej7 = {4.2, 4.2, 3.7};
    TID::Grupo grupo7;
    grupo7.addVector(ej7);
    grupos.push_back(grupo7);

    std::vector<double> ej8 = {2.8, 6.1, 4.9};
    TID::Grupo grupo8;
    grupo8.addVector(ej8);
    grupos.push_back(grupo8);

    std::vector<double> ej9 = {3.6, 2.7, 4.2};
    TID::Grupo grupo9;
    grupo9.addVector(ej9);
    grupos.push_back(grupo9);

    std::vector<double> ej10 = {2.8, 1.9, 3.8};
    TID::Grupo grupo10;
    grupo10.addVector(ej10);
    grupos.push_back(grupo10);
    int i = 0;
    std::cout << "\33[37;41mPaso " << i << "\33[m" <<std::endl;
   	mostrarGrupos(grupos);
   	std::cout << std::endl;
   	i++;
    while (grupos.size() != 1) {
    	std::cout << "\33[37;41mPaso " << i << "\33[m" <<std::endl;
        int from = 0;
        int to = 0;
        double distancia = 9999;
        for (int i = 0; i < grupos.size() - 1; i++) {
            for (int j = i + 1; j < grupos.size(); j++) {
                if (grupos[i].distancia(grupos[j]) < distancia) {
                    distancia = grupos[i].distancia(grupos[j]);
                    from = i;
                    to = j;
                }
            }

        }
        grupos[from].addGrupo(grupos[to]);
        grupos.erase(grupos.begin() + to);
        std::cout << "Entra el " << to << " al " << from << std::endl;
        mostrarGrupos(grupos);
        std::cout << std::endl;
        i++;

    }
    return 0;
}














//END
