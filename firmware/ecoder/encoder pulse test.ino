// N20 Motor Encoder Pulse Test
// Arduino D8 -> L298N IN1
// Arduino D9 -> L298N IN2
//
// Encoder:
// Yellow -> Arduino D2
// Green  -> Arduino D3
// Black  -> Arduino 5V
// Blue   -> Arduino GND

const byte IN1 = 8;
const byte IN2 = 9;

const byte encoderA = 2;
const byte encoderB = 3;

volatile unsigned long pulses = 0;

void countPulse() {
  pulses++;
}

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(encoderA, INPUT_PULLUP);
  pinMode(encoderB, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(encoderA),
    countPulse,
    RISING
  );

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  Serial.println("Encoder test starting...");
  delay(3000);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void loop() {
  static unsigned long lastTime = 0;

  if (millis() - lastTime >= 1000) {

    noInterrupts();
    unsigned long count = pulses;
    pulses = 0;
    interrupts();

    Serial.print("Encoder pulses per second: ");
    Serial.println(count);

    lastTime = millis();
  }
}
