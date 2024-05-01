package week9.j082;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class fileIo {
    public ArrayList<Integer> readFIle(){
        ArrayList<Integer> datalist = new ArrayList<>();
        try{
            File file = new File("/Users/jessicacha/Documents/Jessica's Macbook/Programming_studio_24_1/src/week9/j082/data.txt");
            Scanner scanner = new Scanner(file);
            int i=0;

            while(scanner.hasNextInt()){
                int num = scanner.nextInt();
                datalist.add(i, num);

                i++;
            }
            scanner.close();
        } catch (FileNotFoundException e){
            e.printStackTrace();;
        }
        return datalist;
    }
}
