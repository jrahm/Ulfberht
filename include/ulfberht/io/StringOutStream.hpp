#ifndef INCLUDE_ULFBERHT_IO_STRINGOUTSTREAM_
#define INCLUDE_ULFBERHT_IO_STRINGOUTSTREAM_

/*
 * Author: jrahm
 * created: 2015/05/26
 * StringOutStream.hpp: <description>
 */

#include <ulfberht/io/BaseOutput.hpp>
#include <string>

namespace io {

class StringOutStream: public BaseOutput {
public:
	StringOutStream(std::string* outstr=NULL);
	virtual ~StringOutStream();

	virtual bool write(byte b) OVERRIDE;

	std::string& getString();
	inline const std::string& getString() const
		{ return const_cast<StringOutStream*>(this)->getString(); }
		
private:
	std::string* m_my_str;
	bool m_owner;
};

}

#endif /* INCLUDE_ULFBERHT_IO_STRINGOUTSTREAM_ */
