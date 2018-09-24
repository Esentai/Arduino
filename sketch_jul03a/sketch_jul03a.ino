const int AnalogIn  = A0;
int n = 0;
int readingIn = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
Serial.println("OK");
}

void loop() {
  // put your main code here, to run repeatedly:
 // Serial.println(analogRead(AnalogIn));
  readingIn = analogRead(AnalogIn);
    n = (readingIn * 100) / 500;
    Serial.println(n);
    delay(500);
}
