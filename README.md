# Kalkulator na Arduino (Klawiatura 4x4 + LCD I2C)

Projekt w języku C++ dla platformy Arduino, który zmienia mikrokontroler w **w pełni funkcjonalny kalkulator arytmetyczny**. Do obsługi interfejsu wykorzystuje klawiaturę matrycową 4x4 oraz wyświetlacz LCD (podłączony przez konwerter I2C), co oszczędza cenne piny Arduino.

---

## 🧮 Główne funkcje i obsługa

Kalkulator obsługuje cztery podstawowe działania matematyczne oraz posiada system stanów pozwalający na wpisywanie wielocyfrowych liczb i obsługę błędów:

* **Wpisywanie liczb (`0-9`):** Wprowadzaj pierwszą liczbę, wybierz operację, a następnie wpisz drugą liczbę.
* **Operacje (Klawisze od A do D):**
  * `A` $\rightarrow$ Dodawanie (`+`)
  * `B` $\rightarrow$ Odejmowanie (`-`)
  * `C` $\rightarrow$ Mnożenie (`*`)
  * `D` $\rightarrow$ Dzielenie (`/`)
* **Obliczanie wyniku (`#`):** Zatwierdza wprowadzanie i wyświetla wynik na ekranie.
* **Reset / Wyczyść (`*`):** Resetuje pamięć kalkulatora, czyszcząc ekran i zerując zmienne.
* **Ochrona przed błędem:** Próba dzielenia przez zero wywoła komunikat `Blad dzielenia` na wyświetlaczu LCD.

---

## 📌 Podłączenie pinów (Schemat)

### 1. Klawiatura matrycowa 4x4
Konfiguracja pinów rzędów i kolumn zdefiniowana w kodzie:

| Klawiatura | Pin Arduino | Opis |
| :--- | :--- | :--- |
| **Rząd 1** | Pin `2` | Wiersz 1 klawiatury |
| **Rząd 2** | Pin `3` | Wiersz 2 klawiatury |
| **Rząd 3** | Pin `4` | Wiersz 3 klawiatury |
| **Rząd 4** | Pin `5` | Wiersz 4 klawiatury |
| **Kolumna 1** | Pin `6` | Kolumna 1 klawiatury |
| **Kolumna 2** | Pin `7` | Kolumna 2 klawiatury |
| **Kolumna 3** | Pin `8` | Kolumna 3 klawiatury |
| **Kolumna 4** | Pin `9` | Kolumna 4 klawiatury |

### 2. Wyświetlacz LCD 16x2 (I2C)
Wyświetlacz wykorzystuje magistralę I2C (`Wire.h`), co oznacza, że wymaga podłączenia tylko dwóch linii danych do odpowiednich pinów Twojej płytki Arduino (np. w Arduino Uno / Nano: **SDA $\rightarrow$ Pin A4**, **SCL $\rightarrow$ Pin A5**, oraz zasilanie **VCC** i **GND**).

---

## 📚 Wymagane biblioteki

Aby skompilować projekt, upewnij się, że masz zainstalowane w swoim środowisku Arduino IDE następujące biblioteki (możesz je pobrać przez Menedżer Bibliotek):
1. **Wire** (wbudowana w środowisko Arduino)
2. **Keypad** (autorstwa Mark Stanley, Alexander Brevig)
3. **Adafruit_LiquidCrystal** (biblioteka do obsługi LCD przez I2C od Adafruit)

---

## 🚀 Jak uruchomić?

1. Podłącz klawiaturę i wyświetlacz LCD I2C do swojej płytki Arduino zgodnie z powyższym opisem.
2. Otwórz Arduino IDE i zainstaluj brakujące biblioteki (`Keypad`, `Adafruit_LiquidCrystal`).
3. Wklej ten kod do edytora.
4. Wybierz odpowiedni model płytki oraz port COM w menu *Narzędzia (Tools)*.
5. Wgraj program (*Upload*) do mikrokontrolera.
