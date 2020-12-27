public class HtmlFileDetails extends FileDetails {
	private int lines;
	private int size;

	public HtmlFileDetails(String path, String fileName, int lines, int size) {
		super(path, fileName);
		this.lines = lines;
		this.size = size;
	}

	public int getLines() {
		return lines;
	}

	public void setLines(int lines) {
		this.lines = lines;
	}

	public int getSize() {
		return size;
	}

	public void setSize(int size) {
		this.size = size;
	}

	@Override
	public int accept(FileVisitor visitor) {
		return visitor.visit(this);
	}
}
