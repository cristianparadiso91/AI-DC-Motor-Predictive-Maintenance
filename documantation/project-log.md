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
