Om spelet
-----------------------
Du �r "playerObjekt" och ditt m�l �r att undvika "enemies" s� l�nge som m�jligt.

Man kan antingen anv�nda musen eller de vanliga piltagenterna f�r att r�ra sin gubbe.

Man kan skjuta och d�rav d�da enemies


N�r man kolliderar men n�got s� �kar n�got annat, man f�rlorar po�ng




Add funktion s�ger helt enkelt "Ge mig din subklass fr�n SpriteObject och en path till bilden, s� fixar jag resten"

Programmets krav p� placering
-------------------------------
1. Alla bilder beh�ver ligga i /assets

SDL Milj� med Visual Studo (kortfattat):
1. Ladda ner SDL2-2.0.9
2. "Properties" -> "Additional Include Directories" -> "edit" -> "new" -> "g� till SDL2-2.0.9 mappen" -> "include" -> "klicka p� v�lj".
2. "Properties" -> "Linker" -> "Additional Library Directories" -> "edit" -> "new" -> "g� till SDL2-2.0.9 mappen" -> "lib" -> "x86" -> "klicka p� v�lj".
3. "Properties" -> "Linker" -> "Input" -> "Additional Dependencies" -> "Klistra in SDL2.lib, (ny rad), SDL2main.lib" -> "klicka p� ok".
4. Kopiera och klistra in SDL2.dll fr�n SDL2-2.0.9 till visual studio projektets map

5. Ladda ner SDL-Image.2.0.4

Samma som ovan fast med SDL2-Image mappen och  "Klistra in SDL2-Image.lib", samt kopiera och klistra in "SDL2-image.dll"