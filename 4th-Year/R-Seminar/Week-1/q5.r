student_records <- read.csv("4th-Year/R-Seminar/Week-1/q5_student_records.csv")

student_records <- transform(
    student_records,
    science_avg = apply(
        subset(
            student_records,
            select = c(
                math_grade,
                physics_grade,
                chemistry_grade
            )
        ),
        1,
        function(d) {
            weighted.mean(
                d,
                subset(
                    student_records,
                    select = c(
                        math_credits,
                        physics_credits,
                        chemistry_credits
                    )
                )
            )
        }
    ),
    social_avg = weighted.mean(
        c(
            psychology_grade,
            history_grade
        ),
        c(
            psychology_credits,
            history_credits
        )
    ),
    avg = weighted.mean(
        c(
            math_grade,
            physics_grade,
            chemistry_grade,
            psychology_grade,
            history_grade
        ),
        c(
            math_credits,
            physics_credits,
            chemistry_credits,
            psychology_credits,
            history_credits
        )
    ),
    sd = sd(
        c(
            math_grade,
            physics_grade,
            chemistry_grade,
            psychology_grade,
            history_grade
        )
    )
)

print(student_records)