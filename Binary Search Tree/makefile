
output : main.o perfomance_binart.o Binary_tree.o expression.o
	g++ main.o perfomance_binart.o Binary_tree.o expression.o -o output

main.o: main.cpp
	g++ -c main.cpp
perfomance_binart.o: perfomance_binart.cpp
	g++ -c perfomance_binart.cpp

Binary_tree.o: Binary_tree.cpp
	g++ -c Binary_tree.cpp
	
expression.o: expression.cpp
	g++ -c expression.cpp
	
clean:
	rm *.o output
	
	

