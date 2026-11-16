
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

Adafruit_LiquidCrystal lcd(0);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins, colPins, ROWS, COLS
);

long liczba1 = 0;
long liczba2 = 0;
long wynik = 0;

char znak = 0;
byte stan = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.clear();
}

void loop() {
  char klawisz = keypad.getKey();

  if (!klawisz) return;

  // Reset
  if (klawisz == '*') {
    liczba1 = 0;
    liczba2 = 0;
    wynik = 0;
    znak = 0;
    stan = 0;
    lcd.clear();
    return;
  }

  // Wybieranie dzialania
  if (klawisz == 'A' || klawisz == 'B' ||
      klawisz == 'C' || klawisz == 'D') {

    if (stan == 0 || stan == 2) {

      if (stan == 2) {
        liczba1 = wynik;
      }

      liczba2 = 0;
      znak = klawisz;
      stan = 1;

      lcd.clear();

      if (znak == 'A') lcd.print("+");
      if (znak == 'B') lcd.print("-");
      if (znak == 'C') lcd.print("*");
      if (znak == 'D') lcd.print("/");
    }
    return;
  }

  // Wpisywanie liczb
  if (klawisz >= '0' && klawisz <= '9') {

    int cyfra = klawisz - '0';

    if (stan == 0) {
      liczba1 = liczba1 * 10 + cyfra;

      lcd.setCursor(0, 0);
      lcd.print(liczba1);
    }
    else if (stan == 1) {
      liczba2 = liczba2 * 10 + cyfra;

      lcd.setCursor(1, 0);
      lcd.print(liczba2);
    }
    return;
  }

  // Obliczanie wyniku
  if (klawisz == '#' && stan == 1) {

    if (znak == 'A') wynik = liczba1 + liczba2;
    if (znak == 'B') wynik = liczba1 - liczba2;
    if (znak == 'C') wynik = liczba1 * liczba2;

    if (znak == 'D') {
      if (liczba2 == 0) {
        lcd.clear();
        lcd.print("Blad dzielenia");
        stan = 2;
        return;
      }

      wynik = liczba1 / liczba2;
    }

    lcd.clear();
    lcd.print("=");
    lcd.print(wynik);

    stan = 2;
  }
}
