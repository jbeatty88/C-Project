import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

public class FileHelper {
    // This class will handle IO
    public static String fileName;
    public static String nameChange;

    // Input
    public FileHelper(String fileName, String nameChange) {
        this.fileName = fileName;
        this.nameChange = nameChange;

        if(!Files.exists(Paths.get(fileName))) {
            System.out.println("\nFile not found" + fileName);
            return;
        }
    }

    public static void readAndShowLines() {
        try {
            List<String> lines = Files.readAllLines(Paths.get(fileName));
            for(String line : lines) {
                System.out.println(line);
            }
        } catch (IOException e) {
            System.out.println(e.getClass().getSimpleName() + " - " + e.getMessage());
        }
    }
}
