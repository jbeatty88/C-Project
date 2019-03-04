package com.imageeditor;

public class ImageEditor {
    private static final int MAX_PIX_SIZE = 255;
    public static void main(String[] args) {
        String fileName = "";
        String nameChange = "";
        String transform = "";
        if(args.length < 3) {
            usageMessage();
        } else {
            fileName = args[0];
            nameChange = args[1];
            transform = args[2];
        }
        // READ IN PPM
        FileHelper ppmImg = new FileHelper(fileName);
        // MAKE A COPY
        FileHelper ppmImgCopy = new FileHelper(ppmImg);

        // TRANSFORM COPY
        Image transformedImg = new Image(ppmImg.getImage().getDim1(), ppmImg.getImage().getDim2());
        switch (transform) {
            case "invert":
                transformedImg.saveImageAs(nameChange, invertImg(ppmImgCopy.getImage()));
                break;
            case "emboss":
                transformedImg.saveImageAs(nameChange, embossImg(ppmImgCopy.getImage()));
                break;
            case "grayscale":
                transformedImg.saveImageAs(nameChange, grayscaleImg(ppmImgCopy.getImage()));
                break;
//            case "motionblur":
//                if(args.length < 4) {
//                    usageMessage();
//                    break;
//                } else if(Integer.parseInt(args[3]) < 0) {
//                    System.out.println("Last param must be > 0");
//                    break;
//                } else {
//                    transformedImg = motionblurImg(ppmImgCopy.getImage(), Integer.parseInt(args[3]));
//                    transformedImg.saveImageAs(nameChange);
//                    break;
//                }
        }
    }

    public static void usageMessage() {
        System.out.println("Usage: java *.ppm *.ppm transformation mb-val");
    }

    public static Image invertImg(Image ppmImg) {
        Image invertedPpm = new Image(ppmImg.getDim1(), ppmImg.getDim2());
        Pixel p;
        // abs( val - 255)
        for(int i = 0; i < ppmImg.getDim1(); i++) {
            for(int j = 0; j < ppmImg.getDim2();j++){
                p = ppmImg.getPixel(i, j);
                p.setAllVals(
                        Math.abs(p.getRedVal() - MAX_PIX_SIZE),
                        Math.abs(p.getGreenVal() - MAX_PIX_SIZE),
                        Math.abs(p.getBlueVal() - MAX_PIX_SIZE)
                );
                invertedPpm.imgPix[i][j] = p;
            }
        }
        return invertedPpm;
    }

    public static Image grayscaleImg(Image ppmImg) {
        Image grayscaledPpm = new Image(ppmImg.getDim1(), ppmImg.getDim2());
        Pixel p;
        // Set each value to avg of all three values
        for(int i = 0; i < ppmImg.getDim1(); i++) {
            for(int j = 0; j<ppmImg.getDim2();j++){
                p = ppmImg.getPixel(i, j);
                int avgVal = ((p.getRedVal() + p.getGreenVal() + p.getBlueVal())/ 3);
                grayscaledPpm.imgPix[i][j] = p.setAllVals(avgVal);
            }
        }
        return grayscaledPpm;
    }

    public static Image embossImg(Image ppmImg) {
        int dim1 = ppmImg.getDim1(), dim2 = ppmImg.getDim2(), embPix;
        Image embossedPpm = new Image(dim1, dim2);
        embossedPpm.imgPix = new Pixel[dim1][dim2]; // Now we have a new Image with a Pixel array full of Null
        embossedPpm.initializeToZero();
        Pixel p = new Pixel(0, 0, 0);

        // Set each value to avg of all three values
        for(int i = dim1 - 1; i >= 0; i--)
            for (int j = dim2 - 1; j >= 0; j--) {
                int currRedPix    = ppmImg.imgPix[i][j].getRedVal(),
                    currGreenPix  = ppmImg.imgPix[i][j].getGreenVal(),
                    currBluePix   = ppmImg.imgPix[i][j].getBlueVal();
                // If we are at the most top, botton, left, right, set that value to 128
                if(i == 0) {
                    embossedPpm.imgPix[i][j] = p.setAllVals(128);
                } else if (j == 0) {
                    embossedPpm.imgPix[i][j] = p.setAllVals(128);
                } else {
                    int upperLeftRedPix    = ppmImg.imgPix[i-1][j-1].getRedVal(),
                        upperLeftGreenPix  = ppmImg.imgPix[i-1][j-1].getGreenVal(),
                        upperLeftBluePix   = ppmImg.imgPix[i-1][j-1].getBlueVal(),
                        redDiff            = getDiff(currRedPix, upperLeftRedPix),
                        greenDiff          = getDiff(currGreenPix, upperLeftGreenPix),
                        blueDiff           = getDiff(currBluePix, upperLeftBluePix),
                        maxDiff            = maxDiff(redDiff, greenDiff, blueDiff);

                    embPix = 128 + maxDiff;
                    if(embPix < 0)
                        embPix = 0;
                    if(embPix > 255)
                        embPix = 255;

                    embossedPpm.imgPix[i][j] = p.setAllVals(embPix);

                }
            }
        return embossedPpm;
    }

    public static int getDiff(int val1, int val2) { return val1 - val2; }
    public static int maxDiff(int r, int g, int b) {
        // Get all of the positive values
        String posR = Integer.toString(Math.abs(r));
        String posG = Integer.toString(Math.abs(g));
        String posB = Integer.toString(Math.abs(b));
        int maxVal;

        // If the values are the same, precedence: Red -> Green -> Blue
        if(posR.equals(posG)) {
            maxVal = Integer.max(Integer.parseInt(posR), Integer.parseInt(posB));
            String maxValStr = Integer.toString(maxVal);
            if(maxValStr.equals(posR))
                return r;
            else
                return b;
        }
        else if(posR.equals(posB)) {
            maxVal = Integer.max(Integer.parseInt(posR), Integer.parseInt(posG));
            String maxValStr = Integer.toString(maxVal);
            if(maxValStr.equals(posR))
                return r;
            else
                return g;
        }
        else if(posG.equals(posB)) {
            maxVal = Integer.max(Integer.parseInt(posR), Integer.parseInt(posG));
            String maxValStr = Integer.toString(maxVal);
            if(maxValStr.equals(posR))
                return r;
            else
                return g;
        }
        // Otherwise just take the largest one
        else {
            maxVal = Integer.max(Integer.parseInt(posR), Integer.max(Integer.parseInt(posG), Integer.parseInt(posB)));
            String maxValStr = Integer.toString(maxVal);
            if(maxValStr.equals(posR))
                return r;
            else if (maxValStr.equals(posG))
                return g;
            else
                return b;
        }
    }

//    public static Image motionblurImg(Image ppmImg, int n) {
////        for(int i = 0; i <)
//    }
}
