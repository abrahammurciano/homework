type <- rep(c("a", "b", "c"), c(6, 6, 6))
method <- rep(c(rep("dipping", 3), rep("spraying", 3)), 3)
adhesion <- c(
    4, 4.5, 4.3, 5.4, 4.9, 5.6, 5.6, 4.9, 5.4,
    5.8, 6.1, 6.3, 3.8, 3.7, 4, 5.5, 5, 5
)

# Part A

summary(aov(adhesion ~ type * method))

# Part B

table(method, type)

# Part C

aggregate(adhesion, by = list(method, type), FUN = mean)

# Part D

aggregate(adhesion, by = list(method, type), FUN = sd)