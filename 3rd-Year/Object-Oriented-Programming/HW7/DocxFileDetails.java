public class DocxFileDetails extends FileDetails {
	private int words;
	private int pages;
	private int size;

	public DocxFileDetails(String path, String fileName, int words, int pages, int size) {
		super(path, fileName);
		this.words = words;
		this.pages = pages;
		this.size = size;
	}

	public int getNumOfPages() {
		return pages;
	}

	public int getWords() {
		return words;
	}

	public int getPages() {
		return pages;
	}

	public int getSize() {
		return size;
	}

	@Override
	public int accept(FileVisitor visitor) {
		return visitor.visit(this);
	}
}
