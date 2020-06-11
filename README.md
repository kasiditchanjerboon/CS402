# CS402
Project File
Name Group 62wil48
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class Pae2 implements ActionListener{
	
	//frame
	private JFrame frame = new JFrame();
	
	//label
	private JLabel label1;
	private JLabel label2;
	private JLabel label3;
	private JLabel label4;
	private JLabel label5;
	
	//text field
	private JTextField field1;
	private JTextField field2;
	private JTextField field3;
	private JTextField field4;
	
	//radio button
	private JRadioButton supercar;
	private JRadioButton saloon;
	private JRadioButton suv;
	private JRadioButton van;
	private ButtonGroup cargroup;
	
	//text area
	private JTextArea area1;
	
	//button
	private JButton check;
	private JButton save;
	
	//writefile
	private FileWriter fw;
	
	private int checkError = 0;
	
		
	Pae2(){
		
		frame.setTitle("Parking Simulation System");
		frame.setBounds(450, 100, 475, 500); 
		frame.getContentPane().setLayout(null); 
		
		label1 = new JLabel("Product name :");
		label1.setBounds(38, 10, 100, 16);
		field1 = new JTextField(22);
		field1.setText("Parking Simulation System :");
		field1.setEditable(false);
		field1.setBounds(200, 7, 230, 22);
		
		label2 = new JLabel("Roof area :");
		label2.setBounds(38, 39, 100, 16);
		field2 = new JTextField(22);
		field2.setText(( "5.2m x 5.0m"+"  (���ͧ  = 39cm. x 29.5cm.)"));
		field2.setEditable(false);
		field2.setBounds(200, 36, 230, 22);
		
		label3 = new JLabel("Height of roof pole :");
		label3.setBounds(38, 68, 120, 16);
		field3 = new JTextField(22);
		field3.setText("2700m"+"  (���ͧ = 27cm.)");
		field3.setEditable(false);
		field3.setBounds(200, 65, 230, 22);
		
		label4 = new JLabel("Number of cars parked :");
		label4.setBounds(38, 97, 150, 16);
		field4 = new JTextField(22);
		field4.setText("2 Cars");
		field4.setEditable(false);
		field4.setBounds(200, 94, 230, 22);
		
		label5 = new JLabel("*Car Type :");
		label5.setBounds(38, 126, 150, 16);
		
		supercar = new JRadioButton("SuperCar");
		supercar.setBounds(200, 123, 100, 22);
		
		saloon = new JRadioButton("Saloon");
		saloon.setBounds(300, 123, 100, 22);
		
		suv = new JRadioButton("SUV");
		suv.setBounds(200, 152, 100, 22);
		
		van = new JRadioButton("Van");
		van.setBounds(300, 152, 100, 22);
		
		frame.getContentPane().add(label1);
		frame.getContentPane().add(field1);
		
		frame.getContentPane().add(label2);
		frame.getContentPane().add(field2);
		
		frame.getContentPane().add(label3);
		frame.getContentPane().add(field3);
		
		frame.getContentPane().add(label4);
		frame.getContentPane().add(field4);
		
		frame.getContentPane().add(label5);
		frame.getContentPane().add(supercar);
		frame.getContentPane().add(saloon);
		frame.getContentPane().add(suv);
		frame.getContentPane().add(van);
		
		cargroup = new ButtonGroup();
		cargroup.add(supercar);
		cargroup.add(saloon);
		cargroup.add(suv);
		cargroup.add(van);
		
		area1 = new JTextArea();
		area1.setText("Note*");
		area1.setLocation(56, 185);
		area1.setSize(350, 150);
		area1.setEditable(false);
		frame.getContentPane().add(area1);
		
		//pum far 80 tub por dee
		check = new JButton("Check");
		check.setBounds(140, 350, 80, 22);
		save = new JButton("Save");
		save.setBounds(240, 350, 80, 22);
		
		frame.getContentPane().add(check);
		frame.getContentPane().add(save);
		
		check.addActionListener(this); // dont forget
		save.addActionListener(this); // dont forget
	
		frame.setResizable(false); //not full size frame
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}
	
	@Override
	public void actionPerformed(ActionEvent ae) {
		if(ae.getActionCommand() == check.getActionCommand()) {
			//msg in text area
			String space = "          ";
			
			try {
				if(!supercar.isSelected() && !saloon.isSelected()
						&& !suv.isSelected() && !van.isSelected() ) {
					JOptionPane.showMessageDialog(frame,
						    "Plese Select One Car Type Button.",
						    "Error",
						    JOptionPane.ERROR_MESSAGE);
					
				}
				if(supercar.isSelected()) {
					System.out.println("supercar");
					area1.setText("Supercar"+"\n"+"Lenght	:"+space+"4600 mm."+"\n"
							+"Width	:"+space+"2000 mm."+"\n"
							+"Height	:"+space+"1200 mm.");
					checkError = 1;
				}
				if(saloon.isSelected()) {
					System.out.println("saloon");
					area1.setText("Saloon"+"\n"+"Lenght	:"+space+"4400 mm."+"\n"
							+"Width	:"+space+"1700 mm."+"\n"
							+"Height	:"+space+"1500 mm.");
					checkError = 2;
				}
				if(suv.isSelected()) {
					System.out.println("suv");
					area1.setText("Suv & PickupTruck"+"\n"+"Lenght	:"+space+"5300 mm."+"\n"
							+"Width	:"+space+"1850 mm."+"\n"
							+"Height	:"+space+"1800 mm.");
					checkError = 3;
				}
				if(van.isSelected()) {
					System.out.println("van");
					area1.setText("Van"+"\n"+"Lenght	:"+space+"5200 mm."+"\n"
							+"Width	:"+space+"1950 mm."+"\n"
							+"Height	:"+space+"1990 mm.");
					checkError = 4;
				}
							
			}catch (Exception e) {
				JOptionPane.showMessageDialog(null, e+"");
			}
		}
		else if(ae.getActionCommand() == save.getActionCommand()) {
			try {
				if(!supercar.isSelected() && !saloon.isSelected()
						&& !suv.isSelected() && !van.isSelected() ) {
					JOptionPane.showMessageDialog(frame,
						    "Plese Select One Car Type Button.",
						    "Error",
						    JOptionPane.ERROR_MESSAGE);
					
				}
				if(supercar.isSelected()) {
					if(checkError == 1) {
						String name = System.getProperty("user.name");
						String name2 = "D:\\"+name+"\\Desktop\\Config.ini";
						fw = new FileWriter(name2);
						fw.write("1000"+"\n");
						fw.close();
						JOptionPane.showMessageDialog(null, "Save Succesfully");
						return;
					}
					else {
						JOptionPane.showMessageDialog(frame,
							    "Plese Check Car Type Again.",
							    "Error",
							    JOptionPane.ERROR_MESSAGE);
					}	
				}
				if(saloon.isSelected()) {
					if(checkError == 2) {
						String name = System.getProperty("user.name");
						String name2 = "D:\\"+name+"\\Desktop\\Config.ini";// ���������ͧ��蹵�ͧ����� "C://"+name+"\\Desktop\\Config.ini""
						fw = new FileWriter(name2);
						fw.write("1300"+"\n");
						fw.close();
						JOptionPane.showMessageDialog(null, "Save Succesfully");
						return;
					}
					else {
						JOptionPane.showMessageDialog(frame,
							    "Plese Check Car Type Again.",
							    "Error",
							    JOptionPane.ERROR_MESSAGE);
					}	
				}
				if(suv.isSelected()) {
					if(checkError == 3) {
						String name = System.getProperty("user.name");
						String name2 = "D:\\"+name+"\\Desktop\\Config.ini";
						fw = new FileWriter(name2);
						fw.write("1600"+"\n");
						fw.close();
						JOptionPane.showMessageDialog(null, "Save Succesfully");
						return;
					}
					else {
						JOptionPane.showMessageDialog(frame,
							    "Plese Check Car Type Again.",
							    "Error",
							    JOptionPane.ERROR_MESSAGE);
					}		
				}
				if(van.isSelected()) {
					if(checkError == 4) {
						String name = System.getProperty("user.name");
						String name2 = "D:\\"+name+"\\Desktop\\Config.ini";
						fw = new FileWriter(name2);
						fw.write("1800"+"\n");
						fw.close();
						JOptionPane.showMessageDialog(null, "Save Succesfully");
						return;
					}
					else {
						JOptionPane.showMessageDialog(frame,
							    "Plese Check Car Type Again.",
							    "Error",
							    JOptionPane.ERROR_MESSAGE);
					}		
				}
				return;
				
			} catch (Exception e) {
				JOptionPane.showMessageDialog(null, e+"");
			}
			
		}
		
	}
	
	public static void main(String[] args) {#include <SPI.h>
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

		
		Pae2 p2 = new Pae2();
	}



}
