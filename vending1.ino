#define NUMROWS 5
#define NUMCOLS 10
byte rows [NUMROWS] = { 13,12,11,10,9 }; // relays connecting to positive DC
byte cols [NUMCOLS] = { 8,7,6,5,4,3,2,A2,A3,A4 }; // relays connecting to negative DC
unsigned long inputValue = 0;
unsigned long startMotorTime = 0;
#define PRIMEVAL 1000 // send this number plus the product number to dispense
#define MOTORTIMEOUT 3000 // maximum time motor can run

void setup() {
  Serial.begin(9600);
  Serial.println("vending1.ino");
  for (int i=0; i < NUMROWS; i++) pinMode(rows[i], OUTPUT);
  for (int i=0; i < NUMCOLS; i++) pinMode(cols[i], OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    inputValue = Serial.parseInt();
    Serial.println(inputValue);
    int vendNum = inputValue - PRIMEVAL;
    if ((vendNum >= 0) && (vendNum < NUMROWS*NUMCOLS)) {
      Serial.print("Dispensing product number ");
      Serial.print(vendNum);
      Serial.print(" on row ");
      Serial.print(vendNum / NUMCOLS);
      Serial.print(" and column ");
      Serial.print(vendNum % NUMCOLS);
      Serial.print(" on pin ");
      Serial.print(rows[vendNum / NUMCOLS]);
      Serial.print(" and pin ");
      Serial.print(cols[vendNum % NUMCOLS]);
      digitalWrite(rows[vendNum / NUMCOLS], HIGH);
      digitalWrite(cols[vendNum % NUMCOLS], HIGH);
      Serial.print(" ");
      startMotorTime = millis(); // store the time we started the motor
      byte progressBar = 0; // for displaying chars while motor turns
      while ((Serial.available() == 0) && (millis() - startMotorTime < MOTORTIMEOUT)){
        delay(100);
        Serial.print(progressBar);
        progressBar = (progressBar + 1) % 10; // count digits 01234567890123456...
      }
      while (Serial.available() > 0) Serial.read(); // empty the serial buffer
      Serial.println("and done.");
      digitalWrite(rows[vendNum / NUMCOLS], LOW);
      digitalWrite(cols[vendNum % NUMCOLS], LOW);
    }
  }
}
