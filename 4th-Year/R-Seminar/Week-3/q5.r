# Part A

prop.test(c(71, 46), c(206, 170), correct = FALSE)

# Part B

chisq.test(c(71 / 206, 46 / 170), p = c(0.5, 0.5))

# Part C

prop.test(c(71, 46), c(206, 170), correct = FALSE, alternative = "g")