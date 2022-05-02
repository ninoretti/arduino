# LiquidCrystal.h
### #include <LiquidCrystal.h>
 Altri schemi di collegamento utilizzano porte diverse sulla scheda
 in questo scratch le porte usate sono:

const int RS=12, Enable=11, D4=5, D5=4, D6=3, D7=2;

#### print("Qui il testo o la stringa")
    // scrive un testo sul monitor

#### begin(16,2)
    //Inizializza il display:  colonne e righe

#### setCursor(c,r)
    //Posizione il cursore

    lcd.setCursor(0, 0); // top left  -> lcd.home()
    lcd.setCursor(15, 0); // top right
    lcd.setCursor(0, 1); // bottom left
    lcd.setCursor(15, 1); // bottom right

##### Funzioni poco utili
    autoscroll()
    noAutoscroll()

https://www.arduino.cc/en/Reference/LiquidCrystal
