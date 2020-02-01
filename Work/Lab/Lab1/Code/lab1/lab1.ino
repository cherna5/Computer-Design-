//Cesar Hernandez
//cherna83

//LAB 2: Get started with Arduino

//Description: This code is suppose to light up 3 led's on-and-off
//             sequentially right after one is off the other turns on and etc.

//Assumptions: For this lab everything was as expected circuit wise.
//             It was just getting familiar with the ide that was new fopr me.

//References:  I used the tutorial provided in the instructions from there I was able 
//             to use the same code to light up the rest of the pins/led's.

void setup()
{
  pinMode(13, OUTPUT); //blue led
  pinMode(12, OUTPUT); //red led
  pinMode(8, OUTPUT);  //green led
}

void loop()
{
  digitalWrite(13, HIGH);   // Turn on the LED
  delay(1000);              // Wait for one second
  digitalWrite(13, LOW);    // Turn off the LED  
  delay(100);//slight fast  // Wait for one second

  digitalWrite(12, HIGH);   //Turns on led
  delay(1000);              //on for a second
  digitalWrite(12, LOW);    //Turns off led
  delay(100);               //off for a sec

  digitalWrite(8, HIGH);    //Turns on led
  delay(1000);              //on for a second
  digitalWrite(8, LOW);     //Turns off led
  delay(100);               //off for a second 
}
