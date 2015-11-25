# Układy Sterujące, grupa nr 1 (środa 16-18)
zadania z ćwiczeń z 25.11.2015

Anna Gawłowska, Sebastian Sęk

Zadanie polegało na wyświetlaniu liczby sekund na czterech wyświetlaczach siedmiosegmentowych, która upłynęła od momentu uruchomienia programu. 

### Ćwiczenie 1 (cw3_zad1.c):
W pierwszej wersji zadania program nie korzysta z mechanizmu obsługi przerwań. 
W pętli while co 1000 milisekund zwiększamy zmienną zliczającą czas. Na jej podstawie, co jedną milisekundę wypisujemy odpowiednie cyfry, po kolei na każdym z wyświetlaczy.

### Ćwiczenie 2 (cw3_zad2.c):
W drugiej wersji program wykorzystuje mechanizm obsługi przerwań. 
Na podstawie dokumentacji konfigurujemy rejestry TCCR0, OCR0 i TIMSK.
Funkcja ISR obsługuje przerwanie TIMER0_COMP_vect zwiększając co 1000 milisekund zmienną zliczającą czas i wypisując cyfry na wyświetlaczach, nie korzystając już z funkcji delay.
