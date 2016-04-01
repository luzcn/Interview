#pragma once
#include "stdafx.h"

// Given a long url, make it shorter.To make it simpler, let's ignore the domain name.
//
// You should implement two methods :
//
// - longToShort(url).Convert a long url to a short url.
// - shortToLong(url).Convert a short url to a long url starts with http ://tiny.url/.
//
// You can design any shorten algorithm, the judge only cares about two things :
//
// The short key's length should equal to 6 (without domain and slash). 
// And the acceptable characters are [a-zA-Z0-9]. For example: abcD9E
// No two long urls mapping to the same short url and no two short urls mapping to the same long url.



namespace lintcode
{
    class TinyUrl {
    public:
        /**
        * @param url a long url
        * @return a short url starts with http://tiny.url/
        */
        string longToShort(string url)
        {
            int id = 0;
            if (mapUrlToId.find(url) != mapUrlToId.end())
            {
                id = mapUrlToId[url];
            }
            else
            {
                id = index;
                mapIdToUrl[index] = url;
                mapUrlToId[url] = index;

                index++;
            }
            

            string shortUrl;

            while (id > 0)
            {
                shortUrl = chars[id % 62] + shortUrl;
                id /= 62;
            }

            while (shortUrl.size() < 6)
            {
                shortUrl = "0" + shortUrl;
            }
            return "http://tiny.url/" + shortUrl;
        }

        /**
        * @param url a short url starts with http://tiny.url/
        * @return a long url
        */
        string shortToLong(string url)
        {
            int id = 0;
            string shortId = url.substr(url.size() - 6);
            for (int i = 5; i >= 0; i--)
            {
                id += toBase62(shortId[i]) * pow(62, (5-i));
            }

            return mapIdToUrl[id];
        }
    private:
        int toBase62(char c)
        {
            if (c >= '0' && c <= '9')
                return c - '0';

            if (c >= 'a' && c <= 'z')
                return c - 'a' + 10;

            if (c >= 'A' && c <= 'Z')
                return c - 'A' + 36;

            return 0;
        }

        int index = 1;
        string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        unordered_map<int, string> mapIdToUrl;
        unordered_map<string, int> mapUrlToId;
    };
}