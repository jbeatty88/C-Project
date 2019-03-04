package com.imageeditor;

import java.io.*;
import java.util.StringJoiner;

public class Image {
    // This is a 2D array of Pixel objects.
    private int dimension1;
    private int dimension2;
    public Pixel[][] imgPix;

    public Image() {}
    public Image(int dim1, int dim2) {
        this.dimension1 = dim1;
        this.dimension2 = dim2;
        imgPix = new Pixel[dimension1][dimension2];
    }
    Image(Image i) {
//        System.out.println("COPY CSTR CALLED FOR IMAGE");
        dimension1 = i.dimension1;
        dimension2 = i.dimension2;
        imgPix = new Pixel[i.getDim1()][i.getDim2()];
        for(int x = 0; x < i.getDim1(); x++) {
            for(int y = 0; y < i.getDim2(); y++) {
                imgPix[x][y] = i.imgPix[x][y];
            }
        }
    }

    public int getDim1() { return this.dimension1; }

    public int getDim2() { return this.dimension2; }

    public Pixel[][] getImgPix() { return this.imgPix; }

    public void addPixelToArr(Pixel p) {
        for(int i = 0; i < dimension1; i++) {
            for(int j = 0; j < dimension2; j++) {
                imgPix[i][j] = p;
            }
        }
    }

    public void setImgPixArr(Pixel[][] pix) { this.imgPix = pix; }

    public void outputRGBVals(int i, int j) {
        System.out.printf("PIXEL: %d %d\n", i, j);
        System.out.println("RED: " + imgPix[i][j].getRedVal());
        System.out.println("GREEN: " + imgPix[i][j].getGreenVal());
        System.out.println("BLUE: " + imgPix[i][j].getBlueVal());
    }

    public void outputImg() {
        for(int i = 0; i < dimension1; i++) {
            for(int j = 0; j < dimension2; j++) {
                System.out.println("\n");
                outputRGBVals(i, j);
                System.out.println("\n");
            }
        }
    }

    public void saveImageAs(String outputName, Image img) {
        try(PrintWriter pw = new PrintWriter(outputName)) {
//            StringBuilder sb = new StringBuilder();
            StringJoiner sj = new StringJoiner("\n");
            StringJoiner dimJoin = new StringJoiner(" ");
            dimJoin.add(Integer.toString(dimension1)).add(Integer.toString(dimension2));
//            .add("# CREATOR: GIMP PNM Filter Version 1.1")
            sj.add("P3").add(dimJoin.toString()).add("255");
            for(int i = 0; i < img.dimension1; i++) {
                for(int j = 0; j < img.dimension2; j++) {
                    sj.add(Integer.toString(img.imgPix[i][j].getRedVal())).add(Integer.toString(img.imgPix[i][j].getGreenVal())).add(Integer.toString(img.imgPix[i][j].getBlueVal()));
                }
            }
            pw.println(sj.toString());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Pixel getPixel(int i, int j) {return imgPix[i][j]; }

    public void initializeToZero() {
        for(int i = 0; i < this.dimension1; i++) {
            for(int j = 0; j < this.dimension2; j++ ) {
                imgPix[i][j] = new Pixel(0, 0, 0);
            }
        }
    }


}
