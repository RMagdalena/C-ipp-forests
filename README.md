# Forests, trees and animals

The program is a simulation of the creation of a world consisting of many unique forests, trees and animals. 
The program user can modify the virtual world according to specific rules and view its current state.


Some detailed information about the program in Polish can be found below.


# Lasy, drzewa, zwierzęta 

## Wstęp

Program jest symulacją tworzenia świata składającego się z wielu unikalnych lasów, drzew oraz zwierząt. 
Użytkownik programu może modyfikować wirtualny świat według konkretnych zasad oraz oglądać go wypisując jego aktualny stan.


## Opis działania programu
Po uruchomieniu programu na świecie nie ma żadnego lasu, żadnego drzewa ani żadnego zwierzęcia. Program czyta dane ze standardowego wejścia i wykonuje niżej opisane polecenia. 

W tych poleceniach parametr `las` jest nazwą lasu, parametr `drzewo` jest nazwą drzewa, a parametr `zwierzę` jest nazwą zwierzęcia. 

### Polecenie ADD

`ADD las` – Dodaje las.

`ADD las drzewo` – Dodaje las i drzewo w lesie.

`ADD las drzewo zwierzę` – Dodaje las, drzewo w lesie i zwierzę żyjące na tym drzewie.
Polecenie ADD dodaje tylko te byty, których brakuje. Ponowna próba dodania istniejącego już na świecie bytu jest ignorowana.

### Polecenie DEL

`DEL` – Usuwa wszystkie lasy, wszystkie w nich drzewa i wszystkie zwierzęta żyjące na tych drzewach.

`DEL las` – Usuwa las, wszystkie w nim drzewa i wszystkie zwierzęta żyjące na tych drzewach.

`DEL las drzewo` – Usuwa drzewo w podanym lesie i wszystkie zwierzęta żyjące na tym drzewie.

`DEL las drzewo zwierzę` – Usuwa zwierzę żyjące na danym drzewie w podanym lesie.
Polecenie DEL usuwa tylko te byty, które istnieją. Próba usunięcia nieistniejącego bytu jest ignorowana.


### Polecenie PRINT

`PRINT` – Wypisuje wszystkie lasy.

`PRINT las` – Wypisuje wszystkie drzewa w podanym lesie.

`PRINT las drzewo` – Wypisuje wszystkie zwierzęta żyjące na danym drzewie w podanym lesie.

`Polecenie PRINT` wypisuje nazwy bytów posortowane leksykograficznie rosnąco według rozszerzonych kodów ASCII, każdą nazwę w osobnym wierszu. Jeśli nie ma żadnego bytu do wypisania, to niczego nie wypisuje.


### Polecenie CHECK

`CHECK las` – Sprawdza, czy istnieje las o danej nazwie.

`CHECK las drzewo` – Sprawdza, czy istnieje drzewo o danej nazwie w podanym lesie.

`CHECK las drzewo zwierzę` – Sprawdza, czy na podanym drzewie w podanym lesie żyje zwierzę o danej nazwie.
W poleceniu CHECK można podać `gwiazdkę` jako wartość parametru z wyjątkiem ostatniego. Gwiazdka jest metaznakiem pasującym do dowolnej nazwy.


## Informacje wypisywane przez program i obsługa błędów

Program kwituje poprawne wykonanie polecenia, wypisując informację na standardowe wyjście:

`Dla poleceń ADD i DEL wiersz ze słowem OK.`

`Dla polecenia CHECK wiersz ze słowem YES lub NO zależnie od wyniku tego polecenia.`

Program wypisuje informacje o błędach na standardowe wyjście diagnostyczne:

Dla każdego błędnego wiersza, program wypisuje wiersz ze słowem ERROR.

Awaryjne zakończenie programu, np. na skutek niemożliwości zaalokowania potrzebnej pamięci, jest sygnalizowane kodem 1.

## Makefile
 W wyniku wywołania polecenia `make` powstaje program wykonywalny `forests`. 

Wywołanie `make clean` usuwa plik wykonywalny i dodatkowe pliki powstałe podczas kompilowania.

Wywołanie `make test` uruchamia skrypt testujący, domyślnie z testem "example".

## Skrypt testujący

Do programu dołączony jest skrypt testujący wywoływany poleceniem:
```
./test.sh prog dir

na przykład: 
./test.sh ./forests test/examples
```
Skrypt uruchamia program `prog` dla wszystkich plików wejściowych postaci `dir/*.in`.


## Uwagi 

1. Prawidłowe nazwy są ciągami niebiałych znaków rozszerzonego ASCII o kodach od 33 do 255. Nazwę prawidłowego polecenia i jego parametry oddzielają białe znaki (znaki ' ', '\t', '\v', '\f', '\r' w C o kodach ASCII odpowiednio 32, 9, 11, 12, 13). Każde prawidłowe polecenie pojawia się w osobnym wierszu zakończonym linuksowym znakiem przejścia do nowej linii (znak \n w C, kod ASCII 10). 

2. Program ignoruje:
- Puste i składające się z samych białych znaków wiersze.
- Wiersze rozpoczynające się znakiem #.
- Białe znaki na początku i końcu wiersz
