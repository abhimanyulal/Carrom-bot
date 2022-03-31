
#define m1 6
#define m2 7
#define m3 8
#define m4 9
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode (m1, OUTPUT);
pinMode (m2, OUTPUT);
pinMode (m3, OUTPUT);
pinMode (m4, OUTPUT);
pinMode (5, OUTPUT);
pinMode (4, OUTPUT);
}
void forward() {
digitalWrite (4, LOW);
digitalWrite (m1, LOW);
digitalWrite (m2, HIGH);
digitalWrite (m3, LOW);
digitalWrite (m4, HIGH);
digitalWrite (5, HIGH);
}
void backward(){
digitalWrite (5, LOW);
digitalWrite (m1, HIGH);
digitalWrite (m2, LOW);
digitalWrite (m3, HIGH);
digitalWrite (m4, LOW);
digitalWrite (4, HIGH);
}
void still(){
digitalWrite (m1, LOW);
digitalWrite (m2, LOW);
digitalWrite (m3, LOW);
digitalWrite (m4, LOW);
digitalWrite (5, LOW);
digitalWrite (4, LOW);
}

void loop() {
  forward();
  delay(1000);
  backward();
  delay(1000);
  still();
  delay(100000000);
}
