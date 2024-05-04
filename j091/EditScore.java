package week9.j091;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class EditScore {
    /*
     받아온 해쉬맵 통해
     수정하고 싶은 학생 이름 입력받고
     해쉬맵의 키값 찾아가면서 점수 수정하기
     */
    public HashMap<String, Score> editingScore(HashMap<String, Score> hashList){
        Scanner sc = new Scanner(System.in);
        boolean hasName = false;
        System.out.print("수정할 학생 이름 > ");
        String name = sc.nextLine();

        for(Map.Entry<String, Score> entry : hashList.entrySet()){
            if(name.equals(entry.getKey())){
                //수정을 위한 Score 객체에 넣을 변수 준비
                //수정하기.
                System.out.println("변경할 과목 점수를 입력하세요");
                System.out.print("국어 > ");
                int kor = sc.nextInt();
                System.out.print("영어 > ");
                int eng = sc.nextInt();
                System.out.print("수학 > ");
                int mat = sc.nextInt();
                 //int sum = kor+ eng+ mat;
                 //int avg = sum/3 ;

                entry.getValue().setKor(kor);
                entry.getValue().setEng(eng);
                entry.getValue().setMat(mat);
                //entry.getValue().setSum(sum);
                //entry.getValue().setAvg(avg);

                System.out.println("점수 수정 완료!");
                 System.out.println("국어: "+ entry.getValue().getKor()+ "점, 영어: "+ + entry.getValue().getEng()+ "점, 수학: "+ entry.getValue().getMat()+ "점");

                 hasName = true;
                 break;
            }
        }
        if(!hasName)
            System.out.println("학생 발견 실패...");

        return hashList;
    }
}
