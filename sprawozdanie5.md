## Układy Sterujące, grupa nr 1 (środa 16-18)
zadania z ćwiczeń z 16.12.2015  

Anna Gawłowska, Sebastian Sęk  

Zadanie polegało na wyświetleniu dowolnego tekstu na wyswietlaczu LCD.

#### cw5_functions.c:
Zostały zaimplementowane następujące funkcje:

* WriteNibble, WriteByte - przesyłają do wyświetlacza odpowiednio 4 i 8 bitów

* LCD_Command - ustawia linię RS w tryb instrukcji i przesyła instrukcję do wyświetlacza

* LCD_GoToXY - przestawia kursor 

* LCD_Text - ustawia linię RS w tryb danych i wypisuje znaki tekstu przestawiając przed każdym z nich kursor wykorzystując LCD_GoToXY 

* LCD_Initalize - implementuje inicjalizujące wyświetlacz instrukcje ze schematu dostępnego na 46 stronie dokumentacji sterownika

Program składa się z dwóch etapów:  
inicjalizacji wyświetlacza - wywołanie funkcji LCD_Initalize() i wyświetlenia tekstu - wywołanie funkcji LCD_Text("text").
