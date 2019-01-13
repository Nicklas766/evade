Om spelet
-----------------------
Du är "playerObjekt" och ditt mål är att undvika "enemies" så länge som möjligt.

Man kan antingen använda musen eller de vanliga piltagenterna för att röra sin gubbe.

Man kan skjuta och därav döda enemies


När man kolliderar men något så ökar något annat, man förlorar poäng




Add funktion säger helt enkelt "Ge mig din subklass från SpriteObject och en path till bilden, så fixar jag resten"

Programmets krav på placering
-------------------------------
1. Alla bilder behöver ligga i /assets

SDL Miljö med Visual Studo (kortfattat):
1. Ladda ner SDL2-2.0.9
2. "Properties" -> "Additional Include Directories" -> "edit" -> "new" -> "gå till SDL2-2.0.9 mappen" -> "include" -> "klicka på välj".
2. "Properties" -> "Linker" -> "Additional Library Directories" -> "edit" -> "new" -> "gå till SDL2-2.0.9 mappen" -> "lib" -> "x86" -> "klicka på välj".
3. "Properties" -> "Linker" -> "Input" -> "Additional Dependencies" -> "Klistra in SDL2.lib, (ny rad), SDL2main.lib" -> "klicka på ok".
4. Kopiera och klistra in SDL2.dll från SDL2-2.0.9 till visual studio projektets map

5. Ladda ner SDL-Image.2.0.4

Samma som ovan fast med SDL2-Image mappen och  "Klistra in SDL2-Image.lib", samt kopiera och klistra in "SDL2-image.dll"