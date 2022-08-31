// -*- C++ -*- compatibility header.

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <cstdio>

#ifndef _GLIBCXX_STDIO_H
#define _GLIBCXX_STDIO_H 1

#ifdef _GLIBCXX_NAMESPACE_C
using std::FILE;
using std::fpos_t;

using std::remove;
using std::rename;
using std::tmpfile;
using std::tmpnam;
using std::fclose;
using std::fflush;
using std::fopen;
using std::freopen;
using std::setbuf;
using std::setvbuf;
using std::fprintf;
using std::fscanf;
using std::printf;
using std::scanf;
using std::snprintf;
using std::sprintf;
using std::sscanf;
using std::vfprintf;
using std::vfscanf;
using std::vprintf;
using std::vscanf;
using std::vsnprintf;
using std::vsprintf;
using std::vsscanf;
using std::fgetc;
using std::fgets;
using std::fputc;
using std::fputs;
using std::getc;
using std::getchar;
using std::gets;
using std::putc;
using std::putchar;
using std::puts;
using std::ungetc;
using std::fread;
using std::fwrite;
using std::fgetpos;
using std::fseek;
using std::fsetpos;
using std::ftell;
using std::rewind;
using std::clearerr;
using std::feof;
using std::ferror;
using std::perror;
#endif

#endif
