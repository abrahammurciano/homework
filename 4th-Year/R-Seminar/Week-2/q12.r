students <- read.csv("q12_students.csv")

hist(students$average)

cumulative_freq <- c(0, cumsum(table(students$average)))
plot(cumulative_freq)
lines(cumulative_freq)

relative <- c(0, cumsum(students$average) / sum(students$average))
plot(relative)
lines(relative)