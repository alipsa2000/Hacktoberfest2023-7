class MyThread implements Runnable {
    String name;
    Thread t;
     MyThread (String thread){
          name = thread; 
          t = new Thread(this, name);
          t.start();
    }
    
    
    public void run() {
     try {
         for(int i = 4; i > 0; i--) {
         System.out.println(name + ": " + i);
          Thread.sleep(1000);
    }
    }catch (InterruptedException e) {
         System.out.println(name + "Interrupted");
    }
         System.out.println(name + " exiting.");
    }
    }
    
    class MultiThread {
    public static void main(String args[]) {
         new MyThread("Hi");
         new MyThread("Hello");
    try {
         Thread.sleep(10000);
    } catch (InterruptedException e) {
          System.out.println("Main thread Interrupted");
    }
          System.out.println("Main thread exiting.");
          }
    }