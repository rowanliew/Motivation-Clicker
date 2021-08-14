const int buttonPin = 8;
int counter = 0;

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.init();
  lcd.clear();
  lcd.backlight();      // Make sure backlight is on

  lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
  lcd.print("Clicks:");
  lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
  lcd.print(counter);
}

void loop() {
  int buttonState;
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    counter++;
    lcd.clear();
    lcd.setCursor(2, 0);  //Set cursor to character 2 on line 0
    lcd.print("Clicks:");

    lcd.setCursor(2, 1);  //Move cursor to character 2 on line 1
    lcd.print(counter);
    delay(150);
  }
}
