package week9.j091;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class studentAnalysis {
    int mostHighIndex = 0;
    ArrayList<Score> wholeDatalist= new ArrayList<>();
    public void studentPrint(){
        //학생별 총점 출력
        //학생별 평균 점수 출력

        System.out.println("\n학생 이름, 총점, 평균점수");
        for(Score d : wholeDatalist)
            System.out.println(d.getName()+ ", "+ d.getSum()+ ", "+ d.getAvg());

        System.out.println("\n1등 학생의 이름, 총점, 평균점수");
        System.out.println(wholeDatalist.get(mostHighIndex).getName()+ ", "
                + wholeDatalist.get(mostHighIndex).getSum()+ ", "
                + wholeDatalist.get(mostHighIndex).getAvg()+"\n");

    }

    /**
     * 과목별 총점& 평균 점수 계산.
     * @param Hashdatalist
     */
    public void studentStatistic(HashMap<String, Score> Hashdatalist) {
        int max = 0;
        int index = 0;
        for (Map.Entry<String, Score> entry : Hashdatalist.entrySet()) {
            Score studentScore = entry.getValue(); // 학생의 점수 리스트 가져오기
            int sum = studentScore.getKor()+ studentScore.getEng()+ studentScore.getMat();
            int avg = sum / 3 ; // 평균 점수 계산

            studentScore.setSum(sum);
            studentScore.setAvg(avg);

            wholeDatalist.add(studentScore);

            if (max < sum) { // 최고 점수 업데이트
                max = sum;
                mostHighIndex = index;
            }
            index++;
        }
    } // studentStatistic
}   //class
