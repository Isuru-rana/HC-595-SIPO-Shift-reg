int SER_Pin = 8; //pin 14 on 75HC595
int RCLK_Pin = 9; //pin 12 on 75HC595
int SRCLK_Pin = 10;//pin 11 on 75HC595

#define number_of_74hc595s 1

#define numOfRegisterPins number_of_74hc595s *8

boolean registers[numOfRegisterPins];

void setup() {
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);

  clearRegisters();
  writeRegisters();
}

void  clearRegisters() {
  for (int i = numOfRegisterPins - 1; i >= 0; i--) {
    registers[i] = LOW;
  }
}
void writeRegisters() {

  digitalWrite(RCLK_Pin, LOW);

  for (int i = numOfRegisterPins - 1; i >= 0; i--) {
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH);
}
void setRegisterPin(int index, int value) {
  registers[index] = value;
}

void loop() {
  for (int i = 0; i < numOfRegisterPins; i++) {
    setRegisterPin(i, HIGH);
    writeRegisters();
    delay(100);
    setRegisterPin(i, LOW);
  }
  for (int i = 0; i > -1; i--) {
    setRegisterPin(i, HIGH);
    writeRegisters();
    delay(100);
    setRegisterPin(i, LOW);
  }
}