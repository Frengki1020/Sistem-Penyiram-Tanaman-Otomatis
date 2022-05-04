#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 3)
#define sensor_capacitivesoil A2
#define relay 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  pinMode (relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Sensor Kelembaban Tanah: Mendeteksi dengan Analog Read yaitu A2
  int SensorValue_CapacitiveSoil = analogRead(sensor_capacitivesoil);
  //Menampilkan Hasil pembacaan Sensor
  Serial.println (SensorValue_CapacitiveSoil);

  //Print pada LCD
  lcd.setCursor(3, 0);
  lcd.print("=SMART GARDEN=");
  lcd.setCursor(2, 1);
  lcd.print("Moisture S1: ")

  //Cek kondisi jika hasil sensor kelembaban lebih besar dari 500
  //kondisi tanah kering
  //Sistem menyalakan Pompa
  if(SensorValue_CapacitiveSoil > 500){
      digitalWrite(relay, LOW);
      lcd.setCursor(15, 1);
      lcd.print(SensorValue_CapacitiveSoil);
      lcd.setCursor(4, 2);
      lcd.print("TANAH KERING");
      lcd.setCursor(5, 3);
      lcd.print("HIDUP KERAN");
    }
    //Cek kondisi jika hasil sensor kelembaban lebih kecil dari 500
    //kondisi tanah basah
    //Sistem mematikan Pompa
    else{
        digitalWrite(relay, HIGH);
        lcd.setCursor(15, 1);
        lcd.print(SensorValue_CapacitiveSoil);
        lcd.setCursor(4, 2);
        lcd.print("TANAH BASAH");
        lcd.setCursor(5, 3);
        lcd.print("MATI KERAN");
      }
}
