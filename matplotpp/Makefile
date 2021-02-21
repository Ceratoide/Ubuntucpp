all: graf.x
	./$<

%.x:%.cpp
	g++ -std=c++17 -I /home/ceratoide/local/include -L /home/ceratoide/local/lib -L /home/ceratoide/local/lib/Matplot++ $< -lmatplot -lnodesoup -ljpeg -ltiff -lpthread -lz -o $@




