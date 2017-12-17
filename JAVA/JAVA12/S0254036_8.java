package com.company;
import java.io.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class S0254036_8
{
    static JFrame frm=new JFrame("個人資料登錄");
    static Container cp=frm.getContentPane();
    static JRadioButton rb1=new JRadioButton("男生");
    static JRadioButton rb2=new JRadioButton("女生");

    static JCheckBox ckb1=new JCheckBox("打籃球",true);
    static JCheckBox ckb2=new JCheckBox("游泳");
    static JCheckBox ckb3=new JCheckBox("慢跑",true);

    static JButton btn=new JButton(" 存檔 ");

    static Choice chc=new Choice();



    static TextField txf2=new TextField("smallming");

    static JLabel lab1=new JLabel("學生個人基本資料");
    static JLabel lab2=new JLabel("性別");
    static JLabel lab3=new JLabel("系所");
    static JLabel lab4=new JLabel("興趣");
    static JLabel lab5=new JLabel("自我介紹");
    static JLabel lab6=new JLabel("姓名");
    static TextArea txa;

    public static void main(String args[]) throws IOException
    {
        lab1.setBounds(250,20,150,20);
        cp.add(lab1);
        lab6.setBounds(20,100,50,20);
        cp.add(lab6);


        txf2.setBounds(90,100,300,20); //                              00000000000000000000
        cp.add(txf2);

        lab5.setBounds(20,260,80,20);
        cp.add(lab5);                     //444444444444444
        txa=new TextArea(" ",5,5,TextArea.SCROLLBARS_VERTICAL_ONLY);
        txa.setBounds(90,260,400,20);
        cp.add(txa);

        lab3.setBounds(20,180,50,20);
        cp.add(lab3);
        chc.add(" CSIE ");
        cp.add(chc);
        chc.setBounds(90,180,300,20);          //2222222222

        cp.add(btn);
        btn.setBounds(270,400,70,20);               //555555555555
        btn.addActionListener(new actlis());


        lab2.setBounds(20,140,50,20);
        cp.add(lab2);
        rb1.setBounds(90,140,120,20);           //11111111
        rb2.setBounds(230,140,120,20);


        lab4.setBounds(20,220,50,20);
        cp.add(lab4);
        ckb1.setBounds(90,220,100,20);             //333333333
        ckb2.setBounds(200,220,100,20);
        ckb3.setBounds(310,220,100,20);


        ButtonGroup bgroup=new ButtonGroup();  // 建立ButtonGroup物件
        bgroup.add(rb1);                 // 將rb1設定為單選
        bgroup.add(rb2);                 // 將rb2設定為單選
        rb1.setSelected(true);              // 設定rb1被選擇


        cp.add(rb1);
        cp.add(rb2);
        cp.add(ckb1);
        cp.add(ckb2);
        cp.add(ckb3);
        cp.setLayout(null);
        //cp.setBackground(Color.);
        frm.setSize(600,600);
        frm.setVisible(true);
    }
    static class actlis implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            FileWriter fw;




            String str=txf2.getText()+"  ,    "+((rb1.isSelected()==true)?"boy":"girl")+"   ,   "+"CSIE"+"   ,   "+((ckb1.isSelected()==true)?"play baseball ":"")+" "+((ckb2.isSelected()==true)?"swimming ":"")+" "+((ckb3.isSelected()==true)?"running ":"")
                    +"   ,   "+"hello! my name is smallming ";

            try {
                fw = new FileWriter("C:\\output.txt");
                fw.write(str);



                fw.close();
            } catch (IOException e1) {

            }





        }
    }
}


