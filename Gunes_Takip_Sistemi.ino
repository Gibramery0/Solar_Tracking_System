#include <Servo.h>

Servo servoX;  // Yatay servo motor
Servo servoY;  // Dikey servo motor

int ldr1Pin = A0;  // LDR1 (güneş panelinin ön tarafı)
int ldr2Pin = A1;  // LDR2 (güneş panelinin arka tarafı)
int ldr3Pin = A2;  // LDR3 (güneş panelinin sağ tarafı)
int ldr4Pin = A3;  // LDR4 (güneş panelinin sol tarafı)

int ldr1Value, ldr2Value, ldr3Value, ldr4Value;
int maxLDRValue, maxLDRIndex;

void setup() {
  Serial.begin(9600);
  
  servoX.attach(9);  // X ekseni servo motoru
  servoY.attach(10); // Y ekseni servo motoru
  
  // Başlangıç pozisyonları (0 derece)
  servoX.write(90);
  servoY.write(90);
}

void loop() {
  // LDR'lerin değerlerini oku
  ldr1Value = analogRead(ldr1Pin);
  ldr2Value = analogRead(ldr2Pin);
  ldr3Value = analogRead(ldr3Pin);
  ldr4Value = analogRead(ldr4Pin);
  
  // En yüksek ışık değerini bul
  maxLDRValue = ldr1Value;
  maxLDRIndex = 1;

  if (ldr2Value > maxLDRValue) {
    maxLDRValue = ldr2Value;
    maxLDRIndex = 2;
  }
  if (ldr3Value > maxLDRValue) {
    maxLDRValue = ldr3Value;
    maxLDRIndex = 3;
  }
  if (ldr4Value > maxLDRValue) {
    maxLDRValue = ldr4Value;
    maxLDRIndex = 4;
  }
  
  // Güneş panelini uygun yöne döndür
  if (maxLDRIndex == 1) {
    servoX.write(90); // Yatay eksende 90 derece
    servoY.write(45); // Dikey eksende 45 derece (örneğin)
  } else if (maxLDRIndex == 2) {
    servoX.write(90); // Yatay eksende 90 derece
    servoY.write(135); // Dikey eksende 135 derece
  } else if (maxLDRIndex == 3) {
    servoX.write(180); // Yatay eksende 180 derece
    servoY.write(90); // Dikey eksende 90 derece
  } else if (maxLDRIndex == 4) {
    servoX.write(0); // Yatay eksende 0 derece
    servoY.write(90); // Dikey eksende 90 derece
  }

  delay(500); // Yeni okuma için kısa bir bekleme
}
