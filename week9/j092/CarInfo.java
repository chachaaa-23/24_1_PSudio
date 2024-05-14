package week9.j092;

import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * 차량 정보를 담는 객체.
 */
public class CarInfo {
    private int number;
    private String type;
    private Date time ;

    public CarInfo (int number, String type){
        setNumber(number);
        setType(type);
        setTime(new Date());
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public Date getTime() {
        return time;
    }

    public void setTime(Date time) {
        this.time = time;
    }
}
