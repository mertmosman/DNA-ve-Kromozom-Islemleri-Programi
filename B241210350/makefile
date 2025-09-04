all:derle bagla calistir
derle:
		g++ -c -I "./include" ./src/Main.cpp -o ./lib/Main.o
		g++ -c -I "./include" ./src/Kromozom.cpp -o ./lib/Kromozom.o
		g++ -c -I "./include" ./src/DNA.cpp -o ./lib/DNA.o
		g++ -c -I "./include" ./src/Gen.cpp -o ./lib/Gen.o
bagla:
		g++ ./lib/Main.o ./lib/Gen.o ./lib/Kromozom.o ./lib/DNA.o -o ./bin/program
calistir:
		./bin/program