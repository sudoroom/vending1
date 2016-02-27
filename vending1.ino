#define NUMROWS 5
#define NUMCOLS 10
byte rows [NUMROWS] = { 13,12,11,10,9 }; // relays connecting to positive DC
byte cols [NUMCOLS] = { 8,7,6,5,4,3,2,A2,A3,A4 }; // relays connecting to negative DC
unsigned long inputValue = 0;
#define PRIMEVAL 987234

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
      Serial.println(vendNum);
      digitalWrite(rows[vendNum / NUMCOLS], HIGH);
      digitalWrite(cols[vendNum % NUMCOLS], HIGH);
      delay(1000);
      digitalWrite(rows[vendNum / NUMCOLS], LOW);
      digitalWrite(cols[vendNum % NUMCOLS], LOW);
    }
  }
}
