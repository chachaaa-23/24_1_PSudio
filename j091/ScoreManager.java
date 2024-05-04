package week9.j091;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

/*
학생 성적, hashmap에 저장하기- key: 학생이름 / Value: Score객체

 */
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
        HashMap<String, Score> datalist = new HashMap<>();
        fileIo f = new fileIo();
        subjectAnalysis subAna = new subjectAnalysis();
        studentAnalysis stuAna = new studentAnalysis();
        Scanner sc = new Scanner(System.in);
        boolean quit = false;

        datalist = f.readFIle();    //파일 읽어오기
        //^ 받아올 때 ArrayList 파라미터에서 HashMap으로 바꿔주기, 아래 두 line 도 same
        StudentSearch studentSearch = new StudentSearch();
        EditScore editScore = new EditScore();

        do{
            System.out.println("1) 점수 통계 출력- 학생별, 과목별 통계 출력.");
            System.out.println("2) 학생 검색기능- 학생 이름 입력받아, 이 학생이 있는지 확인.");
            System.out.println("3) 학생 점수 수정 기능- 학생 이름 입력받아, 이 학생의 과목 점수 변경.");
            System.out.println("4) 프로그램 종료");

            System.out.print("> ");
            int choice = sc.nextInt();
            //^ 기존 방식을 쓰면 모든 문자의 첫글짜만 들어가서 switch문에서 check할 수 없으므로
            // 정규분포 활용해 첫 문자를 가져오게 바꿈
            switch (choice){
                case 1:
                    subAna.subjectStatistic(datalist);   //과목 분석
                    stuAna.studentStatistic(datalist);   //학생별 분석
                    stuAna.studentPrint();    //학생 분석결과 출력
                    subAna.subjectPrint();      //과목 분석결과 출력
                    break;
                case 2:
                    studentSearch.studentSearch(datalist);
                    break;

                case 3:
                    datalist = editScore.editingScore(datalist);
                    break;

                case 4:
                    quit = true;
                    break;

                default:
                    System.out.print("잘못된 입력...");
                    break;
            }
        } while(!quit);
    }   //run method
}   //class
