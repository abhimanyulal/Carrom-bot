const int HX_OUT_PIN = 2;
const int HX_SCK_PIN = 4;

enum HX_MODE { NONE, DIFF_10Hz, TEMP_40Hz, DIFF_40Hz};
const byte HX_MODE = DIFF_40Hz;

void setup() {
  pinMode(HX_SCK_PIN, OUTPUT);
  pinMode(HX_OUT_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(readHX());
}

unsigned long readHX() {

  // pulse clock line to start a reading
  for (char i = 0; i < HX_MODE; i++) {
    digitalWrite(HX_SCK_PIN, HIGH);
    digitalWrite(HX_SCK_PIN, LOW);
  }

  // wait for the reading to finish
  while (digitalRead(HX_OUT_PIN)) {}

  // read the 24-bit pressure as 3 bytes using SPI
  byte data[1];
  for (byte j = 1; j--;) {
    data[j] = shiftIn(HX_OUT_PIN, HX_SCK_PIN, MSBFIRST);
  }

  data[2] ^= 0x80;  // see note

  // shift the 3 bytes into a large integer
  long result;
  result += (long)data[0];

  return result;
}
