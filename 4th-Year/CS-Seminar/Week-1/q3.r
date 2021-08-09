library("rjson")

output <- function(name, science_avg, social_avg, overall_avg) {
    cat(paste0(
        name, " had an average of ", science_avg,
        " in his science courses and ", social_avg,
        " in his social science courses. His overall average was ",
        overall_avg, "."
    ))
}

avg <- function(course_list) {
    mean(unlist(course_list))
}

student_record <- fromJSON(
    file = "4th-Year/CS-Seminar/Week-1/q3_student_record.json"
)

output(
    student_record[["name"]],
    avg(student_record[["courses"]][["science"]]),
    avg(student_record[["courses"]][["social"]]),
    avg(student_record[[""]])
)