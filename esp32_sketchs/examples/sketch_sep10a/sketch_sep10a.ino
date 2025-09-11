// C++ Code
const int LED_RED     = 11;
const int LED_YELLOW  = 12;
const int LED_GREEN   = 13;
const int BUTTON      = 7;

// === Variables para botón ===
int lastButtonReading = HIGH;
int stableButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
int pressCount = 0;

// === Variables para intermitencia ===
bool blinkRed = false;
bool blinkYellow = false;
bool blinkGreen = false;
bool blinkState = false;
unsigned long prevMillis = 0;
const unsigned long interval = 500;

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);   

  Serial.begin(9600);
  printMenu();
}

void loop() {
  checkSerial();   
  checkButton();   
  handleBlink();   
}

// === Muestra menú ===
void printMenu() {
  Serial.println("Main menu:");
  Serial.println("[0] Toggle LED red (on/off)");
  Serial.println("[1] Turn on LED red");
  Serial.println("[2] Turn off LED red");
  Serial.println("[3] Turn on LED yellow");
  Serial.println("[4] Turn off LED yellow");
  Serial.println("[5] Turn on LED green");
  Serial.println("[6] Turn off LED green");
  Serial.println("[7] Turn on ALL");
  Serial.println("[8] Turn off ALL");
  Serial.println("[9] Intermitence ALL");
}

// === Lógica Serial monitor ===
void checkSerial() {
  if (Serial.available()) {
    char option = Serial.read();
    switch (option) {
      case '0': toggleRed(); break;
      case '1': digitalWrite(LED_RED, HIGH); blinkRed = false; break;
      case '2': digitalWrite(LED_RED, LOW); blinkRed = false; break;
      case '3': digitalWrite(LED_YELLOW, HIGH); blinkYellow = false; break;
      case '4': digitalWrite(LED_YELLOW, LOW); blinkYellow = false; break;
      case '5': digitalWrite(LED_GREEN, HIGH); blinkGreen = false; break;
      case '6': digitalWrite(LED_GREEN, LOW); blinkGreen = false; break;
      case '7': allOn(); blinkRed = blinkYellow = blinkGreen = false; break;
      case '8': allOff(); blinkRed = blinkYellow = blinkGreen = false; break;
      case '9': blinkRed = blinkYellow = blinkGreen = true; break;
    }
    printMenu();
  }
}

// === Lógica botón ===
void checkButton() {
  int reading = digitalRead(BUTTON);

  // Antirrebote
  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != stableButtonState) {
      stableButtonState = reading;
      // Detectar transición de HIGH a LOW
      if (stableButtonState == LOW) {
        pressCount++;
        if (pressCount > 6) pressCount = 1;  // Ciclo de 1 a 6
        doButtonAction(pressCount);
      }
    }
  }
  lastButtonReading = reading;
}

// === Acciones del botón ===
void doButtonAction(int action) {
  allOff();  
  blinkRed = blinkYellow = blinkGreen = false;

  Serial.print("Button action: ");
  Serial.println(action);

  switch (action) {
    case 1: digitalWrite(LED_RED, HIGH); break;
    case 2: digitalWrite(LED_GREEN, HIGH); break;
    case 3: digitalWrite(LED_YELLOW, HIGH); break;
    case 4: break;
    case 5: allOn(); break;
    case 6: blinkRed = blinkYellow = blinkGreen = true; break;
  }
}

// === Toggle LED rojo ===
void toggleRed() {
  blinkRed = false; 
  if (digitalRead(LED_RED) == HIGH) {
    digitalWrite(LED_RED, LOW);   
  } else {
    digitalWrite(LED_RED, HIGH);  
  }
}

// === Encender/apagar todos ===
void allOn() {
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_GREEN, HIGH);
}

void allOff() {
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
}

// === Intermitencia con millis ===
void handleBlink() {
  if (blinkRed || blinkYellow || blinkGreen) {
    unsigned long currentMillis = millis();
    if (currentMillis - prevMillis >= interval) {
      prevMillis = currentMillis;
      blinkState = !blinkState;
      
      if (blinkRed) digitalWrite(LED_RED, blinkState);
      if (blinkYellow) digitalWrite(LED_YELLOW, blinkState);
      if (blinkGreen) digitalWrite(LED_GREEN, blinkState);
    }
  }
}