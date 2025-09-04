// C++ code
char opt; // Variable public
int const LEDRED = 4;
int const LEDGREEN = 1;
int const LEDYELLOW = 2;

void setup() {
    pinMode(LEDRED, OUTPUT);
    pinMode(LEDYELLOW, OUTPUT);
    pinMode(LEDGREEN, OUTPUT);
    Serial.begin(9600); // Baudios
    Serial.println("WELCOME");
    Serial.println("Press any key to continue");
}
void loop() {
    if (Serial.available() > 0) {
        mainMenu();
        opt = Serial.read();
        if (opt == '1') {
            digitalWrite(LEDRED, HIGH);
        } else if (opt == '2') {
            digitalWrite(LEDRED, LOW);
        } else if (opt == '3') {
            digitalWrite(LEDYELLOW, HIGH);
        } else if (opt == '4') {
            digitalWrite(LEDYELLOW, LOW);
        } else if (opt == '5') {
            digitalWrite(LEDGREEN, HIGH);
        } else if (opt == '6') {
            digitalWrite(LEDGREEN, LOW);
        } else if (opt == '7') {
            digitalWrite(LEDRED, HIGH);
            digitalWrite(LEDGREEN, HIGH);
            digitalWrite(LEDYELLOW, HIGH);
        } else if (opt == '8') {
            digitalWrite(LEDRED, LOW);
            digitalWrite(LEDGREEN, LOW);
            digitalWrite(LEDYELLOW, LOW);
        } else if (opt == '9') {
            digitalWrite(LEDYELLOW, HIGH);
            digitalWrite(LEDGREEN, LOW);
            digitalWrite(LEDYELLOW, HIGH);
        } else if (opt == '10') {
            digitalWrite(LEDRED, LOW);
            digitalWrite(LEDGREEN, LOW);
            digitalWrite(LEDYELLOW, LOW);
        }
    }
}

void mainMenu() {
  Serial.println("Please select an option: ");
  Serial.println("Main menu");
  Serial.println("[1]. Turn on the LED RED");
  Serial.println("[2]. Turn off the LED RED");
  Serial.println("[3]. Turn on the LED YELLOW");
  Serial.println("[4]. Turn off the LED YELLOW");
  Serial.println("[5]. Turn on the LED GREEN");
  Serial.println("[6]. Turn off the LED GREEN");
  Serial.println("[7]. Turn on all");
  Serial.println("[8]. Turn off all");
  Serial.println("[9]. Intermitent mode");
  Serial.println("[10]. Exit");
}