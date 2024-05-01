package week9.j082;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
public class Main {
    /*
    <비만인 사람 비율 알아내기>
    file IO 통해 파일을 가져와서 어딘가에 보관
    보관된 내용을 어떤 메소드로 보내서 비만인 사람 수 리턴.
    퍼센트 수 나타내기.
     */
    public static void main(String[] args){
        week9.j082.Main m = new week9.j082.Main();
        m.run(args);
    }

    public void run (String[] args) {
        ArrayList<Integer> datalist = new ArrayList<>();
        fileIo f = new fileIo();
        checkOverweight checkw = new checkOverweight();
        datalist = f.readFIle();
        System.out.println("All "+ datalist.size()/2+ " persons.");

        int overWeightCount = checkw.check(datalist);
        double percent = 0;
        percent = (( overWeightCount / (datalist.size()/2.0) )* 100.0) ;
        System.out.println("Total overweight persons: "+ overWeightCount
                + " (" + percent + "%)");
    }
}
