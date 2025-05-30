main.out: main.o driver.o mamoriat.o snap.o
	g++ main.o driver.o mamoriat.o snap.o -o main.out

main.o: main.cpp header.hpp
	g++ -c -std=c++11 main.cpp

driver.o: driver.cpp header.hpp
	g++ -c -std=c++11 driver.cpp

mamoriat.o: mamoriat.cpp header.hpp
	g++ -c -std=c++11 mamoriat.cpp

snap.o: snap.cpp header.hpp
	g++ -c -std=c++11 snap.cpp

clean: 
	rm *.o main.out