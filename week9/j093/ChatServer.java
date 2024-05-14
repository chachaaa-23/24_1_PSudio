package week9.j093;
// SimpleChat Server

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
/* 명령어 /userlist 추가하기

 */
public class ChatServer {

    public static void main(String[] args) {
        try{
            ServerSocket server = new ServerSocket(10001);
            System.out.println("Waiting Connections...");
            HashMap hm = new HashMap();
            while(true){
                Socket sock = server.accept();
                ChatThread chatthread = new ChatThread(sock, hm);
                chatthread.start();
            } // while
        }catch(Exception e){
            System.out.println(e);
        }
    } // main
}

class ChatThread extends Thread{
    private Socket sock;
    private String id;
    private BufferedReader br;
    private HashMap hm;
    private boolean initFlag = false;
    public ChatThread(Socket sock, HashMap hm){
        this.sock = sock;
        this.hm = hm;
        try{
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(sock.getOutputStream()));
            br = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            id = br.readLine();
            broadcast(id + " entered.");
            System.out.println("[Server log] " + id + " entered.");
            synchronized(hm){
                hm.put(this.id, pw);
            }
            initFlag = true;
        }catch(Exception ex){
            System.out.println(ex);
        }
    }
    public void run(){
        try{
            String line = null;
            while((line = br.readLine()) != null){
                if(line.equals("/quit"))
                    break;
                if(line.indexOf("/to ") == 0){
                    sendmsg(line);
                }
                if(line.equals("/userlist")){
                    sendUserlist();
                }
                else
                    broadcast(id + " : " + line);
            }
        }catch(Exception ex){
            System.out.println(ex);
        }finally{
            synchronized(hm){
                hm.remove(id);
            }
            broadcast(id + " exited.");
            System.out.println("[Server log] " + id + " exited.");
            try{
                if(sock != null)
                    sock.close();
            }catch(Exception ex){}
        }
    } // run

    //userList 보내주는 매서드
    public void sendUserlist() {
        StringBuilder userList = new StringBuilder("There are " + hm.size() + " users\n");  //StringBuilder써서 메시지 보내기
        for (Object userName : hm.keySet()) {   //해쉬맵의 모든 사용자 key(id)를
            userList.append(userName).append(", "); //StringBuilder에 추가.
        }
        // Remove the trailing comma and space
        userList.setLength(userList.length() - 2);  //맨 마지막은 쉼표랑 띄어쓰기 없어야함
        sendMessageToClient(userList.toString());   //만든 StringBuilder를 클라이언트에게 전달.(by 또다른 매서드)
    }
    private void sendMessageToClient(String message) {  //클라이언트에게 메시지 보내는 메서드
        try {
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(sock.getOutputStream()));
            //^소켓 출력 스트림 만들기.
            pw.println(message);    //메시지 보내기
            pw.flush();
        } catch (Exception ex) {
            System.out.println(ex);
        }
    }

    public void sendmsg(String msg){
        int start = msg.indexOf(" ") +1;
        int end = msg.indexOf(" ", start);
        if(end != -1){
            String to = msg.substring(start, end);
            String msg2 = msg.substring(end+1);
            Object obj = hm.get(to);
            if(obj != null){
                PrintWriter pw = (PrintWriter)obj;
                pw.println(id + "'s secret message: " + msg2);
                pw.flush();
            } // if
        }
    } // sendmsg
    public void broadcast(String msg){
        synchronized(hm){
            Collection collection = hm.values();
            Iterator iter = collection.iterator();
            while(iter.hasNext()){
                PrintWriter pw = (PrintWriter)iter.next();
                pw.println(msg);
                pw.flush();
            }
        }
    } // broadcast
}