/* GNU make's jobserver related functionality.

See dbgcnt.def for usage information.  */

#ifndef GCC_JOBSERVER_H
#define GCC_JOBSERVER_H

using namespace std;

struct jobserver_info
{
  /* Default constructor.  */
  jobserver_info ();

  /* Connect to the server.  */
  void connect ();

  /* Disconnect from the server.  */
  void disconnect ();

  /* Get token from the server.  */
  bool get_token ();

  /* Return token to the server.  */
  void return_token ();

  /* Error message if there is a problem.  */
  string error_msg = "";
  /* Skipped MAKEFLAGS where --jobserver-auth is skipped.  */
  string skipped_makeflags = "";
  /* File descriptor for reading used for jobserver communication.  */
  int rfd = -1;
  /* File descriptor for writing used for jobserver communication.  */
  int wfd = -1;
  /* Named pipe path.  */
  string pipe_path = "";
  /* Pipe file descriptor.  */
  int pipefd = -1;
  /* Return true if jobserver is active.  */
  bool is_active = false;
  /* Return true if communication with jobserver is working.  */
  bool is_connected = false;
};

#endif /* GCC_JOBSERVER_H */
