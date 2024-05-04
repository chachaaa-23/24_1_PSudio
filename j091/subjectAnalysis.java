package week9.j091;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class subjectAnalysis {
    int[] classSum = new int[3];   //국영수 총점
    int[] classAverage = new int[3];//국어 평균점수

    public void subjectPrint(){
        //과목별 총점 출력
        //과목별 평균 점수 출력
        System.out.println("국어 총점, 평균점수: "+ classSum[0]+ ", "+ classAverage[0]);
        System.out.println("영어 총점, 평균점수: "+ classSum[1]+ ", "+ classAverage[1]);
        System.out.println("수학 총점, 평균점수: "+ classSum[2]+ ", "+ classAverage[2]+ "\n");

    }

    public void subjectStatistic(HashMap<String, Score> Hashdatalist){
        //과목별 평균 점수 계산
        //for loop 써서 datalist에 있는 특정 과목의 총점과 평균점수 할당.
        //-> HashMap 사용하기.
        for(int i=0; i<3; i++){ //초기화!
            classSum[i] = 0;
            classAverage[i] = 0;
        }

        for(Map.Entry<String, Score> entry : Hashdatalist.entrySet()){
            //각 해쉬맵에 있는 국,영,수 과목을 더하기.
            classSum[0] = classSum[0]+ entry.getValue().getKor();
            classSum[1] = classSum[1]+ entry.getValue().getEng();
            classSum[2] = classSum[2]+ entry.getValue().getMat();
        }
        for(int i=0; i<3; i++)
            classAverage[i] = classSum[i] / Hashdatalist.size() ;

    }   //subjectStatistic
}   //class
