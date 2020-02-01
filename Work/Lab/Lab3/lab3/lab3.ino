
// include the library code:
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int stringLength = 0, itr = 0, setDelay = 250, LCDWidth = 16;
String myName = "Cesar", subString[16];

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  scroll(1, "Play hard or go home - ARG ");
}

void scroll(int line, String string) {
  stringLength = string.length();
  
  for (itr = LCDWidth; itr >= 0; itr--) {
    lcd.setCursor(0, line - 1);
    lcd.print(myName);
    lcd.setCursor(itr, line);
    lcd.print(string.substring(0, 16));
    delay(setDelay);
  }
  
  itr = 0;
  
  while (itr != stringLength) {
    itr++;
    lcd.setCursor(0, line);
    lcd.print(string.substring(itr,itr+16));
    delay(setDelay);
  }
}
