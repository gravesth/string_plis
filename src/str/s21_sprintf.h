#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdarg.h>

#include "../s21_string.h"

typedef struct {
  int minus;
  int plus;
  int space;
  int width;
  int precision;
  char length;
  char specifier;
} FormatOptions;

int local_strlen(const char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

void local_reverse(char *str) {
  int i = 0;
  int j = local_strlen(str) - 1;
  while (i < j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
}

double local_fabs(double val) { return (val < 0.0) ? -val : val; }

void s21_utoa(unsigned long long val, char *buf) {
  int i = 0;
  unsigned long long temp = val;
  if (temp == 0) {
    buf[i] = '0';
    i++;
  }
  while (temp > 0) {
    buf[i] = (char)('0' + (temp % 10));
    i++;
    temp /= 10;
  }
  buf[i] = '\0';
  local_reverse(buf);
}

void s21_itoa(long long val, char *buf) {
  unsigned long long uval = (val < 0) ? -val : val;
  s21_utoa(uval, buf);
}

long long round_half_to_even(double scaled) {
  long long floor_val = (long long)scaled;
  double diff = scaled - (double)floor_val;
  long long rounded = floor_val;
  if (diff > 0.5) {
    rounded = floor_val + 1;
  } else if (diff == 0.5) {
    if (floor_val % 2 != 0) {
      rounded = floor_val + 1;
    }
  }
  return rounded;
}

void s21_ftoa(double val, char *buf, int precision) {
  double scale = 1.0;
  int i = 0;
  while (i < precision) {
    scale *= 10.0;
    i++;
  }
  double scaled = val * scale;
  long long total = round_half_to_even(scaled);
  long long int_part = total;
  long long frac_part = 0;
  if (precision > 0) {
    long long divisor = (long long)scale;
    int_part = total / divisor;
    frac_part = total % divisor;
  }
  s21_itoa(int_part, buf);
  if (precision > 0) {
    int len = local_strlen(buf);
    buf[len++] = '.';
    char frac_buf[256] = {0};
    s21_itoa(frac_part, frac_buf);
    int frac_len = local_strlen(frac_buf);
    int pad = precision - frac_len;
    int j = 0;
    while (j < pad) {
      buf[len++] = '0';
      j++;
    }
    j = 0;
    while (j < frac_len) {
      buf[len++] = frac_buf[j++];
    }
    buf[len] = '\0';
  }
}

void init_options(FormatOptions *opts) {
  opts->minus = 0;
  opts->plus = 0;
  opts->space = 0;
  opts->width = 0;
  opts->precision = -1;
  opts->length = 0;
  opts->specifier = 0;
}

const char *parse_flags(const char *fmt, FormatOptions *opts) {
  int loop = 1;
  while (loop) {
    if (*fmt == '-') {
      opts->minus = 1;
      fmt++;
    } else if (*fmt == '+') {
      opts->plus = 1;
      fmt++;
    } else if (*fmt == ' ') {
      opts->space = 1;
      fmt++;
    } else {
      loop = 0;
    }
  }
  return fmt;
}

const char *parse_width(const char *fmt, FormatOptions *opts) {
  while (*fmt >= '0' && *fmt <= '9') {
    opts->width = opts->width * 10 + (*fmt - '0');
    fmt++;
  }
  return fmt;
}

const char *parse_precision(const char *fmt, FormatOptions *opts) {
  if (*fmt == '.') {
    fmt++;
    opts->precision = 0;
    while (*fmt >= '0' && *fmt <= '9') {
      opts->precision = opts->precision * 10 + (*fmt - '0');
      fmt++;
    }
  }
  return fmt;
}

const char *parse_length(const char *fmt, FormatOptions *opts) {
  if (*fmt == 'h' || *fmt == 'l') {
    opts->length = *fmt;
    fmt++;
  }
  return fmt;
}

const char *parse_specifier(const char *fmt, FormatOptions *opts) {
  if (*fmt == 'c' || *fmt == 'd' || *fmt == 'f' || *fmt == 's' || *fmt == 'u' ||
      *fmt == '%') {
    opts->specifier = *fmt;
    fmt++;
  }
  return fmt;
}

const char *parse_options(const char *fmt, FormatOptions *opts) {
  fmt = parse_flags(fmt, opts);
  fmt = parse_width(fmt, opts);
  fmt = parse_precision(fmt, opts);
  fmt = parse_length(fmt, opts);
  fmt = parse_specifier(fmt, opts);
  return fmt;
}

void apply_integer_precision(char *buf, int precision) {
  int len = local_strlen(buf);
  if (len == 1 && buf[0] == '0' && precision == 0) {
    buf[0] = '\0';
  } else if (len < precision) {
    int pad = precision - len;
    int i = len;
    while (i >= 0) {
      buf[i + pad] = buf[i];
      i--;
    }
    i = 0;
    while (i < pad) {
      buf[i] = '0';
      i++;
    }
  }
}

char get_sign_char(int is_neg, const FormatOptions *opts, int is_unsigned) {
  char sign = '\0';
  if (!is_unsigned) {
    if (is_neg) {
      sign = '-';
    } else if (opts->plus) {
      sign = '+';
    } else if (opts->space) {
      sign = ' ';
    }
  }
  return sign;
}

void pad_and_align(char *dest, const char *buf, char sign,
                   const FormatOptions *opts) {
  int val_len = local_strlen(buf);
  int sign_len = (sign != '\0') ? 1 : 0;
  int total_len = val_len + sign_len;
  int pad_len = (opts->width > total_len) ? (opts->width - total_len) : 0;
  int d_idx = 0;
  if (opts->minus) {
    if (sign != '\0') {
      dest[d_idx++] = sign;
    }
    int i = 0;
    while (i < val_len) {
      dest[d_idx++] = buf[i++];
    }
    int j = 0;
    while (j < pad_len) {
      dest[d_idx++] = ' ';
      j++;
    }
  } else {
    int j = 0;
    while (j < pad_len) {
      dest[d_idx++] = ' ';
      j++;
    }
    if (sign != '\0') {
      dest[d_idx++] = sign;
    }
    int i = 0;
    while (i < val_len) {
      dest[d_idx++] = buf[i++];
    }
  }
  dest[d_idx] = '\0';
}

void format_char(char *dest, const FormatOptions *opts, int c) {
  int pad_len = (opts->width > 1) ? (opts->width - 1) : 0;
  int d_idx = 0;
  if (opts->minus) {
    dest[d_idx++] = (char)c;
    int j = 0;
    while (j < pad_len) {
      dest[d_idx++] = ' ';
      j++;
    }
  } else {
    int j = 0;
    while (j < pad_len) {
      dest[d_idx++] = ' ';
      j++;
    }
    dest[d_idx++] = (char)c;
  }
  dest[d_idx] = '\0';
}

void format_string(char *dest, const FormatOptions *opts, const char *src) {
  const char *str = (src == NULL) ? "(null)" : src;
  int val_len = local_strlen(str);
  if (opts->precision >= 0 && opts->precision < val_len) {
    val_len = opts->precision;
  }
  int pad_len = (opts->width > val_len) ? (opts->width - val_len) : 0;
  int d_idx = 0;
  if (opts->minus) {
    int i = 0;
    while (i < val_len) {
      dest[d_idx++] = str[i++];
    }
    int j = 0;
    while (j < pad_len) {
      dest[d_idx++] = ' ';
      j++;
    }
  } else {
    int j = 0;
    while (j < pad_len) {
      dest[d_idx++] = ' ';
      j++;
    }
    int i = 0;
    while (i < val_len) {
      dest[d_idx++] = str[i++];
    }
  }
  dest[d_idx] = '\0';
}

long long get_signed_arg(va_list args, char length) {
  long long val = 0;
  if (length == 'l') {
    val = va_arg(args, long);
  } else if (length == 'h') {
    val = (short)va_arg(args, int);
  } else {
    val = va_arg(args, int);
  }
  return val;
}

unsigned long long get_unsigned_arg(va_list args, char length) {
  unsigned long long val = 0;
  if (length == 'l') {
    val = va_arg(args, unsigned long);
  } else if (length == 'h') {
    val = (unsigned short)va_arg(args, unsigned int);
  } else {
    val = va_arg(args, unsigned int);
  }
  return val;
}

void process_specifier(const FormatOptions *opts, va_list args,
                       char *temp_buf) {
  if (opts->specifier == 'c') {
    int c = va_arg(args, int);
    format_char(temp_buf, opts, c);
  } else if (opts->specifier == 's') {
    const char *str = va_arg(args, const char *);
    format_string(temp_buf, opts, str);
  } else if (opts->specifier == 'd') {
    long long val = get_signed_arg(args, opts->length);
    char val_buf[2048] = {0};
    int is_neg = (val < 0);
    s21_itoa(val, val_buf);
    apply_integer_precision(val_buf, opts->precision);
    char sign = get_sign_char(is_neg, opts, 0);
    pad_and_align(temp_buf, val_buf, sign, opts);
  } else if (opts->specifier == 'u') {
    unsigned long long val = get_unsigned_arg(args, opts->length);
    char val_buf[2048] = {0};
    s21_utoa(val, val_buf);
    apply_integer_precision(val_buf, opts->precision);
    char sign = get_sign_char(0, opts, 1);
    pad_and_align(temp_buf, val_buf, sign, opts);
  } else if (opts->specifier == 'f') {
    double val = va_arg(args, double);
    char val_buf[2048] = {0};
    int is_neg = (val < 0.0);
    double abs_val = local_fabs(val);
    int prec = (opts->precision == -1) ? 6 : opts->precision;
    s21_ftoa(abs_val, val_buf, prec);
    char sign = get_sign_char(is_neg, opts, 0);
    pad_and_align(temp_buf, val_buf, sign, opts);
  } else if (opts->specifier == '%') {
    format_char(temp_buf, opts, '%');
  }
}

int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int count = 0;
  const char *fmt = format;
  char *dest = str;
  while (*fmt != '\0') {
    if (*fmt == '%') {
      fmt++;
      FormatOptions opts;
      init_options(&opts);
      fmt = parse_options(fmt, &opts);
      char temp_buf[4096] = {0};
      process_specifier(&opts, args, temp_buf);
      int len = local_strlen(temp_buf);
      int i = 0;
      while (i < len) {
        *dest++ = temp_buf[i++];
        count++;
      }
    } else {
      *dest++ = *fmt++;
      count++;
    }
  }
  *dest = '\0';
  va_end(args);
  return count;
}

#endif
