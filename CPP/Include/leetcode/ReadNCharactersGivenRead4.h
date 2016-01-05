#pragma once
#include "stdafx.h"

// The API: int read4(char *buf) reads 4 characters into the "buf" at a time from a file.
// The return value is the actual number of characters read.
// For example, it returns 3 if there is only 3 characters left in the file.
// 
// By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
namespace leetcode
{
    // Forward declaration of the read4 API.
    int read4(char *buf);

    int read(char *buf, int n)
    {
        char* buf_4Chars = new char[4];
        int buf_index = 0;

        while (buf_index < n)
        {
            int read = read4(buf_4Chars);

            for (int i = 0; i < read && buf_index < n; i++)
            {
                buf[buf_index] = buf_4Chars[i];
                buf_index++;
            }

            if (read < 4)   // end of the file
                break;
        }

        return buf_index;
    }

    // the read function may call multiple times
    // Thought:
    // the tricky of calling multiple times is in each read function call,
    // it may read more characters than required to put into "buf"
    // 
    // For example: read(1) needs to read only 1 character into destination buffer "buf", 
    // however, by calling read4, 4 characters have been processed (read into a temporary buffer "m_buffer").
    // So, the next read function call needs to start reading from the m_buffer not from the file, since there are 3
    // characters in "m_buffer" unprocessed.
    //
    // Basic idea:
    // 1. set the temporary 4 characters buffer as a member varialbe, since this buffer will be used in multiple calls.
    // 2. use an integer variable "m_buffer_size" to indicate how many characters in the temporary 4 characters buffer 
    //    have not been processed from the previous read function call.
    // 3. set an integer variable "offset" to indicate the start position of reading chars from m_buffer.
    class Solution
    {
    public:
        Solution()
            :m_offset(0), m_buffer_size(0)
        {}

        // call multiple times
        int read(char* buf, int n)
        {
            if (n <= 0)
                return 0;

            int have_read = 0;  // the count number, how many characters have been read to buf
            bool eof = false;

            while (!eof && have_read < n)
            {
                // there are unprocessed characters from previous "read" call
                // so, no need to call "read4" immediately.
                if (m_buffer_size == 0)
                {
                    m_buffer_size = read4(m_buffer);
                    if (m_buffer_size < 4)
                    {
                        eof = true;
                    }
                }

                int read = min(n - have_read, m_buffer_size);
                for (int i = 0; i < read; i++)
                {
                    buf[have_read] = m_buffer[m_offset + i];
                    have_read++;
                }

                m_buffer_size -= read;
                m_offset = (m_offset + read) % 4;
            }

            return have_read;
        }
    private:
        int     m_offset;       // the start position need to read characters from m_buffer
        int     m_buffer_size;  // indicate how may characters in the m_buffer have not been read to "buf"
        char    m_buffer[4];    // used to save the read4 characters
    };
}