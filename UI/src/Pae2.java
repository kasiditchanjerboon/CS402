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
		field2.setText(( "5.2m x 5.0m"+"  (จำลอง  = 39cm. x 29.5cm.)"));
		field2.setEditable(false);
		field2.setBounds(200, 36, 230, 22);
		
		label3 = new JLabel("Height of roof pole :");
		label3.setBounds(38, 68, 120, 16);
		field3 = new JTextField(22);
		field3.setText("2700m"+"  (จำลอง = 27cm.)");
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
						String name2 = "D:\\"+name+"\\Desktop\\Config.ini";// ถ้าเป็นเครื่องอื่นต้องใส่เป็น "C://"+name+"\\Desktop\\Config.ini""
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
	
	public static void main(String[] args) {
		
		Pae2 p2 = new Pae2();
	}



}
