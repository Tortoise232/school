package main;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;

import java.util.ArrayList;
import java.util.Arrays;

public class Main extends Application {
    TextField plaintText;
    TextField encryptionkey;
    TextField alphabet;
    TextField cipher;
    Button hackingTime;
    Button unhackingTime;
    PermutationCrypter elliot;
    Image hkm = new Image("file:hackerman.png");

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("main.fxml"));
        primaryStage.setTitle("th3 3n1gm@ m@ch1n3");

        setUpShop(primaryStage);
        primaryStage.show();

    }

    public void setUpShop(Stage primaryStage){

        GridPane programStateGrid = new GridPane();
        this.alphabet = new TextField("abcdefghijklmnopqrstuvxyz .,!?_");
        this.plaintText = new TextField("message");
        this.cipher = new TextField("");
        this.encryptionkey = new TextField("0");
        this.hackingTime = new Button("IT'S HACKING TIME");
        this.unhackingTime = new Button("IT'S UNHACKING TIME");
        this.hackingTime.setOnAction(e -> {
            this.elliot = new PermutationCrypter(convertEncryptionKey(this.encryptionkey.getText()), this.alphabet.getText());
            this.cipher.setText(this.elliot.crypt(this.plaintText.getText()));
        });
        this.unhackingTime.setOnAction(e -> {
            this.elliot = new PermutationCrypter(convertEncryptionKey(this.encryptionkey.getText()), this.alphabet.getText());
            this.cipher.setText(this.elliot.decrypt(this.plaintText.getText()));
        });

        ImageView hkmView = new ImageView(hkm);
        hkmView.setFitHeight(200);
        hkmView.setFitWidth(200);
        programStateGrid.addRow(0, new Label("message:"), this.plaintText, this.hackingTime);
        programStateGrid.addRow(1, new Label("encryption key:"), this.encryptionkey, this.unhackingTime);
        programStateGrid.addRow(2, new Label("result:"), this.cipher);
        programStateGrid.addRow(10, new Label("an hero:"), hkmView);
        primaryStage.setScene(new Scene(programStateGrid, 640, 480));
    }

    public static void main(String[] args) {
        launch(args);
    }


    public static ArrayList<Integer> convertEncryptionKey(String candidate){
        System.out.println(candidate);
        int max = 0;
        ArrayList<Integer> result = new ArrayList<>();
        for(int i=0; i < candidate.length(); i++){
            if(candidate.charAt(i) >= '0' && candidate.charAt(i) <= '9') {
                int number = Character.getNumericValue(candidate.charAt(i));
                result.add(number);
                max = (number > max) ? number : max;
            }
        }
        boolean isResultValid = true;
        for(int i = 0; i < max; i ++){
            if(!result.contains(i))
                isResultValid = false;
        }
        System.out.println(result);
        return (isResultValid) ? result : null;
    }
}
