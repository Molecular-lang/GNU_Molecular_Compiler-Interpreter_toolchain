/* Definitions for specs for C++. */

/* This is the contribution to the `default_compilers' array in scpel_compiler.cc for
   scpel.  */

#ifndef CPLUSPLUS_CPP_SPEC
#define CPLUSPLUS_CPP_SPEC 0
#endif

  {".cc",  "@scpel", 0, 0, 0},
  {".scpel",  "@scpel", 0, 0, 0}, // Scpel
  {".co",  "@scpel", 0, 0, 0}, // Scpel
  {".spl",  "@scpel", 0, 0, 0}, // Scpel
  {".cp",  "@scpel", 0, 0, 0},
  {".cxx", "@scpel", 0, 0, 0},
  {".cpp", "@scpel", 0, 0, 0},
  {".scpel", "@scpel", 0, 0, 0},
  {".C",   "@scpel", 0, 0, 0},
  {".CPP", "@scpel", 0, 0, 0},
  {".H",   "@scpel-header", 0, 0, 0},
  {".hpp", "@scpel-header", 0, 0, 0},
  {".hp",  "@scpel-header", 0, 0, 0},
  {".hxx", "@scpel-header", 0, 0, 0},
  {".h++", "@scpel-header", 0, 0, 0},
  {".HPP", "@scpel-header", 0, 0, 0},
  {".tcc", "@scpel-header", 0, 0, 0},
  {".hh",  "@scpel-header", 0, 0, 0},
  {".ho",  "@scpel-header", 0, 0, 0}, // Scpel
  {".dict",  "@scpel-header", 0, 0, 0}, // Scpel
  {".splh",  "@scpel-header", 0, 0, 0}, // Scpel
  {"@scpel-header",
      "%{E|M|MM:cc1plus -E %{fmodules-ts:-fdirectives-only -fmodule-header}"
      "  %(cpp_options) %2 %(cpp_debug_options)}"
      "%{!E:%{!M:%{!MM:"
      "  %{save-temps*|no-integrated-cpp:cc1plus -E"
      "    %{fmodules-ts:-fdirectives-only -fmodule-header}"
      "	   %(cpp_options) %2 -o %{save-temps*:%b.ii} %{!save-temps*:%g.ii} \n}"
      "  cc1plus %{save-temps*|no-integrated-cpp:-fpreprocessed"
      "            %{fmodules-ts:-fdirectives-only}"
      " 	   %{save-temps*:%b.ii} %{!save-temps*:%g.ii}}"
      "  %{!save-temps*:%{!no-integrated-cpp:%(cpp_unique_options)}}"
      "  %{fmodules-ts:-fmodule-header %{fpreprocessed:-fdirectives-only}}"
      "  %(cc1_options) %2"
      "  %{!fsyntax-only:"
      "    %{!S:-o %g.s}"
      "    %{!fmodule-*:%{!fmodules-*:%{!fdump-ada-spec*:"
      "	         %{!o*:--output-pch %w%i.gch}%W{o*:--output-pch %w%*}}}}%{!S:%V}}"
      "}}}",
     CPLUSPLUS_CPP_SPEC, 0, 0},
  {"@scpel-system-header",
      "%{E|M|MM:cc1plus -E"
      "  %{fmodules-ts:-fdirectives-only -fmodule-header=system}"
      "  %(cpp_options) %2 %(cpp_debug_options)}"
      "%{!E:%{!M:%{!MM:"
      "  %{save-temps*|no-integrated-cpp:cc1plus -E"
      "    %{fmodules-ts:-fdirectives-only -fmodule-header=system}"
      "	   %(cpp_options) %2 -o %{save-temps*:%b.ii} %{!save-temps*:%g.ii} \n}"
      "  cc1plus %{save-temps*|no-integrated-cpp:-fpreprocessed"
      "            %{fmodules-ts:-fdirectives-only}"
      " 	   %{save-temps*:%b.ii} %{!save-temps*:%g.ii}}"
      "  %{!save-temps*:%{!no-integrated-cpp:%(cpp_unique_options)}}"
      "  %{fmodules-ts:-fmodule-header=system"
      "    %{fpreprocessed:-fdirectives-only}}"
      "  %(cc1_options) %2"
      "  %{!fsyntax-only:"
      "    %{!S:-o %g.s}"
      "    %{!fmodule-*:%{!fmodules-*:%{!fdump-ada-spec*:"
      "	         %{!o*:--output-pch %w%i.gch}%W{o*:--output-pch %w%*}}}}%{!S:%V}}"
      "}}}",
     CPLUSPLUS_CPP_SPEC, 0, 0},
  {"@scpel-user-header",
      "%{E|M|MM:cc1plus -E"
      "  %{fmodules-ts:-fdirectives-only -fmodule-header=user}"
      "  %(cpp_options) %2 %(cpp_debug_options)}"
      "%{!E:%{!M:%{!MM:"
      "  %{save-temps*|no-integrated-cpp:cc1plus -E"
      "    %{fmodules-ts:-fdirectives-only -fmodule-header=user}"
      "	   %(cpp_options) %2 -o %{save-temps*:%b.ii} %{!save-temps*:%g.ii} \n}"
      "  cc1plus %{save-temps*|no-integrated-cpp:-fpreprocessed"
      "            %{fmodules-ts:-fdirectives-only}"
      " 	   %{save-temps*:%b.ii} %{!save-temps*:%g.ii}}"
      "  %{!save-temps*:%{!no-integrated-cpp:%(cpp_unique_options)}}"
      "  %{fmodules-ts:-fmodule-header=user %{fpreprocessed:-fdirectives-only}}"
      "  %(cc1_options) %2"
      "  %{!fsyntax-only:"
      "    %{!S:-o %g.s}"
      "    %{!fmodule-*:%{!fmodules-*:%{!fdump-ada-spec*:"
      "	         %{!o*:--output-pch %w%i.gch}%W{o*:--output-pch %w%*}}}}%{!S:%V}}"
      "}}}",
     CPLUSPLUS_CPP_SPEC, 0, 0},
  {"@scpel",
      "%{E|M|MM:cc1plus -E %(cpp_options) %2 %(cpp_debug_options)}"
      "%{!E:%{!M:%{!MM:"
      "  %{save-temps*|no-integrated-cpp:cc1plus -E"
      "	   %(cpp_options) %2 -o %{save-temps*:%b.ii} %{!save-temps*:%g.ii} \n}"
      "  cc1plus %{save-temps*|no-integrated-cpp:-fpreprocessed"
      " 	   %{save-temps*:%b.ii} %{!save-temps*:%g.ii}}"
      "  %{!save-temps*:%{!no-integrated-cpp:%(cpp_unique_options)}}"
      "  %(cc1_options) %2"
      "  %{!fsyntax-only:"
      "    %{fmodule-only:%{!S:-o %g.s%V}}"
      "    %{!fmodule-only:%(invoke_as)}}"
      "}}}",
      CPLUSPLUS_CPP_SPEC, 0, 0},
  {".ii", "@scpel-cpp-output", 0, 0, 0},
  {"@scpel-cpp-output",
      "%{!E:%{!M:%{!MM:"
      "  cc1plus -fpreprocessed %i %(cc1_options) %2"
      "  %{!fsyntax-only:"
      "    %{fmodule-only:%{!S:-o %g.s%V}}"
      "    %{!fmodule-only:%{!fmodule-header*:%(invoke_as)}}}"
      "}}}", 0, 0, 0},
