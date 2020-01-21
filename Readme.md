# Latte

## Wymagania:

Clang obsługujący c++17.

## Kompilacja:

```bash
    make
```
Na studentsie kompiluje się około 15 minut więc polecam przejść się po herbatę, obejrzeć serial itp.

Wygeneruje to kompilator `latc_x86_64` oraz pomocniczą bibliotekę `latte_lib/latte_lib.o` zawierającą funkcje pomocnicze.

Kompilator generuje kod w assemblera x86_64 działający zarówno na Linuxie (students) jak i MacOS (Catalina).



## Zaimplementowane funkcjonalności 

* pełny front-end wraz z obsługą obiektów i tablic
* kompilacja do x86_64
* użycie rejestrów wewnąrz wyrażenia, czasem wykonuje niepotrzebnego pusha ale ogólnie jakoś ogarnia
* odśmiecanie

## Struktura projektu:

`Latte.xcodeproj` - projekt XCode  

`Latte/main.cpp` - kompilator (jedynie wczytanie pliku)  
`Tests` - pomocniczy projekt z testami  
`antlr4-runtime` - biblioteka parsera  
`Latte.g4` - gramatyka parsera  
`latte_lib` - pomocnicza biblioteka z którą linkują sie wygenerowane programy  
`Logic/` - logika kompilatora  
`Logic/assembler/` - reprezentacja instrukcji assemblera  
`Logic/ast/` - drzewo składni   
`Logic/ast_factory` - zamiana wyniku ANTLR4 na drzewo składni  
`Logic/environment` - środowiska (funkcji, bloku, typu itp.)  
`Logic/staticCheck` - wyjątki które mogą zostać zgłoszone podczas statycznego sprawdzania

## Logika

### Liczenie wyrażeń:

każde wyrażenie ma funckję 

```cpp

virtual void compile(
    AssemblerValue::Size type,
    std::list<std::unique_ptr<const AsmInstruction>> & compiled,
    Environment const * env,
    AsmRegistersHandler & handler,
    AsmLabelHandler & lblHandler,
    AsmRegister::Type destination
) const

```

`type` - w sumie nigdy nie użyty (początkowo rozważałem pisanie x32 i x64)  
`compiled` - wynik  
`env` - aktualne środowisko, pozwala wyjąć typy, zmienne funkcje itp  
`handler` - wie które rejestry były użyte i narzadanie zwalnia rejestr  
`lblHandler` - tworzy unikatowe labele  
`destination` - docelowy rejestr w którym ma znaleźć się wynik

liczenie a + b wygląda następująco  
zarezerwuj rejestr na a (r_a)  
wylicz a do r_a  
zarezerwuj rejestr na b (r_b)  
wylicz b do r_b (handler wie że r_a jest zajete)  
zsumuj r_a i r_b do destination  
zwolnij r_a i r_b

### Odśmiecanie:
counter jest zaimplementowany w bibliotece latte_lib.  
każdy napis na starcie ma licznik 1  
wyciągniecie wartości ze zmiennej podbija licznik o 1    
parametry funkcji które są napisami są przechowywane do fikcyjnych zmiennych  
w momencie wyjścia ze z bloku usuwane są wszystkie zmienne (w tym fikcyjne) co zminejsza liczniki o 1  
dodatkowo stmt_expr zmniejsza o 1 licznik swojego wyniku 

każdy program kończy się wywołaniem 
```cpp
void checkDelete();
```
które wypisze na ekran liczbę nieusuniętych napisów i scrashuje program jeśli jakiś został