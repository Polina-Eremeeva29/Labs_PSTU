#include "Convector.h"

std::string& Convector_String_to_string(String^ s, std::string& os)
{
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
	return os;
}
String^ Convector_string_to_String(std::string& os, String^ s)
{
	s = gcnew System::String(os.c_str());
	return s;
}
System::String^ Convert_char_to_String(char ch)
{
	char chr;
	chr = ch;
	System::String^ str;
	str += wchar_t(ch);
	return str;
}