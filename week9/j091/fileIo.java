package week9.j091;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class fileIo {
    //파일 읽어올 때 Score 사용.
    public HashMap<String, Score > readFIle(){
        ArrayList<Score> datalist = new ArrayList<>();
        HashMap<String, Score > Hashdatalist = new HashMap<>();

        try{
            File file = new File("/Users/jessicacha/Documents/Jessica's Macbook/Programming_studio_24_1/src/week9/j083/data.txt");
            Scanner scanner = new Scanner(file);
            int i=0;

            while(scanner.hasNext()){
                String name = scanner.next();   //공백을 기준으로 첫번째 String 만 읽기.
                int kor = scanner.nextInt();
                int eng = scanner.nextInt();
                int mat = scanner.nextInt();

                Score s = new Score(name, kor, eng, mat);
                datalist.add(i, s);
                Hashdatalist.put(name, s);

                i++;
            }
            scanner.close();
        } catch (FileNotFoundException e){
            e.printStackTrace();;
        }
        return Hashdatalist;
    }
}
