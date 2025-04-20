#ifndef LINE_H

#define LINE_H

void clear_line(void);

void add_word(const char *word);

int space_remaining(void);

void write_line(int space_bias_front);

void flush_line(void);

#endif

