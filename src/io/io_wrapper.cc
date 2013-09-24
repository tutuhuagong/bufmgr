#include "io_wrapper.h"

ssize_t readall(int fd, void* buf, size_t nbyte)
{
    ssize_t nread = 0, n;

    do {
      if ( (n = ::read(fd, &((char*)buf)[nread], nbyte - nread ) ) == -1 ) {
          if (errno == EINTR) {
            continue;
          } else {
              return -1;
          }
      }
      if (n ==0) {
        return nread;
      }
      nread += n;
    } while (nread < nbyte);

    return nread;
}

ssize_t writeall(int fd, void* buf, size_t nbyte)
{
    ssize_t nwritten = 0, n;
    
    do{
        if ( (n = ::write(fd, &((const char*)buf)[nwritten], nbyte - nwritten) ) == -1 ){
            if (errno == EINTR){
                continue;
            } else {
                return -1;
            }
        }
        nwritten += n;
    }while (nwritten < nbyte);

    return nwritten;
}
