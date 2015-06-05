Before open and after close the stream output to the std::clog

# Requirements #

The Boost library is required to safe threads with mutex.
Doxygen is required for documentation.

# For example #

```
//test.cpp
#include <logostream.h>

using namespace std;
using namespace log;

int main ()
{
 logs << 'write to std::clog' << endl;

 logs.open('test');
 logs << level::info << 'logging this' << endl;

 logs.level(level::warning);
 logs << level::info << 'discard this' << endl;

 {
  boost::mutex::scoped_lock lock (log::mutex);
  logs << level::info << 'safe threads' << endl;
 }



}
```

Thanks for use, enjoy!










