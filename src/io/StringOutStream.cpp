#include <ulfberht/io/StringOutStream.hpp>

using namespace std;

namespace io {

StringOutStream::StringOutStream(string* outstr):
	m_my_str(outstr), m_owner(false) {
	if(m_my_str) {
		m_owner = true; 
	} else {
		m_my_str = new string();
	}
}

bool StringOutStream::write(byte b) {
	m_my_str->operator+=(b);
	return true;
}

string& StringOutStream::getString() {
	return * m_my_str;
}

StringOutStream::~StringOutStream() {
	if(m_owner) delete m_my_str;
}

}
