import java.util.Scanner;
public class hw8 {
    public static void main (String[] args) {
        int n = 0;
        boolean error = true;
        double average;
        int sum = 0;
        int num;
        Scanner keyboard = new Scanner(System.in);

        do {
            try {
                error = false;
                System.out.print("How many numbers do you want to enter: ");
                n = keyboard.nextInt();
                if (n < 0 )
                    throw new Exception ("Number must be greater than 0.");
            }
            catch (Exception e) {
                String message = e.getMessage();
                System.out.println(message);
                System.exit(0);
            }
        }while(error);
        int i;
        for (i = 0; i < n; i ++) {
            System.out.print("Enter Value " + (i+1) + ": ");
            num = keyboard.nextInt();
            while(num<0) {
                System.out.print("Number be positive, please try number " + (i+1)+ " again :");
                num = keyboard.nextInt();
            }
            sum = sum+num;
        }
        average = sum/(double)i;
        System.out.println ("Average: " + average);
    }
}