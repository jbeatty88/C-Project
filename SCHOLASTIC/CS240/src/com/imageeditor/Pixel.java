package com.imageeditor;

public class Pixel {
    // This class will handle the Red Green Blue values for each pixel in an image
    private Integer redVal;
    private Integer greenVal;
    private Integer blueVal;

    public Pixel() {}
    public Pixel(int red, int green, int blue) {
        this.redVal = red;
        this.greenVal = green;
        this.blueVal = blue;
    }

    public void setRedVal(int r) {this.redVal = r; }

    public int getRedVal() {return this.redVal; }

    public void setGreenVal(int g) {this.greenVal = g; }

    public int getGreenVal() {return this.greenVal; }

    public void setBlueVal(int b) {this.blueVal = b; }

    public int getBlueVal() {return this.blueVal; }

    public Pixel setAllVals(int r, int g, int b) { return new Pixel(r, g, b); }

    public Pixel setAllVals(int v) { return new Pixel(v, v, v); }


}
