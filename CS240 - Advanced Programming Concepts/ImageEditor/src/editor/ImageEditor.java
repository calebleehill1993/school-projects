package editor;

import java.io.*;
import java.util.Scanner;

public class ImageEditor {
    public static void main(String[] args) throws FileNotFoundException {
        File input = new File(args[0]);
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


        //OPTIONS
        PpmImage newImage;
        if (args.length == 3) {
            if (args[2].equals("invert")){
                newImage = ImageWriter.invert(originalPpm);
            }
            else if (args[2].equals("grayscale")) {
                newImage = ImageWriter.gray(originalPpm);
            }
            else if (args[2].equals("emboss")) {
                newImage = ImageWriter.emboss(originalPpm);
            }
            else {
                newImage = originalPpm;
                System.out.println("USAGE: java ImageEditor in-file out-file (grayscale|invert|emboss|motionblur motion-blur-length)");
            }
        }
        else if (args.length == 4 && args[2].equals("motionblur") && args[3].matches("\\d+")) {
            if (Integer.parseInt(args[3]) == 0) {
                newImage = originalPpm;
            }
            else {
                newImage = ImageWriter.blur(originalPpm, Integer.parseInt(args[3]));
            }
        }
        else {
            newImage = originalPpm;
            System.out.println("USAGE: java ImageEditor in-file out-file (grayscale|invert|emboss|motionblur motion-blur-length)");
        }
        File output = new File(args[1]);
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(output))) {
            writer.write(ImageWriter.output(newImage).toString());
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
//"/users/guest/c/clhill93/ImageEditor/slctempleResultsInvert.ppm"