library(dplyr)

students <- read.csv("q7_students.csv")

print(subset(
    filter(students, !(country %in% c("US", "England"))),
    select = c(name, average, country)
))