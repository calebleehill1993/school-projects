

public class Pixel {
    private int red;
    private int green;
    private int blue;

    Pixel(){
        red = 0;
        green = 0;
        blue = 0;
    }

    Pixel(int red, int green, int blue){
        this.red = red;
        this.green = green;
        this.blue = blue;
    }

    public int getBlue() {
        return blue;
    }

    public int getGreen() {
        return green;
    }

    public int getRed() {
        return red;
    }

    public void setBlue(int blue) {
        this.blue = blue;
    }

    public void setGreen(int green) {
        this.green = green;
    }

    public void setRed(int red) {
        this.red = red;
    }

}
