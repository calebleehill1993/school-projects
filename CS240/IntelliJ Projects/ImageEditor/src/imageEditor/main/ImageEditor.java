package imageEditor.main;
import java.io.*;
import java.util.Scanner;

public class ImageEditor {
    public static void main(String[] args) throws FileNotFoundException {
        System.out.println("testing");
        File input = new File("/users/guest/c/clhill93/IdeaProjects/ImageEditor/src/imageEditor/main/slctemple.ppm");
        Scanner scanner = new Scanner(input);
        scanner.useDelimiter("((#[^\\n]*\\n)|(\\s+))+");
        String begins = scanner.next();
        int width = scanner.nextInt();
        int height = scanner.nextInt();
        int maxColorValue = scanner.nextInt();
        Pixel pixels[][] = new Pixel[height][width];
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                pixels[i][j] = new Pixel(scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
            }
        }
        PpmImage originalPpm = new PpmImage(begins, width, height, maxColorValue, pixels);


        //INVERT
        PpmImage invertedImage = ImageWriter.invert(originalPpm);
        PpmImage grayImage = ImageWriter.gray(originalPpm);
        PpmImage embossImage = ImageWriter.emboss(originalPpm);
        PpmImage blurImage = ImageWriter.blur(originalPpm, 10);
        System.out.println(ImageWriter.output(originalPpm));
        System.out.println((ImageWriter.output(blurImage)));

        File output = new File("/users/guest/c/clhill93/IdeaProjects/ImageEditor/src/imageEditor/main/slctempleResultsInvert.ppm");
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
            writer.write(ImageWriter.output(invertedImage).toString());
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
