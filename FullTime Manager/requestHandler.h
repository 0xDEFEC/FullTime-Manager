#define ROOT "https://api.fulltimehosting.net/"
#define GET "GET"
#define POST "POST"
#define PUT "PUT"
#define DELETE "DELETE"

using namespace System::Net;
using namespace System::IO;
using namespace System::Web::Script::Serialization;
using namespace Newtonsoft::Json::Linq;

class request {
	// performRequest() overload without JSON parameters 
	public: static System::String^ performRequest(System::String^ method, System::String^ key, System::String^ path);
    // performRequest() overload with JSON parameters - format is handled in calling GUI
	public: static System::String^ performRequest(System::String^ method, System::String^ key, System::String^ path, System::String^ jsonData);
};