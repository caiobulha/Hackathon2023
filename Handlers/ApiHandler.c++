// ApiHandler.h

#pragma once

#include <iostream>
#include <curl/curl.h>
#include <sstream>

class ApiHandler {
public:
    virtual ~ApiHandler() {}

    virtual std::string GetData() = 0;

    // Callback function to handle the response from the HTTP request
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
        size_t totalSize = size * nmemb;
        output->append(static_cast<char*>(contents), totalSize);
        return totalSize;
    }
};

class PokemonApiHandler : public ApiHandler {
public:
    std::string GetData() override {
        CURL* curl;
        CURLcode res;
        std::string url = "https://pokeapi.co/api/v2/pokemon/1"; // You can modify the URL as needed

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        std::string response;

        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            }

            curl_easy_cleanup(curl);
        }

        curl_global_cleanup();

        return response;
    }
};

class CatApiHandler : public ApiHandler {
public:
    std::string GetData() override {
        CURL* curl;
        CURLcode res;
        std::string url = "https://api.thecatapi.com/v1/images/search"; // You can modify the URL as needed

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        std::string response;

        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
            }

            curl_easy_cleanup(curl);
        }

        curl_global_cleanup();

        return response;
    }
};
