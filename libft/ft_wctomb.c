




#include <wchar.h>

int ft_wctomb(char *mb, wchar_t wc)
{
  char *tmp;

  tmp = mb;
  if (wc < (1 << 7))
    *mb++ = (unsigned char)(wc);
  else if (wc < (1 << 11))
  {
    *mb++ = (unsigned char)((wc >> 6) | 0xC0);
    *mb++ = (unsigned char)((wc & 0x3F) | 0x80);
  }
  else if (wc < (1 << 16))
  {
    *mb++ = (unsigned char)((wc >> 12) | 0xE0);
    *mb++ = (unsigned char)(((wc >> 6) & 0x3F) | 0x80);
    *mb++ = (unsigned char)((wc & 0x3F) | 0x80);
  }
  else if (wc < (1 << 21))
  {
    *mb++ = (unsigned char)(((wc >> 18)) | 0xF0);
    *mb++ = (unsigned char)(((wc >> 12) & 0x3F) | 0x80);
    *mb++ = (unsigned char)(((wc >> 6) & 0x3F) | 0x80);
    *mb++ = (unsigned char)((wc & 0x3F) | 0x80);
  }
  return (mb - tmp);
 }
