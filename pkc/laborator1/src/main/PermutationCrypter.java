package main;

import java.util.ArrayList;

/**
 * Created by Petean Mihai on 10/13/2017.
 */
public class PermutationCrypter {

    private String alphabet;
    private ArrayList<Integer> encryptionKey;

    public PermutationCrypter(ArrayList<Integer> encryptionKey, String alphabet) {
        this.encryptionKey = encryptionKey;
        this.alphabet = alphabet;
    }

    public String getAlphabet() {
        return alphabet;
    }

    public void setAlphabet(String alphabet) {
        this.alphabet = alphabet;
    }

    public ArrayList<Integer> getEncryptionKey() {
        return encryptionKey;
    }

    public void setEncryptionKey(ArrayList<Integer> encryptionKey) {
        this.encryptionKey = encryptionKey;
    }

    public String fillString(String plainText){
        int diff = plainText.length() % this.encryptionKey.size();
        while(diff > 0) {
            plainText += "_";
            diff--;
        }
        System.out.println("FILLED: " + plainText);
        return plainText;
    }

    public boolean checkText(String plainText){
        for(int ct = 0; ct < plainText.length(); ct++){
            if(!this.alphabet.contains(plainText.charAt(ct) + ""))
                return false;
        }
        return true;
    }

    public String crypt(String plainText){
        if(!this.checkText(plainText))
            return "INVALID PLAIN TEXT";
        plainText = this.fillString(plainText);
        //parse each chunk separately
        String cipherText = new String();
        for(int ct = 0; ct <= plainText.length() - encryptionKey.size() ; ct += encryptionKey.size() ){
            for(int ctEncryptionKey = 0; ctEncryptionKey < encryptionKey.size(); ctEncryptionKey ++){
                cipherText += plainText.charAt(ct + encryptionKey.get(ctEncryptionKey));
            }
        }

        return cipherText.toUpperCase();
    }

}



