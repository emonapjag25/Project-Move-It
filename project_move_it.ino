//tell code to use servo library
#include <Servo.h>
#define DOOR_PIN 2 //defines the motor at pin 2
#define OPEN_BUTTON 10 //defines the button at pin 10
#define RED_LED 3 //defines the red LED at pin 3
#define GREEN_LED 4 //defines the green LED at pin 4

//makes a servo object
Servo door;

void setup() { // the code here runs once
  door.attach(DOOR_PIN); //conncting the servo object to the pin
  pinMode(OPEN_BUTTON, INPUT); //defines the button as an input
  pinMode(RED_LED, OUTPUT); //defines the red LED as an output
  pinMode(GREEN_LED, OUTPUT); //defines the green LED as an output
  door.write(0); //set start of the propeller to 0 degrees
  delay (1000); //wait 1000 milliseconds
  Serial.begin(9600);
  Serial.setTimeout(10);
} //end of void setup

void loop() { // the code here runs repetedly
// Serial.println(digitalRead(OPEN_BUTTON));
  if(digitalRead(OPEN_BUTTON)==1){//if the button is pressed
    Serial.println("pressed");//"pressed" will be printed on the serial monitor
    door.write(90); //the motor moves 90 degrees
    digitalWrite(GREEN_LED, HIGH); //the green light turns on
    delay (5000); //wait 5000 milliseconds
    door.write(-90); //the motor moves backward 90 degrees
    digitalWrite(GREEN_LED, LOW); //the green light turns off
    digitalWrite(RED_LED, HIGH); //the red light turns on
    delay (1000); //wait 1000 milliseconds
    digitalWrite(RED_LED, LOW); //the red light turns off

  } else{ //if the button is not pressed
    door.write(0); //the motor stays at zero, does not move
    delay (1000); //wait 1000 milliseconds
    Serial.println("not pressed"); //"not pressed" will be printed on the serial monitor
  }//end of if else statement
}//end of void loop