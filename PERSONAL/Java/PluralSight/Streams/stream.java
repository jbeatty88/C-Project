/*
Streams have only 2 types:
Byte Streams: bineary data
Text Streams: Unicode Character data

Reading From:
    BaseClasses: InputStream(Byte)                |         Reader(Text)
                  int read() 1 byte                           int read() 1 char
		  int read(byte[] buff) 1+ byte               int read(char[] buff) 1+ char
  

                INPUTSTREAM_EX:
                   InputStream input = // create input streams
		   int intVal;
		   while((intVal = input.read()) >= 0) {
		       byte byteVal = (byte) intVal;

		   }
		 READER_EX:
		   Reader reader = // create reader
		   int intVal;
		   while((intVal = reader.read()) >= 0) {
		       char charVal = (char) intVal;
		       
		   }

		 
		   AUTO_CLEANUP_EX:
		   try (Reader reader = Helper.openReader("asdf.txt")) {
		       while(length = reader.read(buff) >= 0) {
		           // Do something here
		       }
		   } catch(IOException e) {
		       // Handle Exception here
		   }
*/
