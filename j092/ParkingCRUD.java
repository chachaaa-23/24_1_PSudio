package week9.j092;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ParkingCRUD {
    Scanner sc = new Scanner(System.in);
    //차량번호와 차종을 입력받아 주차 등록.
    //새로운 CarInfo 만들어서 해쉬맵에 저장 및 반환.
    HashMap<Integer, CarInfo> parkList = new HashMap<>();    //주차정보 저장하는 해쉬맵
    public void createParking(){
        int number=0;
        String type;
        //정보입력
        System.out.print("Enter number, type > ");
        number = sc.nextInt();
        //sc.nextLine();

        type = sc.nextLine();

        //정보 저장
        CarInfo car = new CarInfo(number, type);
        parkList.put(number, car);

        System.out.println("item added");
    }

    //출차하기
    public void exitParking(){
        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");
        int number=0;
        String type;

        System.out.print("Enter car number to exit > ");
        number = sc.nextInt();
        sc.nextLine();

        //차량 실제로 존재하는지 찾기
        for(Map.Entry<Integer, CarInfo> entry : parkList.entrySet()){
            int carNumber = entry.getKey();

            if(number == carNumber){    //존재한다면
                //주차한 시간 계산
                Date currentTimeDate = new Date();

                long currentTimeLong = currentTimeDate.getTime();
                long carTimeLong = entry.getValue().getTime().getTime();

                long diff = carTimeLong - currentTimeLong;
                long diffMin = diff / (1000* 60);

                //주차요금 계산
                int parkingfee = 0;
                //시간계산: 0~10분 미만 = 무료, 10~20분 미만= 500₩씩
                //n분 / 10 = 에 따라, 결과가 0이면 0원, 1이면 500원, 2이면 500*2원...
                //  i이면 500*i 원!
                parkingfee = ( (int)diffMin / 10)* 500 ;
                SimpleDateFormat nowTime = new SimpleDateFormat("yyyyMMdd HHmm");

                //차량정보 출력(번호, 이름, 주차시간, 차량비, 현재시간)
                System.out.print(entry.getValue().getNumber()+ " "
                        + entry.getValue().getType()+ " "
                        + diffMin + ", "+
                        "Parking fee "+ parkingfee+ " (" +
                        "current time " + nowTime.format(currentTimeDate) + ")\n");

                parkList.remove(carNumber);
                return;
            }
        }
        //차량번호 없을 시..
        System.out.println("입력된 차량번호 없음...");
    }
    //listParking
    public void listParking(){
        String pnum = "num";
        String ptype = "type";
        String ptime = "time";
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyyMMdd HHmm");

        System.out.println("========================================");
        System.out.printf("%-20s %-20s %-20s\n", pnum, ptype, ptime);

        int i=0;
        for(Map.Entry<Integer, CarInfo> entry : parkList.entrySet()){

            String formattedDate = dateFormat.format(entry.getValue().getTime());

            System.out.printf("[%d] %-15d %-21s %-20s\n", i+1, entry.getKey(), entry.getValue().getType(), formattedDate);
            i++;
        }

    }

}
