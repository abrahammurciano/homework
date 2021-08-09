name <- readline(prompt = "Name: ")
science <- c(
    math = as.integer(readline(prompt = "Math: ")),
    physics = as.integer(readline(prompt = "Physics: ")),
    chemistry = as.integer(readline(prompt = "Chemistry: "))
)
social <- c(
    psychology = as.integer(readline(prompt = "Psychology: ")),
    rahistory = as.integer(readline(prompt = "History: "))
)
all_courses <- c(science, social)

cat(paste(
    name, "had an average of", mean(science), "in his science course and",
    mean(social), "in his social science courses. His overall average was",
    mean(all_courses), "\n"
))