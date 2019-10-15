# Interpreter prostego języka z wbudowanym typem macierzy 2D

## Dokumentacja

Autor: Adrian Nadulny


# 1 Opis projektu
###    Projekt ma na celu wykonanie interpretera prostego języka z wbudowanym typem macierzy 2D. Język ma być wyposażony w zmienne, podstawowe konstrukcje sterujące (pętla i instrukcja warunkowa), możliwość definiowania funkcji. Ponadto język powinien obsługiwać wyrażenia matematyczne z uwzględnieniem priorytetu operatorów.

## Przyjęte założenia dla uproszczenia języka:
Jedynym typem wbudowanym jest typ macierzowy, który przechowuje tylko i wyłącznie liczby. Obsługiwane są tylko macierze jedno i dwuwymiarowe.
Istnieje możliwość traktowania macierzy jako operacji logicznych prawda/ fałsz, jeżeli wyznacznik macierzy wynosi 0 to w wyrażeniu warunkowym zwracany jest fałsz. Za to pozostałe macierze byłyby traktowane jako prawda.
Każdy program musi zawierać funkcję main (podobnie jak to jest w języku C++)
Operacje takie jak: utworzenie macierzy, wypisanie macierzy na standardowe wyjście, funkcja zwracająca wyznacznik macierzy; będą zdefiniowane w bibliotece standardowej języka
Funkcje są globalne i nie mogą być nadpisywane 
Dopuszczalne jest wykorzystanie funkcji zanim jej ciało pojawi się, czyli funkcja zostanie zdefiniowana. 
W wyrażeniach warunkowych wspierane są operacje logiczne, operacje arytmetyczne, jak i wywoływanie funkcji.


# 2 Zakładana funkcjonalność

- Odczytanie, parsowanie i analiza skryptów zapisanych w plikach tekstowych
- Kontrola poprawności wprowadzonych danych oraz poprawne zgłaszanie błędów wykrytych podczas kolejnych etapów analizy plików
- Wykonywanie poprawnie zapisanych instrukcji z plików skryptowych (bez generowania błędów)
- Wyświetlanie komunikatów o zaistniałych błędach analizy plików w prostej dla użytkownika formie, gdzie miejsce popełnionego błędy będzie jednoznacznie określone
- Wykonywanie operacji arytmetycznych na macierzach z uwzględnieniem priorytetu operatorów (), *, /, +, - 
- Wykonywanie wyrażeń logicznych uwzględniając priorytet operatorów (), ==, ||, &&
- Możliwość korzystania z instrukcji warunkowych oraz pętli
- Możliwość wypisania całej zawartość macierzy na standardowe wyjście
- Możliwość definiowania własnych funkcji oraz ich późniejsze wywołanie w skryptach


# 3 Biblioteka standardowa

Operacje na macierzach
operacje arytmetyczne (dodawanie, odejmowanie, mnożenie)


Funkcje generowania macierzy
generate(X, Y, fill) - generowanie macierzy X x Y o wypełnieniu wartością fill
generate2D (a, b, c, d) - generowanie macierzy 2x2 o wartościach a (lewy górny róg macierzy), b (prawy górny róg macierzy), c (lewy dolny róg macierzy), d(prawy dolny róg macierzy)

Funkcje macierzowe wykonywane na zmiennych wywołujących je:
determinant() - wypisanie wyznacznika macierzy na standardowe wyjście
getValue(x, y) - zwrócenie elementu macierzy z wiersza x i kolumny y
setValue(x, y, newValue) - wpisanie nowej wartości do elementu macierzy o numerze wiersza x oraz numerze kolumny y

Inne funkcje:
    print( matrix ) - wypisanie zawartości macierzy matrix na standardowe wyjście
    printf( text ) - wypisanie statyczne podanego ciągu znakowego text

# 4 Środowisko

Program zostanie zaimplementowany w języku C++ i pierwotnie będzie uruchamiany w środowisku Visual Studio na Windows 10.


# 5 Budowa programu:

Program będzie złożony z modułów odpowiedzialnych za kolejne etapy analizy plików wejściowych, oraz z dodatkowych modułów pomocniczych, wspomagających cały proces. Proces analizy wraz z wykonaniem skryptów będzie odbywał się w następujących kolejnych etapach:
Analiza leksykalna (moduł lexera) + Analiza składniowa (moduł parsera)
Analiza semantyczna (moduł analizatora semantycznego)
Wykonanie zbioru instrukcji (moduł wykonawczy)


Analiza leksykalna: 
Moduł lexera będzie odpowiedzialny za zamianę skryptu w otwartym pliku wejściowego na tokeny,  które będą wykorzystywane przez analizator składniowy. Lexer będzie odczytywał znak po znaku,  do czasu stwierdzenia odczytania całości sekwencji odpowiadającej jednemu z  rozpoznawanych i akceptowanych tokenów języka. Tokeny te będą zwracane do parsera,  jeden po drugim, każdy dla pojedynczego wywołania metody lexera “odczytaj następny  token” przez parser.  Moduł ten będzie wspierany przez moduł obsługi pliku wejściowego oraz tablicę  akceptowalnych tokenów.  

Analiza składniowa 
Moduł parsera będzie pracował przy współpracy analizatora leksykalnego, ładując za jego  pomocą kolejne tokeny. Jego zadaniem jest sprawdzenie, czy wszystkie rozpoznane  tokeny są ułożone zgodnie ze zdefiniowaną gramatyką języka. Po pobraniu tokena,  analizator decyduje którą ścieżką ma teraz podążać, stopniowo schodząc w głąb  analizowanego skryptu. Wymagane będą do tego odpowiednie procedury rozbioru.  Zatwierdzone struktury gramatyczne będą tworzyć drzewo składniowe

Analiza semantyczna 
Moduł analizatora semantycznego ma za zadanie sprawdzić poprawność utworzonego przez analizator składniowy drzewa. Analizator zstępuje w głąb drzewa,  analizując zgodność skryptu, tj. poprawność używanych identyfikatorów, brak  nadpisywania identyfikatorów funkcji (zarówno tych ze “standardowej biblioteki” jak i  zdefiniowanych przez użytkownika), zgodność kontekstów operacji arytmetycznych czy  logicznych, zgodność ilości parametrów wywołań funkcyjnych itd.  Podczas sprawdzania, generowane jest drzewo reprezentacji instrukcji do wykonania. 


Wykonanie zbioru instrukcji 
Moduł wykonawczy ma za zadanie sekwencyjne wykonanie instrukcji zawartych w drzewie  wytworzonym na poprzednich etapach. Na tym poziomie jedynymi błędami jakie mogą się pojawić, są błędy związane z zawartościami zmiennych ­ np. nieodpowiednie argumenty  do operacji dodawania dwóch macierzy (niezgodność rozmiarów macierzy).  Po wykonaniu wszystkich instrukcji program kończy swoje działanie.  


# 6 Obsługa programu

Program będzie prostą aplikacją konsolową, uruchamianą przez wywołanie wraz z przekazaniem ścieżki do pliku ze skryptem, do interpretacji.
Wynik poszczególnych etapów analizy pliku, wynik interpretacji końcowej i wykonania będzie wyświetlany na standardowym wyjściu. W zależności od analizy, na standardowe wyjście mogą być zgłaszane błędy analizy pliku, błędy składniowe, błędy semantyczne lub wynik wykonania skryptu. Ponadto, jest możliwość zapisywania wyników do pliku, poprzez przekierunkowanie wyjścia bezpośrednio do pliku.


# 7 Przykład: 

    function simple(parameter) {
        printf("Parameter w funkcji simple");
        print(parameter);
        return parameter + 1;
    }

    function main() {
        var p = simple(-3);
        var q = (4 - simple(p) * 3);
        print(p);
        print(q);
        var p1 = generate2D(0,0,1,0);
        if((p != -3 && 2 == 1 + 2 || ((p1)))){
            print(1);
        }

        var t = (-7);
        var t1 = (-(-7))*(-1);
        var t2 = (-t);
        print(t);
        print(t1);
        print(t2);

        printf("");
        var matrix = generate(3, 1, 1);
        print(matrix);
        printf("Determinant: ");
        print(matrix.determinant());

        return 0;
    }


# 8 Lista tokenów:
“if” ,  “while” ,  “else” ,  “(” ,  “)” ,  “return” ,  “+” ,  “-” ,  “*” ,  “!” ,  “=” ,  “var” ,  “||” ,  “&&” ,  “==” ,  “!=” ,  “;” ,  “,” ,  “{” ,  “}” ,  “<” ,  “>” ,  “<=” ,  “>=” ,  “/”,  “.” ,  “function” ,  “#”, “continue”, “break” ,   “ " ”,  “printf”, “_”,  “[” ,  “]”



## Gramatyka
program = { functionDef }
functionDef = “function” identifier “(“ [ parameters ]“)” statementBlock 
parameters =  identifier { “,” identifier } 

statementBlock = “{“ { ifStatement | whileStatement | returnStatement | initStatement “;” | assignOrFunctionCall “;” |  “continue” “;” | “break” “;” | printStatement } “}” 
ifStatement = “if” “(” logicExpr “)” statementBlock [ “else” statementBlock ] 
whileStatement = “while” “(“ logicExpr“)” statementBlock 
returnStatement = “return” mathExpr “;” 
initStatement = “var” identifier [ restOfAssignStatement ]
assignOrFunctionCall = identifier ( restOfAssignStatement | functionCall )
printStatement = “printf” “(” ( stringLiteral ) “)” “;”

restOfAssignStatement = assignmentOp mathExpr 
functionCall = [ “.”  identifier ] “(” [ arguments ] “)” 
arguments = mathExpr { “,” mathExpr }

mathExpr = multiplicativeExpr { additiveOp multiplicativeExpr }
multiplicativeExpr = baseMathExpr { multiplicativeOp baseMathExpr}
baseMathExpr = [ unaryMathOp ] ( literal | variable | parentMathExpr ) 
parentMathExpr = “(“ mathExpr “)”

logicExpr = andExpr { orOp andExpr }
andExpr = relationalExpr { andOp relationalExpr 
relationalExpr = baseLogicExpr [ relationOp baseLogicExpr ] 
baseLogicExpr  = [ unaryLogicOp ] ( mathExpr | parentLogicExpr )
parentLogicExpr = “(“ logicExpr “)”

assignmentOp = “=”
unaryLogicOp = “!”
unaryMathOp = “-”
orOp = “||”
andOp = “&&”
relationOp = “<” | “>” | “<=” | “>=” | “==” | “!=” 
additiveOp = “+” | “-”
multiplicativeOp = “*” | “/” 

literal = numberLiteral
variable = identifier [ functionCall ]
numberLiteral = digit { digit } [ “.” { digit } ]

stringLiteral = ‘ “ ‘ { allCharacters - ‘ “ ‘ } ‘ “ ‘ 
identifier = letter { digit | letter | specialSign }
commentary = “#” { allCharacters - “#” } “#”

letter = “a” .. “z” | “A” .. “Z”
digit = “0” .. “9”
specialSign = “_”
allCharacters = ? all visible characters ?

