game.exe: game.o Creature.o Player.o Monster.o Potion.o
	g++ game.o Creature.o Player.o Monster.o Potion.o -o game.exe
	rm -f Creature.o
	rm -f game.o
	rm -f Player.o
	rm -f Monster.o
	rm -f Potion.o

game.o:
	g++ -c game.cpp

Creature.o:
	g++ -c Creature.cpp

Player.o:
	g++ -c Player.cpp

Monster.o:
	g++ -c Monster.cpp

Potion.o:
	g++ -c Potion.cpp