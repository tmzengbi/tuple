main: main.o
	g++ $^ -o main
main.o: main.cpp
	g++ -c main.cpp
.PHONY:rm 
rm:
	@rm main *.o
.PHONY:run
run:
	@./main
