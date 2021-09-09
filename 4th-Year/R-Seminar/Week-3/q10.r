# Part A

fit <- lm(
    Murder ~ Population + Illiteracy + Income + Frost,
    data = as.data.frame.matrix(state.x77)
)
summary(fit)

# Part B

# Illiteracy