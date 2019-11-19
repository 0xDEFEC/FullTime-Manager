/*

	configuration.h : This header file handles any process related to information needed to request data from the FTH API.
					  For example, on startup, if an API key is not detected, this file will handle file creation,
					  saving of the file, and parsing of the key from siad file. If a key is detected, it will handle 
					  passing that key to any functions that need it.

*/

#define KEYFILEPATH "Data/key.txt"
#define IDFILEPATH "Data/serverid.txt"
#define IPFILEPATH "Data/serverip.txt"

using namespace System;
using namespace System::IO;

enum FILE_RESPONSE_VALUES {
	FILE_OK,
	FILE_EMPTY
};

class configuration {
	public: static int keyFileCheck();
	public: static void getAPIKey(System::String^ %apiKeyContainer);
	public: static void changeAPIKey(System::String^ newKey, System::String^ %apiKeyContainer);
	public: static void addServerID(System::String^ id);
	public: static void removeServerIDs();
	public: static void addServerIP(System::String^ ip);
	public: static void removeServerIPs();
	public: static void printServerIDs();
	public: static void printServerIPs();
};