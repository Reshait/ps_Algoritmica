#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Tamano de Muestra (N)"
set ylabel "Tiempo (microseg)"
plot 'Datos.txt' using 1:2 t "Curva observada" w l, 'Datos.txt' using 1:3 t "Curva ajustada" w l
_end_
