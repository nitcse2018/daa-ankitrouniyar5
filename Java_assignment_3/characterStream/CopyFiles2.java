package javafiles;
import java.io.*;
class CopyFiles2{
public static void main(String[] args ) throws IOException,FileNotFoundException{
	
	FileReader fis = new FileReader("input.txt");
	FileWriter fos = new FileWriter("output.txt");
	int data;
	
	while ((data = fis.read()) != -1) {
		fos.write(data);
		
	}
	fis.close();
	fos.close();
	
}
}
