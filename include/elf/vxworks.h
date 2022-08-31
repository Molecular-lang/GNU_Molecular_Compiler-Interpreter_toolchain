/* VxWorks ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_VXWORKS_H
#define _ELF_VXWORKS_H

#define DT_VX_WRS_TLS_DATA_START 0x60000010
#define DT_VX_WRS_TLS_DATA_SIZE  0x60000011
#define DT_VX_WRS_TLS_DATA_ALIGN 0x60000015
#define DT_VX_WRS_TLS_VARS_START 0x60000012
#define DT_VX_WRS_TLS_VARS_SIZE  0x60000013
  
#endif /* _ELF_VXWORKS_H */
