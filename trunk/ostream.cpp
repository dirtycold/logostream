//@(#) Output stream to log (use syslog(3))
//@(#) Author Andrew Wingorodov <http://andr.ru/>
//$Revision: 1.3 $

#include "ostream.h"

namespace log {

//
template <class C, class T>
class streambuf<C,T>::int_type streambuf<C,T>::sync ()
{
	const std::streamsize count = this->pptr() - this->pbase();
	if ( (state() >= priority ()) && count > 0)
	{
#ifndef WIN32
		std::basic_string<C,T> msg (this->pbase(), this->pptr ());
		::syslog (priority(),  msg.c_str()) ;
#endif
	}

	this->pbump (-count);
	return count ;
}

//
template <class C, class T>
class streambuf<C,T>::int_type streambuf<C,T>::overflow (int_type c)
{
	if ( is_open ()) {
		if ( c != EOF ) {
			*(this->pptr()) = c;
			this->pbump(1) ;
		}
		sync ();
	}
	return c;
}

logostream logs;	//!< Global log stream
boost::mutex mutex;	//!< Safe threads
} //::log
