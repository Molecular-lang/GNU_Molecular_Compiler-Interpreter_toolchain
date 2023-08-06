<div align="center">
	<h1>Subconscious Electronic Programming Language</h1>
	<img src="https://scpel.org/scpel_logo.png"  width="300" height="200">
</div>

This is the main source code repository for [Scpel] on GNU GCC 14.0.0 implementation. 
It contains the compiler, [Scpel Standard AI Library (Ssail)], and documentation.

[Scpel]: https://www.scpel.org/
[Scpel Standard AI Library (Ssail)]: https://www.scpel.org/

**Note: this README is for _users_ rather than _contributors_.**
If you wish to _contribute_ to the compiler, you should read
[CONTRIBUTING.md](CONTRIBUTING.md) instead.

## Quick Start

Read ["Installation"] from [The Book].

["Installation"]: https://docs.scpel.org/user/
[The Book]: https://docs.scpel.org/user/

## Installing from Source

Follow the instructions bellow.

### Dependencies

Make sure you have installed the dependencies:

* `libgmp-dev`
* `libmpfr-dev`
* `libisl-dev`
* `libmpc-dev`
* `bison`
* `flex`
* `texinfo`
* A C/C++ compiler (when building for the host, `gcc` is enough; cross-compiling may
  need additional compilers) and `make`

### Building on Linux

#### Build steps

1. Clone the [source] with `git`:

   ```sh
   git clone https://github.com/Scpel-lang/GNU_Scpel_Compiler-Interpreter_toolchain.git
   cd GNU_Scpel_Compiler-Interpreter_toolchain
   ```

[source]: https://github.com/Scpel-lang/GNU_Scpel_Compiler-Interpreter_toolchain

2. Build and install:
   ```sh
   ./configure --disable-bootstrap --disable-multilib
   make && sudo make install
   ```

## Notes

Since the Scpel compiler is written in Scpel (at least we try), it must be built by a precompiled
"developer snapshot" version of itself (made in an earlier stage of development).
The snapshot can either be downloaded from the release or [Here](https://www.scpel.org/binaries/scpel_1.0.0-dev_amd64).

You will get a debian package file installable using:
   ```sh
   sudo dpkg -i /path/to/downloads/scpel_1.0.0-dev_amd64
   ```
Run a [sample Scpel program](https://www.scpel.org/getting-started.html) from your terminal with:
   ```sh
   $ scpel -o output_file input_file.scpel
   ```
then run the program with:
   ```sh
   $./output_file
   ```
   
If the program runs fine please proceed with the build.
Good luck!

## Getting Help

See https://www.scpel.org/community for a list of chat platforms, forums and
mailing lists.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md).

## License

Scpel is primarily distributed under the terms an conditions of the GNU General
Public Licence.

See [COPYING](COPYING) for more details.

## Trademark

[Scpel Software Foundation][ss-foundation] owns and protects the Scpel and its toolchain
trademarks and logos (the "Scpel Trademarks").

If you want to use these names or brands, please read the
[media guide][media-guide].

Third-party logos may be subject to third-party copyrights and trademarks. See
[Licenses][policies-licenses] for details.

[ss-foundation]: https://foundation.scpel.org
[media-guide]: https://foundation.scpel.org/policies/logo-policy-and-media-guide/
[policies-licenses]: https://www.scpel.org/policies/licenses