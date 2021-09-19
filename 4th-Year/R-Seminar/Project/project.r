setwd("/home/abraham/Documents/homework/4th-Year/R-Seminar/Project")
shirts <- read.csv("shirts.csv")

# Create a class Option which has a label and a function
Option <- setRefClass(
    "Option",
    fields = list(
        label = "character",
        action = "function"
    )
)

p_value <- function(model) {
    f <- summary(model)$fstatistic
    p <- pf(f[1], f[2], f[3], lower.tail = FALSE)
    attributes(p) <- NULL
    return(p)
}

test_relation <- function(var1, var2) {
    model <- lm(var1 ~ var2)
    p <- p_value(model)
    plot(var2, var1)
    abline(model)
    cat(paste0(
        "p value: ", p, "\nThe relationship is",
        ifelse(p < 0.05, "", " not"), " significant"
    ))
}

population_var <- function(x) var(x) * (length(x) - 1) / length(x)

population_sd <- function(x) sqrt(population_var(x))

stat_mode <- function(x) {
    ux <- unique(x)
    ux[which.max(tabulate(match(x, ux)))]
}

options <- list(
    Option$new(
        label = paste(
            "Test a linear relationship between strength of the shirt,",
            "and quality of material. Plot the relationship and determine",
            "if it is significant."
        ),
        action = function() {
            test_relation(shirts$Strength, shirts$Quality)
        }
    ),
    Option$new(
        label = paste(
            "Test a quadratic relationship between Strength of the shirt,",
            "and quality of material. Plot the relationship and determine",
            "if it is significant."
        ),
        action = function() {
            test_relation(shirts$Strength, shirts$Quality^2)
        }
    ),
    Option$new(
        label = paste(
            "Test a linear relationship between Strength of the shirt,",
            "and quality of material and amount of die."
        ),
        action = function() {
            test_relation(shirts$Strength, shirts$Quality + shirts$Dye)
        }
    ),
    Option$new(
        label = paste(
            "Display relative frequency of the country of origin as a pie",
            "chart, 3D pie chart, and as a bar graph."
        ),
        action = function() {
            freq <- table(shirts$Origin) / nrow(shirts)
            pie(freq)
            barplot(freq)
        }
    ),
    Option$new(
        label = paste(
            "Concerning the strength, we wish to determine basic measures,",
            "such as Mean, sample standard deviation, population standard",
            "deviation, median, Inter quartile range, 25, 50, 75, and 90th",
            "percentiles, range, and mode."
        ),
        action = function() {
            strength <- shirts$Strength
            cat(paste0(
                "Mean strength: ", mean(strength),
                "\nSample standard deviation: ", sd(strength),
                "\nPopulation standard deviation: ", population_sd(strength),
                "\nMedian: ", median(strength),
                "\nIQR: ", IQR(strength),
                "\nRange: ", range(strength),
                "\nMode: ", stat_mode(strength),
                "\nPercentiles:\n"
            ))
            print(quantile(strength, c(.25, .5, .75, .9)))
        }
    ),
    Option$new(
        label = paste(
            "For the strength variable, prepare a histogram, and determine the",
            "midpoint of the class with the greatest frequency."
        ),
        action = function() {
            h <- hist(shirts$Strength)
            lower_interval <- h$breaks[-length(h$breaks)]
            upper_interval <- h$breaks[-1]
            print(subset(data.frame(
                interval = paste(lower_interval, "-", upper_interval),
                mid = h$mids,
                freq = h$counts
            ), freq == max(freq)))
        }
    ),
    Option$new(
        label = paste(
            "For the strength variable, prepare a boxplot and stem and leaf",
            "plot."
        ),
        action = function() {
            strength <- shirts$Strength
            boxplot(strength)
            stem(strength)
        }
    ),
    Option$new(
        label = paste(
            "For the mean of the strength variable, find a 98% confidence",
            "interval."
        ),
        action = function() {
            print(t.test(shirts$Strength, conf.level = 0.98))
        }
    ),
    Option$new(
        label = paste(
            "For the origin, find a 98% confidence interval for the",
            "probability that a randomly chosen shirt was made in India."
        ),
        action = function() {
            cat(paste(
                "98% confidence interval for the probability that a randomly",
                "chosen shirt was made in India is between:\n"
            ))
            print(prop.test(
                nrow(shirts[shirts$Origin == "India", ]),
                nrow(shirts),
                conf.level = 0.98
            )$conf.int)
        }
    ),
    Option$new(
        label = paste(
            "Is there a difference in the expected strength of shirts from",
            "different countries? Which pairs are significantly different",
            "from each other?"
        ),
        action = function() {
            print(TurkeyHSD(aov(Strength ~ Origin, shirts)))
        }
    ),
    Option$new(
        label = paste(
            "Is there a difference in the expected strength of shirts from",
            "different countries and different materials?"
        ),
        action = function() {
            print(TurkeyHSD(
                aov(Strength ~ interaction(Origin, Material), shirts)
            ))
        }
    ),
    Option$new(
        label = paste(
            "Is there any interaction between different countries and",
            "different materials?"
        ),
        action = function() {
            print(summary(lm(Material ~ Origin, shirts)))
        }
    )
)

menu <- function(options) {
    i <- 1
    for (op in options) {
        cat(paste0(i, " - ", op$label, "\n"))
        i <- i + 1
    }
    return(as.integer(readline("Choose an option: ")))
}

options[[menu(options)]]$action()