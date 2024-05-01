package week9.j083;

import java.util.ArrayList;

public class subjectAnalysis {
    int[] classSum = new int[3];   //국영수 총점
    int[] classAverage = new int[3];//국어 평균점수

    public void subjectPrint(){
        //과목별 총점 출력
        //과목별 평균 점수 출력
        System.out.println("국어 총점, 평균점수: "+ classSum[0]+ ", "+ classAverage[0]);
        System.out.println("영어 총점, 평균점수: "+ classSum[1]+ ", "+ classAverage[1]);
        System.out.println("수학 총점, 평균점수: "+ classSum[2]+ ", "+ classAverage[2]);

    }

    public void subjectStatistic(ArrayList<Score> datalist){
        //과목별 평균 점수 계산
        //for loop 써서 datalist에 있는 특정 과목의 총점과 평균점수 할당.
        for(Score d : datalist){
            classSum[0] = classSum[0]+ d.getKor();
            classSum[1] = classSum[1]+ d.getEng();
            classSum[2] = classSum[2]+ d.getMat();
        }
        for(int i=0; i<3; i++)
            classAverage[i] = classSum[i] / datalist.size() ;

    }   //subjectStatistic
}   //class
