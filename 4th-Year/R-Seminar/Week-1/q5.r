student_records <- read.csv("q5_student_records.csv")

student_records <- transform(
    student_records,
    science_avg = (
        math_grade * math_credits
            + physics_grade * physics_credits
            + chemistry_grade * chemistry_credits
    ) / (math_credits + physics_credits + chemistry_credits),
    social_avg = (
        psychology_grade * psychology_credits + history_grade * history_credits
    ) / (psychology_credits + history_credits),
    avg = (
        math_grade * math_credits
            + physics_grade * physics_credits
            + chemistry_grade * chemistry_credits
            + psychology_grade * psychology_credits
            + history_grade * history_credits
    ) / (
        math_credits
        + physics_credits
            + chemistry_credits
            + psychology_credits
            + history_credits
    )
)

sd_summand <- function(grades, credits, average) {
    return(credits * (grades - average) * (grades - average))
}

student_records <- transform(
    student_records,
    sd = sqrt((
        sd_summand(math_grade, math_credits, avg)
        + sd_summand(physics_grade, physics_credits, avg)
            + sd_summand(chemistry_grade, chemistry_credits, avg)
            + sd_summand(psychology_grade, psychology_credits, avg)
            + sd_summand(history_grade, history_credits, avg)
    ) / (
        (nrow(student_records) - 1) / nrow(student_records)
            * (
                math_credits
                + physics_credits
                    + chemistry_credits
                    + psychology_credits
                    + history_credits
            )
    ))
)

print(student_records)