#include <Servo.h>
Servo esc_signal;

void setup()
{
  esc_signal.attach(3);  //Specify here the pin number on which the signal pin of ESC is connected.
  esc_signal.write(30);   //ESC arm command. ESCs won't start unless input speed is less during initialization.
  delay(2000);            //ESC initialization delay.
}

void loop()
{
esc_signal.write(150);    //Vary this between 65-170 to change the speed of motor. Higher value, higher speed.
delay(7000);
esc_signal.write(55);
delay(1000000);
}
