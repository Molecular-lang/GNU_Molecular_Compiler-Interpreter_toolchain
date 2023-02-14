/* host.h - Parameters about the a.out format, based on the host system
   on which the program is compiled. 
 */

/* Address of data segment in memory after it is loaded.
   It is up to you to define SEGMENT_SIZE on machines not listed here.  */
#ifndef SEGMENT_SIZE

#if defined(pyr)
#define SEGMENT_SIZE page_size
#endif

#ifdef is68k
#define SEGMENT_SIZE 0x20000
#endif

#endif /*!defined(SEGMENT_SIZE)*/

