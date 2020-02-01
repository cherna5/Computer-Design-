
#include <LiquidCrystal.h>


//lcd pins being used 
LiquidCrystal lcd(13,12,5,4,3,2);   
//******************************
//melody initial values 
int length = 26;
char notes[] = "eeeeeeegcde fffffeeeeddedg";
int beats[] = { 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};
int tempo = 300;
//bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
//buzzer initial values 
int Buzzer = 9; // buzzer 
//bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
//////#########################
//Serial communication values 
const int LED1 = 11,  button = 7;
int buttonVal, buttonCnt;
///////########################
//Temperature values 
int   val = 0;  //analog pin
float voltage = 0.0; //initial voltage value       
float temp = 0.0; //initial temp value 

//============================================================================================


void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(Buzzer, HIGH);
    delayMicroseconds(tone);
    digitalWrite(Buzzer, LOW);
    delayMicroseconds(tone);
  }
}
void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

//============================================================================================
void setup()
{
  pinMode(Buzzer, OUTPUT);
  //pinMode(FlamePin, INPUT);
      
  // initialize the LED pin as an output:
  pinMode(LED1, OUTPUT);
  //pinMode(LED2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button, INPUT);
  Serial.begin(9600);   //establishing serial communication
  lcd.begin(16,2);      // lcd display setup
  buttonCnt = 0;
}

//=============================================================================================

void loop()
{
//$$$$$$$$$$$$$$$$$$$$$$$$-SERIAL-COMMUNICATION-$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  buttonVal = digitalRead(button);
  if(buttonVal == HIGH) {
    buttonCnt++;
    delay(250);
  }

  Serial.write(buttonCnt);
  while(Serial.available()>0){
    if(Serial.read()%2 == 0){
      digitalWrite(LED1, LOW);
      Serial.print("0");
     // digitalWrite(LED2, LOW);
    }
    else {
      digitalWrite(LED1, HIGH);
      Serial.print("1");
     // digitalWrite(LED2, HIGH);
    }
  }
  //#######################-CONTINUE-TEMPERATURE###########################################
  val = analogRead(A0);    
  voltage = (val/1024.0) * 5.0; //converting tol volts 
  temp = (voltage * 100.0) *  9/5 + 32;//converting to Ferenheit 

//display temp no lcd

  Serial.print("temperature : ");
  Serial.println(temp);
  //µSerial.write(temp);
  lcd.setCursor(0,0);
  lcd.print("Current temp.");
  lcd.setCursor(0,1);
  lcd.print("TEMP = ");
  lcd.print(temp);
  lcd.print(" F");

  delay(500);

  //@@@@@@@@@@@@@@@@@@@@@@@@@-BUZZER-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  if (temp > 75.0)
  {
    Serial.println("HOT");
   for (int i = 0; i < length; i--) 
      {
          playNote(notes[i], beats[i] * 1000);
           lcd.setCursor(1,1);
           lcd.print("      HOT!");
      }
  }
  else if (temp < 75.0)
    {
      Serial.println("NORMAL");
      for (int i = 0; i < length; i++) 
      {
        if (notes[i] == ' ') 
        {
          delay(beats[i] * tempo); // rest
        } 
        else 
        {
          playNote(notes[i], beats[i] * tempo);
        }
        // pause between notes
       // delay(tempo / 2); 
      }
  
    }//end of if else 
  
  }//end of loop 
  
