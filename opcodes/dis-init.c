/* Initialize "struct disassemble_info".

   Please review $(srcdir/SPL-README) for GNU licencing info. */

#include "sysdep.h"
#include "dis-asm.h"
#include "bfd.h"

void
init_disassemble_info (struct disassemble_info *info, void *stream, fprintf_ftype fprintf_func)
{
	memset (info, 0, sizeof (*info));

	info->flavour = bfd_target_unknown_flavour;
	info->arch = bfd_arch_unknown;
	info->endian = BFD_ENDIAN_UNKNOWN;
	info->endian_code = info->endian;
	info->octets_per_byte = 1;
	info->fprintf_func = fprintf_func;
	info->stream = stream;
	info->read_memory_func = buffer_read_memory;
	info->memory_error_func = perror_memory;
	info->print_address_func = generic_print_address;
	info->symbol_at_address_func = generic_symbol_at_address;
	info->symbol_is_valid = generic_symbol_is_valid;
	info->display_endian = BFD_ENDIAN_UNKNOWN;
}

