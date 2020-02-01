//Cesar Hernandez
//cherna83-675501405

//Lab 8 - Interrupts

//Description:
//  When the first button is pressed, the display should display “Interrupt received! Press button 2 to continue”
//  When the user presses button 2 the display goes back to displaying "We have been waiting for X seconds", 
//  and restarts the time a 0 seconds.

//Assumptions:
// we were instructed to use 2 and 3 pins for this lab
// assuming that the lcd will work correct
// we can just move the pins from 2 and 3 connected to the lcd 
// and replace with the interrupts/buttons 


//References:
//https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll //lcd setup
//https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
//interruption communication setup

#include <LiquidCrystal.h>


LiquidCrystal lcd(12,11,7,6,5,4);
int secCount = 0; //keep time
int interruptButton = 2; //button 1
int timeButton = 3; //button 2
int state = 0; //for toggle 

void setup() 
{
  //lcd established
  lcd.begin(16, 2);
  //push button mode established
  pinMode(interruptButton,INPUT_PULLUP);
  pinMode(timeButton,INPUT); 
  //interruption communcations established 
  attachInterrupt(digitalPinToInterrupt(2),blink,CHANGE);
  attachInterrupt(digitalPinToInterrupt(3),reset,CHANGE);
  
}

void loop()
{
  //when no button is pushed 
  if(state != 1)
  {
  lcd.setCursor(0,0);
  lcd.print("We have been wa-");
  lcd.setCursor(0,1);
  lcd.print("iting for");
  lcd.setCursor(10,1);
  lcd.print(secCount);
  lcd.setCursor(13,1);
  lcd.print("sec");
  
   secCount++; // updating as time goes on
  }
  //when button is pushed 
  //Interruption button 
  else 
  {
    lcd.setCursor(0,0);
    lcd.print("Interrupion pre-");
    lcd.setCursor(0,1);
    lcd.print("-ss b2 to cont.");
  }
  delay(1000);
  lcd.clear();

}

//function that will allow us to move from 1 button to the other 
void blink()
{
  state = 0;
}

//reset the time when we toggle 
void reset()
{
  lcd.clear();
  secCount = 0;
  state = 1;
}
