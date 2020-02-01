
const int led = 11, button = 7;
int buttonVal, buttonCnt;

void setup() {
  // put your setup code here, to run once:
  //lcd.begin(16,2);
  pinMode(led, OUTPUT);

  pinMode(button, INPUT);
  Serial.begin(9600);
  buttonCnt = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal = digitalRead(button);
  if(buttonVal == HIGH) {
    buttonCnt++;
    delay(250);
  }

  Serial.write(buttonCnt);
  while(Serial.available()>0){
    if(Serial.read()%2 == 0){
      digitalWrite(led, LOW);

    }
    else {
      digitalWrite(led, HIGH);

    }
  }
}
