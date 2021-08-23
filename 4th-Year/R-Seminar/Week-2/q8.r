library(dplyr)

students <- read.csv("q8_students.csv")

cat(paste(
    "Enter a choice (1-7).",
    paste(
        "1 - Print students' names and grades in social sciences from",
        "highest to lowest."
    ),
    paste(
        "2 - Prints students' names and average grades in social sciences",
        "from highest to lowest, on condition that the average is above 80."
    ),
    paste(
        "3 - Print male students' names and average grades in social sciences",
        "from highest to lowest, on condition that the average is above 80"
    ),
    "4 - Show all information about the best student in sciences.",
    "5 - Show all information about the best female student in sciences.",
    paste(
        "6 - Show all information about a student, given his first and last",
        "name (assumed unique)."
    ),
    paste(
        "7 - Print student list alphabetically, including class rank (overall",
        "average), overall average, social science average, science average."
    ),
    sep = "\n"
))

choice <- as.integer(readline(prompt = "> "))

actions <- list(

    # Option 1
    function() {
        transformed <- transform(
            students,
            social_average = (
                students$psychology_grade * students$psychology_credits +
                    students$history_grade * students$history_credits
            ) / (
                students$psychology_credits + students$history_credits
            )
        )
        print(select(
            transformed[order(transformed$social_average, decreasing = TRUE), ],
            name,
            psychology_grade,
            history_grade,
            social_average
        ))
    },

    # Option 2
    function() {
        transformed <- transform(
            students,
            social_average = (
                students$psychology_grade * students$psychology_credits +
                    students$history_grade * students$history_credits
            ) / (
                students$psychology_credits + students$history_credits
            )
        )
        print(select(
            filter(
                transformed[
                    order(transformed$social_average, decreasing = TRUE),
                ],
                social_average > 80
            ),
            name,
            social_average
        ))
    },

    # Option 3
    function() {
        transformed <- transform(
            students,
            social_average = (
                students$psychology_grade * students$psychology_credits +
                    students$history_grade * students$history_credits
            ) / (
                students$psychology_credits + students$history_credits
            )
        )
        print(select(
            filter(
                transformed[
                    order(transformed$social_average, decreasing = TRUE),
                ],
                social_average > 80,
                sex == "male"
            ),
            name,
            social_average
        ))
    },

    # Option 4
    function() {
        transformed <- transform(
            students,
            science_average = (
                students$math_grade * students$math_credits +
                    students$physics_grade * students$physics_credits +
                    students$chemistry_grade * students$chemistry_credits
            ) / (
                students$math_credits +
                    students$physics_credits +
                    students$chemistry_credits
            )
        )
        print(transformed[
            order(transformed$science_average, decreasing = TRUE)[1],
        ])
    },

    # Option 5
    function() {
        transformed <- transform(
            students,
            science_average = (
                students$math_grade * students$math_credits +
                    students$physics_grade * students$physics_credits +
                    students$chemistry_grade * students$chemistry_credits
            ) / (
                students$math_credits +
                    students$physics_credits +
                    students$chemistry_credits
            )
        )
        filtered <- filter(transformed, sex == "female")
        print(filtered[
            order(filtered$science_average, decreasing = TRUE)[1],
        ])
    },

    # Option 6
    function() {
        input <- readline(prompt = "Enter the student's name.\n>")
        print(filter(students, name == input))
    },

    # Option 7
    function() {
        transformed <- transform(
            students,
            social_average = (
                students$psychology_grade * students$psychology_credits +
                    students$history_grade * students$history_credits
            ) / (
                students$psychology_credits + students$history_credits
            ),
            science_average = (
                students$math_grade * students$math_credits +
                    students$physics_grade * students$physics_credits +
                    students$chemistry_grade * students$chemistry_credits
            ) / (
                students$math_credits +
                    students$physics_credits +
                    students$chemistry_credits
            ),
            rank = rank(-students$average)
        )
        print(transformed[order(transformed$name), ])
    }
)

actions[[choice]]()