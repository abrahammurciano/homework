import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FileDetailsFactory {
    public static void main(String[] args) {
        FileDetails details = FileDetailsFactory.getFileDetails("web/backup.mp3 length in seconds: 354, 7901 bytes");
    }
    private final static String EXTENTION_CAPTURE_PATTERN = "^[^ .]*(\\.[^ ]*)?";
    private final static String MP3_CAPTURE_PATTERN = "(.*/)?([^ /]*) length in seconds: (\\d+), (\\d+) bytes";
    private final static String JPG_CAPTURE_PATTERN = "(.*/)?([^ /]*) (\\d+)x(\\d+), (\\d+) bytes";
    private final static String HTML_CAPTURE_PATTERN = "(.*/)?([^ /]*) lines: (\\d+), (\\d+) bytes";
    private final static String TXT_CAPTURE_PATTERN = "(.*/)?([^ /]*) words: (\\d+), (\\d+) bytes";
    private final static String PPTX_CAPTURE_PATTERN = "(.*/)?([^ /]*) slides: (\\d+), (\\d+) bytes";
    private final static String DOCX_CAPTURE_PATTERN = "(.*/)?([^ /]*) words: (\\d+), pages: (\\d+), (\\d+) bytes";
    private final static String DIRECTORY_CAPTURE_PATTERN = "(.*/)?([^ /]*)";
    public static FileDetails getFileDetails(String description){
        Matcher matcher;
        switch (getExtension(description)){
            case "":
                matcher=getMatcher(DIRECTORY_CAPTURE_PATTERN, description);
                return new DirectoryDetails(matcher.group(1), matcher.group(2));
            case "mp3":
                matcher=getMatcher(MP3_CAPTURE_PATTERN, description);
                return new Mp3FileDetails(matcher.group(1), matcher.group(2),
                        Integer.parseInt(matcher.group(3)),Integer.parseInt(matcher.group(4)));
            case "jpg":
                matcher=getMatcher(JPG_CAPTURE_PATTERN, description);
                return new JpgFileDetails(matcher.group(1), matcher.group(2),
                        Integer.parseInt(matcher.group(3)),
                        Integer.parseInt(matcher.group(4)),
                        Integer.parseInt(matcher.group(5)));
            case "html":
                matcher=getMatcher(HTML_CAPTURE_PATTERN, description);
                return new HtmlFileDetails(matcher.group(1), matcher.group(2),
                        Integer.parseInt(matcher.group(3)),Integer.parseInt(matcher.group(4)));
            case "pptx":
                matcher=getMatcher(PPTX_CAPTURE_PATTERN, description);
                return new PptxFileDetails(matcher.group(1), matcher.group(2),
                        Integer.parseInt(matcher.group(3)),Integer.parseInt(matcher.group(4)));
            case "txt":
                matcher=getMatcher(TXT_CAPTURE_PATTERN, description);
                return new TxtFileDetails(matcher.group(1), matcher.group(2),
                        Integer.parseInt(matcher.group(3)),Integer.parseInt(matcher.group(4)));
            case "docx":
                matcher=getMatcher(DOCX_CAPTURE_PATTERN, description);
                return new DocxFileDetails(matcher.group(1), matcher.group(2),
                        Integer.parseInt(matcher.group(3)),
                        Integer.parseInt(matcher.group(4)),
                        Integer.parseInt(matcher.group(5)));
        }
        throw new RuntimeException("wrong file type");
    }
    public static String getExtension(String fileDescription){
        String extention = getMatcher(EXTENTION_CAPTURE_PATTERN,fileDescription).group(1);
        return extention== null ? "" : extention.substring(1);
    }
    public static Matcher getMatcher(String regex, String toMatch){
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(toMatch);
        matcher.find();
        return matcher;
    }
}
