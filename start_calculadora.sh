#!/bin/bash
# 2021-02-10
# Author: Ibón González Martínez de Apellániz

echo "Compilación del programa"
make -f Makefile_Rational

echo "Lanzamos la calculadora"
./calculadora
