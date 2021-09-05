x <- c(115, 116, 117, 118, 119, 120, 121, 122, 123, 124)
freq <- c(4, 6, 9, 13, 15, 19, 20, 18, 15, 10)

# Part A
wm <- weighted.mean(x, freq)
cat(paste0("Weighted mean: ", wm, ".\n"))

# Part B
wpv <- t(freq) %*% x^2 / sum(freq) - wm^2
cat(paste0("Weighted population variance: ", wpv, ".\n"))

# Part C
d <- rep(x, freq)
wm <- mean(d)
cat(paste0("Weighted mean: ", wm, ".\n"))
wpv <- var(d) * (length(d) - 1) / length(d)
cat(paste0("Weighted population variance: ", wpv, ".\n"))

# Part D
med <- median(d)
cat(paste0("Median: ", med, ".\n"))
iqr <- IQR(d)
cat(paste0("Inter-quartile range: ", iqr, ".\n"))