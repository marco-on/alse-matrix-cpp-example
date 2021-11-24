CC = g++
EXEC_NAME = Matrix_calc_1_1_0.bin

MAIN_FILE_NAME = main_matrix_calc.cpp
FUNCTIONS1_NAME = matrix_class_functions.cpp
FUNCTIONS2_NAME = array_operations.cpp

all: $(EXEC_NAME)

$(EXEC_NAME) : main.o class_functions.o other_functions.o
	$(CC) main.o class_functions.o other_functions.o -o $(EXEC_NAME)
	rm -f *.o
	
main.o : src/$(MAIN_FILE_NAME)
	$(CC) -c src/$(MAIN_FILE_NAME) -o main.o
	
class_functions.o : src/$(FUNCTIONS1_NAME)
	$(CC) -c src/$(FUNCTIONS1_NAME) -o class_functions.o

other_functions.o : src/$(FUNCTIONS2_NAME)
	$(CC) -c src/$(FUNCTIONS2_NAME) -o other_functions.o
	
clean:
	rm -f *.o
