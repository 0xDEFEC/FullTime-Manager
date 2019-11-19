#include "requestHandler.h"

// overload without JSON parameters
System::String^ request::performRequest(System::String^ method, System::String^ key, System::String^ path) {
	try {
		HttpWebRequest^ request = gcnew HttpWebRequest(); request = dynamic_cast<HttpWebRequest^>(WebRequest::Create(ROOT + path));
		request->ContentType = "application/json";
		request->Method = method;
		request->Headers->Add("Authorization", key); // auth is done via Authorization header, not request queries or cookies

		HttpWebResponse^ response = gcnew HttpWebResponse(); response = dynamic_cast<HttpWebResponse^>(request->GetResponse());
		StreamReader^ sr = gcnew StreamReader(response->GetResponseStream());
		return JToken::Parse(sr->ReadToEnd())->ToString();
	} catch (WebException^ e) {
		return e->Message;
	}
}

// overload with JSON parameters
System::String^ request::performRequest(System::String^ method, System::String^ key, System::String^ path, System::String^ jsonData) {
	try {
		HttpWebRequest^ request = gcnew HttpWebRequest(); request = dynamic_cast<HttpWebRequest^>(WebRequest::Create(ROOT + path));
		request->ContentType = "application/json";
		request->Method = method;
		request->Headers->Add("Authorization", key); // auth is done via Authorization header, not request queries or cookies
		StreamWriter^ sw = gcnew StreamWriter(request->GetRequestStream());
		sw->Write(jsonData);

		HttpWebResponse^ response = gcnew HttpWebResponse(); response = dynamic_cast<HttpWebResponse^>(request->GetResponse());
		StreamReader^ sr = gcnew StreamReader(response->GetResponseStream());
		return JToken::Parse(sr->ReadToEnd())->ToString();
	}
	catch (WebException^ e) {
		return e->Message;
	}
}