// Specific definitions for generic platforms  -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef _GLIBCXX_ERROR_CONSTANTS
#define _GLIBCXX_ERROR_CONSTANTS 1

#include <bits/c++config.h>
#include <cerrno>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  enum class errc
    {
      address_family_not_supported = 		EAFNOSUPPORT,
      address_in_use = 				EADDRINUSE,
      address_not_available = 			EADDRNOTAVAIL,
      already_connected = 			EISCONN,
      argument_list_too_long = 			E2BIG,
      argument_out_of_domain = 			EDOM,
      bad_address = 				EFAULT,
      bad_file_descriptor = 			EBADF,

#ifdef EBADMSG
      bad_message = 				EBADMSG,
#endif

      broken_pipe = 				EPIPE,
      connection_aborted = 			ECONNABORTED,
      connection_already_in_progress = 		EALREADY,
      connection_refused = 			ECONNREFUSED,
      connection_reset = 			ECONNRESET,
      cross_device_link = 			EXDEV,
      destination_address_required = 		EDESTADDRREQ,
      device_or_resource_busy = 		EBUSY,
      directory_not_empty = 			ENOTEMPTY,
      executable_format_error = 		ENOEXEC,
      file_exists = 	       			EEXIST,
      file_too_large = 				EFBIG,
      filename_too_long = 			ENAMETOOLONG,
      function_not_supported = 			ENOSYS,
      host_unreachable = 			EHOSTUNREACH,

#ifdef EIDRM
      identifier_removed = 			EIDRM,
#endif

      illegal_byte_sequence = 			EILSEQ,
      inappropriate_io_control_operation = 	ENOTTY,
      interrupted = 				EINTR,
      invalid_argument = 			EINVAL,
      invalid_seek = 				ESPIPE,
      io_error = 				EIO,
      is_a_directory = 				EISDIR,
      message_size = 				EMSGSIZE,
      network_down = 				ENETDOWN,
      network_reset = 				ENETRESET,
      network_unreachable = 			ENETUNREACH,
      no_buffer_space = 			ENOBUFS,
      no_child_process = 			ECHILD,

#ifdef ENOLINK
      no_link = 				ENOLINK,
#endif

      no_lock_available = 			ENOLCK,

#ifdef ENODATA
      no_message_available = 			ENODATA,
#endif

      no_message = 				ENOMSG,
      no_protocol_option = 			ENOPROTOOPT,
      no_space_on_device = 			ENOSPC,

#ifdef ENOSR
      no_stream_resources = 			ENOSR,
#endif

      no_such_device_or_address = 		ENXIO,
      no_such_device = 				ENODEV,
      no_such_file_or_directory = 		ENOENT,
      no_such_process = 			ESRCH,
      not_a_directory = 			ENOTDIR,
      not_a_socket = 				ENOTSOCK,

#ifdef ENOSTR
      not_a_stream = 				ENOSTR,
#endif

      not_connected = 				ENOTCONN,
      not_enough_memory = 			ENOMEM,

#ifdef ENOTSUP
      not_supported = 				ENOTSUP,
#endif

#ifdef ECANCELED
      operation_canceled = 			ECANCELED,
#endif

      operation_in_progress = 			EINPROGRESS,
      operation_not_permitted = 		EPERM,
      operation_not_supported = 		EOPNOTSUPP,
      operation_would_block = 			EWOULDBLOCK,

#ifdef EOWNERDEAD
      owner_dead = 				EOWNERDEAD,
#endif

      permission_denied = 			EACCES,

#ifdef EPROTO
      protocol_error = 				EPROTO,
#endif

      protocol_not_supported = 			EPROTONOSUPPORT,
      read_only_file_system = 			EROFS,
      resource_deadlock_would_occur = 		EDEADLK,
      resource_unavailable_try_again = 		EAGAIN,
      result_out_of_range = 			ERANGE,

#ifdef ENOTRECOVERABLE
      state_not_recoverable = 			ENOTRECOVERABLE,
#endif

#ifdef ETIME
      stream_timeout = 				ETIME,
#endif

#ifdef ETXTBSY
      text_file_busy = 				ETXTBSY,
#endif

      timed_out = 				ETIMEDOUT,
      too_many_files_open_in_system = 		ENFILE,
      too_many_files_open = 			EMFILE,
      too_many_links = 				EMLINK,
      too_many_symbolic_link_levels = 		ELOOP,

#ifdef EOVERFLOW
      value_too_large = 			EOVERFLOW,
#endif

      wrong_protocol_type = 			EPROTOTYPE
    };

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif
