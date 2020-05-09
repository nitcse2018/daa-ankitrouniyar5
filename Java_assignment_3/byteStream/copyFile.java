package javafiles;
import java.io.*;

public class copyFile {
	public static void main(String[] args ) throws IOException,FileNotFoundException{
		
		FileInputStream fis = new FileInputStream("input.txt");
		FileOutputStream fos = new FileOutputStream("output.txt");
		int data;
		
		while ((data = fis.read()) != -1) {
			fos.write(data);
			
		}
		fis.close();
		fos.close();
		
	}
	}


