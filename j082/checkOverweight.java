package week9.j082;

import java.util.ArrayList;

public class checkOverweight{
    public int check(ArrayList<Integer> datalist){
        //datalist에 저장되있는 각 사람의 키&몸무게 가져와서 (i,i+1) 비만도 계산
        //비만일 시 변수++, 마지막에 해당 변수 리턴.
        int overWeightCount=0;
        int i=0;
        while(i<datalist.size() ){
            int height = datalist.get(i);
            i++;
            int weight = datalist.get(i);
            double bmi = weight / (height*0.01* height*0.01) ;

            if( bmi >= 25 )
                overWeightCount++;
            i++;
        }

        return overWeightCount;
    }
}
