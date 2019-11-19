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
