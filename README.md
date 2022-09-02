# Scpel-1.0.0-Beta
Subconscious Electronic Programming Language

# Description
This project aims at merging the incompatibilities of GNU
C and C++ as of GCC 13.0.0 pre release please visit 
"https://www.scpel.org/incompatibilities.html" for a
detailed review. Incompatibilities aside, the project also
aims at modifying and redesigning GNU C++ facilities to
directly support machine learning algorithmic implementations
through introducing new features that are reusable at both
system and application level. 

Having merged GNU C and C++ and redesign GCC to one language (Scpel)
having the compiler specifically meet all Metaprogramming 
techniques like reflection, The project is to be used as a
programming standard for perfectly intelligent systems and all
mathematical computing use cases.

# How to build
Even in its early stages, I have tried so hard to bootstrap the compiler
so: To build Scpel, you need a minimal of Scpel-1.0.0. Please visit 
"https://www.scpel.org" to download the minimal Scpel binaries or, attached 
to this exact repo is a debian package "Scpel_1.0.0-1_amd64.deb" ready
for download.

From your terminal:
$ sudo dpkg -i /path/to/downloads/Scpel_1.0.0-1_amd64
which will install the binaries in your /usr/local directory.

NOTE:
	Some systems won't understand the "amd64" value, it is strongly advisable
	that in times as those, please run:
	$ sudo dpkg --add-architecture amd64
	which will add "amd64" to your architecture list.
	
Otherwise, you're now good to go, test the compiler by compiling a simple C
or C++ "hello_world.co". ".co" is the default Scpel file extension

# How to actually build the binaries from source
1. Clone the repo. 
2. Create a new directory with a name of your choice either 
   inside the $(srcdir) or outside the cloned directory.
3. From your newly created directory, "open terminal there"
   and point to your $(srcdir) with something like:
   $ ../Scpel-1.0.0/configure --enable-languages=scpel --disable-bootstrap 
   --enable-checking --enable-multilib --prefix=/usr/local && make -j $(nproc)
   On my:
   CPU    ==> Intel Pentium(R) Silver N5030 CPU @ 1.10GHz x 4
   MEMORY ==> 3.6 GiB
   the variable "-j $(nproc)" tends to freeze my entire (Debian 11 Xfce) system,
   if the same that side, please run the above command without "-j $(nproc)"
4. After some time the build will complete, run:
   $ sudo make install
   Which wiil have your newly compiled binaries installed in /usr/local
5. From your terminal, call the driver by:
   $ spl -o file_name file_name.co
   Assuming file_name.co is the file that contains your sample hello world
   
# NOTE:
  Please visit $(srcdir)/SPL_README, $(srcdir)/LICENCE for licencing info
  or $(srcdir)/COPYING for more stuff you would'nt love to miss

Best Regards:
Francis Ssessaazi
phrunsys.scpel.256.ug@gmail.com
