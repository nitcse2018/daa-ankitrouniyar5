package multi;

class setget {
	
	private int num ;
	private boolean valueset;
	
	public synchronized void set(int num)  {
		
		while(valueset) {
			
			try {wait();} catch (Exception e) {}
		}
		
		System.out.println("SET : " + num);
		this.num = num;
		valueset = true;
		notify();
		
	}
	
	public synchronized void get()  {
		
		while(!valueset) {
			try {wait();} catch (Exception e) {}
			
		}
		
		valueset = false;
		notify();
		System.out.println("GET : " + num);
		
		
	}
}


public class InterThread {
	
	public static void main (String[] args) {
		
		
		final setget sg = new setget();
		
		Thread Producer = new Thread() {
			public void run () {
				System.out.println("Producer Thread has started");
				for (int i = 1;i <=6;i++) {
					sg.set(i);
					
				}
			}
			
			
		}; 
		Thread Consumer = new Thread() {
			public void run () {
				System.out.println("Consumer Thread has started");
				for (int i = 1;i <=6;i++) {
					sg.get();
					
				}
			}
			
			
		};
		
		Consumer.start();
		Producer.start();
		
		
		
		
		
	}

}

