package week9.j091;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/*
    입력받은 학생 이름을 통해
    이 이름 가진 학생 있는지 확인,
        포문 통해 쭉 돌면서 해쉬맵 키값 탐색.
     결과출력
 */
public class StudentSearch {
    public void studentSearch(HashMap<String, Score> hashMapList){
        Scanner sc = new Scanner(System.in);
        boolean hasName = false;
        System.out.print("검색할 학생 이름 > ");
        String name = sc.nextLine();

        for(Map.Entry<String, Score> entry : hashMapList.entrySet()){
            if(name.equals(entry.getKey())){
                System.out.println("학생 발견! : "+ entry.getKey());
                hasName = true;
            }
            if(hasName) break;
        }
        if(!hasName)
            System.out.println("학생 발견 실패...");
    }

}
