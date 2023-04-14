// Australian Airport Location Briefing/ATIS Example Request

#include <iostream>
#include <string>
#include <curl/curl.h>

size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string url = "https://www.airservicesaustralia.com/naips/briefing-service?wsdl";
    std::string xmlRequest = R"(<?xml version="1.0" encoding="UTF-8"?>
    <SOAP-ENV:Envelope
        xmlns:ns0="http://schemas.xmlsoap.org/soap/envelope/"
        xmlns:ns1="http://www.airservicesaustralia.com/naips/xsd"
        xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
        xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/">
    <SOAP-ENV:Header/>
    <ns0:Body>
      <ns1:loc-brief-rqs password="NAIPS_PASSWORD" requestor="NAIPS_USERNAME" source="atis">
      <ns1:loc>YSSY</ns1:loc>
      <ns1:flags met="true"/>
    </ns1:loc-brief-rqs>
    </ns0:Body>
    </SOAP-ENV:Envelope>)";
    std::string response;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, xmlRequest.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, xmlRequest.length());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: text/xml; charset=utf-8");
        headers = curl_slist_append(headers, "SOAPAction: \"\"");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    std::cout << "Response:\n" << response << std::endl;

    curl_global_cleanup();
    return 0;
}
