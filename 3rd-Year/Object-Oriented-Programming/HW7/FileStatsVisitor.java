public class FileStatsVisitor implements FileVisitor {

	@Override
	public int visit(DirectoryDetails dir) {
		for (FileDetails file : dir) {
			file.accept(this);
		}
		System.out.printf("Directory %s has %d files.%n", dir.getName(),
				dir.accept(new FileCountVisitor()));
		return 0;
	}

	@Override
	public int visit(DocxFileDetails file) {
		System.out.printf("The file %s has an average of %.6f words per page.%n", file.getName(),
				(double) file.getWords() / file.getNumOfPages());
		return 0;
	}

	@Override
	public int visit(HtmlFileDetails file) {
		System.out.printf("The file %s contains %d lines.%n", file.getName(), file.getLines());
		return 0;
	}

	@Override
	public int visit(JpgFileDetails file) {
		System.out.printf("The picture %s has an average of %.6f bits per pixel.%n", file.getName(),
				(double) file.getSize() / (file.getHeight() * file.getWidth()));
		return 0;
	}

	@Override
	public int visit(Mp3FileDetails file) {
		System.out.printf("The bitrate of %s is %.6f bytes per second.%n", file.getName(),
				(double) file.getSize() / file.getLengthSec());
		return 0;
	}

	@Override
	public int visit(PptxFileDetails file) {
		System.out.printf("The average slide size in Presentation %s is %.6f.%n", file.getName(),
				(double) file.getSize() / file.getSlides());
		return 0;
	}

	@Override
	public int visit(TxtFileDetails file) {
		System.out.printf("The file %s contains %d words.%n", file.getName(), file.getWords());
		return 0;
	}
}
