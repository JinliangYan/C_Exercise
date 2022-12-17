//
// Created by Kokomi on 2022/12/17.
//

#ifndef EXERCISE_FATAL_H
#define EXERCISE_FATAL_H
#include <stdlib.h>
#define error(str) fprintf(stderr, str)
#define fatal_error(str) fprintf(stderr, str), exit(1)
#endif //EXERCISE_FATAL_H
