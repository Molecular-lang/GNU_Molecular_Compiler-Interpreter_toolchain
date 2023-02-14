/* SOM clock definition for BFD. */

#ifndef _SOM_CLOCK_H
#define _SOM_CLOCK_H

struct som_external_clock
{
  unsigned char secs[4];
  unsigned char nanosecs[4];
};

#endif /* _SOM_CLOCK_H */
