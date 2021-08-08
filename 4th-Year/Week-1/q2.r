library("rjson")

student_record <- fromJSON(file = "student_record.json")

cat(paste(
    student_record[["name"]], "had an average of",
    mean(unlist(student_record[["courses"]][["science"]])),
    "in his science course and",
    mean(unlist(student_record[["courses"]][["social"]])),
    "in his social science courses. His overall average was",
    mean(unlist(student_record[["courses"]]), recursive = TRUE)
))