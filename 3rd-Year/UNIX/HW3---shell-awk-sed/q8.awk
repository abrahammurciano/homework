#!/usr/sbin/awk -f

# Calculates average grade per course from the CSV file provided.

BEGIN	{
	FS = ",";
}
{
	if (NR > 1) {
		grades[$2] += $1;
		++count[$2];
	}
}
END	{
	print "Course\tAverage";
	for (course in grades) {
		print course "\t" grades[course] / count[course];
	}
}