import java.lang.Math;

public class ImageWriter {
    public static StringBuilder output(PpmImage image){
        StringBuilder output = new StringBuilder();
        output.append(image.getBegins() + "\n");
        output.append(image.getWidth() + "\t" + image.getHeight() + "\n");
        output.append(image.getMaxColorValue() + "\n");
        for (int i = 0; i < image.getHeight(); i++){
            for (int j = 0; j < image.getWidth(); j++){
                output.append(image.getPixels()[i][j].getRed() + "\t" +
                        image.getPixels()[i][j].getGreen() + "\t" +
                        image.getPixels()[i][j].getBlue() + "\n");
            }
        }
        return output;
    }

    public static PpmImage invert(PpmImage originalImage){
        Pixel[][] pixels = new Pixel[originalImage.getHeight()][originalImage.getWidth()];
        for (int i = 0; i < originalImage.getHeight(); i++){
            for (int j = 0; j < originalImage.getWidth(); j++){
                pixels[i][j] = new Pixel(255 - originalImage.getPixels()[i][j].getRed(),
                        255 - originalImage.getPixels()[i][j].getGreen(),
                        255 - originalImage.getPixels()[i][j].getBlue());
            }
        }
        PpmImage invertedImage = new PpmImage(originalImage.getBegins(), originalImage.getWidth(),
                originalImage.getHeight(), originalImage.getMaxColorValue(), pixels);
        return invertedImage;
    }

    public static PpmImage gray(PpmImage originalImage){
        Pixel[][] pixels = new Pixel[originalImage.getHeight()][originalImage.getWidth()];
        for (int i = 0; i < originalImage.getHeight(); i++){
            for (int j = 0; j < originalImage.getWidth(); j++){
                int average = (originalImage.getPixels()[i][j].getRed() + originalImage.getPixels()[i][j].getGreen() + originalImage.getPixels()[i][j].getBlue()) / 3;
                pixels[i][j] = new Pixel(average, average, average);
            }
        }
        PpmImage grayImage = new PpmImage(originalImage.getBegins(), originalImage.getWidth(),
                originalImage.getHeight(), originalImage.getMaxColorValue(), pixels);
        return grayImage;
    }

    public static PpmImage emboss(PpmImage originalImage){
        Pixel[][] pixels = new Pixel[originalImage.getHeight()][originalImage.getWidth()];
        for (int i = 0; i < originalImage.getHeight(); i++){
            for (int j = 0; j < originalImage.getWidth(); j++){
                if (i == 0 || j == 0){
                    pixels[i][j] = new Pixel(128, 128, 128);
                }
                else {
                    int v;
                    int redDiff = originalImage.getPixels()[i][j].getRed() - originalImage.getPixels()[i-1][j-1].getRed();
                    int greenDiff = originalImage.getPixels()[i][j].getGreen() - originalImage.getPixels()[i-1][j-1].getGreen();
                    int blueDiff = originalImage.getPixels()[i][j].getBlue() - originalImage.getPixels()[i-1][j-1].getBlue();
                    if (Math.abs(redDiff) >= Math.abs(greenDiff)) {
                        if (Math.abs(redDiff) >= Math.abs(blueDiff)) {
                            v = 128 + redDiff;
                        }
                        else{
                            v = 128 + blueDiff;
                        }
                    }
                    else{
                        if (Math.abs(greenDiff) >= Math.abs(blueDiff)) {
                            v = 128 + greenDiff;
                        }
                        else {
                            v = 128 + blueDiff;
                        }
                    }
                    if (v < 0) {
                        v = 0;
                    }
                    else if (v > 255) {
                        v = 255;
                    }
                    pixels[i][j] = new Pixel(v, v, v);
                }
            }
        }
        PpmImage embossImage = new PpmImage(originalImage.getBegins(), originalImage.getWidth(),
                originalImage.getHeight(), originalImage.getMaxColorValue(), pixels);
        return embossImage;
    }

    public static PpmImage blur(PpmImage originalImage, int n) {
        Pixel[][] pixels = new Pixel[originalImage.getHeight()][originalImage.getWidth()];
        for (int i = 0; i < originalImage.getHeight(); i++){
            for (int j = 0; j < originalImage.getWidth(); j++){
                int averageRed = 0;
                int averageGreen = 0;
                int averageBlue = 0;
                if (j + n > originalImage.getWidth()) {
                    for (int z = j; z < originalImage.getWidth(); z++) {
                        averageRed += originalImage.getPixels()[i][z].getRed();
                        averageGreen += originalImage.getPixels()[i][z].getGreen();
                        averageBlue += originalImage.getPixels()[i][z].getBlue();
                    }
                    averageRed = averageRed / (originalImage.getWidth() - j);
                    averageBlue = averageBlue / (originalImage.getWidth() - j);
                    averageGreen = averageGreen / (originalImage.getWidth() - j);
                }
                else {
                    for (int z = j; z < (j + n); z++) {
                        averageRed += originalImage.getPixels()[i][z].getRed();
                        averageGreen += originalImage.getPixels()[i][z].getGreen();
                        averageBlue += originalImage.getPixels()[i][z].getBlue();
                    }
                    averageRed = averageRed / n;
                    averageBlue = averageBlue / n;
                    averageGreen = averageGreen / n;
                }
                pixels[i][j] = new Pixel(averageRed, averageGreen, averageBlue);
            }
        }
        PpmImage blurImage = new PpmImage(originalImage.getBegins(), originalImage.getWidth(),
                originalImage.getHeight(), originalImage.getMaxColorValue(), pixels);
        return blurImage;
    }
}
