import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class S0254023 extends WindowAdapter implements ActionListener{
	static JTextField field;
	static JButton btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9;
	static JPanel panel1, panel2;
	static Container cp;
	static JFrame frm;
	static S0254023 abc = new S0254023();
	public static void main(String Args[]){
		frm = new JFrame("calculater");
		field = new JTextField(40);
		frm.setSize(400,250);
		frm.addWindowListener(abc);
		cp = frm.getContentPane();
		cp.setLayout(new BorderLayout(5,2));
		panel1 = new JPanel(new FlowLayout(40));
		panel2 = new JPanel(new GridLayout(3,3));
		panel1.add(field);
		btn1 = new JButton("1");
		btn2 = new JButton("2");
		btn3 = new JButton("3");
		btn4 = new JButton("4");
		btn5 = new JButton("5");
		btn6 = new JButton("6");
		btn7 = new JButton("7");
		btn8 = new JButton("8");
		btn9 = new JButton("9");
		btn1.addActionListener(abc);
		btn2.addActionListener(abc);
		btn3.addActionListener(abc);
		btn4.addActionListener(abc);
		btn5.addActionListener(abc);
		btn6.addActionListener(abc);
		btn7.addActionListener(abc);
		btn8.addActionListener(abc);
		btn9.addActionListener(abc);
		panel2.add(btn1);
		panel2.add(btn2);
		panel2.add(btn3);
		panel2.add(btn4);
		panel2.add(btn5);
		panel2.add(btn6);
		panel2.add(btn7);
		panel2.add(btn8);
		panel2.add(btn9);
		cp.add(panel1,BorderLayout.NORTH);
		cp.add(panel2,BorderLayout.CENTER);
		frm.setVisible(true);
	}
	public void actionPerformed (ActionEvent e){
		if(e.getSource() == btn1){
			field.setText(field.getText() + "1");}
		if(e.getSource() == btn2){
			field.setText(field.getText() + "2");}
		if(e.getSource() == btn3){
			field.setText(field.getText() + "3");}
		if(e.getSource() == btn4){
			field.setText(field.getText() + "4");}
		if(e.getSource() == btn5){
			field.setText(field.getText() + "5");}
		if(e.getSource() == btn6){
			field.setText(field.getText() + "6");}
		if(e.getSource() == btn7){
			field.setText(field.getText() + "7");}
		if(e.getSource() == btn8){
			field.setText(field.getText() + "8");}
		if(e.getSource() == btn9){
			field.setText(field.getText() + "9");}
	}
	public void windowClosing(WindowEvent e) {
		JOptionPane.showMessageDialog(null, "You're closing the calculater", "warning", JOptionPane.WARNING_MESSAGE);
        System.out.println("windowClosing");
        frm.dispose();
    }
}