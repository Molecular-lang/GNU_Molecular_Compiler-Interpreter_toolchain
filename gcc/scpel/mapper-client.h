/* C++ modules.  Experimental!	-*- c++ -*-
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* Forward to the header in c++tools.  */

#ifndef MAPPER_CLIENT_H
#define MAPPER_CLIENT_H 1

#include "cody.hh"

#ifndef HAVE_SIGHANDLER_T
typedef void (*sighandler_t) (int);
#endif

class module_client : public Cody::Client {
	pex_obj *pex = nullptr;
	sighandler_t sigpipe = SIG_IGN;
	Cody::Flags flags = Cody::Flags::None;

	public:
		module_client(Cody::Server *s)
			: Client (s) { }
		module_client(pex_obj *pex, int fd_from, int fd_to);

		module_client(int fd_from, int fd_to)
			: Client (fd_from, fd_to) { }

	public:
		Cody::Flags get_flags() const {
			return flags;
		}

	public:
		static module_client *open_module_client(location_t loc, const char *option, void (*set_repo) (const char *), char const *);
		static void close_module_client(location_t loc, module_client *);
};

#endif
