//@(#) logostream exapmle
//@(#) Author Andrew Wingorodov <http://andr.ru/>
//$Revision: 1.3 $

#include "ostream.h"

using namespace std;
using namespace log;

/*! \brief Using logstream
  
You must add the string of identification "test"
into syslog.conf(5) and restart the syslogd(8).
   
\code
#/etc/syslog.conf 
#
!test
*.*            /var/log/test.log
\endcode

Example for use:
\code

logs.level (level::emerg);
logs << level::info << "discard" << endl;

logs.level (level::warning);
logs << level::error << "logging" << endl;
logs << level::warning << "logging" << endl;
logs << level::info << "discard" << endl;

\endcode
 */
class example {};

int
 main ()
{
	logs << "Welcom! This is message output to the std::clog" << endl
		 << "We are open the logs now and write input" << endl
		 << "from you keyboard to syslog(3)" << endl
		 << "(type CTRL-D to close logostream and exit)"
		 << endl;

	logs.open ("test") ;
	logs.level (level::error);

	std::string line;
	while ( getline ( cin,line))
	{
		{ //!< USE log::mutex for SAFE THREADs
		boost::mutex::scoped_lock lock (log::mutex);

		logs << level::info << "discard this level" << endl;
		logs << level::critical << line << endl;
		}
	}

	logs.close ();
	logs << "Well, we are close connect to syslogd(8) and write messages "
	 	 << "to std::clog again. Look up result at /var/log/test.log"
		 << endl;
}
