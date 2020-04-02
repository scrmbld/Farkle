a.out: main.o die.o table.o player.o
	g++ main.o die.o table.o player.o -lgtest -pthread -DFOO -Wall -Wextra -Werror -std=c++17 -Wno-unused-variable -Wno-unused-parameter

main.o: main.cc die.h table.h player.h
	g++ -c main.cc

table.o: table.cc table.h die.h
	g++ -c table.cc

player.o: player.cc player.h
	g++ -c player.cc

die.o: die.cc die.h
	g++ -c die.cc

clean: 
	rm -f *.o a.out core
