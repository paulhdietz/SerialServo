// Serial Servo
// by Paul H. Dietz, 4/22/2014
//
// Allows an Arduino UNO to act like a Scott Edwards Mini Serial Servo Controller.
//
// Data Format:
//
// 9600 baud, 8-N-1
//
// Sync byte (255), Servo Num (2-13), Postion (0-254)
//
// Position to us:
//
// 6 * Position + 738
//
// 0 -> 738us, 254 -> 2262us
//
// This code is in the public domain. Use at your own risk.

#include <Servo.h>

byte ServoNum, ServoPos;

// Byte count for input
byte inCNT = 0;

// create servo objects
Servo servo2, servo3, servo4, servo5, servo6, servo7, servo8, servo9, servo10, servo11, servo12, servo13;

void setup()
{
  // Initialize serial:
  Serial.begin(9600);

  // Initialize Servos
  servo2.attach(2);
  servo3.attach(3);
  servo4.attach(4);
  servo5.attach(5);
  servo6.attach(6);
  servo7.attach(7);
  servo8.attach(8);
  servo9.attach(9);
  servo10.attach(10);
  servo11.attach(11);
  servo12.attach(12);
  servo13.attach(13);

}

/* Wait for data, then process

  inCNT keeps track of current state:

  0 – Waiting for sync byte
  1 – Sync byte received
  2 – Sync byte and ServoNum received

*/
void loop() {
  while (Serial.available()) {
    // get the new byte:
    byte inByte = Serial.read();
    if (inByte == 255) {
      // Sync found
      inCNT = 1;
    }
    else {
      if (inCNT == 1) {
        ServoNum = inByte;
        inCNT = 2;
      }
      else {
        if (inCNT == 2) {
          ServoPos = inByte;
          setServo();
          inCNT = 0;
        }
        else {
          inCNT = 0;
        }
      }
    }
  }
}

void setServo() {

  switch (ServoNum) {
    case 2:
      servo2.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 3:
      servo3.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 4:
      servo4.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 5:
      servo5.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 6:
      servo6.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 7:
      servo7.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 8:
      servo8.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 9:
      servo9.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 10:
      servo10.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 11:
      servo11.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 12:
      servo12.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
    case 13:
      servo13.writeMicroseconds((int)ServoPos * 6 + 738);
      break;
  }
}


