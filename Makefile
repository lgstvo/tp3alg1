CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra -g # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp03 # nome do executavel que sera gerado, nao troque
TMPOUT=tp03.testresult

$(EXEC): src/main.cpp Station.o Controller.o
	$(CC) $(CFLAGS) src/main.cpp Station.o Controller.o -o $(EXEC)
	rm -rf Station.o
	rm -rf Controller.o

Station.o: src/classes/Station.cpp 
	$(CC) $(CFLAGS) -c src/classes/Station.cpp  -o Station.o

Controller.o: src/classes/Controller.cpp
	$(CC) $(CFLAGS) -c src/classes/Controller.cpp -o Controller.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf Station.o
	rm -rf Controller.o