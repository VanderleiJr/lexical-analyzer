lexical-analyzer.out:	src/LA.cpp src/LA.h
	@echo Compilando...
	g++ -o lexical-analyzer.out main.cpp src/LA.cpp -I/usr/local/include/antlr4-runtime -L/usr/local/lib/ -lantlr4-runtime -w