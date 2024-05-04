package week9.j093;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

//조건대로 ChatThread 만 수정했으나, 앞에 날짜가 무조건 붙는 경우
public class ChatServer {

    public static void main(String[] args) {
        try{
            ServerSocket server = new ServerSocket(10001);
            System.out.println("Waiting Connections...");
            HashMap<String, PrintWriter> hm = new HashMap<>();
            while(true){
                Socket sock = server.accept();
                ChatThread chatthread = new ChatThread(sock, hm);
                chatthread.start();
            }
        }catch(Exception e){
            System.out.println(e);
        }
    }
}

class ChatThread extends Thread{
    private Socket sock;
    private String id;
    private BufferedReader br;
    private PrintWriter pw;
    private HashMap<String, PrintWriter> hm;
    private boolean initFlag = false;

    public ChatThread(Socket sock, HashMap<String, PrintWriter> hm){
        this.sock = sock;
        this.hm = hm;
        try{
            br = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            pw = new PrintWriter(new OutputStreamWriter(sock.getOutputStream()));
            id = br.readLine();
            synchronized(hm){
                hm.put(id, pw);
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
                if(line.equals("/quit")) {
                    break;
                } else if (line.equals("/userlist")) {
                    sendUserList();
                } else if(line.indexOf("/to ") == 0){
                    sendmsg(line);
                } else {
                    broadcast(id + " : " + line);
                }
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
    }

    public void sendmsg(String msg){
        int start = msg.indexOf(" ") +1;
        int end = msg.indexOf(" ", start);
        if(end != -1){
            String to = msg.substring(start, end);
            String msg2 = msg.substring(end+1);
            PrintWriter pw = hm.get(to);
            if(pw != null){
                pw.println(id + "'s secret message: " + msg2);
                pw.flush();
            } else {
                // If recipient not found, notify sender
                pw = hm.get(id);
                pw.println(to + " is not online.");
                pw.flush();
            }
        }
    }

    public void broadcast(String msg){
        synchronized(hm){
            Collection<PrintWriter> collection = hm.values();
            Iterator<PrintWriter> iter = collection.iterator();
            while(iter.hasNext()){
                PrintWriter pw = iter.next();
                pw.println(msg);
                pw.flush();
            }
        }
    }

    public void sendUserList(){
        StringBuilder userList = new StringBuilder("There are " + hm.size() + " users\n");
        Set<String> userSet = hm.keySet();
        for (String user : userSet) {
            userList.append(user).append(", ");
        }
        pw.println(userList.toString());
        pw.flush();
    }
}
