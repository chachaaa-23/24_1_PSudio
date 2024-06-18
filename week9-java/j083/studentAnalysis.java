package week9.j083;

import java.util.ArrayList;

public class studentAnalysis {
    int mostHighIndex = 0;
    public void studentPrint(ArrayList<Score> datalist){
        //학생별 총점 출력
        //학생별 평균 점수 출력
        System.out.println("\n학생 이름, 총점, 평균점수");
        for(Score d : datalist)
            System.out.println(d.getName()+ ", "+ d.getSum()+ ", "+ d.getAvg());

        System.out.println("\n1등 학생의 이름, 총점, 평균점수");
        System.out.println(datalist.get(mostHighIndex).getName()+ ", "+ datalist.get(mostHighIndex).getSum()+ ", "+ datalist.get(mostHighIndex).getAvg());

    }

    public void studentStatistic(ArrayList<Score> datalist){
        //개인별 평균 점수 계산
        //for loop 써서 datalist에 있는 각 개인별 sum&avg에
        //값을 계산한걸 넣는다.
        int max=0;
        for(int i=0; i<datalist.size(); i++){
            int sum = datalist.get(i).getKor()+ datalist.get(i).getMat()+ datalist.get(i).getEng() ;
            datalist.get(i).setSum(sum);

            if(max < sum){  //1등학생 찾기
                max = sum;
                mostHighIndex = i;
            }

            int avg = sum / 3;
            datalist.get(i).setAvg(avg);
        }
    }   //studentStatistic
}   //class
