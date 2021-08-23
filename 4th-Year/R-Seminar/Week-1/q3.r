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
    return(weighted.mean(
        unlist(lapply(course_list, function(course) course$grade)),
        unlist(lapply(course_list, function(course) course$credits))
    ))
}

student_record <- fromJSON(
    file = "q3_student_record.json"
)

output(
    student_record$name,
    avg(student_record$courses$science),
    avg(student_record$courses$social),
    avg(c(student_record$courses$science, student_record$courses$social))
)