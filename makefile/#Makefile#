# Comentario
# @: target
# ^: todas las dependencias
# <: la primera dependencia

all: fig.pdf

%.x: %.cpp
	g++ $< -o $@

datos.txt: sumas.x
	./$< > $@

fig.pdf: plot.py datos.txt
	python3 $<
clean:
	rm -f a.out *.x datos.txt
