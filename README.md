# Mrówka Langtona


## Sposób wywołania
Program jest uruchamiany z linii poleceń, a użytkownik może dostarczyć pewne argumenty w celu dostosowania parametrów symulacji.
gdzie:

-r liczba wierszy planszy,

-c liczba kolumn planszy,

-i liczba iteracji (kroków) symulacji.

-d początkowy kierunek (od 1 do 4)

-l czy plansza ma być losowa (0 to plansza białych pól, 1 to plansza na losowo czarno biała)

-f nazwa pliku do którego ma być zapisana mrówka


## Przykładowe działanie programu dla różnych ustawień:
Przykład 1:

./out -r 10 -c 10 -i 20

Wygeneruje symulację mrówki Langtona na planszy o rozmiarze 10x10 przez 20 kroków.

Przykład 2:

./out -r 5 -c 8 -i 15 -d 2 -f name

Symulacja dla planszy o rozmiarze 5x8 przez 15 kroków z początkowym kierunkiem na wschód i zapisuje do pliku name_15.txt
