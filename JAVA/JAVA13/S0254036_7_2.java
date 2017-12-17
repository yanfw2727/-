package com.company;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class S0254036_7_2 extends JFrame implements ActionListener
{
    Container c;
    JButton bot0,bot1,bot2,bot3,bot4,bot5,bot6,bot7,bot8,bot9;
    JTextField txt;
    JPanel jpl;
    JScrollPane jsp;
    int sum,mode;
    public S0254036_7_2()
    {
        super("計算機");
        sum=0;mode=1;
        c=getContentPane();
        c.setLayout(new BorderLayout());
        jpl=new JPanel();
        txt=new JTextField(16);
        jsp=new JScrollPane(jpl);
        c.add(txt,BorderLayout.NORTH);
        c.add(jsp,BorderLayout.CENTER);
        jpl.setLayout(new GridLayout(4,4));
        bot1=new JButton("1");
        bot2=new JButton("2");
        bot3=new JButton("3");
        bot4=new JButton("4");
        bot5=new JButton("5");
        bot6=new JButton("6");
        bot7=new JButton("7");
        bot8=new JButton("8");
        bot9=new JButton("9");
        txt.setHorizontalAlignment(JTextField.RIGHT);
        txt.setEditable(false);
        bot1.addActionListener(this);
        bot2.addActionListener(this);
        bot3.addActionListener(this);
        bot4.addActionListener(this);
        bot5.addActionListener(this);
        bot6.addActionListener(this);
        bot7.addActionListener(this);
        bot8.addActionListener(this);
        bot9.addActionListener(this);
        jpl.add(bot1);jpl.add(bot2);jpl.add(bot3);jpl.add(bot4);jpl.add(bot5);jpl.add(bot6);
        jpl.add(bot7);jpl.add(bot8);jpl.add(bot9);
        setSize(640,480);
        setVisible(true);
    }
    public void paint(Graphics g)
    {
        super.paint(g);
    }
    public void actionPerformed(ActionEvent e)
    {
        if (e.getSource()==bot1)
            txt.setText(txt.getText()+"1");
        if (e.getSource()==bot2)
            txt.setText(txt.getText()+"2");
        if (e.getSource()==bot3)
            txt.setText(txt.getText()+"3");
        if (e.getSource()==bot4)
            txt.setText(txt.getText()+"4");
        if (e.getSource()==bot5)
            txt.setText(txt.getText()+"5");
        if (e.getSource()==bot6)
            txt.setText(txt.getText()+"6");
        if (e.getSource()==bot7)
            txt.setText(txt.getText()+"7");
        if (e.getSource()==bot8)
            txt.setText(txt.getText()+"8");
        if (e.getSource()==bot9)
            txt.setText(txt.getText()+"9");
    }
    public static void main(String args[])
    {
        S0254036_7_2 app=new S0254036_7_2();
        app.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }
        });
    }
}
