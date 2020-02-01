//cesar Hernandez - cherna83 - 675501405
//Lab 9 - Graphing sensor data on a PC
//Description:
//  Connect two analog devices to the arduino and plot the data received on the computer using processing.
//
//Assumption:
//            I used the following 2 analogs: potentionmeter A0 & photon resistor A1
//References:
//https://www.arduino.cc/en/Tutorial/Graph
//https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction
//https://www.processing.org/download/?processing
//Remarks: used the pde provided in the lab 


void setup() {
  //serial communication: established
  Serial.begin(9600);
}

void loop() {
  //Analog Data 1 for potenmeter to be read
  Serial.println(analogRead(A0));
  //Analog Data2 for photon resistor to be read
  Serial.println(analogRead(A1));
  delay(2);
}
