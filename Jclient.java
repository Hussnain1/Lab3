import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.net.Socket;

public class Jclient {
	
	public static void client() throws Exception {
		 Socket mysocket = new Socket("127.0.0.1", 55555);
		    
		    byte[] bsize = new byte[1024];
		    System.out.println("Client!!!");
		    InputStream istream = mysocket.getInputStream();
		    FileOutputStream fstream = new FileOutputStream("receivedFile.txt");
		    BufferedOutputStream bstream = new BufferedOutputStream(fstream);
		    
		    int rbytes = istream.read(bsize, 0, bsize.length);
		    bstream.write(bsize, 0, rbytes);
		    System.out.println("Receiving file from a server");
		    bstream.close();
		    mysocket.close();
		  		
	}
	
  
  
}
