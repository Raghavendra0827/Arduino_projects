#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows



byte customChar1[8] = {
  0b00100,
  0b01110,
  0b11111,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};
unsigned long overallStartTime;
unsigned long blinkStartTime;
unsigned long overallPeriod = 5000;
unsigned long blinkPeriod = 200;
unsigned long currentTime; 
               
const int microseconds;       
long duration, cm, inches;                 
unsigned long myTime;                    
const int TRIG_PIN = 6; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 7; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int LED_PIN  = 3; // Arduino pin connected to LED's pin
const int DISTANCE_THRESHOLD = 2; // centimeters

// variables will change:
float duration_us, distance_cm;
float duration_us1, distance_cm1;
float duration_us2, distance_cm2;

void setup() {   
  Serial.begin (9600);       // initialize serial port
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);
   pinMode(11, OUTPUT); 
  pinMode(9, OUTPUT); 
  lcd.begin(16, 2);
  //  lcd.createChar(1, customChar1); 
  lcd.clear();


    // set arduino pin to output mode
  // generate 10-microsecond pulse to TRIG pi
}
void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = duration_us*0.017; 
 while(distance_cm >=DISTANCE_THRESHOLD && distance_cm<=11 ) { delay(10000);
 // pulseIn(ECHO_PIN, LOW);
 digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration_us2 = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm2 = duration_us2*0.017;
  if(distance_cm2 >=DISTANCE_THRESHOLD && distance_cm2<=11){
 digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration_us1 = pulseIn(ECHO_PIN, HIGH);
 // calculate the distance
  distance_cm1 = duration_us1*0.017;
 if(distance_cm1 >=DISTANCE_THRESHOLD && distance_cm1<=11){
     digitalWrite(LED_PIN, HIGH);
    delay(1000*5);
  
    lcd.init();
    lcd.clear();
    lcd.backlight();
  lcd.setCursor(14,0); // move cursor to (4, 0)
  lcd.write((byte)1); 
  lcd.setCursor(0,0);
    delay(100);
    lcd.print("H");
    delay(100);
    lcd.print("I");
    delay(100);
  lcd.print("G");
  delay(100);
  lcd.print("H");
  delay(100);
  
  lcd.print("T");
  delay(100);
  lcd.print("R");
  delay(100);
  lcd.print("A");
  delay(100);
  lcd.print("F");
  delay(100);
  lcd.print("F");
  delay(100);
  lcd.print("I");
  delay(100);
  lcd.print("C");
  delay(100);
       lcd.setCursor(13,0); 
        lcd.print("_");
        delay(100);
          lcd.setCursor(0,1);
  lcd.write((byte)15);
  lcd.print("GOOD MORNING");
digitalWrite(11, HIGH);
delay(1000);
digitalWrite(11, LOW);
delay(1000);
digitalWrite(11, HIGH);
delay(1000);
digitalWrite(11, LOW);
delay(1000);
digitalWrite(11, HIGH);
delay(1000);
digitalWrite(11, LOW);
delay(1000);
digitalWrite(11, HIGH);
delay(1000);
digitalWrite(11, LOW);
delay(1000);
  digitalWrite(LED_PIN, LOW);
    delay(1000);
 lcd.init();
  lcd.clear(); // initialize the lcd
 lcd.backlight();
  lcd.setCursor(14,0);
  lcd.write((byte)1);
   lcd.setCursor(0, 0);
  lcd.print("L");
  delay(100);
  lcd.print("O");
  delay(100);
  lcd.print("W");
  delay(100);
  lcd.print("T");
  delay(100);
  lcd.print("R");
  delay(100);
  lcd.print("A");
  delay(100);
  lcd.print("F");
  delay(100);
  lcd.print("F");
  delay(100);
  lcd.print("I");
  delay(100);
  lcd.print("C");
  delay(100);
  lcd.setCursor(0,1);
  lcd.write((byte)15);
  lcd.print("GOOD MORNING");
 lcd.setCursor(13,0);
   lcd.createChar(1, customChar1); 
   delay(100);
 
  }
 return(0);
 }
   
   // digitalWrite(LED_PIN, LOW);  // turn off LED
  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
}
