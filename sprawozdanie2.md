# Układy Sterujące, grupa nr 1 (środa 16-18)
zadania z ćwiczeń z 18.11.2015

Anna Gawłowska, Sebastian Sęk


### Ćwiczenie 1 (cw2_zad1.c):

Ćwiczenie polegało na napisaniu programu, który zlicza ilość przerwań (wciśnięć przycisku na klawiaturze) i wyświetla ją binarnie na 7 diodach. Dioda pierwsza „miga”, za co odpowiada kod wewnątrz pętli while(1), z tego powodu też wynik jest przesuwany w funkcji obsługującej przerwanie o jeden bit w lewo.

### Ćwiczenie 2 (cw2_zad2.c):

Celem ćwiczenia było napisanie programu z wykorzystaniem mechanizmów fast pwm i OCR do przygaszania i rozświetlania diody w podobny sposób jak na pierwszych zajęciach. Nie zdążyliśmy na zajęciach, zatem dokończyliśmy zadanie w domu na trochę innej płytce (szczegółowe informacje w komentarzach zadania 2 w kodzie). Należało włączyć fast pwm poprzez ustawienie rejestru TCCR0 zgodnie z dokumentacją i użycie dwóch przycisków klawiatury, jednego do przygaszania diody, drugiego do procedury odwrotnej. Dodany został też delay 20 ms aby następowało to w miarę płynnie. Aby zwiększyć jasność należało zwiększyć wartość rejestru OCR0 i odwrotnie w przeciwnym wypadku.
