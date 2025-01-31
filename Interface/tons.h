#ifndef IN_OUT_H
#define IN_OUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* (*listaNotas())[2];

char* criarListaNotas();

int indexNota(char *nota);

void subirMeioTom(char** trecho, int t);

int calculaDeslocamentoDeTons(char *tom1, char *tom2);

#endif