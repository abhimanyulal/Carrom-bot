const int trigPinA = 52;
const int echoPinA = 50;
const int trigPinB = 46;
const int echoPinB = 48;
unsigned long trigTimeA = 0;
unsigned long trigTimeB = 0;
unsigned long oldTime = 0;
unsigned long newTime = 0;
long timeDiff = 0;
bool A = false;
bool B = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (trigPinA, OUTPUT);
  pinMode (echoPinA, INPUT);
  pinMode (trigPinB, OUTPUT);
  pinMode (echoPinB, INPUT);
}

unsigned long clicker(int trigPin, int echoPin){
  unsigned long duration = 0;
  unsigned long distance = 0;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  return distance;
}

void loop() {
  char buf[50];
  unsigned long clickA = clicker(trigPinA, echoPinA);
  if (clickA < 11 && A == false){
    A = true;
    oldTime = millis();
  }
  unsigned long clickB = clicker(trigPinB, echoPinB);
  if (clickB < 11 && A == true){
    A = false;
    newTime = millis();
    timeDiff = newTime - oldTime;
    sprintf(buf, "oldTime %lu, newTime %lu, timeDiff %lu\n", oldTime, newTime, timeDiff);
    Serial.println(newTime);
    Serial.println(buf);
    sprintf(buf, "clickA %lu, clickB %lu", clickA, clickB);
    Serial.println(buf);
    
    /*Serial.println(oldTime);
    Serial.println("\n");
    Serial.println(newTime);
    Serial.println("\n");
    Serial.println(timeDiff);
    Serial.println("\n");*/
        delay(2000); 
    }  
  
}  
  
