package application;

import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.geometry.Pos;
import javafx.geometry.Insets;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.control.Button;
import javafx.event.EventHandler;
import javafx.event.ActionEvent;

import javax.swing.*;
import java.lang.String;

import java.io.*;
import java.util.Scanner;

public class Main extends Application {

    public static void main(String[] args) {
        launch(args);
    }

    public static int[][] itemStock = { { 1, 18, 69 },
            { 2, 20, 54 },
            { 3, 12, 43 },
            { 4, 13, 53 },
            { 5, 11, 84 },
            { 6, 6, 23 },
            { 7, 5, 65 },
            { 8, 19, 63 },
            { 9, 21, 113 },
            { 10, 12, 66 } };

    public static String[][] itemInfo = { { "Bananas", "Item 1 Desc" },
            { "Cherries", "Item 2 Desc" },
            { "Lemons", "Item 3 Desc" },
            { "Limes", "Item 4 Desc" },
            { "Lemons", "Item 3 Desc" },
            { "Pears", "Item 3 Desc" },
            { "Watermelons", "Item 3 Desc" },
            { "Apples", "Item 3 Desc" },
            { "Figs", "Item 3 Desc" },
            { "Berries", "Item 3 Desc" },};

    public static int[][] cart = new int[10][2];
    public static String[] loggedIn = { "", "", "", "", "", "", "" };
    //                                  User, Pass, Name, Addr, Phone, CC, Type
    public static int balance;
    public static int cost;



    private TextField username;
    private TextField password;
    private Label passMatch;

    Account admin = new Account(loggedIn[0], loggedIn[1], loggedIn[2], loggedIn[3], loggedIn[4], loggedIn[5], loggedIn[6]);

    Stage primaryStage = new Stage();

    Stage Cat_Stage = new Stage();
    Stage Order_Stage = new Stage();
    Stage Supply_Stage = new Stage();
    Stage Supp_Order_Stage = new Stage();
    Stage Ship_Stage = new Stage();
    Stage Orders_Stage = new Stage();

    Scene Catalog;
    Scene ViewOrder;
    Scene Stock;
    Scene OrderProcessing;

    /////////////////////////////////
    // Initial Load and Login Menu //
    /////////////////////////////////

    @Override
    public void start(Stage primaryStage) {
        try {

//			BorderPane root = new BorderPane();
//			Scene scene = new Scene(root,1200,720);
//			scene.getStylesheets().add(getClass().getResource("application.css").toExternalForm());
//			primaryStage.setScene(scene);
//			primaryStage.show();

            Label promptUser = new Label("Enter Username: ");
            username = new TextField();

            Label promptPass = new Label("Enter Password: ");
            password = new TextField();

            Button Login = new Button("Enter");
            Login.setOnAction(new LogInHandler());

            Button CreateAccount = new Button("Create Account");
            CreateAccount.setOnAction(new AccountHandler());

            passMatch = new Label();

            HBox hboxRT = new HBox(30, promptUser, username, promptPass, password);
            VBox vboxRT = new VBox (15, passMatch, hboxRT, Login, CreateAccount);

            vboxRT.setAlignment(Pos.CENTER);
            vboxRT.setPadding(new Insets(10));

            Scene root = new Scene(vboxRT);
            primaryStage.setScene(root);
            primaryStage.setTitle("Log In to Krustomer's");
            primaryStage.show();

        } catch(Exception e) {
            e.printStackTrace();
        }
    }

    //////////////////
    // LogInHandler //
    //////////////////

    class LogInHandler implements EventHandler<ActionEvent> {
        @Override
        public void handle(ActionEvent event) {

            String user = String.valueOf(username.getText());
            String pass = String.valueOf(password.getText());

            passMatch.setText(admin.LogIn(admin, user, pass));

            if (admin.LogIn(admin, user, pass) == "Success!") {
                if (loggedIn[6].equals("Regular") || loggedIn[6].equals("Premium")) {
                    try {
                        //Label welcome = new Label("Welcome to Gamer Shopping!");

                        ///////////////////////////
                        // CONSTRUCT CATALOG HERE//
                        ///////////////////////////

                        Label label1 = new Label("" + itemInfo[0][0]);
                        Label label2 = new Label("" + itemInfo[1][0]);
                        Label label3 = new Label("" + itemInfo[2][0]);
                        Label label4 = new Label("" + itemInfo[3][0]);
                        Label label5 = new Label("" + itemInfo[4][0]);
                        Label label6 = new Label("" + itemInfo[5][0]);
                        Label label7 = new Label("" + itemInfo[6][0]);
                        Label label8 = new Label("" + itemInfo[7][0]);
                        Label label9 = new Label("" + itemInfo[8][0]);
                        Label label10 = new Label("" + itemInfo[9][0]);

                        Button button1 = new Button("Add to Cart");
                        button1.setOnAction(new cartAddition());
                        Button button2 = new Button("Add to Cart");
                        button2.setOnAction(new cartAddition());
                        Button button3 = new Button("Add to Cart");
                        button3.setOnAction(new cartAddition());
                        Button button4 = new Button("Add to Cart");
                        button4.setOnAction(new cartAddition());
                        Button button5 = new Button("Add to Cart");
                        button5.setOnAction(new cartAddition());
                        Button button6 = new Button("Add to Cart");
                        button6.setOnAction(new cartAddition());
                        Button button7 = new Button("Add to Cart");
                        button7.setOnAction(new cartAddition());
                        Button button8 = new Button("Add to Cart");
                        button8.setOnAction(new cartAddition());
                        Button button9 = new Button("Add to Cart");
                        button9.setOnAction(new cartAddition());
                        Button button10 = new Button("Add to Cart");
                        button10.setOnAction(new cartAddition());

                        button1.setMinWidth(100);
                        button1.setMinHeight(50);
                        HBox hbox = new HBox(label1, button1);
                        hbox.setAlignment(Pos.CENTER);
                        hbox.setPadding(new Insets(10));

                        button2.setMinWidth(100);
                        button2.setMinHeight(50);
                        HBox hbox2 = new HBox(label2, button2);
                        hbox2.setAlignment(Pos.CENTER);
                        hbox2.setPadding(new Insets(10));

                        button3.setMinWidth(100);
                        button3.setMinHeight(50);
                        HBox hbox3 = new HBox(label3, button3);
                        hbox3.setAlignment(Pos.CENTER);
                        hbox3.setPadding(new Insets(10));

                        button4.setMinWidth(100);
                        button4.setMinHeight(50);
                        HBox hbox4 = new HBox(label4, button4);
                        hbox4.setAlignment(Pos.CENTER);
                        hbox4.setPadding(new Insets(10));

                        button5.setMinWidth(100);
                        button5.setMinHeight(50);
                        HBox hbox5 = new HBox(label5, button5);
                        hbox5.setAlignment(Pos.CENTER);
                        hbox5.setPadding(new Insets(10));

                        button6.setMinWidth(100);
                        button6.setMinHeight(50);
                        HBox hbox6 = new HBox(label6, button6);
                        hbox6.setAlignment(Pos.CENTER);
                        hbox6.setPadding(new Insets(10));

                        button7.setMinWidth(100);
                        button7.setMinHeight(50);
                        HBox hbox7 = new HBox(label7, button7);
                        hbox7.setAlignment(Pos.CENTER);
                        hbox7.setPadding(new Insets(10));

                        button8.setMinWidth(100);
                        button8.setMinHeight(50);
                        HBox hbox8 = new HBox(label8, button8);
                        hbox8.setAlignment(Pos.CENTER);
                        hbox8.setPadding(new Insets(10));

                        button9.setMinWidth(100);
                        button9.setMinHeight(50);
                        HBox hbox9 = new HBox(label9, button9);
                        hbox9.setAlignment(Pos.CENTER);
                        hbox9.setPadding(new Insets(10));

                        button10.setMinWidth(100);
                        button10.setMinHeight(50);
                        HBox hbox10 = new HBox(label10, button10);
                        hbox10.setAlignment(Pos.CENTER);
                        hbox10.setPadding(new Insets(10));

                        Button processall = new Button("Purchase all");
                        processall.setOnAction(new ViewOrderHandler());
                        VBox Supplier_VBox = new VBox(hbox, hbox2, hbox3, hbox4, hbox5, hbox6, hbox7, hbox8, hbox9, hbox10, processall);
                        Scene Supply = new Scene(Supplier_VBox, 850, 1000);

                        // After process update stock here
                        Cat_Stage.setTitle("Welcome to Krustomer's");
                        Cat_Stage.setScene(Supply);
                        Cat_Stage.show();

                    }
                    catch (Exception e) {
                        e.printStackTrace();
                    }
                }




                else if (loggedIn[6].equals("Supplier")) {
                    try {
                        Label welcome = new Label("Welcome " + admin.getName());

                        // CONSTRUCT SUPPLY STOCK HERE//
                        Button ProcessOrders = new Button("Process Pending Orders");
                        ProcessOrders.setOnAction(new ProcessOrder());

                        Button ShipOrders = new Button("Ship Processed Orders");
                        ShipOrders.setOnAction(new ShipOrder());

                        VBox Supplier_VBox = new VBox(welcome, ProcessOrders, ShipOrders);
                        Scene Supply = new Scene(Supplier_VBox, 800, 600);

                        Supply_Stage.setTitle("Welcome to Krustomer's");
                        Supply_Stage.setScene(Supply);
                        Supply_Stage.show();

                    }
                    catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }


    ///////////////////////
    // VIEW ORDER HANDLER//
    ///////////////////////

    class ViewOrderHandler implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent event) {
            String banker;
            try {

                Label orderHeader = new Label("Review your Order:");

                /////////////////////////////////
                // CONSTRUCT VIEWING ORDER HERE//
                /////////////////////////////////

                banker = Banker();
                if (banker.equals("e.balance")){

                } else if (banker.equals("e.cc")){

                }

                Button Return = new Button("Continue Shopping");
                Return.setOnAction(new ReturnHandler());

                HBox Order_HB = new HBox();
                VBox Order_VB = new VBox(orderHeader, Order_HB, Return);
                Scene Order = new Scene(Order_VB, 400, 400);

                Order_Stage.setScene(Order);
                Order_Stage.show();
            }
            catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

    class cartAddition implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent event) {
            try {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 2; j++) {
                        if (j == 1) {
                            cost += Main.cart[i][j];
                        }
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    ////////////////////
    // RETURN HANDLER //
    ////////////////////

    class ReturnHandler implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent event) {

            Order_Stage.close();
        }
    }


    //Need creditCardNum, balance, cost
    static String Banker() {
        String authNum = null;
        if (loggedIn[5].length() == 16) {
            if (balance >= cost) {
                for (int i = 0; i < 12; i++) {
                    int rnd = (int) (Math.random() * 52);
                    char base = (rnd < 26) ? 'A' : 'a';
                    base = (char) (base + rnd % 26);
                    authNum += base;
                }
                return authNum;
            }
            return "e.balance";
        }
        return "e.cc";
    }


    ///////////////////////
    // Processing Order  //
    ///////////////////////

    class ProcessOrder implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent actionEvent) {
            try {
                Label welcome = new Label("Orders needing processing");

                // Show Orders here ? Maybe a button to individually process each and a process all

                Button ViewStock = new Button("Process Orders");
                ViewStock.setOnAction(new ViewOrderSHandler());

                Button Back = new Button("Back");
                Back.setOnAction(new BackProcessHandler());

                VBox Supplier_VBox = new VBox(welcome, ViewStock, Back);
                Scene Supply = new Scene(Supplier_VBox, 400, 400);

                // After process update stock here


                Orders_Stage.setScene(Supply);
                Orders_Stage.show();

            }
            catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

    class ShipOrder implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent actionEvent) {
            try {
                Label welcome = new Label("Orders to be shipped");

                // Show *PROCESSED* Orders here ? Maybe a button to individually ship each and a ship all

                Button Back = new Button("Back");
                Back.setOnAction(new BackShipHandler());

                Button ViewStock = new Button("Ship All Orders");
                ViewStock.setOnAction(new ViewOrderSHandler());
                VBox Supplier_VBox = new VBox(welcome, ViewStock, Back);
                Scene Supply = new Scene(Supplier_VBox, 400, 400);

                // After ship update order status and numbers in stock here

                Ship_Stage.setScene(Supply);
                Ship_Stage.show();

            }
            catch (Exception e) {
                e.printStackTrace();
            }
        }

    }


    ///////////////////////
    // ViewOrdersHandler //
    ///////////////////////

    class ViewOrderSHandler implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent event) {

        }

    }

    ///////////////////////
    // BackOrderHandler //
    ///////////////////////

    class BackProcessHandler implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent event) {
            Orders_Stage.close();
        }

    }

    ///////////////////////
    // BackShipHandler //
    ///////////////////////

    class BackShipHandler implements EventHandler<ActionEvent> {

        @Override
        public void handle(ActionEvent event) {
            Ship_Stage.close();
        }

    }

    ///////////////////
    //Account Boolean//
    ///////////////////

    static boolean accountDetails (String user, String pass) {
        // User, Pass, Name, Addr, Phone, CC, Type
        String accFile = "accounts.txt";
        File inFile = new File(accFile);
        String[] contents = null;
        try {
            Scanner scanner = new Scanner(inFile);
            while (scanner.hasNextLine()) {
                String data = scanner.nextLine();

                if (data.indexOf(user) != -1) {
                    for (int i = 0; i < 7; i++) {
                        loggedIn[i] = data;
                        data = scanner.nextLine();
                    }
                    return true;
                }
            }
            scanner.close();
        }
        catch (FileNotFoundException e) {
            return false;
        }
        return false;
    }


    /////////////////////
    // ACCOUNT HANDLER //
    /////////////////////

    class AccountHandler implements EventHandler<ActionEvent> {
        @Override
        public void handle(ActionEvent event) {
            String accFile = "accounts.txt"; //Name of file for storing accounts.

            //Pryor - added new buttons and stage/scene to differentiate between customer and supplier account.
            Button Customer = new Button("Customer Account");
            Button Supplier = new Button("Supplier Account");

            HBox hboxAcc = new HBox(30, Customer, Supplier);
            hboxAcc.setAlignment(Pos.CENTER);
            hboxAcc.setPadding(new Insets(10));


            Stage AccountStage = new Stage();

            Scene AccountSel = new Scene(hboxAcc);

            AccountStage.setScene(AccountSel);
            AccountStage.show();

            ///////////////////////
            // NEW CUST ACCOUNT //
            //////////////////////

            //Customer button to handle customer account creation.
            Customer.setOnAction(val -> {
                TextField userField;
                TextField passField;
                TextField nameField;
                TextField addrField;
                //Pryor - added text fields for phone & credit card number. These are part of the 'Create Account'
                //        use case in the project PDF.
                TextField phonField;
                TextField cardField;
                try {

                    Label promptInfo = new Label("To make a new account, please enter your personal information below: ");
                    Label promptUser = new Label("Username: ");
                    Label promptPass = new Label("Password: ");
                    Label promptName = new Label("Legal Name: ");
                    Label promptAddr = new Label("Mailing Address: ");
                    Label promptPhone = new Label("Phone Number: ");
                    Label promptCard = new Label("Credit Card Number: ");

                    userField = new TextField();
                    passField = new TextField();
                    nameField = new TextField();
                    addrField = new TextField();
                    phonField = new TextField();
                    cardField = new TextField();


                    Button createCust = new Button("Create Customer Account");


                    HBox info_hbox = new HBox(promptInfo);
                    // Pryor - added some spacing for the HBoxes (v: 10)
                    HBox user_pass_hbox = new HBox(10, promptUser, userField, promptPass, passField);
                    HBox name_addr_hbox = new HBox(10, promptName, nameField, promptAddr, addrField);
                    HBox phon_card_hbox = new HBox(10, promptPhone, phonField, promptCard, cardField);
                    VBox vboxAcc = new VBox (30, info_hbox, user_pass_hbox, name_addr_hbox, phon_card_hbox,createCust);



                    vboxAcc.setAlignment(Pos.CENTER);
                    vboxAcc.setPadding(new Insets(10));

                    AccountStage.setTitle("New Customer Account!");
                    AccountStage.setScene(new Scene(vboxAcc));

                    AccountStage.show();

                    //Button to create a new customer account.
                    createCust.setOnAction(val2 -> {
                        try {
                            String username = String.valueOf(userField.getText());
                            String password = String.valueOf(passField.getText());
                            String name = String.valueOf(nameField.getText());
                            String address = String.valueOf(addrField.getText());
                            String phoneNum = String.valueOf(phonField.getText());
                            String creditCard = String.valueOf(cardField.getText());

                            //Checking whether given username already exists or not.
                            File inFile = new File(accFile);
                            String[] contents = null;
                            FileReader fileRead = new FileReader(inFile);
                            BufferedReader checkUser = new BufferedReader(fileRead);
                            String temp;
                            boolean userError = false;

                            while ((temp = checkUser.readLine()) != null) {
                                contents = temp.split("\n");
                                for (String checkName : contents) {
                                    if (checkName.equals(username)) {

                                        userError = true;

                                        Stage DupStage = new Stage();

                                        Button returnUser = new Button("Return");
                                        HBox confButton = new HBox(returnUser);

                                        Label dupName = new Label("Error, that username already exists, please input a different username.");

                                        HBox promptError = new HBox(10, dupName);
                                        VBox vboxError = new VBox(30, promptError, confButton);

                                        vboxError.setAlignment(Pos.CENTER);
                                        vboxError.setPadding(new Insets(10));

                                        DupStage.setTitle("Error, Duplicate Username!");
                                        DupStage.setScene(new Scene(vboxError));
                                        DupStage.show();


                                        returnUser.setOnAction(val3 -> {
                                            DupStage.close();
                                            AccountStage.show();
                                        });
                                    }
                                }
                            }

                            if(userError == true){
                                AccountStage.close();
                            }

                            else {



                                Label promptType = new Label("Please select your account type: ");

                                HBox prompt_type = new HBox(promptType);

                                Button regularType = new Button("Regular");
                                Button premiumType = new Button("Premium");

                                HBox type_sel = new HBox(10, regularType, premiumType);

                                VBox vboxType = new VBox(10, prompt_type, type_sel);
                                vboxType.setAlignment(Pos.CENTER);
                                vboxType.setPadding(new Insets(10));

                                AccountStage.setTitle("New Customer Account! - Select Type");
                                AccountStage.setScene(new Scene(vboxType));

                                AccountStage.show();

                                //Buttons to select account type - Regular or Premium
                                regularType.setOnAction(val3 -> {
                                    String accountType = "Regular";


                                    // Writing new account info to accounts.txt
                                    try {
                                        FileWriter accountsFW = new FileWriter(accFile, true);
                                        BufferedWriter accountsBW = new BufferedWriter(accountsFW);
                                        PrintWriter accounts = new PrintWriter(accountsBW);

                                        accounts.println(username);
                                        accounts.println(password);
                                        accounts.println(name);
                                        accounts.println(address);
                                        accounts.println(phoneNum);
                                        accounts.println(creditCard);
                                        accounts.println(accountType);
                                        accounts.println();
                                        accounts.close();


                                    } catch (IOException e) {
                                        e.printStackTrace();
                                    }


                                    Label promptSuccess = new Label("Account created successfully!");
                                    Label promptReg = new Label("Type - Regular Customer");

                                    HBox prompt_succ = new HBox(promptSuccess);
                                    HBox acc_type = new HBox(promptReg);

                                    Button retLogin = new Button("Return to login");

                                    VBox regSuccess = new VBox(10, prompt_succ, acc_type, retLogin);
                                    regSuccess.setAlignment(Pos.CENTER);
                                    regSuccess.setPadding(new Insets(10));

                                    AccountStage.setTitle("Account Creation Successful!");
                                    AccountStage.setScene(new Scene(regSuccess));

                                    AccountStage.show();

                                    retLogin.setOnAction(val5 -> {
                                        AccountStage.close();
                                    });
                                });


                                premiumType.setOnAction(val4 -> {
                                    String accountType = "Premium";
                                    //Must also charge membership fee here.  See use case: Create Account - Step 4

                                    // Writing new account info to accounts.txt
                                    try {
                                        FileWriter accountsFW = new FileWriter(accFile, true);
                                        BufferedWriter accountsBW = new BufferedWriter(accountsFW);
                                        PrintWriter accounts = new PrintWriter(accountsBW);

                                        accounts.println(username);
                                        accounts.println(password);
                                        accounts.println(name);
                                        accounts.println(address);
                                        accounts.println(phoneNum);
                                        accounts.println(creditCard);
                                        accounts.println(accountType);
                                        accounts.println();
                                        accounts.close();


                                    } catch (IOException e) {
                                        e.printStackTrace();
                                    }

                                    Label promptSuccess = new Label("Account created successfully!");
                                    Label promptPrem = new Label("Type - Premium Customer");

                                    HBox prompt_succ = new HBox(promptSuccess);
                                    HBox acc_type = new HBox(promptPrem);

                                    Button retLogin = new Button("Return to login");

                                    VBox premSuccess = new VBox(10, prompt_succ, acc_type, retLogin);
                                    premSuccess.setAlignment(Pos.CENTER);
                                    premSuccess.setPadding(new Insets(10));

                                    AccountStage.setTitle("Account Creation Successful!");
                                    AccountStage.setScene(new Scene(premSuccess));

                                    retLogin.setOnAction(val5 -> {
                                        AccountStage.close();
                                    });

                                });
                            }

                        }

                        catch (Exception e) {
                            e.printStackTrace();
                        }
                    });


                }
                catch (Exception e) {
                    e.printStackTrace();
                }

            });

            ///////////////////////
            // NEW SUPP ACCOUNT //
            //////////////////////

            //Supplier button to handle supplier account creation.
            Supplier.setOnAction(value ->{
                TextField userField;
                TextField passField;
                try {

                    Label promptInfo = new Label("To make a new account, please enter your supplier information below: ");
                    Label promptUser = new Label("Username: ");
                    Label promptPass = new Label("Password: ");

                    userField = new TextField();
                    passField = new TextField();


                    Button createSupp = new Button("Create Supplier Account");


                    HBox info_hbox = new HBox(promptInfo);
                    // Pryor - added some spacing for the HBoxes (v: 10)
                    HBox user_pass_hbox = new HBox(10, promptUser, userField, promptPass, passField);
                    VBox vboxAcc = new VBox (30, info_hbox, user_pass_hbox, createSupp);


                    vboxAcc.setAlignment(Pos.CENTER);
                    vboxAcc.setPadding(new Insets(10));

                    AccountStage.setTitle("New Supplier Account!");
                    AccountStage.setScene(new Scene(vboxAcc));

                    AccountStage.show();

                    createSupp.setOnAction(val1 -> {
                        try{
                            String username = String.valueOf(userField.getText());
                            String password = String.valueOf(passField.getText());

                            //Checking whether given username already exists or not.
                            File inFile = new File(accFile);
                            String[] contents = null;
                            FileReader fileRead = new FileReader(inFile);
                            BufferedReader checkUser = new BufferedReader(fileRead);
                            String temp;
                            boolean userError = false;

                            while ((temp = checkUser.readLine()) != null) {
                                contents = temp.split("\n");
                                for (String checkName : contents) {
                                    if (checkName.equals(username)) {

                                        userError = true;

                                        Stage DupStage = new Stage();

                                        Button returnUser = new Button("Return");
                                        HBox confButton = new HBox(returnUser);

                                        Label dupName = new Label("Error, that username already exists, please input a different username.");

                                        HBox promptError = new HBox(10, dupName);
                                        VBox vboxError = new VBox(30, promptError, confButton);

                                        vboxError.setAlignment(Pos.CENTER);
                                        vboxError.setPadding(new Insets(10));

                                        DupStage.setTitle("Error, Duplicate Username!");
                                        DupStage.setScene(new Scene(vboxError));
                                        DupStage.show();


                                        returnUser.setOnAction(val3 -> {
                                            DupStage.close();
                                            AccountStage.show();
                                        });
                                    }
                                }
                            }

                            String accountType = "Supplier";

                            if(userError == true){
                                AccountStage.close();
                            }

                            else {

                                // Writing new account info to accounts.txt
                                try {
                                    FileWriter accountsFW = new FileWriter(accFile, true);
                                    BufferedWriter accountsBW = new BufferedWriter(accountsFW);
                                    PrintWriter accounts = new PrintWriter(accountsBW);

                                    accounts.println(username);
                                    accounts.println(password);
                                    accounts.println(".");
                                    accounts.println(".");
                                    accounts.println(".");
                                    accounts.println(".");
                                    accounts.println(accountType);
                                    accounts.println();
                                    accounts.close();

                                } catch (IOException e) {
                                    e.printStackTrace();
                                }

                                Label promptSuccess = new Label("Account created successfully!");
                                Label promptSupp = new Label("Type - Supplier");

                                HBox prompt_supp = new HBox(promptSuccess);
                                HBox acc_type = new HBox(promptSupp);

                                Button retLogin = new Button("Return to login");

                                VBox suppSuccess = new VBox(10, prompt_supp, acc_type, retLogin);
                                suppSuccess.setAlignment(Pos.CENTER);
                                suppSuccess.setPadding(new Insets(10));

                                AccountStage.setTitle("Account Creation Successful!");
                                AccountStage.setScene(new Scene(suppSuccess));
                                AccountStage.show();

                                retLogin.setOnAction(val2 -> {
                                    AccountStage.close();
                                });
                            }
                        }

                        catch (Exception e) {
                            e.printStackTrace();
                        }
                    });


                }
                catch (Exception e) {
                    e.printStackTrace();
                }
            });
        }
    }

//////////////////////
// Account Creation //
//////////////////////

    class Account {
        private String username;
        private String password;
        private String name;
        private String address;
        private String phoneNum;
        private String creditCard;
        private String accountType;

        Account(String tempID, String tempPass, String tempName, String tempAddress, String tempPhone, String tempCard, String tempType) {
            this.username = tempID;
            this.password = tempPass;
            this.name = tempName;
            this.address = tempAddress;
            this.phoneNum = tempPhone;
            this.creditCard = tempCard;
            this.accountType = tempType;

        }

        /////////////////////
        // Getters/Setters //
        /////////////////////

        public void setUser(String input) {	this.username = input; }
        public String getUser() {	return this.username; }

        public void setPass(String input) { this.password = input; }
        public String getPass() { return this.password; }

        public void setName(String input) { this.name = input; }
        public String getName() { return this.name; }

        public void setAddr(String input) { this.address = input; }
        public String getAddr() { return this.address; }

        public void setPhone(String input) { this.phoneNum = input; }
        public String getPhone() { return this.phoneNum; }

        public void setCard(String input) { this.creditCard = input; }
        public String getCard() { return this.creditCard; }

        public void setType(String input) { this.accountType = input; }
        public String getType() { return this.accountType; }

////////////////////
// Log in Boolean //
////////////////////

        public String LogIn( Account reference, String user, String pass) {

            accountDetails(user, pass);

            if (ContainsKeyword(loggedIn[0], user)) {
                if (ContainsKeyword(loggedIn[1], pass)) {
                    return "Success!";
                }
                else {    return "You have entered the password incorrectly";    }
            }
            else {    return "Account Doesn't Exist!";    }

        }

        public boolean ContainsKeyword(String index, String keyword) {
            if (index.equals(keyword)) {
                return true;
            }
            else { return false; }
        }
    }
}
