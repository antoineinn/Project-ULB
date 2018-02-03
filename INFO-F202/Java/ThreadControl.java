//Antoine Innocent BA2 Informatique
//Matricule: 000394700


package packaging;



public class ThreadControl {
	// This class is used to control the synchronization of all the threads
	
	
	
	///////////// Variables ///////////////
	
		public int threadStop;
		private int totalThread;
        private int passedThread;
        private Lock lock;
        
        
  ///////////// Constructor ////////////////      

        ThreadControl(int totalThread) {
            this.totalThread = totalThread;
            this.passedThread = totalThread;
            threadStop=totalThread;
            this.lock = new Lock();
        }
             
        synchronized void synchronize() throws InterruptedException {
        	// This function synchronizes all threads
               
        	passedThread--;
            if (passedThread != 0) {
                Lock lock2 = this.lock;
                System.out.println(Thread.currentThread().getName()+" is waiting");
                while (lock2.stop) {
                    this.wait();
                }
                System.out.println(Thread.currentThread().getName()+" is active");

            } 
            else{ // Last thread passes 
            	this.notifyAll();                                 
	            lock.stop = false; 
	            this.lock = new Lock(); 
	            passedThread = totalThread;
	            }
        }
        
        private class Lock {
        	// Will be used as a lock condition in wait loop
            boolean stop;
            private Lock()
            {
                this.stop = true;
            }
        }
}
