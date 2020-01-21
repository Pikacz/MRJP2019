grammar Latte;

main: (topDef)* EOF;


topDef
:   function
|   type
;



type: Kclass Identifier extendBlock? '{' typeMember* '}';

extendBlock: Kextends Identifier;

typeMember
:   typeVar
|   function
;

typeVar: decType Identifier ';';

function: decType Identifier funcArgs block;

funcArgs
: ParBL ParBR
| ParBL arg (',' arg)* ParBR
;


arg: decType Identifier;

// ****** Statements ***********************************************************

stmt
:   ';'
|   block
|   decType decVar (',' decVar)* ';'               // int a = 1 
|   expr OAss expr ';'                             // a = 1
|   expr OPlusPlus ';'                             // a++
|   expr OMinusMinus ';'                           // a--
|   Kreturn expr ';'                               // return a
|   Kreturn ';'                                    // return 
|   Kif ParBL expr ParBR stmt                          // if(a)
|   Kif ParBL expr ParBR stmt  Kelse stmt              // if(a)else
|   Kwhile ParBL expr ParBR stmt                       // while(a)
|   expr ';'                                       // a
;


block: '{' stmt* '}';

decVar
:   Identifier
|   Identifier OAss expr
;

decType
:   typeName
|   decType OArrBL OArrBR
;


typeName
:   Identifier
|   Kint
|   Kstring
|   Kvoid
|   Kbool
;

// ***** Expressions ***********************************************************
expr: expr7;

expr7
: expr6 OOr expr7
| expr6
; 


expr6
: expr5 OAnd expr6
| expr5
;


expr5
: expr5 OLT expr4
| expr5 OLTE expr4
| expr5 OGT expr4
| expr5 OGTE expr4
| expr5 OEq expr4
| expr5 ONEq expr4
| expr4
;


expr4
: expr4 OPlus expr3
| expr4 OMinus expr3
| expr3
;


expr3
: expr3 OMul expr2
| expr3 OMod expr2
| expr3 ODiv expr2
| expr2
;


expr2
:   expr2 Dot Identifier
|   expr2 OArrBL expr OArrBR
|   expr2 ParBL callList? ParBR
|   expr1
;



expr1
:   expr1IntConstant
|   expr1StringConstant
|   expr1Variable
|   expr1BoolConstant
|   expr1Minus
|   expr1Not
|   expr1Par
|   expr1NewArray
|   expr1NewObject
|   expr1Null
;

expr1IntConstant:      IntLiteral;
expr1StringConstant:   StringLiteral;
expr1BoolConstant:     (KFalse | KTrue);
expr1Variable:         Identifier;
expr1Minus:            OMinus expr1;
expr1Not:              ONot expr1;
expr1Par:              ParBL expr ParBR;
expr1NewArray:         Knew decType OArrBL expr OArrBR;
expr1NewObject:        Knew Identifier;
expr1Null:             ParBL Identifier ParBR KNull;

callList
:   expr (',' expr)*
;



// ******* Operators ***********************************************************
OPlus: '+';
OMinus: '-';
ODiv: '/';
OMul: '*';
OMod: '%';
OPlusPlus: '++';
OMinusMinus: '--';
OAss: '=';
OLT: '<';
OLTE: '<=';
OGT: '>';
OGTE: '>=';
OEq: '==';
ONEq: '!=';
ONot: '!';
OAnd: '&&';
OOr: '||';
OArrBL: '[';
OArrBR: ']';
ParBL: '(';
ParBR: ')';
Dot: '.';


// ******** Keywords ***********************************************************
Kreturn: 'return';
Kwhile: 'while';
Kif: 'if';
Kelse: 'else';
Kclass: 'class';
Kextends: 'extends';

Knew: 'new';

Kint: 'int';
Kstring: 'string';
Kvoid: 'void';
Kbool: 'boolean';
KTrue: 'true';
KFalse: 'false';
KNull: 'null';


// ***** Identifiers ***********************************************************
Identifier: IdentifierStart (IdentifierContent)*;

fragment IdentifierStart: [a-zA-Z_];
fragment IdentifierContent: [0-9a-zA-Z_];
// ******** Integers ***********************************************************
IntLiteral: ([1-9]([0-9]*)) | '0' ;


// ********* Strings ***********************************************************
StringLiteral
: '"' SChar* '"'
;


fragment SChar
:   ~["\\\r\n]
|   '\\n'   // new line
|   '\\t'   // tab
|   '\\"'   // "
|   '\\\\'  // /
;

// ***** Whitespaces ***********************************************************
Whitespace
:   [ \t\n]+ -> skip
;

// ******** Comments ***********************************************************
BlockComment
:   '/*' .*? '*/' -> skip
;

LineComment
:    ('//'| '#') ~[\r\n]* -> skip
;