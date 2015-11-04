# Układy Sterujące, grupa nr 1 (środa 16-18)


Anna Gawłowska, Sebastian Sęk


# Ćwiczenie 1 (GccApplication1.c):

Celem ćwiczenia było napisanie programu służącego do włączania diod w kierunku od lewej do prawej strony i z powrotem. Aby osiągnąć porządany rezultat - za pomocą przesunięcia bitowego „zapalamy” kolejne bity (począwszy od najmniej znaczącego) PORTA z delay równym 800 milisekund, następnie „wracając” włączamy bity począwszy od najbardziej znaczącego.

# Ćwiczenie 2 (GccApplication2.c):

Ćwiczenie polegało na włączaniu diód z różnymi poziomami intensywności, efekt „przygaszenia” osiągamy włączając diody na coraz krótszy okres czasu (od 150 ms do 0) i wyłączając na coraz dłuższy. Efekt odwrotny uzyskujemy odwracając proces (włączając diody na coraz dłuższy okres i wyłączając na coraz krótszy poprzez manipulację operacją _delay_ms(...).
