package week9.j093;
// SimpleChat Client

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.text.SimpleDateFormat;
import java.util.Date;

public class ChatClient {

    public static void main(String[] args) {
        if(args.length != 2){
            System.out.println("Usage : java ChatClient [Username] [Server IP]");
            System.exit(1);
        }
        Socket sock = null;
        BufferedReader br = null;
        PrintWriter pw = null;
        boolean endflag = false;
        try{
            sock = new Socket(args[1], 10001);
            pw = new PrintWriter(new OutputStreamWriter(sock.getOutputStream()));
            br = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            BufferedReader keyboard = new BufferedReader(new InputStreamReader(System.in));
            // Transmit Username

            pw.println(args[0]);
            pw.flush();
            InputThread it = new InputThread(sock, br);
            it.start();
            String line = null;
            while((line = keyboard.readLine()) != null){
                pw.println(line);
                pw.flush();
                if(line.equals("/quit")){
                    endflag = true;
                    break;
                }
            }
            System.out.println("Connection closed.");
        }catch(Exception ex){
            if(!endflag)
                System.out.println(ex);
        }finally{
            try{
                if(pw != null)
                    pw.close();
            }catch(Exception ex){}
            try{
                if(br != null)
                    br.close();
            }catch(Exception ex){}
            try{
                if(sock != null)
                    sock.close();
            }catch(Exception ex){}
        } // finally
    } // main
} // class

class InputThread extends Thread{
    private Socket sock = null;
    private BufferedReader br = null;
    public InputThread(Socket sock, BufferedReader br){
        this.sock = sock;
        this.br = br;
    }
    public void run(){
        try{
            String line = null;
            while((line = br.readLine()) != null){  //문자열이 null이 아닐때
                //현재 시간과 함계 입력받은 메시지를 출력한다.
                SimpleDateFormat dataTime = new SimpleDateFormat("HH:mm:ss");
                String currentTime = dataTime.format(new Date());
                System.out.println("["+ currentTime+ "]"+ line);
            }
            //if( (line = br.readLine()).equals(" ") )
        }catch(Exception ex){
        }finally{
            try{
                if(br != null)
                    br.close();
            }catch(Exception ex){}
            try{
                if(sock != null)
                    sock.close();
            }catch(Exception ex){}
        }
    } // InputThread
}
