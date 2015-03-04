import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Jserver {
	
	public static void server() throws IOException {
		 ServerSocket mysocket = new ServerSocket(55555);
		    File myFile = new File("transfer.txt");
		    System.out.println("Server is up!!!!");
		    System.out.println("Sending file to client");
		    while (true) {
		      Socket sock = mysocket.accept();
		      
		      byte[] filebytes = new byte[(int) myFile.length()];
		      
		      BufferedInputStream bstream = new BufferedInputStream(new FileInputStream(myFile));
		      bstream.read(filebytes, 0, filebytes.length);
		      OutputStream ostream = sock.getOutputStream();
		      
		      ostream.write(filebytes, 0, filebytes.length);
		      
		      ostream.flush();
		      sock.close();
		    }
		
	}
	
  
}
