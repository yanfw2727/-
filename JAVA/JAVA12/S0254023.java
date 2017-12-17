import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.lang.String.*;

public class S0254023 implements ActionListener{
	JFrame frm;
	Container pane;
	JLabel label_name, label_gender, label_department, label_interesting,label_introduce, topic ;
	JTextField name;
	JRadioButton gender_m, gender_w;
	JComboBox department;
	JCheckBox interesting_bas, interesting_swm, interesting_jog;
	JTextArea introduce;
	JButton save;
	public S0254023(){
		
		//creat frm and container
		frm  = new JFrame("personal data login");
		pane = frm.getContentPane();
		pane.setLayout(null);
		
		//set frm
		frm.setSize(500,500);
		frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		//creat opertaors' labels
		label_name = new  JLabel("name:");
		label_gender = new JLabel("gender:");
		label_department = new JLabel("department:");
		label_interesting = new JLabel("interesting:");
		label_introduce = new JLabel("introduce:");
		topic = new JLabel("Sutdent presonal elementry data");
		
		//creat operators
		name = new JTextField(40);
		gender_m = new JRadioButton("M");
		gender_w = new JRadioButton("W");
		String[] combo = {"CSIE"};
		department = new JComboBox(combo);
		interesting_bas = new JCheckBox("Basketball");
		interesting_swm = new JCheckBox("Swimming");
		interesting_jog = new JCheckBox("Jogging");
		introduce = new JTextArea();
		save = new JButton("save");
		
		//set pane
		name.setBounds(100, 70, 100, 20);
		gender_m.setBounds(100, 110, 50 , 20);
		gender_w.setBounds(150, 110, 50, 20);
		department.setBounds(100, 150, 100, 20);
		interesting_bas.setBounds(100, 190, 100, 20);
		interesting_swm.setBounds(200, 190, 100, 20);
		interesting_jog.setBounds(300, 190, 100, 20);
		introduce.setBounds(100, 230, 300, 20);
		save.setBounds(170, 280, 100, 50);
		
		//set label
		topic.setBounds(140, 10, 200, 20);
		label_name.setBounds(20, 70, 80, 20);
		label_gender.setBounds(20, 110, 80, 20);
		label_department.setBounds(20, 150, 80, 20);
		label_interesting.setBounds(20, 190, 80, 20);
		label_introduce.setBounds(20, 230, 80, 20);
		
		//add to frm
		pane.add(name);
		pane.add(gender_m);
		pane.add(gender_w);
		pane.add(department);
		pane.add(interesting_bas);
		pane.add(interesting_swm);
		pane.add(interesting_jog);
		pane.add(introduce);
		pane.add(save);
		
		//add label
		pane.add(topic);
		pane.add(label_name);
		pane.add(label_gender);
		pane.add(label_department);
		pane.add(label_interesting);
		pane.add(label_introduce);
		
		//add to listener
		save.addActionListener(this);
		
		frm.setVisible(true);
		}
		
	public static void main(String[] Args) throws IOException{
		S0254023 app = new S0254023();
	}
	public void actionPerformed(ActionEvent e){
	String str = new String();
		if(e.getSource() == save){
			str = name.getText();
			if(gender_m.isSelected())
			str = str + ", " + "man";
			if(gender_w.isSelected())
			str = str + ", " + "woman";
			str = str + ", " + department.getSelectedItem();
			if(interesting_bas.isSelected())
			str = str + ", " + "basketball";
			if(interesting_swm.isSelected())
			str = str + ", " + "swimming";
			if(interesting_jog.isSelected())
			str = str + ", " + "jogging";
			str = str + ", " + introduce.getText();
			JOptionPane.showMessageDialog(null,str,"saving",JOptionPane.WARNING_MESSAGE);
			JOptionPane.showMessageDialog(null,"succeed","saved",JOptionPane.WARNING_MESSAGE);
		}
		FileWriter fw;
		try {
			fw = new FileWriter("C:\\output.txt");
			fw.write(str);
			
			fw.close();
		} catch (IOException e1){
		}
	}
}