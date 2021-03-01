lexer grammar LA;

// Lista de palavras chaves
PalvraChave			:	'algoritmo' | 'fim_algoritmo' | 'declare' | 'constante'
					| 'tipo' | 'literal' | 'inteiro' | 'real' | 'logico'
					| 'verdadeiro' | 'falso' | 'registro' | 'fim_registro'
					| 'funcao' | 'fim_funcao' | 'var' | 'leia' | 'escreva'
					| 'se' | 'entao' | 'senao' | 'fim_se' | 'caso' | 'seja'
					| 'fim_caso' | 'para' | '<-' | 'ate' | 'faca' | 'fim_para'
					| 'enquanto' | 'fim_enquanto' | 'retorne' | 'nao' | 'procedimento'
					| 'fim_procedimento';

//Operadores lógicos: devem ser reconhecidos primeiros, antes de serem uma cadeia
OP_LOGICO			: 	'e' | 'ou';

//Números Inteiros e Números Reais(separados por '.')
NUM_INT 			:	('0'..'9')+;
NUM_REAL 			: 	('0'..'9')+'.'('0'..'9')+;

//Identificadores, ou seja, as variáveis
IDENT 				:	(('a'..'z')|('A'..'Z')|'_')(('a'..'z')|('A'..'Z')|'_'|('0'..'9'))*;

//Strings com ' ' entre as palavras, inicadas por '"'
CADEIA				:	'"' ( ~('\n') )*? '"';

//Comentários ignorados de forma não gulosa para reconhecimento de erro
COMENTARIO			:	'{' ~('\n')*? '}' -> skip;

//Espaços podem ser ignorados, junto tabulação e retorno. A linha é usada para impressão de mensagens de erro
ESPACO				:	( ' ' | '\t' | '\r') -> skip;
LINHA				:	'\n';

//Simbolos Epspeciais utilizados
DELIMITADOR			: 	':';
ABRE_PAR 			: 	'(';
FECHA_PAR 			:	')';
ABRE_COL			: 	'[';
FECHA_COL			:	']';

//Operadores
OP_ARIT				:	'+' | '-' | '*' | '/' | '%' | '^' | '&';
OP_REL				:	'>' | '>=' | '<' | '<=' | '<>' | '=';
ATE 				:	'..';
VIRGULA				:	',';
PONTO 				:	'.';

//Todo símbolo especial não identificado, irá cair no ERRO
ERRO				:	.;