package week9.j083;

import java.util.ArrayList;

public class ScoreManager {
    /*
    <비만인 사람 비율 알아내기>
    file IO 통해 파일을 가져와서 어딘가에 보관
    보관된 내용을 어떤 메소드로 보내서 비만인 사람 수 리턴.
    퍼센트 수 나타내기.
     */
    public static void main(String[] args){
        ScoreManager m = new ScoreManager();
        m.run(args);
    }

    /*
    데이터 파일 읽어오기
        읽어올 때 ArrayList에 Score을 사용해서 넣은 걸 리턴하기
    각 과목별 총점과 평균점수 출력
    각 학생별 총점과 평균점수 출력
    가장 높은 평균 점수인 학생의 이름과 점수 출력
    */
    public void run (String[] args) {
        ArrayList<Score> datalist = new ArrayList<>();
        fileIo f = new fileIo();
        subjectAnalysis subAna = new subjectAnalysis();
        studentAnalysis stuAna = new studentAnalysis();

        datalist = f.readFIle();    //파일 읽어오기
        subAna.subjectStatistic(datalist);   //과목 분석
        subAna.subjectPrint();      //과목 분석결과 출력
        stuAna.studentStatistic(datalist);   //학생별 분석
        stuAna.studentPrint(datalist);       //학생 분석결과 출력



    }
}
