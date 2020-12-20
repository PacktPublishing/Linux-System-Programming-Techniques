#include <stdio.h>
#include <curl/curl.h>
 
int main(void)
{
    CURL *curl;
 
    curl = curl_easy_init();
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, 
            "https://ifconfig.me"); 
        curl_easy_perform(curl); 
        curl_easy_cleanup(curl);
    }
    else
    {
        fprintf(stderr, "Cannot initialize curl\n");
        return 1;
    }
    return 0;
}
