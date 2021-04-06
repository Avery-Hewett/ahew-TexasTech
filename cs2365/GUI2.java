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

public class GUI2 extends Application {
    // Fields
    private TextField houseValue;
    private Label resultLabel;
    private Label resultLabel2;

    public static void main(String[] args)
    {
        // Launch the application.
        launch(args);
    }

    @Override
    public void start(Stage primaryStage)
    {
        // Create a Label to display a prompt.
        Label promptLabel = new Label("Enter value of property:");

        // Create a TextField for input.
        houseValue = new TextField();

        // Create a Button to perform the conversion.
        Button calcButton = new Button("Convert");

        // Register the event handler.
        calcButton.setOnAction(new CalcButtonHandler());

        // Create an empty Label to display the result.
        resultLabel = new Label();
        resultLabel2 = new Label();

        // Put the promptLabel and the kiloTextField in an HBox.
        HBox hbox = new HBox(10, promptLabel, houseValue);

        // Put the HBox, calcButton, and resultLabel in a VBox.
        VBox vbox = new VBox(10, hbox, calcButton, resultLabel, resultLabel2);

        // Set the VBox's alignment to center.
        vbox.setAlignment(Pos.CENTER);

        // Set the VBox's padding to 10 pixels.
        vbox.setPadding(new Insets(10));

        // Create a Scene.
        Scene scene = new Scene(vbox);

        // Add the Scene to the Stage.
        primaryStage.setScene(scene);

        // Set the stage title.
        primaryStage.setTitle("Assessment Value and Property Tax Calculator");

        // Show the window.
        primaryStage.show();
    }

    /*
     * Event handler class for calcButton
     */

    class CalcButtonHandler implements EventHandler<ActionEvent>
    {
        @Override
        public void handle(ActionEvent event)
        {
            // Get the kilometers.
            Double value = Double.parseDouble(houseValue.getText());

            // Convert the kilometers to miles.
            Double assessment = value * 0.6;
            Double tax = (assessment/100) * 0.64;

            // Display the results.
            resultLabel.setText(String.format("Assessment Value: $%,.2f", assessment));
            resultLabel2.setText(String.format("Property Tax: $%,.2f", tax));
        }
    }
}

