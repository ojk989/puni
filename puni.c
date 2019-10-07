/*
 *   Author:ojk
 *     data:2019-10-06
 *  version:0.01
 *    usage:./puni 4e2e 61 ...
 */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_ITEM_NUM 20
int main(int argc, char **argv)
{
int i,n;
wchar_t *item,*items;
wchar_t ch,*usageMessage;
unsigned int num;
setlocale(LC_ALL,"");
if (argc<2)
   {
   usageMessage=L"   Introduce:*puni*可以根据unicode编码，打印出unicode字符，一次最多打印20个码。使用方法：\nusage: ./puni 4e2e 61\n";
   usageMessage=L"   Introduce:*puni* can print unicode charactor(s) from a list of hexed unicode separated by a space charactor. The maximum length of the unicode parameter list is 20.\n   usage: ./puni 4e2e 61\n";
   wprintf(usageMessage);
   return 0;
   }
else if (argc>MAX_ITEM_NUM)
   {
   wprintf(L"参数过多，最多一次给出20个字符。\n");
   return 1;
   }
/*
这里可以判断argv[1-n]的有效性，否则一切推给strtol
*/
n=argc-1;
item=malloc(13*4);
items=malloc(13*4*MAX_ITEM_NUM);
for (i=1; i<=n; i++)
   {
   num=strtol(argv[i], NULL, 16);
   swprintf(item,52,L"(%#x):%lc ",(wchar_t)num,(wchar_t)num);
   wcscat(items,item);
   }
//num=strtol("4e2a", NULL, 16);
//swprintf(pp,600,L"%ls",L"");
wprintf(L"%ls\n",items);
}
