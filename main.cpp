/*
Lexical Analyzer with ANTLR4

Made by Vanderlei Junior
https://github.com/VanderleiJr
*/

#include <fstream>
#include <iostream>

#include "antlr4-runtime.h"
#include "src/LA.h"

using namespace std;
using namespace antlr4;


int main(int argc, char *argv[]){

  //Contador de linhas para informar o erro na linha exata ao usuário
  unsigned int lineCount = 1;

  //Declaração dos arquivos de entrada e saída recebidos via argumento
  ifstream dadosEntrada;
  ofstream dadosSaida;
  dadosEntrada.open(argv[1]);
  dadosSaida.open(argv[2], std::fstream::trunc);  //Usado para criar sempre um arquivo novo, caso o anterior já exista

  ANTLRInputStream input(dadosEntrada);
  LA lexer (&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens()) {
    if(token->getText().compare("<EOF>")){
      // '/n' não são totalmente ignorados, eles são usados para contas as linhas, porém, não geram tokens na tela/arquivo
      if(token->getText().compare("\n") == 0){
        lineCount++;
        continue;
      }
      // Quando algum ERRO é encontrado
      if(token->getType() == 20){
        dadosSaida << "Linha "<< lineCount <<": ";
        // Cadeia literal não fechada, falta de '"' no final da string
        if(token->getText() == "\""){
          dadosSaida << "cadeia literal nao fechada" << endl;
        // Comentário não fechado por '}'
        } else if(token->getText() == "{"){
          dadosSaida << "comentario nao fechado" << endl;
        // Símbolo desconhecido
        } else {
          dadosSaida << token->getText() << " - simbolo nao identificado" << endl;
        }
        
        // Fechar os arquivos após o ERRO encontrado
        dadosEntrada.close();
        dadosSaida.close();
        return 0;
      }
      // Se for um NUM_INT, NUM_REAL, IDENT ou CADEIA, o método de impressão é diferente dos outros.
      if(token->getType() > 2 && token->getType() < 7){
        dadosSaida << "<'" << token->getText() << "'," << lexer.getRuleNames()[token->getType()-1] << ">" << endl;
      } else {
        dadosSaida << "<'" << token->getText() << "','" << token->getText() << "'>" << endl;
      }
    } 
  }

  //Fechamento dos arquivos abertos pelo analisador
  dadosEntrada.close();
  dadosSaida.close();

  return 0;
}

