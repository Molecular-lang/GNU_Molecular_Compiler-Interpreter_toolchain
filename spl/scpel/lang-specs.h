/* Definitions for specs for C++. */

/* This is the contribution to the `default_compilers' array in spl.cc for
   scpel.  */

#ifndef CPLUSPLUS_CPP_SPEC
#define CPLUSPLUS_CPP_SPEC 0
#endif

  {".cc",  "@c++", 0, 0, 0},
  {".scpel",  "@c++", 0, 0, 0},
  {".co",  "@c++", 0, 0, 0},
  {".cp",  "@c++", 0, 0, 0},
  {".cxx", "@c++", 0, 0, 0},
  {".cpp", "@c++", 0, 0, 0},
  {".c++", "@c++", 0, 0, 0},
  {".C",   "@c++", 0, 0, 0},
  {".CPP", "@c++", 0, 0, 0},
  {".H",   "@c++-header", 0, 0, 0},
  {".hpp", "@c++-header", 0, 0, 0},
  {".hp",  "@c++-header", 0, 0, 0},
  {".hxx", "@c++-header", 0, 0, 0},
  {".h++", "@c++-header", 0, 0, 0},
  {".HPP", "@c++-header", 0, 0, 0},
  {".tcc", "@c++-header", 0, 0, 0},
  {".hh",  "@c++-header", 0, 0, 0},
  {".hspl",  "@c++-header", 0, 0, 0},
  {".ho",  "@c++-header", 0, 0, 0},
  {"@c++-header",
      "%{E|M|MM:splprop -E %{fmodules-ts:-fdirectives-only -fmodule-header}"
      "  %(cpp_options) %2 %(cpp_debug_options)}"
      "%{!E:%{!M:%{!MM:"
      "  %{save-temps*|no-integrated-cpp:splprop -E"
      "    %{fmodules-ts:-fdirectives-only -fmodule-header}"
      "	   %(cpp_options) %2 -o %{save-temps*:%b.ii} %{!save-temps*:%g.ii} \n}"
      "  splprop %{save-temps*|no-integrated-cpp:-fpreprocessed"
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
  {"@c++-system-header",
      "%{E|M|MM:splprop -E"
      "  %{fmodules-ts:-fdirectives-only -fmodule-header=system}"
      "  %(cpp_options) %2 %(cpp_debug_options)}"
      "%{!E:%{!M:%{!MM:"
      "  %{save-temps*|no-integrated-cpp:splprop -E"
      "    %{fmodules-ts:-fdirectives-only -fmodule-header=system}"
      "	   %(cpp_options) %2 -o %{save-temps*:%b.ii} %{!save-temps*:%g.ii} \n}"
      "  splprop %{save-temps*|no-integrated-cpp:-fpreprocessed"
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
  {"@c++-user-header",
      "%{E|M|MM:splprop -E"
      "  %{fmodules-ts:-fdirectives-only -fmodule-header=user}"
      "  %(cpp_options) %2 %(cpp_debug_options)}"
      "%{!E:%{!M:%{!MM:"
      "  %{save-temps*|no-integrated-cpp:splprop -E"
      "    %{fmodules-ts:-fdirectives-only -fmodule-header=user}"
      "	   %(cpp_options) %2 -o %{save-temps*:%b.ii} %{!save-temps*:%g.ii} \n}"
      "  splprop %{save-temps*|no-integrated-cpp:-fpreprocessed"
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
  {"@c++",
      "%{E|M|MM:splprop -E %(cpp_options) %2 %(cpp_debug_options)}"
      "%{!E:%{!M:%{!MM:"
      "  %{save-temps*|no-integrated-cpp:splprop -E"
      "	   %(cpp_options) %2 -o %{save-temps*:%b.ii} %{!save-temps*:%g.ii} \n}"
      "  splprop %{save-temps*|no-integrated-cpp:-fpreprocessed"
      " 	   %{save-temps*:%b.ii} %{!save-temps*:%g.ii}}"
      "  %{!save-temps*:%{!no-integrated-cpp:%(cpp_unique_options)}}"
      "  %(cc1_options) %2"
      "  %{!fsyntax-only:"
      "    %{fmodule-only:%{!S:-o %g.s%V}}"
      "    %{!fmodule-only:%(invoke_as)}}"
      "}}}",
      CPLUSPLUS_CPP_SPEC, 0, 0},
  {".ii", "@c++-cpp-output", 0, 0, 0},
  {"@c++-cpp-output",
      "%{!E:%{!M:%{!MM:"
      "  splprop -fpreprocessed %i %(cc1_options) %2"
      "  %{!fsyntax-only:"
      "    %{fmodule-only:%{!S:-o %g.s%V}}"
      "    %{!fmodule-only:%{!fmodule-header*:%(invoke_as)}}}"
      "}}}", 0, 0, 0},
