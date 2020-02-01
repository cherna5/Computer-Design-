
//============================================================================================
//Initializing values 
int photoSens = A0;
int analogVal = 0;
int patCount = 0;   //Our pattern counter
//*************S
const int button = 7;
int buttonVal, buttonCnt;
const int LED = 11;

//============================================================================================
void setup() {
  Serial.begin(9600);   //debug purpose for PhotoResitor
  //Serial.begin(19200);  //debug purpose for Thermostat
  pinMode(A0, INPUT);   //photoResistor
  pinMode(A5, INPUT);   //ARDUINO 1
  pinMode(LED_BUILTIN, OUTPUT);
  //pinMode(10, HIGH);   //1 sphere
  pinMode(LED, HIGH);  //4 spheres
  pinMode(LED, OUTPUT);
  //pinMode(10, OUTPUT);
  //pinMode(11, OUTPUT);
  pinMode(button, INPUT);
  buttonCnt = 0;

}

//============================================================================================
//Holiday Tree lighting
void loop() 
{

 
  
  //analogVal.update();
  analogVal = analogRead(photoSens);
  Serial.println(analogVal);
  
  //digitalWrite(9, HIGH);
  ///*
  if(analogVal < 800){
    serial();
   allOn();
   allFlash();
   fade();
   nine2eleven();
  }
  //Lighting in Room is Lit enough to have lights off
  else if(analogVal > 800){
    digitalWrite(LED, LOW);
    //digitalWrite(11, LOW);
  }
  delay(250);
 //*/
}


//============================================================================================
void allOn(){
    while(patCount < 11){
      serial();
      analogVal = analogRead(photoSens);
      Serial.println(analogVal);
//      push();
        if(analogVal > 800){
          return;
        }
      digitalWrite(LED, HIGH);
      //digitalWrite(11, HIGH);
      delay(200);
      patCount++;
    }
  }

//============================================================================================
void allFlash(){
    while(patCount < 21){
      analogVal = analogRead(photoSens);
      Serial.println(analogVal);
       //push();
       if(analogVal > 800){
          return;
        }
      digitalWrite(LED, HIGH);
     // digitalWrite(11, HIGH);
      delay(275);
      //digitalWrite(10, LOW);
      digitalWrite(LED, LOW);
      delay(275);
      patCount++;
      }
  }

//============================================================================================
 void fade(){
  serial();
  int brightness = 0;    // how bright the LED is
  int fadeAmount = 5;    // how many points to fade the LED by
   while(patCount < 36){
      analogVal = analogRead(photoSens);
      Serial.println(analogVal);
      if(analogVal > 800){
          return;
      }
    // set the brightness of pin 9:
    analogWrite(LED, brightness);
    //analogWrite(11, brightness);
    
    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(20);
    patCount++;
  }
}//endFade

//=======================================================================================
void nine2eleven(){
   while(patCount < 56){
    serial();
      analogVal = analogRead(photoSens);
      Serial.println(analogVal);
      if(analogVal > 800){
          return;
      }
    digitalWrite(LED, HIGH);
    delay(250);
   // digitalWrite(11,HIGH);
    //delay(250);
   // digitalWrite(10, LOW);
   // delay(250);
    digitalWrite(LED, LOW);
    delay(250);
    patCount++;
  }
    while(patCount < 66){
      analogVal = analogRead(photoSens);
      Serial.println(analogVal);
      if(analogVal > 800){
          return;
      }
    //digitalWrite(10, HIGH);
    //delay(250);
    //digitalWrite(10,LOW);
    //delay(250);
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
    patCount++;
  }
  patCount = 0;
}//END 9 11

//=============================================================
void serial(){
   //$$$$$$$$$$$$$$$$$$$$$$$$-SERIAL-COMMUNICATION-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  buttonVal = digitalRead(button);
  if(buttonVal == HIGH) {
    buttonCnt++;
    delay(250);
  }

  Serial.write(buttonCnt);
  while(Serial.available()>0){
    if(Serial.read()%2 == 0){
      digitalWrite(LED, LOW);
      Serial.print("0");
     // digitalWrite(LED2, LOW);
    }
    else {
      digitalWrite(LED, HIGH);
      Serial.print("1");
     // digitalWrite(LED2, HIGH);
    }
  }
  //$$$$$$$$$$$$$$$$$$$$$$$$-CONTINUE-To-LIGHT-SHOW-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  
}
