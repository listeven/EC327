CC=g++

OBJS=main.o Cart_Point.o Cart_Vector.o Game_Object.o Gold_Mine.o Soldier.o Miner.o Person.o Town_Hall.o Model.o View.o Game_Command.o

default: PA3

PA3: $(OBJS)
	$(CC) -o PA3 $(OBJS) 

Cart_Vector.o: Cart_Vector.cpp Cart_Vector.h
	$(CC) -c Cart_Vector.cpp -o Cart_Vector.o 
	
Cart_Point.o: Cart_Point.cpp Cart_Point.h Cart_Vector.h
	$(CC) -c Cart_Point.cpp -o Cart_Point.o 

Game_Object.o: Game_Object.cpp Game_Object.h Cart_Point.h Cart_Vector.h Input_Handling.h
	$(CC) -c Game_Object.cpp -o Game_Object.o 

Gold_Mine.o: Gold_Mine.cpp Gold_Mine.h Game_Object.h Cart_Point.h Input_Handling.h
	$(CC) -c Gold_Mine.cpp -o Gold_Mine.o 

Miner.o: Miner.cpp Miner.h Person.h Game_Object.h Gold_Mine.h Town_Hall.h Cart_Point.h Cart_Vector.h Input_Handling.h
	$(CC) -c Miner.cpp -o Miner.o 

Town_Hall.o: Town_Hall.cpp Town_Hall.h Game_Object.h Cart_Point.h Input_Handling.h
	$(CC) -c Town_Hall.cpp -o Town_Hall.o 

Person.o: Person.cpp Person.h Game_Object.h Cart_Point.h Cart_Vector.h Town_Hall.h Gold_Mine.h Input_Handling.h
	$(CC) -c Person.cpp -o Person.o

Soldier.o: Soldier.cpp Soldier.h Person.h Miner.h Game_Object.h Gold_Mine.h Town_Hall.h Cart_Point.h Cart_Vector.h Input_Handling.h
	$(CC) -c Soldier.cpp -o Soldier.o

Model.o: Model.cpp Model.h View.h Soldier.h Miner.h Person.h Game_Object.h Gold_Mine.h Town_Hall.h Cart_Point.h Cart_Vector.h Input_Handling.h
	$(CC) -c Model.cpp -o Model.o

Game_Command.o: Game_Command.cpp Game_Command.h Model.h Miner.h Person.h Game_Object.h Gold_Mine.h Town_Hall.h Cart_Point.h Cart_Vector.h Input_Handling.h
	$(CC) -c Game_Command.cpp -o Game_Command.o

View.o: View.cpp View.h Model.h Miner.h Person.h Game_Object.h Gold_Mine.h Town_Hall.h Cart_Point.h Cart_Vector.h Input_Handling.h
	$(CC) -c View.cpp -o View.o

main.o: main.cpp Input_Handling.h Cart_Point.h Cart_Vector.h Gold_Mine.h Soldier.h Miner.h Person.h Town_Hall.h Game_Object.h Model.h Game_Command.h View.h
	$(CC) -c main.cpp

clean: 
	rm $(OBJS) PA3

