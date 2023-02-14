# Scpel-0.0.1 (Let there be...)
Subconscious Electronic Programming Language

Copyright (C) 1997-2023 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>. 

# Description
Scpel aims at closely borrowing the C programming language low level power in
the advantage of deep learning, machine learning and artificial intelligence.
With this in mind, the language (Scpel) offers a fully working C compiler framework
with more AI supportive features and light-weight abstractions directly to the hardware
targeting usecases like [artificial intelligence in the kernel layer](https://www.scpel.org/artificial_systems.html) and having robust
AI libraries and API all accessible at the systems level. For more, please visit [https://www.scpel.org](https://www.scpel.org)

# How to build
To build Scpel, you need a minimal of Scpel-0.0.1 compiler. Please visit 
<https://www.scpel.org> to download the minimal Scpel binaries or
download an appropriate release from the main branch.

From your terminal:
$ sudo dpkg -i /path/to/downloads/name-of-release-.deb
which will install the binaries in your /usr/local directory.

NOTE:
	Some systems won't understand the "amd64" value, it is strongly advisable
	that in times as those, please run:
	$ sudo dpkg --add-architecture amd64
	which will add "amd64" to your architecture list.
	
Otherwise, you're now good to go, test the compiler by compiling a simple C
"hello_world.co". ".co" is the default Scpel file extension

# How to actually build the binaries from source
1. Clone the repo. 
2. Create a new directory with a name of your choice either 
   inside the $(srcdir) or outside the cloned directory. NOTE: GCC deprecated
   in-tree builds.
3. From your newly created directory, "open terminal there"
   and point to your $(srcdir) with something like:
   $ ../Scpel-0.0.1/configure --enable-languages=c --disable-bootstrap 
   --enable-checking --enable-multilib --prefix=/usr/local && make -j $(nproc)
   NOTE: It is advisabe to please run the above command without "-j $(nproc)",
   		 attempt it only if your system has the necessary resources not to freeze
   		 or hang.
4. After some time the build will complete, run:
   $ sudo make install
   Which wiil have your newly compiled binaries installed in /usr/local
5. From your terminal, call the driver by:
   $ scpel -o file_name file_name.co
   Assuming file_name.co is the file that contains your sample code.
   
# NOTE:
  Please visit $(srcdir)/COPYING for more stuff you would'nt love to miss

Best of regards:
	Francis Ssessaazi
	phrunsys.scpel.256.ug@gmail.com
