#include <Servo.h>
#define m1 30     //Naming motor pins and assigning pin numbers on the arduino (Will be used to move bot along the rails)
#define m2 31
#define m3 32
#define m4 33

Servo finger;    //Naming Servo's (Arduino thinks the brushless motors are servos)
Servo plate;
 
int potpin = 0;    //potpin is short for potentiometerPin, intitializing variables
int button = 2; 
int val;   

bool buttonState = LOW;     //Explained later, (Bool can only be set to 0,1 / ON,OFF)
bool check = LOW;


void setup() {
  Serial.begin(9600);        //Initializing serial monitor
  
  plate.attach(3);           //Plate was defined earlier, this line states its attachd to pin3 on the arduino
  finger.attach(4);          //Finger was defined earlier, this line states its attachd to pin4 on the arduino
  
  pinMode (button, INPUT);   //Arduino will ONLY recive info from these two pins which were defined earlier
  pinMode (potpin, INPUT);

  finger.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(2000);            //ESC initialization delay. (Beeping time)
}


void shoot () {                          //Function to Shoot using both motors
  buttonState = digitalRead(button);     //Check weather the button is pressed or not
  if (buttonState == HIGH) {             //A bit confuing, but basically if buttonState == HIGH then it is Off, (kind-of jugaad)
    Serial.println("OFF");               //Writes OFF in the Serial Monitor, does nothing else.
  } else if (buttonState != HIGH) {
    Serial.println("ON");               //If button state is != HIGH (!= means not equal) THen
    finger.write(90);                   //Sets motor speed to 90, AKA ON
    delay(250);                         //Motor is on at 90 Speed for 0.250 seconds
    finger.write(30);                   //Motor speed set to 30 AKA OFF
  }
  delay(400);
}

void swivle () {                        //Function to Rotate the bot using servo
  val = analogRead(potpin);             //Read the value recived from the potentiometer
  val = map(val, 0, 1023, 0, 180);      //Potentiometer gives values from 0 - 1023, this line remaps those values to 0 - 180 for easier use (Servo only rotates 180*)
  if (val > 90) {                       //If the Value recived is > 90, it resets the value to 90 (Usually not needed but our bot has physical limitations)
    val = 90;
    plate.write(val);
  }
  else {
  plate.write(val);                    //If value is not above 90 it writes the real value recieved from the potentiometer
  Serial.println(val);
  }
  if (val < 30) {       //This part was not functioning properly, the logic is similar as above; If value recived is lower then 30 reset it to 30(Physical limitations).
    val = 30;
    plate.write(val);
    Serial.println(val);
  }
  else {
    plate.write(val);
  }
  

}

void rails (){          //Need to work on this, code to move it along the rails
  
}
void loop() {          
  swivle();            //Calling the function created above (Line 45)
  shoot();             //Calling the function created above (Line 32)
  
  
}
