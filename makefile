CXX = g++
CXXFLAGS = -Wall -g
OBJECTS = Game.o Area.o Entity.o Zerg.o Zergling.o Mutalisk.o Hydralisk.o Terran.o Marine.o Ghost.o Battlecruiser.o
IODIR =../../proj4_IO

proj4: $(OBJECTS) proj4.cpp
	$(CXX) $(CXXFLAGS) $(OBJECTS) proj4.cpp -o proj4

Game.o: Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Area.o: Area.cpp Area.h
	$(CXX) $(CXXFLAGS) -c Area.cpp

Entity.o: Entity.cpp Entity.h
	$(CXX) $(CXXFLAGS) -c Entity.cpp

Zerg.o: Zerg.cpp Zerg.h Entity.o
	$(CXX) $(CXXFLAGS) -c Zerg.cpp

Zergling.o: Zergling.cpp Zergling.h Zerg.o 
	$(CXX) $(CXXFLAGS) -c Zergling.cpp 

Mutalisk.o: Mutalisk.cpp Mutalisk.h Zerg.o 
	$(CXX) $(CXXFLAGS) -c Mutalisk.cpp 

Hydralisk.o: Hydralisk.cpp Hydralisk.h Zerg.o 
	$(CXX) $(CXXFLAGS) -c Hydralisk.cpp

Terran.o: Terran.cpp Terran.h Entity.o
	$(CXX) $(CXXFLAGS) -c Terran.cpp

Marine.o: Marine.cpp Marine.h Terran.o
	$(CXX) $(CXXFLAGS) -c Marine.cpp 

Ghost.o: Ghost.cpp Ghost.h Terran.o
	$(CXX) $(CXXFLAGS) -c Ghost.cpp

Battlecruiser.o: Battlecruiser.cpp Battlecruiser.h Terran.o 
	$(CXX) $(CXXFLAGS) -c Battlecruiser.cpp 

clean:
	rm *.o*
	rm *~

run1:
	./proj4 proj4_map1.txt

run2:
	./proj4 proj4_map2.txt

val1:
	valgrind ./proj4 proj4_map1.txt

val2:
	valgrind ./proj4 proj4_map2.txt

ta1:
	./proj4 $(IODIR)/ta1_data.txt

vta1:
	valgrind ./proj4 $(IODIR)/ta1_data.txt
