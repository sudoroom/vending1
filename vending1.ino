byte pins [] = { 2,3,4,5,6,7,8,9,10,11,12,13,A0,A1,A2,A3,A4,A5 };

void setup() {
    pinMode(13, OUTPUT);
}

void loop() {
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
}
