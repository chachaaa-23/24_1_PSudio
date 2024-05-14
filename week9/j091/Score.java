package week9.j091;

public class Score {
    private String name;
    private int kor;
    private int eng;
    private int mat;
    private int sum;
    private double avg;

    //constructor
    Score(String name, int kor, int eng, int mat){
        this.setName(name);
        this.setKor(kor);
        this.setEng(eng);
        this.setMat(mat);
    }
    //getter, setter
    public String toString(){  //점수 출력
        String s = name+ " "+ kor+ " " + eng+ " "+mat ;
        return s;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getKor() {
        return kor;
    }

    public void setKor(int kor) {
        this.kor = kor;
    }

    public int getEng() {
        return eng;
    }

    public void setEng(int eng) {
        this.eng = eng;
    }

    public int getMat() {
        return mat;
    }

    public void setMat(int mat) {
        this.mat = mat;
    }

    public int getSum() {
        return sum;
    }

    public void setSum(int sum) {
        this.sum = sum;
    }

    public double getAvg() {
        return avg;
    }

    public void setAvg(double avg) {
        this.avg = avg;
    }
}
