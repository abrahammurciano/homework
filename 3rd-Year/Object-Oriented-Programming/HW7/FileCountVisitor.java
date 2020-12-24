public class FileCountVisitor implements FileVisitor {

	@Override
	public int visit(DirectoryDetails dir) {
		int file_count = 0;
		for (FileDetails file : dir) {
			file_count += file.accept(this);
		}
		return file_count;
	}

	@Override
	public int visit(DocxFileDetails file) {
		return 1;
	}

	@Override
	public int visit(HtmlFileDetails file) {
		return 1;
	}

	@Override
	public int visit(JpgFileDetails file) {
		return 1;
	}

	@Override
	public int visit(Mp3FileDetails file) {
		return 1;
	}

	@Override
	public int visit(PptxFileDetails file) {
		return 1;
	}

	@Override
	public int visit(TxtFileDetails file) {
		return 1;
	}
}
