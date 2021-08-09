name <- "Jack Stein"
science <- c(math = 80, physics = 80, chemistry = 80)
social <- c(psychology = 50, history = 50)
all_courses <- c(science, social)

cat(paste(
    name, "had an average of", mean(science), "in his science course and",
    mean(social), "in his social science courses. His overall average was",
    mean(all_courses)
))