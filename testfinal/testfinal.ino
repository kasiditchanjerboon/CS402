#include <SPI.h>
#include <SD.h>

const int trigPin1 = 2;
const int echoPin1 = 3;
const int trigPin3 = 5;
const int echoPin3 = 6;
const int ledgreen1 = 8;
const int ledred1 = 7;
const int ledgreen3 = 10;
const int ledred3 = 9;
long duration;
int distance[4];
int count = 0;
int sol1 = 0;
int value = 0;
String a = "no car";
String b = "1 car";
String c = "2 car";
int numcar = 0;
int car = 1;
int dis1 = 0;
int dis2 = 0;
int dis3 = 0;
int dis4 = 0;
int carend1 = 0;
int carend2 = 0;
//read form card
int setheightcar[2];
int indexArray = 0;

//start Variable sd card
File myFile; // สร้างออฟเจก File สำหรับจัดการข้อมูล

const int chipSelect = 4;

void setup() { //เช็คสถานะไฟ
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(ledgreen1, OUTPUT);
  pinMode(ledred1, OUTPUT);
  pinMode(ledgreen3, OUTPUT);
  pinMode(ledred3, OUTPUT);
  digitalWrite(ledgreen1, HIGH);
  digitalWrite(ledgreen3, HIGH);
  digitalWrite(ledgreen1, LOW);
  digitalWrite(ledgreen3, LOW);
  digitalWrite(ledgreen1, HIGH);
  digitalWrite(ledgreen3, HIGH);
  Serial.begin(115200);

  //set read file
  Serial.print("Initializing SD card...");
  pinMode(SS, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // เปิดไฟล์เพื่ออ่าน
  myFile = SD.open("Config.ini"); // สั่งให้เปิดไฟล์เพื่ออ่านข้อมูล
  if (myFile) {
    Serial.println("Config.ini:");
    // อ่านข้อมูลทั้งหมดออกมา
    while (myFile.available()) {
      //Serial.write(myFile.read()); //ปริ้นทุกอย่างที่อยู่ในไฟล์
      int inputFile = myFile.parseInt(); //อ่านค่าในไฟล์ แปลงเป็นint แล้วใส่ในarray
      setheightcar[indexArray] = inputFile;
      indexArray++;
    }

    myFile.close(); // เมื่ออ่านเสร็จ ปิดไฟล์
  } else {
    // ถ้าอ่านไม่สำเร็จ ให้แสดง error
    Serial.println("error opening Config.ini");
  }

}
void loop() {
  delay(3000);
  //กำหนดค่าเริ่มต้น sensor
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);

  Serial.print("Round ");
  Serial.println(count);

  //ค่าที่รับมาจาก UI
  /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< เช็คค่า input */
  if (setheightcar[0] == 1000 || setheightcar[0] == 1300 || setheightcar[0] == 1600 || setheightcar[0] == 1800) {
    setheightcar[1] = setheightcar[0] / 100;
    Serial.print("-->>        Setheightcar  = ");
    Serial.println(setheightcar[1]);
    Serial.println(" ");
    distance[3] = setheightcar[1];
    /*------------------------------------------------------------------------*/
    //group1
    digitalWrite(trigPin1, LOW);
    duration = pulseIn(echoPin1, HIGH, 2700);
    distance[0] = duration * (0.034 / 2);

    //group3
    digitalWrite(trigPin3, LOW);
    duration = pulseIn(echoPin3, HIGH, 2700);
    distance[1] = duration * (0.034 / 2);


    // คำนวณค่าระยะทาง
    if (count < 2) {
      Serial.print("-->>        Distance1: ");
      Serial.print(distance[0]);
      Serial.println("cm");
      Serial.print("-->>        Distance2: ");
      Serial.print(distance[1]);
      Serial.println("cm");
      Serial.println(" ");


      if (distance[0] > distance[1]) {
        sol1 = distance[0];
      }
      else if (distance[1] > distance[0]) {
        sol1 = distance[1];
      }
      else if (distance[0] == distance[1]) {
        sol1 = distance[0];
      }
      value = sol1;
      dis3 = distance[0];
      dis4 = distance[1];
      //Serial.print("-->>        Highdistance ");
      //Serial.print(count + 1);
      // Serial.print(" = ");
      //Serial.println(value);
      //Serial.println(" ");
      //Serial.println(count);
    }

    if (count <= 1) {
      distance[2] = value / 2 ;
      Serial.print("-->>        CheckSensorDistance = ");
      Serial.println(distance[2]);

    }

    count++;
    //เปิดปิดไฟที่จอดรถ
    //1

    if (count > 2) {
      Serial.print("-->>        Distance1: ");
      Serial.print(distance[0]);
      Serial.println("cm");
      Serial.print("-->>        Distance2: ");
      Serial.print(distance[1]);
      Serial.println("cm");
      Serial.println(" ");
      dis1 = ((distance[2] * 2) + 2); // 23
      dis2 = ((distance[2] * 2) - 2); // 20
      if (distance[0] >= dis2 && distance[0] <= dis1 ) {
        Serial.print("-->>        heightcar1: ");
        Serial.print(distance[0] * 0);
        Serial.println("cm");
        carend1 = 0;
      } else {
        Serial.print("-->>        heightcar1: ");
        carend1 = dis3 - distance[0];
        Serial.print(carend1);
        Serial.println("cm");
      }
      if (distance[1] >= dis2 && distance[1] <= dis1 ) {
        Serial.print("-->>        heightcar2: ");
        Serial.print(distance[1] * 0);
        Serial.println("cm");
        Serial.println(" ");
        carend2 = 0;
      }
      else {
        Serial.print("-->>        heightcar2: ");
        carend2 = dis4 - distance[1];
        Serial.print(carend2);
        Serial.println("cm");
        Serial.println(" ");
      }
      //เปิดปิดไฟที่จอดรถ

      //1

      Serial.println("-->>        Status Parking Slot");
      if (carend1 >= 8 && carend1 <= distance[3] ) {
        digitalWrite (ledgreen1, LOW);
        digitalWrite (ledred1, HIGH);
        Serial.print("-->>            1 : ");
        Serial.println("Parking space is not available.");
      }
      else if (carend1 == 0 ) {
        digitalWrite (ledgreen1, HIGH);
        digitalWrite (ledred1, LOW);
        Serial.print("-->>            1 : ");
        Serial.println("Parking space is available.");
      }
      else if (carend1 >= distance[3] && carend1 <= dis1) {
        digitalWrite (ledgreen1, LOW);
        digitalWrite (ledred1, LOW);
        Serial.print("-->>            1 : ");
        Serial.println("Out of bound");
      }
      
      //2
      if (carend2 >= 8 && carend2 <= distance[3] ) {
        digitalWrite (ledgreen3, LOW);
        digitalWrite (ledred3, HIGH);
        Serial.print("-->>            2 : ");
        Serial.println("Parking space is not available.");
      }
      else if (carend2 == 0 ) {
        digitalWrite (ledgreen3, HIGH);
        digitalWrite (ledred3, LOW);
        Serial.print("-->>            2 : ");
        Serial.println("Parking space is available.");
      }
      else if (carend2 >= distance[3] && carend2 <= dis1) {
        digitalWrite (ledgreen3, LOW);
        digitalWrite (ledred3, LOW);
        Serial.print("-->>            2 : ");
        Serial.println("Out of bound");
      }
    }
    // นับจำนวนรถ เริ่มตั้งแต่รอบที่ 3
    if (count > 2) {
      //1
      if (carend1 >= 8 && carend1 <= distance[3]) {
        car++;
      }
      else if (carend1 == 0 || carend1 > distance[3] ) {//เท่ากับ 0 หรือ มากกว่า ระยะสูงสุด คือว่าง
        if (car != 1) {
          car--;
        }
      }

      //2
      if (carend2 >= 8 && carend2 <= distance[3] ) {
        car++;
      }
      else if (carend2 == 0 || carend2 > distance[3] ) {
        if (numcar != 0) {
          car--;
        }
      }
      //Serial.println(car);
      //แสดงสถานะ จำนวนรถ
      Serial.println("-->>        How many car");
      if (car == 1) {
        Serial.print("-->>            : ");
        Serial.println(a);
      }
      else if (car == 2) {
        Serial.print("-->>            : ");
        Serial.println(b);
      }
      else if (car == 3) {
        Serial.print("-->>            : ");
        Serial.println(c);
      }
      car = 1;
      Serial.println(" ");

    }
 /*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< เช็คค่า input */
  }  else {
    Serial.println("-->>        Data is not correct ");
    Serial.println("-->>        Please check file Config.ini  ");
  }
}
