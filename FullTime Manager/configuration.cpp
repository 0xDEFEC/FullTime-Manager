#include "configuration.h"

using namespace System::Windows::Forms;

/* int keyFileCheck()
Handles checking if a given keyFile exists or not. If not, creates one.
	Returns:
			- FILE_OK (0)
			- FILE_EMPTY (1)
*/
int configuration::keyFileCheck() {
	if (File::Exists(KEYFILEPATH)) {
		if (FileInfo(KEYFILEPATH).Length == 0 || FileInfo(KEYFILEPATH).Length == 1) { // due to GitHub's adding of 1 Byte to empty files
			return FILE_EMPTY;
		}
		return FILE_OK;
	}
	else if (!File::Exists(KEYFILEPATH)) {
		File::Create(KEYFILEPATH)->Close();
		return FILE_EMPTY; // empty upon creation
	}	
}

// Gets API key from file if detected
void configuration::getAPIKey(System::String^ %apiKeyContainer) {
	apiKeyContainer = File::ReadAllText(KEYFILEPATH);
}

// change API key on file to a newly supplied one
void configuration::changeAPIKey(System::String^ newKey, System::String^ %apiKeyContainer) {
	File::WriteAllText(KEYFILEPATH, newKey);
	apiKeyContainer = File::ReadAllText(KEYFILEPATH);
}

// adds a new server ID to the server ID file
void configuration::addServerID(System::String^ id) {
	File::AppendAllText(IDFILEPATH, id + "\n");
}

// removes all stored server IDs
void configuration::removeServerIDs() {
	File::WriteAllText(IDFILEPATH, "");
}

// adds a new server IP to the server IP file
void configuration::addServerIP(System::String^ ip) {
	File::AppendAllText(IPFILEPATH, ip + "\n");
}

// removes all stored server IPs
void configuration::removeServerIPs() {
	File::WriteAllText(IPFILEPATH, "");
}

void configuration::printServerIDs() {
	array<System::String^>^ idList = File::ReadAllLines(IDFILEPATH);
	if (idList->Length == 0 || idList->Length == 1) {
		MessageBox::Show("No Server IDs found. Add them in the <Settings> Tab!", "Notice");
	}
	else {
		System::String^ idListString;
		for each (auto string in idList) {
			idListString += string + "\n";
		}
		MessageBox::Show(idListString, "Info");
	}
}

void configuration::printServerIPs() {
	array<System::String^>^ ipList = File::ReadAllLines(IPFILEPATH);
	if (ipList->Length == 0 || ipList->Length == 1) {
		MessageBox::Show("No IP Addresses found. Add them in the <Settings> Tab!", "Notice");
	}
	else {
		System::String^ ipListString;
		for each (auto string in ipList) {
			ipListString += string + "\n";
		}
		MessageBox::Show(ipListString, "Info");
	}
}