import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class DirectoryDetails extends FileDetails implements Iterable<FileDetails> {

	List<FileDetails> children;

	public DirectoryDetails(String path, String name) {
		super(path, name);
		children = new ArrayList<>();
	}

	public void addFile(FileDetails fileDetails) {
		children.add(fileDetails);
	}

	@Override
	public int accept(FileVisitor visitor) {
		return visitor.visit(this);
	}

	@Override
	public Iterator<FileDetails> iterator() {
		return children.iterator();
	}
}
