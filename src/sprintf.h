#ifndef SPRINTF
#define SPRINTF

#define ON 1
#define OFF 0

struct Flags {
    int plus;
    int minus;
    int space;
    int width;
    int precision;
    int is_precision;
    int length_h;
    int length_l;
};

int s21_sprintf(char *buf, const char *format, ...);
//void record_arg(const char **format, char **str, struct Flags *flags, va_list vl);
void Obnull(struct Flags *flags);
int Parsing (const char **format, struct Flags *flags);
int IsDigit(char c);
int IsSpecifier (char c);

#endif