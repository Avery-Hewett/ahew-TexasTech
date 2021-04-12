import java.lang.*;
class Producer extends Thread {
    private Buffer buff;
    public Producer(Buffer buff) {
        this.buff = buff;
    }

    public void run() {
        while (true) {
            String[] startThread = {"add,5", "multiply,9", "multiply,4", "add,3","add,10","add,30", "multiply,7" };
            for(int i=0;i<7;i++) {
                buff.send(startThread[i]);
            }
            System.exit(1);
        }
    }
}

class Consumer extends Thread {
    private Buffer buff;
    public Consumer(Buffer buff) {
        this.buff = buff;
    }
    public void run() {
        String msg;
        while (true) {
            msg = buff.receive();
        }
    }
}

public class Procon {
    public static void main(String[] args) {
        Buffer buff = new Buffer();
        Producer pro = new Producer(buff);
        Consumer con = new Consumer(buff);
        pro.start();
        con.start();
    }
}

class Buffer {
    private String Message;
    private boolean messageBufferFull;
    public Buffer() {
        this.messageBufferFull = true;
    }

    public synchronized void send(String Message) {
        while (!this.messageBufferFull) {
            try {
                this.wait();
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        this.Message = Message;
        this.messageBufferFull = false;
        this.notify();
        System.out.println("Put: " + Message);
    }

    public synchronized String receive() {
        while (this.messageBufferFull) {
            try {
                this.wait();
            }
            catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        this.messageBufferFull = true;
        this.notify();
        String[] str_array = Message.split(",");
        String message = str_array[0];
        int num= Integer.parseInt(str_array[1]);
        if(message.startsWith("add")) {
            num=num+10;
        }
        if(message.startsWith("multiply")) {
            num=num*10;
        }
        System.out.println("Got: "+num);
        return Message;
    }
}