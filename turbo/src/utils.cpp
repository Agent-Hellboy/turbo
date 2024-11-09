#include "utils.h"
#include <curl/curl.h>
#include <fstream>
#include <iostream>

size_t writeData(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

bool downloadPackage(const std::string& url, const std::string& destination) {
    CURL* curl;
    FILE* file;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        file = fopen(destination.c_str(), "wb");
        if (!file) return false;

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(file);

        if (res != CURLE_OK) {
            std::cerr << "Download failed: " << curl_easy_strerror(res) << std::endl;
            return false;
        }
        return true;
    }
    return false;
}
