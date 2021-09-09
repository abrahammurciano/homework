data <- read.csv("q6.csv")

strengths <- data[, 2:ncol(data)]
labels <- data[, 1]
avgs <- apply(strengths, 1, mean)
sums <- apply(strengths, 1, sum)

summary(
    aov(
        c(
            as.matrix(strengths)
        ) ~ gl(
            length(labels),
            1,
            length(labels) * length(strengths),
            factor(labels)
        )
    )
)