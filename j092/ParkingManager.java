package week9.j092;

import week9.j091.*;

import java.util.HashMap;
import java.util.Scanner;

/*
학생 성적, hashmap에 저장하기- key: 학생이름 / Value: Score객체

 */
public class ParkingManager {
    /*
    <비만인 사람 비율 알아내기>
    file IO 통해 파일을 가져와서 어딘가에 보관
    보관된 내용을 어떤 메소드로 보내서 비만인 사람 수 리턴.
    퍼센트 수 나타내기.
     */
    public static void main(String[] args){
        ParkingManager m = new ParkingManager();
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
        Scanner sc = new Scanner(System.in);
        boolean quit = false;
        HashMap<Integer, CarInfo> parkList = new HashMap<>();    //주차정보 저장하는 해쉬맵

        do{
            System.out.print("1) enter, 2) exit, 3) list 4) quit > ");

            int choice = sc.nextInt();
            //^ 기존 방식을 쓰면 모든 문자의 첫글짜만 들어가서 switch문에서 check할 수 없으므로
            // 정규분포 활용해 첫 문자를 가져오게 바꿈
            switch (choice){
                case 1:     //주차 차량 등록

                    break;
                case 2: //출차, 차 번호 입력해서 몇분 나왔는지, 얼마 내야하는지 보여줌.

                    break;

                case 3: //현재 주차된 모든 차량 정보와 입차시간 출력.

                    break;

                case 4: //프로그램 종료
                    quit = true;
                    break;

                default:
                    System.out.print("잘못된 입력...");
                    break;
            }
        } while(!quit);
    }   //run method
}   //class
