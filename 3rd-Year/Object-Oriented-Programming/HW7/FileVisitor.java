public interface FileVisitor {
	int visit(DirectoryDetails file);

	int visit(DocxFileDetails file);

	int visit(HtmlFileDetails file);

	int visit(JpgFileDetails file);

	int visit(Mp3FileDetails file);

	int visit(PptxFileDetails file);

	int visit(TxtFileDetails file);
}
