A simple C++ output stream for logging to syslog system.

# Introduction #


Before open and after close the stream output to the std::clog


# Details #

```
//test.cpp
#include <logostream.h>

using namespace std;
using namespace log;

int main ()
{
 logs << "write to std::clog" << endl;

 logs.open("test");
 logs << level::info << "logging this" << endl;

 logs.level(level::warning);
 logs << level::info << "discard this" << endl;

}
```

Thanks for use, enjoy!
My homepage
http://www.andr.ru/








