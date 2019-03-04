package com.imageeditor;

import javax.management.ObjectName;
import java.io.*;
import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.Scanner;

public class FileHelper {
    // This class will handle IO
    private String fileName;
    private String outputName;
    private Image ppmImg;
    // Input
    public FileHelper() {}
    public FileHelper(String fileName) { this.fileName = fileName; makeImage();}
    public FileHelper(String fileName, String outputName) { this.fileName = fileName; this.outputName = outputName; }

    // COPY CSTR
    FileHelper(FileHelper fh) {
//        System.out.println("COPY CSTR CALLED in FILEHELPER");
        fileName = fh.fileName;
        ppmImg = fh.ppmImg;
        outputName = fh.outputName;
        makeImage();
    }

    public void setOutputFileName(String outputFileName) { this.outputName = outputFileName; }

    public String getFileName() { return this.fileName; }

    public void setFileName(String fileName) {this.fileName = fileName; }

    public String getOutputName() { return this.outputName; }

    public void readInLines() {
        try (Scanner sc = new Scanner(new File(fileName)).useDelimiter("((#[^\\n]*\\n)|(\\s+))+")) {
            while(sc.hasNext()) {
                String str = sc.next();
                System.out.println(str);

            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void makeImage() {
        // Open File and read in everything execept for the "P3" and comments
        try (Scanner sc = new Scanner(new File(fileName)).useDelimiter("(#[^\\n]*\\n)|(\\s+)+")) {
            // Set the dimensions (Default is 10 * 10)
            String ppmType = sc.next();
            String space  = sc.next();
            int dim1 = Integer.parseInt(sc.next());
            int dim2 = Integer.parseInt(sc.next());
            int maxSize = Integer.parseInt(sc.next());
            // Make a 2-D array of pixels
            Pixel[][] pix = new Pixel[dim1][dim2];
            // Make and Image Object
            this.ppmImg = new Image(dim1, dim2); // This will initialize an empty 10 x 10 2-D array
            // While there is something following
            for(int i = 0; i < dim1; i++) {
                for(int j = 0; j < dim2; j++) {
                    if(sc.hasNext()) {
                        Integer red = Integer.parseInt(sc.next());
                        if(sc.hasNext()) {
                            Integer green = Integer.parseInt(sc.next());
                            if(sc.hasNext()) {
                                Integer blue = Integer.parseInt(sc.next());
                                Pixel pixel = new Pixel(red, green, blue);
                                pix[i][j] = pixel;
                            }
                        }
                    }
                }
            }
                        // Set the Pixels in our Image Object
            this.ppmImg.setImgPixArr(pix);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void makeFileCopy() {
        try (Scanner sc = new Scanner(new File(fileName))) {
            PrintWriter pw = new PrintWriter(outputName);
            while(sc.hasNext()) {
                pw.println(sc.nextLine());
            }
            pw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void writeFileAs(String outputName) {
        try (Scanner sc = new Scanner(new File(fileName))) {
            PrintWriter pw = new PrintWriter(outputName);
            while(sc.hasNext()) {
                pw.println(sc.nextLine());
            }
            pw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Image getImage() { return this.ppmImg; }


}
