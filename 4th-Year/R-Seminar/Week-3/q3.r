brand1 <- c(
    30, 26, 31, 27, 37, 28, 31, 29, 25, 26, 33, 30, 28,
    27, 31, 35, 30, 36, 35, 32, 27, 29, 33, 27, 30
)

brand2 <- c(
    24, 27, 22, 31, 30, 25, 22, 26, 29, 33, 20, 18, 26,
    25, 20, 22, 24, 17, 21, 18, 25, 27, 24, 24, 20
)

# Part A

avg1 <- mean(brand1)
avg2 <- mean(brand2)

sd1 <- sd(brand1)
sd2 <- sd(brand2)

n1 <- length(brand1)
n2 <- length(brand2)

avg_diff <- avg1 - avg2

pooled_sd <- sqrt((((n1 - 1) * sd1) + ((n2 - 1) * sd2)) / (n1 + n2 - 2))

t <- avg_diff / (pooled_sd * sqrt(1 / n1 + 1 / n2))
cat(paste0("The t-statistic is ", t, ".\n"))

p <- 2 * (1 - pt(abs(t), df = n1 + n2 - 2))
cat(paste0("The p-value is ", p, ".\n"))

# Part B

t.test(brand1, brand2, mu = 0, paired = TRUE, var.equal = TRUE)

# Part C

t.test(brand1, brand2, mu = 0, paired = TRUE, var.equal = FALSE)