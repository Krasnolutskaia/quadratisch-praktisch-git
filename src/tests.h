#ifndef TESTS_H_
#define TESTS_H_

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

const char TEST_MODE[] = "--test";
const char AUTO_TEST_MODE[] = "--auto-test";
const char HELP_MODE[] = "--help";


void run_tests_from_file(FILE* file);

void run_auto_test();

#endif
