# ifndef LOCAL_COMMUNICATION_H
# define LOCAL_COMMUNICATION_H

# include <communication.H>

/* reads up to "n" bytes of data, available from "fd" and 
   writes them on "vptr" */

ssize_t readn(int fd, void *vptr, size_t n)
{
 size_t  nleft;
 ssize_t nread;
 char    *ptr;

 ptr = static_cast<char *>(vptr);
 nleft = n;
 while (nleft > 0) 
   {
    if ( (nread = read(fd, ptr, nleft)) < 0) 
         {
          if (errno == EINTR)
             nread = 0;              /* and call read() again */
             else
             return(-1);
          } 
           else 
              if (nread == 0)
                 break;                          /* EOF */

                nleft -= nread;
                ptr   += nread;
   }
 return(n - nleft);              /* return >= 0 */
}


/* writes the chunk of "n" bytes stored at "vptr" in the 
   socket "fd" */

ssize_t writen(int fd, const void *vptr, size_t n)
{
   size_t          nleft;
   ssize_t         nwritten;
   const char      *ptr;

   ptr = static_cast<char *>(vptr);
   nleft = n;
   while (nleft > 0) 
     {
         if ( (nwritten = write(fd, ptr, nleft)) <= 0) 
	   {
                if (errno == EINTR)
                    nwritten = 0;           /* call write() again */
                   else
                    return (-1);                     /* error */
           }
          nleft -= nwritten;
          ptr   += nwritten;
     }
   return(n);
}

# endif // LOCAL_COMMUNICATION_H



