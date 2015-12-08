# Układy Sterujące, grupa nr 1 (środa 16-18)
zadania z ćwiczeń z 2.12.2015

Anna Gawłowska, Sebastian Sęk

Zadanie polegało na wyświetlaniu numeru wciśniętego przycisku klawiatury na wyświetlaczu siedmiosegmentowym, 
należało przerobić zadanie z poprzednich zajęć.

### Ćwiczenie 1 (cw4_zad1.c):
Zadanie zostało dokończone na czerwonej płytce z dodatkową klawiaturą, PIND odpowiada wejściu z klawiatury, sprawdzamy który przycisk został wciśnięty poprzez pobranie numeru wiersza i kolumny, następnie przypisujemy odpowiednią wartość z tablicy.
Do delay użyliśmy kilkuset przebiegów pustej pętli, w przerwaniu zamiast czasu jest tym razem numer przycisku pobrany w petli while funkcji main, dzięki czemu wyświetlana jest właściwa wartość. Aby być w stanie pobrać numer kolumny najpierw
ustawiamy DDRD = 0xF0; PORTD = 0x0F; i odwrotnie aby pobrać nr wiersza.
