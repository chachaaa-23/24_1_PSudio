package week9.j081;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;

public class Main {
    /*
    <최댓값과 최솟값 구하기>
    file IO 통해 파일을 가져와서 어딘가에 보관
    이 숫자들 중 가장 큰수와 작은수 판별하고 출력
     */
    public static void main(String[] args){
        Main m = new Main();
        m.run(args);
    }

    public void run (String[] args){
        String rawString = readFile();
        System.out.println("rawString : "+ rawString);
        //이 숫자들 중 가장 큰수와 작은수 판별하고 출력
        //공백을 기준으로 숫자를 나누고, 첫번쨰 숫자와 두 번쨰 숫자를 비교하기..
        //rawString에서 공백을 기준으로 나왔던 모든 수를 하나의 수로 인식해서 array 에 넣고 비교..
        String[] array = rawString.split(" ") ;
        int max = Integer.parseInt(array[0]);    //초깃값 설정
        int min = Integer.parseInt(array[0]);

        for(String a : array){
            int num = Integer.parseInt(a);
            if(num > max)
                max = num;
            if(num < min)
                min = num;
        }

        System.out.println("Maximum number : "+ max);
        System.out.println("Minimum number : "+ min);

    }

    public String readFile() {
        String readedString = "";
        try{
            Reader reader = new FileReader("/Users/jessicacha/Documents/Jessica's Macbook/Programming_studio_24_1/src/week9/j081/data.txt");

            int data=0;

            while((data = reader.read()) != -1){
                char num = (char) data;
                readedString = readedString + num;
            }
            reader.close();
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        } catch (IOException e){
            e.printStackTrace();
        }

        return readedString;
    }   //readFile

}   //class Main
