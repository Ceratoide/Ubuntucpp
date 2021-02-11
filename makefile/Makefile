# Comentario
all: fig.pdf

sumas.x: suma.cpp
	g++ suma.cpp -o sumas.x

datos.txt: sumas.x
	./sumas.x > datos.txt

fig.pdf: plot.py datos.txt
	python3 plot.py
