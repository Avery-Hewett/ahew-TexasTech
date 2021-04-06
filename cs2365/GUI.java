package com.hw6;

import javafx.application.Application;
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


public class GUI extends Application {
    private TextField getwholesale;
    private TextField getmarkup;
    private Label resultLabel;

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) {
        Label promptLabel = new Label("Enter a wholesale cost:");
        Label promptLabel2 = new Label("Enter a markup percentage:");

        getwholesale = new TextField();
        getmarkup = new TextField();

        Button calcButton = new Button("Calculate");

        calcButton.setOnAction(new CalcButtonHandler());

        resultLabel = new Label();

        HBox hbox = new HBox(10, promptLabel, getwholesale);
        HBox hbox2 = new HBox(10, promptLabel2, getmarkup);

        VBox vbox = new VBox(10, hbox, hbox2, calcButton, resultLabel);

        vbox.setAlignment(Pos.CENTER);

        vbox.setPadding(new Insets(10));

        Scene scene = new Scene(vbox);

        primaryStage.setScene(scene);

        primaryStage.setTitle("Markup Calculator");

        primaryStage.show();
    }

    class CalcButtonHandler implements EventHandler<ActionEvent> {
        @Override
        public void handle(ActionEvent event) {
            Double wholesale = Double.parseDouble(getwholesale.getText());
            Double markup = Double.parseDouble(getmarkup.getText());

            Double total = wholesale + (wholesale * (markup*.01));

            resultLabel.setText(String.format("$%,.2f", total));
        }
    }
}
