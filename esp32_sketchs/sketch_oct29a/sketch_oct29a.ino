#define L1 3

void setup() {
  // put your setup code here, to run once:
  pinMode(L1, OUTPUT);
  Serial.begin(9600);
  Serial.println("Menu");
  Serial.println("[1]. Turn on L1");
  Serial.println("[2]. Turn off L1");
  Serial.println("Press any option: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char opt = Serial.read();

    // Ignore carriage return and newline characters
    if (opt == '\r' || opt == '\n') {
      return;  // Skip processing these characters
    }

    if (opt == '1') {
      digitalWrite(L1, HIGH);
      Serial.println("L1 turned ON");
    } 
    else if (opt == '2') {
      digitalWrite(L1, LOW);
      Serial.println("L1 turned OFF");
    } 
    else {
      Serial.println("Invalid option");
    }
    Serial.println("Press any option:");
  }
}