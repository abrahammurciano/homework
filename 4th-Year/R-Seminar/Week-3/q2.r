tomatoes <- c(7.07, 7, 7.1, 6.97, 7, 7.03, 7.01, 7.01, 6.98, 7.08)

# Part A
avg <- mean(tomatoes)
sd <- sd(tomatoes)
n <- length(tomatoes)
error <- qt(0.99, df = n - 1) * sd / sqrt(n)
left <- avg - error
right <- avg + error
cat(paste0(
    "The 98% confidence interval for the expected weight is between ",
    left, " and ", right, ".\n"
))

# Part B
test <- t.test(tomatoes, alternative = "less", conf.level = 0.98, mu = 7.5)
print(test)

# Part C
test <- t.test(tomatoes, alternative = "two.sided", conf.level = 0.98)
print(test)