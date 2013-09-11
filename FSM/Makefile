BaseGameEntity.o: BaseGameEntity.cpp BaseGameEntity.h
	g++ -c BaseGameEntity.cpp -o BaseGameEntity.o

Soldier.o: Soldier.cpp State.h BaseGameEntity.h
	g++ -c Soldier.cpp -o Soldier.o

main.o: main.cpp BaseGameEntity.h State.h
	g++ -c main.cpp -o main.o



all:  BaseGameEntity.o Soldier.o main.o
	g++ BaseGameEntity.o Soldier.o main.o -o testFSM.out
clean:
	rm -rf BaseGameEntity.o Soldier.o main.o

