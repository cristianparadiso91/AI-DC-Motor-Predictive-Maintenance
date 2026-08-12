# Project Development Log

This document records the construction, testing, and results of the AI-based predictive maintenance system.

## Milestone 1 — Hardware Documentation

**Date:** July 12, 2026

### Work Completed

- Organized and photographed the project components.
- Identified the Arduino Uno R3.
- Identified two 12 V, 500 RPM N20 gearmotors.
- Identified the L298N motor driver.
- Identified the ACS712 current sensor.
- Identified the GY-521 MPU-6050 vibration sensor.
- Identified the DS18B20 temperature sensors.
- Confirmed the 12 V, 1 A power adapter.

### Result

The main electronic components were obtained and documented.

---

## Milestone 2 — Arduino Communication Test

**Date:** July 12, 2026

### Test Procedure

1. Connected the Arduino Uno to the computer using a USB cable.
2. Opened the Arduino IDE.
3. Selected Arduino Uno and the correct COM port.
4. Compiled and uploaded the Blink example.
5. Observed the built-in LED turning on and off once per second.

### Result

**Test passed.**

The Arduino Uno, USB cable, computer connection, and programming environment are working correctly.

### Evidence

- Component photograph: `images/components/initial-components.jpg`
- Blink-test video: `videos/arduino-blink-test.mp4`
- Test code: `firmware/blink-test/blink-test.ino`

## Milestone 3 — First Controlled Motor Test

**Date:** August 5, 2026

### Work Completed

- Mounted the 12 V N20 gearmotor securely.
- Connected the motor to the L298N motor driver.
- Connected the L298N control inputs to the Arduino Uno.
- Corrected the control connections using male-to-female jumper wires.
- Uploaded and tested the Arduino motor-control program.

### Result

The Arduino successfully controlled the DC motor through the L298N motor driver.

### Evidence

- Motor test video: `videos/first-controlled-motor-test.mp4`
- Wiring photograph: `images/assembly/motor-driver-wiring.jpg`
- Arduino code: `firmware/motor-control/motor-diagnostic.ino`

## Milestone 4 — Encoder Pulse Test

**Date:** August 12, 2026

### Work Completed

- Connected the GA12-N20 motor encoder to the Arduino Uno.
- Supplied the encoder with 5 V and GND from the Arduino.
- Connected encoder Channel A to Arduino digital pin D2.
- Connected encoder Channel B to Arduino digital pin D3.
- Used a solderless breadboard to make secure encoder connections.
- Uploaded an Arduino program to count encoder pulses.
- Successfully received encoder pulse data in the Serial Monitor.

### Result

The motor encoder successfully detected shaft rotation and transmitted pulse signals to the Arduino.

During testing, the Serial Monitor recorded pulse counts above zero, confirming that the encoder, Arduino, and wiring were functioning correctly.

### Evidence

- Arduino code: `firmware/encoder/encoder-pulse-test.ino`
- Test screenshot: `images/testing/encoder-pulse-test.jpg`
- Test video: `videos/encoder-pulse-test-working.mp4`

### Next Step

Convert the measured encoder pulses into motor RPM and display the motor speed in real time.

## Milestone 5 — Live Motor RPM Measurement

**Date:** August 12, 2026

### Objective

Measure the rotational speed of the GA12-N20 DC gearmotor using its built-in encoder and display the calculated RPM in real time through the Arduino Serial Monitor.

### Work Completed

* Used the motor's built-in encoder to monitor shaft rotation.
* Powered the encoder from the Arduino 5 V supply.
* Connected the encoder ground to Arduino GND.
* Connected encoder Channel A to Arduino digital pin D2.
* Connected encoder Channel B to Arduino digital pin D3.
* Used an interrupt-based Arduino program to count encoder pulses.
* Converted the measured pulse rate into an estimated motor RPM.
* Displayed both pulses per second and motor speed in the Arduino Serial Monitor.

### Test Results

During startup, the motor speed increased until reaching a stable operating condition.

Once stabilized, the encoder produced approximately **3000 pulses per second**.

Using the current calibration value of **350 counts per output-shaft revolution**, the calculated motor speed stabilized at approximately:

**514–517 RPM**

Example readings included:

* 3002 pulses/s → 514.6 RPM
* 3009 pulses/s → 515.8 RPM
* 3011 pulses/s → 516.2 RPM
* 3018 pulses/s → 517.4 RPM

The relatively small variation in the steady-state readings shows that the encoder is providing consistent rotational-speed measurements.

### Engineering Note

The value of **350 counts per output-shaft revolution** is currently being used as the encoder calibration value. This value will be verified or refined during later testing before it is treated as the final calibrated RPM measurement.

### Result

The Arduino successfully receives encoder pulses and converts them into a real-time estimate of motor speed.

This completes the first working RPM-monitoring stage of the predictive-maintenance system.

### Evidence

* Arduino RPM program: `firmware/encoder/rpm-monitor.ino`
* RPM test screenshot: `images/testing/live-rpm-test.jpg`
* RPM test video: `videos/live-rpm-test.mp4`

### Next Step

Collect a baseline set of RPM measurements while the motor operates normally. These measurements will later be compared with data from different motor conditions and additional sensors such as current, temperature, and vibration.
