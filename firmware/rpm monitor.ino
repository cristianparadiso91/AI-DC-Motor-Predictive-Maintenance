RPM code is giving me approximately 514-517 RPM

  // GA12-N20 Motor + Encoder RPM Test
//
// Motor driver:
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

const byte ENCODER_A = 2;
const byte ENCODER_B = 3;

volatile unsigned long pulseCount = 0;

// Current calibration value to test
const float PULSES_PER_OUTPUT_REV = 350.0;

void countPulse() {
  pulseCount++;
}

void setup() {

  Serial.begin(9600);

  // Motor-driver pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // Encoder pins
  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);

  // Count every rising edge from encoder channel A
  attachInterrupt(
    digitalPinToInterrupt(ENCODER_A),
    countPulse,
    RISING
  );

  // Start with motor OFF
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  Serial.println("RPM test starting...");
  delay(3000);

  // Start motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void loop() {

  static unsigned long previousTime = 0;

  if (millis() - previousTime >= 1000) {

    // Safely copy pulse count
    noInterrupts();
    unsigned long pulses = pulseCount;
    pulseCount = 0;
    interrupts();

    // Calculate RPM
    float rpm =
      (pulses * 60.0) / PULSES_PER_OUTPUT_REV;

    // Display results
    Serial.print("Pulses/sec: ");
    Serial.print(pulses);

    Serial.print("   Motor Speed: ");
    Serial.print(rpm, 1);

    Serial.println(" RPM");

    previousTime = millis();
  }
}
