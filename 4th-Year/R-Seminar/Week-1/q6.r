student_records <- read.csv("q6_student_records.csv")

sex <- 0
sex <- factor(sex, levels = c("Male", "Female"))
disabilities <- 0
disabilities <- factor(disabilities, levels = c("Yes", "No"))
country <- 0
country <- factor(
    country,
    levels = c(
        "Israel",
        "US",
        "England",
        "France",
        "Switzerland",
        "Austria",
        "Belgium",
        "Other"
    )
)

rownames(student_records) <- student_records$name

print(student_records["Bob", ])