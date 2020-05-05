editdis: editdis.o
	g++ -o editdis editdis.o
editdis.o: editdis.cpp
	g++ -c -std=c++11 editdis.cpp
