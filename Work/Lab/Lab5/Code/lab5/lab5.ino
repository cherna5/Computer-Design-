
//Cesar Hernandez - 675501405
//cherna83

//LAB 5: Multiple inputs and outputs

//Description: leds will lit up if more darkness/shade is on the photon resistor
//             and if more light is emitted than the leds won't lit up as much.
//             Along with the buzzer, the sound/buzzing will be according to the sensing of the light emitted.

//Assumptions: Once the lighting of the leds can increase or decrease in brightness the volume of the buzzer should also mimic the amount of light being absorbed. 

//References:  Lab4/
               //http://www.ardumotive.com/how-to-use-a-buzzer-en.html
               //https://www.arduino.cc/reference/en/language/functions/math/map/
               //https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/

//              
//=======================================================


//using 4 leds 
const int numLeds = 4;
int led[numLeds] = {13,12,8,7}; //leds pins
const int photonPin = A0; //photon resistor
const int buzzerPin = 2;//buuz pin
int sensor_val= 0;//have to start with 0, initializing 
int ledlevel = 0;//led bright level

const int potentionPin = A1;//tone/volume measurement 
//-----------------------
void setup()
{
  int i = 0;
  Serial.begin(9600);//connectivity
  //loop for all leds and buzzing accros the circuit to work
  for (i = 0; i < numLeds; i++)//loop for all leds and buzzing accros the circuit to work
  {
    pinMode (led[i], OUTPUT);
    pinMode (buzzerPin, OUTPUT);
  }

  delay(1000);
}

//----------------------------------------

void loop()
{

sensor_val = analogRead(photonPin); // reading A0
Serial.println(sensor_val); //display in tool kit sketch 
Serial.println(buzzerPin);
ledlevel = map(sensor_val, 200 , 1024, 0 , numLeds+1); //divide the sensor val to all leds from 0-4 & 0-1023

double volume = analogRead(potentionPin); //read in the sound
volume = volume * 1.5; //manipulate the sound 


for (int i=0; i < numLeds; i++)
{
  if (i < ledlevel)
  { //if leds keep on getting a lot of darkness the leds will bright 
    digitalWrite(led[i], HIGH);
    tone (buzzerPin, volume); //sound increases
    
  }
  else
  { //more light than leds are at a lower light
    digitalWrite(led[i], LOW);

    tone (buzzerPin, volume); //volume pitch reduces
  
  }
  
}

 delay(sensor_val); 
 
}
//-----------------------------------------
