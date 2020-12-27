public class JpgFileDetails extends FileDetails {
	private int width;
	private int height;
	private int size;

	public JpgFileDetails(String path, String fileName, int width, int height, int size) {
		super(path, fileName);
		this.width = width;
		this.height = height;
		this.size = size;
	}

	public int getWidth() {
		return width;
	}

	public int getHeight() {
		return height;
	}

	public int getSize() {
		return size;
	}

	@Override
	public int accept(FileVisitor visitor) {
		return visitor.visit(this);
	}
}
