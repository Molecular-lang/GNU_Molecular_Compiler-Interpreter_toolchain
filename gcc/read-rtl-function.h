/* read-rtl-function.h - Reader for RTL function dumps */

#ifndef GCC_READ_RTL_FUNCTION_H
#define GCC_READ_RTL_FUNCTION_H

extern bool read_rtl_function_body (const char *path);

extern bool read_rtl_function_body_from_file_range (location_t start_loc, location_t end_loc);

#endif /* GCC_READ_RTL_FUNCTION_H */
