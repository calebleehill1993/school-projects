package editor;

public class PpmImage {
    private String begins;
    private int width;
    private int height;
    private int maxColorValue;
    private Pixel[][] pixels;

    PpmImage(String begins, int width, int height, int maxColorValue, Pixel[][] pixels){
        this.begins = begins;
        this.width = width;
        this.height = height;
        this.maxColorValue = maxColorValue;
        this.pixels = pixels;
    }

    //COPY CONSTRUCTOR
    PpmImage(PpmImage copy){
        this.begins = copy.getBegins();
        this.width = copy.getWidth();
        this.height = copy.getHeight();
        this.maxColorValue = copy.getMaxColorValue();
        this.pixels = copy.getPixels();
    }

    public String getBegins() {
        return begins;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public int getMaxColorValue() {
        return maxColorValue;
    }

    public Pixel[][] getPixels() {
        return pixels;
    }
}