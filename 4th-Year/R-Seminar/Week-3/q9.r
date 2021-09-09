# Part A

fit <- lm(weight ~ height + I(height^2), data = women) # lm is: linear model
summary(fit)

# Part B

# Yes because the p-values are small.

# Part C

plot(women$height, women$weight,
    main = "Women Age 30-39",
    xlab = "Height (in inches)",
    ylab = "Weight (in pounds)"
) # x-axis is height, y is weight
res <- residuals(fit) # shows difference between y-i and y-hat
x <- c(1:15)
z <- rep(0, 15)
plot(x, res, type = "p")
lines(women$height, fitted(fit))