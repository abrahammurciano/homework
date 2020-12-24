public class FileShortRepVisitor implements FileVisitor {

	@Override
	public int visit(DirectoryDetails dir) {
		for (FileDetails file : dir) {
			file.accept(this);
		}
		System.out.println(dir.getName());
		return 0;
	}

	@Override
	public int visit(DocxFileDetails file) {
		System.out.println(file.getName());
		return 0;
	}

	@Override
	public int visit(HtmlFileDetails file) {
		System.out.println(file.getName());
		return 0;
	}

	@Override
	public int visit(JpgFileDetails file) {
		System.out.println(file.getName());
		return 0;
	}

	@Override
	public int visit(Mp3FileDetails file) {
		System.out.println(file.getName());
		return 0;
	}

	@Override
	public int visit(PptxFileDetails file) {
		System.out.println(file.getName());
		return 0;
	}

	@Override
	public int visit(TxtFileDetails file) {
		System.out.println(file.getName());
		return 0;
	}
}
