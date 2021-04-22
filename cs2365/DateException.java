import java.util.Scanner;

public class DateException {

    public static void main(String[] args) {
        int day, month, year, month_days = 0;
        String date="";
        String month_name[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Date: ");
        date = sc.next();
        String dat[] = date.split("/");
        month = Integer.parseInt(dat[0]);
        while (true) {
            try {
                if (month < 1 || month > 12) {
                    throw new MonthException("Month Exception, must be between 1-12.");

                } else
                    break;
            } catch (MonthException e) {
                System.out.print("Enter Month: ");
                month = sc.nextInt();
                continue;
            }

        }
        day = Integer.parseInt(dat[1]);
        year = Integer.parseInt(dat[2]);
        while (true) {
            if (year < 1000 || year > 3000) {
                try {
                    throw new YearException("Year Exception, must be between 1000-3000.");
                } catch (YearException e) {
                    System.out.print("Enter Year: ");
                    year = sc.nextInt();
                    continue;
                }
            } else
                break;
        }
        if (month == 1) {
            month_days = 31;
        } else if (month == 2) {
            if (year % 400 == 0) {
                month_days = 29;
            } else if (year % 100 == 0) {
                month_days = 28;
            } else if (year % 4 == 0) {
                month_days = 29;
            } else {
                month_days = 28;
            }
        } else if (month == 3) {
            month_days = 31;
        } else if (month == 4) {
            month_days = 30;
        } else if (month == 5) {
            month_days = 31;
        } else if (month == 6) {
            month_days = 30;
        } else if (month == 7) {
            month_days = 31;
        } else if (month == 8) {
            month_days = 31;
        } else if (month == 9) {
            month_days = 30;
        } else if (month == 10) {
            month_days = 31;
        } else if (month == 11) {
            month_days = 30;
        } else if (month == 12) {
            month_days = 31;
        }

        while (true) {
            if (day < 1 || day > month_days) {
                try {
                    throw new DayException("Day Exception, must be between 1-" + month_days + ".");
                } catch (DayException e) {
                    System.out.print("Enter Day: ");
                    day = sc.nextInt();
                    continue;
                }
            } else
                break;
        }
        System.out.print("\nDate: "+month_name[month-1]+" "+day+", "+year);
    }

}