package awt;
import java.awt.*;
import java.awt.event.*;
import java.io.FileWriter;


public class Resume extends Frame implements ActionListener,WindowListener,ItemListener {
	
	
	Frame f;
	TextField t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
	Label title,l1,l2,l3,l4,l5,l6,l0,l7,l8,l9,l10;
	Checkbox m,c,o;
	CheckboxGroup cbg;
	Choice l;
	Button b;
	
	Resume()
	{
		f = new Frame();
		
		
		Font myFont = new Font("arial",Font.BOLD,15);
		
		title = new Label("RESUME");
		title.setBounds(200,30,100,15);
		 title.setFont(myFont);
		 
		 
		
		l0 = new Label("Personal Details");
		l0.setBounds(20,60,200,12);
		 l0.setFont(myFont);
		
		l1 = new Label("First name :");
		l1.setBounds(10, 120, 100, 20);
		
		t1 = new TextField(50);
		t1.setBounds(110, 120, 100, 20);
		
		l2 = new Label("Last name :");
		l2.setBounds(230,120,100, 20);
		
		t2 = new TextField(50);
		t2.setBounds(340, 120, 120, 20);
		
		l3 = new Label("Sex :-");	
		l3.setBounds(80,150,40,20);
		
		cbg = new CheckboxGroup();
		m  = new Checkbox("M", cbg, false);
		m.setBounds(150,150,40,20);
		
		c = new Checkbox("F", cbg, false);
		c.setBounds(220,150,40,20);
		
		o = new Checkbox("Others", cbg, false);
		o.setBounds(300,150,60,20);
		
		l4 = new Label("DOB ( dd/mm/yy):-");
		l4.setBounds(10,170,100,20);
		
		t4 = new TextField(10);
		t4.setBounds(120,170,100,20);
	
		l5 = new Label("Education");
		l5.setBounds(20,240,100,20);
		 l5.setFont(myFont);
		 
		 l6 = new Label("Institute Name:-");
		 l6.setBounds(10,300,100,20);
		 
		 t6 = new TextField(100);
		 t6.setBounds(120,300,300,20);
		 
		 l8 = new Label("Branch:-");
		 l8.setBounds(10,380,80,20);
		 
		 t8 = new TextField(10);
		 t8.setBounds(100,380,150,20);
		 
		 l7 =  new Label("Semester:-");
		 l7.setBounds(10,340,80,20);
		 
		 l9 = new Label("CGPA:-");
		 l9.setBounds(10,420,80,20);
		 
		 t9 = new TextField(10);
		 t9.setBounds(100,420,150,20);
		 
		 l10 = new Label("Area of Interest:-");
		 l10.setBounds(10,460,100,20);
		 
		 t10 = new TextField(10);
		 t10.setBounds(120,460,150,20);
		 

		 
		 l = new Choice();
		 l.setBounds(100,340,150,25);
		 
		 l.add("1");
		 l.add("2");
		 l.add("3");
		 l.add("4");
		 l.add("5");
		 l.add("6");
		 l.add("7");
		 l.add("8");
		 l.add("completed");
		 
		 b = new Button("Submit");
		 b.setBounds(200,500,70,20);
		
		

		add(title);
		add(l1);
		add(t1);
		add(l2);
		add(t2);
		add(l3);
		add(m);
		add(c);
		add(o);
		add(l4);
		add(t4);
		add(l5);
		add(l0);
		add(l6);
		add(t6);
		add(l7);
		add(l);
		add(l8);
		add(t8);
		add(l9);
		add(t9);
		add(l10);
		add(t10);
		add(b);
	
		setLayout(null);
		
		setSize(500,700);
		setVisible(true);
		addWindowListener(this);
		b.addActionListener(this);
		m.addItemListener(this);
	    c.addItemListener(this);
	    o.addItemListener(this);
	 
		
		
		
	}
	
	
	@Override public void windowClosing(WindowEvent evt) {
	      System.exit(0);
	   }
	
	
	
	String str = "";
	public void itemStateChanged(ItemEvent e)
	  {
		 
	    if(m.getState() == true)
	      str = "Male";
	    else if(c.getState() == true)
	      str = "Female";
	    else if(o.getState() == true)
	      str = "Other";
	           
	    
	  }

	
	
	public void actionPerformed (ActionEvent ae)
	{
		
		
		 String fname=t1.getText();
         String lname=t2.getText();
         String dob=t4.getText();
         String instituteName=t6.getText();
         String branch=t8.getText();
         String sem=l.getSelectedItem();
         String cg = t9.getText();
         String interest = t10.getText();
         
         try{    
             FileWriter fw=new FileWriter("C:\\Users\\DELL\\Desktop\\resume.txt");    
             fw.write("-----------------------RESUME-------------------------------\n\n\n"); 
             fw.write("\n\n Personal Details");
             fw.write("\n\n First Name :- "+ fname + "\t");  
             fw.write(" Last Name :-"+ lname);
             fw.write("\n\n sex :-  "+ str);
             fw.write("\n\n dob :-  "+ dob);
             fw.write("\n\n ----------------------------------------------------------------");
             fw.write("\n\n EDUCATION");
             fw.write("\n\n Institute name :- "+ instituteName);
             fw.write("\n\n Branch :- "+ branch);
             fw.write("\n\n Semester :- "+ sem);
             fw.write("\n\n CGPA :- "+ cg);
             fw.write("\n\n Interest :- "+ interest);
             fw.close();    
            }catch(Exception e){System.out.println(e);}    
            System.out.println("Success..."); 
      
		
	}
	
	public static void main (String args[]) {
		 new Resume();
		 
		
	}
	 @Override public void windowOpened(WindowEvent evt) { }
	   @Override public void windowClosed(WindowEvent evt) { }
	   @Override public void windowIconified(WindowEvent evt) { System.out.println("Window Iconified"); }
	   @Override public void windowDeiconified(WindowEvent evt) { System.out.println("Window Deiconified"); }
	   @Override public void windowActivated(WindowEvent evt) { System.out.println("Window Activated"); }
	   @Override public void windowDeactivated(WindowEvent evt) { System.out.println("Window Deactivated"); }
	}


	


