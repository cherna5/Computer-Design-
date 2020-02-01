//Cesar Hernandez - 675501405
//cherna83
 
//LAB 2: Input and Output

//Description: leds should increment and decrement when pressed on the button. 
//             This is run on a 3bit binary form therefore it should not pass 7 or run down 0.
//              (using 8, 9, and 10 as outputs) 

//Assumptions: Once it's done or passes with 7 all leds should be off therefore the state will be at state 0.

//References:  HW1 problem 1 with the whole binary bit formation. Arduino Tutorial Button, how to set up and develop code.
//              

//Also document what happens when you reach 7 and/or 0.
//On these states, at 0 they're all off and at 7 they're all on. Now when pushed they go on to 0 instead of 
//causing per say an overflow b/c of the masking I did to prevent a 4 bit binary form b/c we only want a 3 bit binary form.
//=======================================================
const int inc_buttonPin = 2;
const int dec_buttonPin = 1;

//array to use a for loop later
int pins[3] = {8, 9, 10};

int inc_buttonState = LOW;
int dec_buttonState = LOW;
int count = 0; //keeps count


//=======================================================
void setup() {

  //our pins from 0-2
  pinMode(pins[0], OUTPUT);
  pinMode(pins[1], OUTPUT);
  pinMode(pins[2], OUTPUT);
  
  //for buttons
  pinMode(inc_buttonPin, INPUT);
  pinMode(dec_buttonPin, INPUT);

}

//=======================================================
void loop() {

  inc_buttonState = digitalRead(inc_buttonPin);
  if(inc_buttonState == HIGH)
  {
    count += 1 % 8; //3 bits is 8 in binary form 
    //waits for you to release your finger on the button
    while(digitalRead(inc_buttonPin) == HIGH) { }
  }

  dec_buttonState = digitalRead(dec_buttonPin); 
  if(dec_buttonState == HIGH)
  {
    count -= 1 % 8; // 3 bits is 8 in binary form 
    //waits for you to release your finger on the button
    while(digitalRead(dec_buttonPin) == HIGH) { }
  }

  int current = 1;
  
  for(int i = 0; i < 3; i++)
  {
     if(count & current)//masking to convert into 3 bit binary
     { 
        digitalWrite(pins[i], HIGH);
     }
     else
     {
        digitalWrite(pins[i], LOW);
     }

     current = current << 1; //shifting by 1 position for next bit 
  }
  

  delay(100);
}
