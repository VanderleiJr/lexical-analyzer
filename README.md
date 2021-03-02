# lexical-analyzer
Analizador Léxico feito em C++ com ANTLR4 (4.9.1) para a disciplina de Construção de Compiladores - UFSCar - ENPE 2020/2

Lexical Analyzer made in C++ with ANTLR4 (4.9.1) for Compiler Construction subject - UFSCar - ENPE 2020/2

### Pré-requesitos
```
Java
cmake
uuid-dev
ANTLR4
```

### Instalando o ANTLR4
* Tenha o Java instalado
* Inicialmente, tenha privilégios SUDO
	```
	$ cd /usr/local/lib
	$ sudo curl -O https://www.antlr.org/download/antlr-4.9.1-complete.jar
	$ export CLASSPATH=".:/usr/local/lib/antlr-4.9.1-complete.jar:$CLASSPATH"
	$ alias antlr4='java -jar /usr/local/lib/antlr-4.9.1-complete.jar'
	$ alias grun='java org.antlr.v4.gui.TestRig'
	```

* Adicionando o alias no seu ~/.bashrc (ou ~/.bash_profile) e logo depois:
	```
	$ source ~/.bashrc (ou ~/.bash_profile)
	```

* Após, baixe o [ANTLR4 C++ Target](https://www.antlr.org/download/antlr4-cpp-runtime-4.9.1-source.zip), então, crie e extraia na pasta "antlr4-dir".
	```
	$ mkdir antlr4-dir
	$ unzip antlr4-cpp-runtime-4.9.1-source.zip antlr4-dir
	```

* Compile a biblioteca do ANTLR4
	```
	$ cd antlr4-dir
	$ mkdir build && mkdir run && cd build
	$ cmake .. -DANTLR_JAR_LOCATION=f/usr/local/lib/antlr-4.9.1-complete.jar
	$ make
	$ DESTDIR=../run make install
	```

* Copie os arquivos necessários para a pasta /usr com:
	```
	$ cd <antlr4-dir>/run
	$ cp -r usr /
	```

	Para conferir se os arquivos foram copiados com sucesso:
		```
		$ ls /usr/local/include/antlr4-runtime
		```

* Pode ser necessário a cópia de algumas bibliotecas para o seu sistema, elas estão na pasta "lexical-analyzer/lib/".
	```
	$ cp -r <lexical-analyzer>/lib/* /usr/local/lib/
	```

* Pronto, ANTLR4 instalado!

### Compilando o Código

* Simples
	```
	$ cd <lexical-analyzer>
	$ make
	```

### Executando o Código

* Caso queira somente executar o código, bastar baixar a source compilada com todas as dependências
	```
	$ ./lexical-analyzer.out <arquivo de entrada> <arquivo de saída>
	```