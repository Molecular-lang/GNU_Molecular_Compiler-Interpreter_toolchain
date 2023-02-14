/* server.c  Set up and handle communications with a server process. */

#ifndef GCC_SERVER_H
#define GCC_SERVER_H

/*
 *  Dual pipe opening of a child process
 */

typedef struct
{
  int read_fd;
  int write_fd;
} t_fd_pair;

typedef struct
{
  FILE *pf_read;		/* parent read fp  */
  FILE *pf_write;		/* parent write fp */
} t_pf_pair;

char* run_shell( const char* pzCmd );
pid_t proc2_fopen( t_pf_pair* p_pair, tCC** pp_args );
pid_t proc2_open( t_fd_pair* p_pair, tCC** pp_args );
int   chain_open( int in_fd, tCC** pp_args, pid_t* p_child );
void close_server( void );

#endif /* ! GCC_SERVER_H */
